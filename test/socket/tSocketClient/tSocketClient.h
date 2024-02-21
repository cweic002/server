#pragma once
#include "interface/iSocket/iSocketClient/iSocketClient.h"

namespace App{
    namespace Test{
        struct SocketClient: public App::Interface::ISocketClient {
            enum Status{
                NoneBad = 0,
                BadRead = 1<<0,
                BadSend = 1<<1,
            };
            SocketClient(Status __status = NoneBad);
            ~SocketClient();
            void close() override;
            bool send(const std::string & str) const override;
            std::string read() override;
        private:
            Status _status;
            int _readCount = 10;
        };
    }
}


