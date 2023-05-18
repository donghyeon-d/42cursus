#ifndef FORK_HPP
#define FORK_HPP

#include <mutex>
#include <chrono>
#include <thread>
#include "./Status.hpp"

class Fork
{
    public :
        Fork();
        ~Fork();
        void Grab();
        void PutDown();

    private :
        ForkStatus _status;
        std::mutex _mutex;
};

#endif