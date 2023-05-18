#ifndef PHILO_HPP
#define PHILO_HPP

#include <vector>
#include <ctime>
#include <mutex>
#include <thread>
#include "./Fork.hpp"
#include "./Status.hpp"
#include "./Timer.hpp"
#include "./DiningRule.hpp"
#include "./Printer.hpp"

class Philo
{
    public :
        Philo(int number, std::vector<Fork*> &forks);
        ~Philo();
        void StartDining();
        void SetLastEatTimeAtNow(); // mutex
        PhiloStatus GetStatus();
        bool CheckStatus(PhiloStatus status);
        void SetStatus(PhiloStatus status); // mutex
        bool IsDied();
        void ThreadJoin();

    private:
        int _number;
        Fork *_leftFork;
        Fork *_rightFork;
        int _eatCount;
        time_t _lastEatTime;
        std::mutex _lastEatTimeMutex;
        PhiloStatus _status;
        std::mutex _statusMutex;
        std::thread* _worker;

        void Act();
        void GrabForks();
        void Eatting();
        void Sleeping();
        
        void GrabForksLeftFirst();
        void GrabForksRightFirst();
        void PutDownForks();
        void AddEatCount();
        bool IsFullCountEat();
};

#endif