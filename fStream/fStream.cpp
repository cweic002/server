#pragma once
#include "fStream.h"

std::map<std::string,std::mutex> App::FStream::mutexs;

App::FStream::FStream(const std::string & __str,
                ios_base::openmode __mode):std::fstream(__str,__mode),
            _mutex(FStream::mutexs[__str]){}

void App::FStream::lock(){
    _mutex.lock();
    sync();
}

void App::FStream::unlock(){
    _mutex.unlock();
}
