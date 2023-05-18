#include "../include/Printer.hpp"

void Printer::PrintStatus(int id, PhiloStatus philoStatus)
{
    _printMutex.lock();

    time_t time = Timer::Now();
    std::cout << time << " " << id;
    
    switch (philoStatus)
    {
        case EATTING:
            std::cout << "is eating";
            break;
        case SLEEPING:
            std::cout << "is sleeping";
            break;
        case THINKING:
            std::cout << "is thinking";
            break;
        case GETFORK:
            std::cout << "has taken a fork";
            break;
        case DIE:
            std::cout << "died";
            break;
    }
    std::cout << std::endl;

    if (philoStatus != DIE)
    {
        _printMutex.unlock();
    }
}

void Printer::Lock()
{
    _printMutex.lock();
}

void Printer::Unlock()
{
    _printMutex.unlock();
}
