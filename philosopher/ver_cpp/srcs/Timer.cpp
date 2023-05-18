#include "../include/Timer.hpp"

void Timer::SetStartTime()
{
    gettimeofday(_start, nullptr);
}

time_t Timer::Now()
{
    if (_start == nullptr)
    {
        return 0;
    }

    timeval currentTime;
    gettimeofday(&currentTime, nullptr);

    currentTime.tv_sec -= _start->tv_sec;
    currentTime.tv_usec -= _start->tv_usec;

    time_t result = (currentTime.tv_sec * 1000000) + (currentTime.tv_usec / 1000);
    return (result);
}
