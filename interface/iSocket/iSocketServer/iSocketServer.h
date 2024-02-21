#pragma once
#include "interface/iSocket/iSocketClient/iSocketClient.h"

namespace App{
    namespace Interface{
        struct ISocketServer {
            virtual bool open() = 0;
            virtual void close() = 0;
            virtual App::Interface::ISocketClient * getClientOrNullptr() = 0;
            virtual ~ISocketServer() = default;
        };
    }
}

 
