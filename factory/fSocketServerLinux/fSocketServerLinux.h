#pragma once
#include "interface/iFactory/iFSocketServer/iFSocketServer.h"
#include "interface/iFactory/iFSocketClient/iFSocketClient.h"
#include "socket/socketServerLinux/socketServerLinux.h"

namespace App{
    namespace Factory{
        struct FSocketServerLinux : public App::Interface::IFSocketServer{
            App::Socket::SocketServerLinux * createISocketServer(const char * port) const override;
            FSocketServerLinux(App::Interface::IFSocketClient * __factory);
        private:
            App::Interface::IFSocketClient * _factory;
        };
    }
}
