#pragma once
#include "interface/iSocket/iSocketClient/iSocketClient.h"

namespace App {
    namespace Interface {
        struct IFSocketClient {
            virtual App::Interface::ISocketClient * createISocketClient(int) const = 0;
            virtual ~IFSocketClient() = default;
        };
    }
}
