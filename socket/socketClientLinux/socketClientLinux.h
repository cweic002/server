#pragma once
#include "interface/iSocket/iSocketClient/iSocketClient.h"

namespace App{
    namespace Socket{
        class SocketClientLinux: public App::Interface::ISocketClient {
            int _socketClient;
        public:
            SocketClientLinux(int __socketClient);
            ~SocketClientLinux();
            void close() override;
            bool send(const std::string & __sendStr) const override;
            std::string read() override;
        };
    }
}


