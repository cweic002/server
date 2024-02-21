#include "fSocketClientLinux.h"

App::Socket::SocketClientLinux * App::Factory::FSocketClientLinux::createISocketClient(int _socketClient) const {
    return new App::Socket::SocketClientLinux(_socketClient);
}
