#pragma once
#include <netinet/in.h>
#include "interface/iSocket/iSocketServer/iSocketServer.h"
#include "interface/iFactory/iFSocketClient/iFSocketClient.h"

namespace App{
    namespace Socket{
        class SocketServerLinux: public App::Interface::ISocketServer {
            int _sockfd, _portno;
            socklen_t _clilen;
            char _buffer[256];
            struct sockaddr_in _serv_addr, _cli_addr;
            App::Interface::IFSocketClient * _factory;
        public:
            SocketServerLinux(const char * port,App::Interface::IFSocketClient * _factory);
            ~SocketServerLinux();
            bool open() override;
            void close() override;
            App::Interface::ISocketClient * waitAndGetClient() override;
        };
    }
}


