#pragma once
#include <map>
#include <mutex>
#include <fstream>

namespace App{
    struct FStream : public std::fstream{
        FStream(const std::string & __str,
                ios_base::openmode __mode = ios_base::in | ios_base::out);
        void lock();
        void unlock();
    private:
        std::mutex & _mutex;
        static std::map<std::string,std::mutex> mutexs;
    };
}
