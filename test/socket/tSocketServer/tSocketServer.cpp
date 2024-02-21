#include "tSocketServer.h"
#include "test/socket/tSocketClient/tSocketClient.h"

App::Test::TSocketServer::TSocketServer(const char * __port,Status __initState):_initState(__initState){}

bool App::Test::TSocketServer::open(){
    if(_initState & BadOpen)
        return false;
    return true;
}

void App::Test::TSocketServer::close(){}

App::Interface::ISocketClient * App::Test::TSocketServer::waitAndGetClient(){
    if (_initState & BadClient)
        return nullptr;
    return new SocketClient();
}
