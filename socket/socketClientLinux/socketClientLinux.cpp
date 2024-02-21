#include "socketClientLinux.h"
#include <netinet/in.h>
#include <unistd.h>
#include <sstream>
#include <string.h>
#include <iostream>

constexpr int INIT_BUFFER = 0;
constexpr size_t SIZE_BUFFER = 255;

App::Socket::SocketClientLinux::SocketClientLinux(int __socketClient):
        _socketClient(__socketClient){}

App::Socket::SocketClientLinux::~SocketClientLinux(){
    this->SocketClientLinux::close();
    std::cout<<"~SocketClientLinux"<<std::endl;
}

void App::Socket::SocketClientLinux::close(){
    ::close(_socketClient);
}

bool App::Socket::SocketClientLinux::send(const std::string & __sendStr) const {
    auto n = write(_socketClient,__sendStr.data(),__sendStr.size());
    if (n < 0)
        return false;
    return true;
}

std::string App::Socket::SocketClientLinux::read() {
    char buffer[SIZE_BUFFER+1]{INIT_BUFFER};//+1 end buffer
    auto n = ::read(_socketClient,buffer,SIZE_BUFFER);
    if (n < 1){
        return "";
    }
    std::stringstream s;
    s<<buffer;
    return s.str();
}
