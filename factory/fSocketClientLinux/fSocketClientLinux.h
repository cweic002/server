#pragma once
#include "interface/iFactory/iFSocketClient/iFSocketClient.h"
#include "socket/socketClientLinux/socketClientLinux.h"

namespace App{
    namespace Factory{
        struct FSocketClientLinux : public App::Interface::IFSocketClient{
            App::Socket::SocketClientLinux * createISocketClient(int) const override;
        };
    }
}
