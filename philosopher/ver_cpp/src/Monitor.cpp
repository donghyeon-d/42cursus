#include "../include/Monitor.hpp"

Monitor::Monitor(std::vector<Philo*> &philoList)
{
    _philoList = philoList;
}

void Monitor::StartMonitoring()
{
    while (true)
    {
        for (int philoNum = 0; philoNum < (int)_philoList.size(); philoNum++)
        {
            if (IsPhiloDied(philoNum))
            {
                Printer::Lock();
                Printer::PrintStatus(philoNum, DIE);
                ChengeAllPhiloStatusToEND();
                Printer::Unlock();
                return ;
            }

            if (IsPhiloEnd(philoNum))
            {
                return ;
            }
        }
    }
}

bool Monitor::IsPhiloDied(int number)
{
    return _philoList[number]->IsDied();
}

bool Monitor::IsPhiloEnd(int number)
{
    return _philoList[number]->CheckStatus(END);
}

void Monitor::ChengeAllPhiloStatusToEND()
{
    for (int philoNum = 0; philoNum < (int)_philoList.size(); philoNum++)
    {
        _philoList[philoNum]->SetStatus(END);
    }
}

