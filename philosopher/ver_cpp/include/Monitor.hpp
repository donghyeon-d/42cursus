#ifndef MONITOR_HPP
#define MONITOR_HPP

#include <vector>
#include "./Philo.hpp"

class Monitor
{
    public:
        Monitor(std::vector<Philo*> &philoList);
        void StartMonitoring();

    private:
        std::vector<Philo*> _philoList;
        bool IsPhiloDied(int number);
        bool IsPhiloEnd(int number);
        void ChengeAllPhiloStatusToEND();
};

bool IsInvalidCount(int argc);
bool IsWrongType(int argc, char **argv);
void InitDiningRule(int argc, char **argv);

#endif