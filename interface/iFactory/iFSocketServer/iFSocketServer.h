#pragma once

#include "interface/iSocket/iSocketServer/iSocketServer.h"

namespace App {
    namespace Interface {
        struct IFSocketServer {
            virtual App::Interface::ISocketServer * createISocketServer(const char * port) const = 0;
            virtual ~IFSocketServer() = default;
    	};
    }
}
