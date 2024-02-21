#include "fSocketServerLinux.h"

App::Factory::FSocketServerLinux::FSocketServerLinux(App::Interface::IFSocketClient * __factory):_factory(__factory){}

App::Socket::SocketServerLinux *
    App::Factory::FSocketServerLinux::createISocketServer(
        const char * __port) const
{
    return new Socket::SocketServerLinux(__port,_factory);
}
