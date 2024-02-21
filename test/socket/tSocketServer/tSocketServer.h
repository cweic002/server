#pragma once
#include "interface/iSocket/iSocketServer/iSocketServer.h"

namespace App{
    namespace Test{
        class TSocketServer: public App::Interface::ISocketServer {
        public:
            enum Status{
                none            = 0,
                BadOpen   = 1<<0,
                BadClient       = 1<<1,
            };
            TSocketServer(const char * __port,Status __initState = none);
            bool open() override;
            void close() override;
            App::Interface::ISocketClient * getClientOrNullptr() override;
        private:
            Status _initState;
        };
    }
}


