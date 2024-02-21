#include "tSocketClient.h"
#include <string>

App::Test::SocketClient::SocketClient(Status __status):_status(__status){}

App::Test::SocketClient::~SocketClient(){}

void App::Test::SocketClient::close(){}

bool App::Test::SocketClient::send(const std::string & __str) const {
    if (_status & Status::BadSend)
        return false;
    return true;
}

std::string App::Test::SocketClient::read() {
    if (_status == Status::BadRead){
        return "";
    }
    if(--_readCount>=0){
       return "str Read test\n";
    }else{
        return "";
    }
}


 
