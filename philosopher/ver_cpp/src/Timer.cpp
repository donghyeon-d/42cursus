#include "../include/Timer.hpp"
#include <iostream>

timeval* Timer::_start;

void Timer::SetStartTime()
{
    _start = new timeval;
    gettimeofday(_start, NULL);
}

time_t Timer::Now()
{
    if (_start == NULL)
        SetStartTime();
    timeval currentTime;
    gettimeofday(&currentTime, NULL);

    currentTime.tv_sec -= _start->tv_sec;
    currentTime.tv_usec -= _start->tv_usec;

    time_t result = (currentTime.tv_sec * 1000) + (currentTime.tv_usec / 1000);

    return (result);
}
