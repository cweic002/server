#pragma once
#include "interface/iFactory/iFSocketServer/iFSocketServer.h"
#include "test/socket/tSocketServer/tSocketServer.h"

namespace App{
    namespace Test{
        struct TFSocketServer : public App::Interface::IFSocketServer{
            App::Test::TSocketServer * createISocketServer(const char * port) const override;
        };
    }
}
