#include "../include/Fork.hpp"
Fork::Fork()
{
    _status = NOTUSED;
}

Fork::~Fork()
{
}

void Fork::Grab()
{
    while (true)
    {
        _mutex.lock();
        if (_status == NOTUSED)
        {
            _status = USED;
            _mutex.unlock();
            break;
        }
        _mutex.unlock();
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
}

void Fork::PutDown()
{
    _mutex.lock();
    _status = NOTUSED;
    _mutex.unlock();
}
