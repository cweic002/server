#pragma once
#include <mutex>

namespace App{
    namespace Interface{
        struct IRefMutex {
            IRefMutex(std::mutex & mutex):mutex(mutex){}
            virtual ~IRefMutex(){}
            void lock(){
                mutex.lock();
            }
            void unlock(){
                mutex.unlock();
            }
            bool try_lock() noexcept
            {
                return mutex.try_lock();
            }
        private:
            std::mutex & mutex;
        };
    }
}

 
