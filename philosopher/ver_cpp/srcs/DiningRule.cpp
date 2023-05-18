#include "../include/DiningRule.hpp"

DiningRule::DiningRule(int philoCount, int timeToDie, int timeToEat, int timeToSleep, int mustEat)
{
    PhiloCount = philoCount;
    TimeToDie = timeToDie;
    TimeToEat = timeToEat;
    TimeToSleep = timeToSleep;
    MustEat = mustEat;
}