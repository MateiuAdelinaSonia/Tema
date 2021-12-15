#include <iostream>
#include <mutex>

class Lock
{
    public:
        explicit Lock(std::mutex *mutex) : myMutex(mutex) {
            lock(myMutex);
        }

        ~Lock() {
            unlock(myMutex);
        }

    private:
        std::mutex *myMutex;

    void lock(std::mutex *m) 
    {
        m->lock();
        std::cout << "\n" << "Flag is locked" << std::endl;
    }

    void unlock(std::mutex *m)
    {
        m->unlock();
        std::cout << "Flag is unlocked" << std::endl;
    }
};