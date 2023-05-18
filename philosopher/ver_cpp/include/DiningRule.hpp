#ifndef DININGRULE_HPP
# define DININGRULE_HPP

class DiningRule
{
    public :
        DiningRule(int philoCount, int timeToDie, int timeToEat, int timeToSleep, int mustEat);
        ~DiningRule();
        static int  PhiloCount;
        static int	TimeToDie;
        static int	TimeToEat;
        static int	TimeToSleep;
        static int	MustEat;
};

#endif