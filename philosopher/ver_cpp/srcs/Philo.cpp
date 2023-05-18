#include "../include/Philo.hpp"

Philo::Philo(int number, std::vector<Fork*> &forks)
{
    _number = number;

    int left = number;
    int right = number + 1;
    if (DiningRule::PhiloCount == number + 1)
        right = 0;
    _leftFork = forks[left];
    _rightFork = forks[right];

    _status = THINKING;
    
    _worker = NULL;
}

Philo::~Philo()
{
    if (_worker != NULL)
    {
        free(_worker);
    }
}

void Philo::StartDining()
{
    _worker = new std::thread(Act)
}

void Philo::Act()
{
    SpendTime(10);
    while(true)
    {
        GrabForks();
        Eatting();
        Sleeping();
        if (CheckStatus(END))
        {
            break;
        }
    }
}

void Philo::GrabForks()
{
    if (CheckStatus(THINKING) == false)
    {
        return ;
    }

    if (IsOddNumber(_number))
    {
        GrabForksLeftFirst();
    }
    else
    {
        GrabForksRightFirst();
    }

    SetStatus(GETFORK);
}

void Philo::Eatting()
{
    if (CheckStatus(GETFORK) == false)
    {
        return ;
    }

    SetStatus(EATTING);
    
    SetLastEatTimeAtNow();
    
    Printer::PrintStatus(_number, EATTING);

    SpendTime(DiningRule::TimeToEat);
    
    PutDownForks();

    AddEatCount();

    if (IsFullCountEat())
    {
        SetStatus(END);
    }
}

void Philo::Sleeping()
{
    if (CheckStatus(EATTING) == false)
    {
        return ;
    }

    SetStatus(SLEEPING);

    SpendTime(DiningRule::TimeToSleep);
    
    SetStatus(THINKING);
}

bool Philo::IsDied()
{
    bool result = false;

    _lastEatTimeMutex.lock();
    if (Timer::Now() - _lastEatTime > DiningRule::TimeToDie)
    {
        result = true;
    }
    _lastEatTimeMutex.unlock();

    return result;
}


bool Philo::CheckStatus(PhiloStatus status)
{
    bool result = false;

    _statusMutex.lock();
    
    if (_status == status)
    {
        result = true;
    }

    _statusMutex.unlock();

    return result;
}

void Philo::SetStatus(PhiloStatus status)
{
    _statusMutex.lock();
    _status = status;
    _statusMutex.unlock();
}

void Philo::GrabForksLeftFirst()
{
    _leftFork->Grab();
    _rightFork->Grab();
}

void Philo::GrabForksRightFirst()
{
    _rightFork->Grab();
    _leftFork->Grab();
}

void Philo::PutDownForks()
{
    if (IsOddNumber(_number))
    {
        _leftFork->PutDown();
        _rightFork->PutDown();
    }
    else
    {
        _rightFork->PutDown();
        _leftFork->PutDown();
    }
}

void Philo::SetLastEatTimeAtNow()
{
    _lastEatTimeMutex.lock();
    _lastEatTime = Timer::Now();
    _lastEatTimeMutex.unlock();
}

void Philo::AddEatCount()
{
    _eatCount++;
}

bool Philo::IsFullCountEat()
{
    if (_eatCount == DiningRule::MustEat)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Philo::ThreadJoin()
{
    _worker->join();
}

void SpendTime(int milliseconds)
{
    std::this_thread::sleep_until(std::chrono::system_clock::now() + \
                std::chrono::milliseconds(milliseconds));
}

bool IsOddNumber(int num)
{
    if (num % 2 == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
