#include "scoped_thread.h"
#include <stdexcept>

App::Thread::Scoped_thread::Scoped_thread(std::thread t_):t(std::move(t_))
{
    if(!t.joinable())
        throw std::logic_error("No thread");
}

App::Thread::Scoped_thread::~Scoped_thread()
{
    t.join();
}
