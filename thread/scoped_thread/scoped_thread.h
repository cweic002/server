#pragma once
#include <thread>

namespace App{
    namespace Thread{
        class Scoped_thread
        {
            std::thread t;
        public:
            explicit Scoped_thread(std::thread t_);
            ~Scoped_thread();
            Scoped_thread(Scoped_thread const&)=delete;
            Scoped_thread& operator=(Scoped_thread const&)=delete;
        };
    }
}
