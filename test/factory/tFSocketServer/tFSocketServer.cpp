#include "tFSocketServer.h"

App::Test::TSocketServer *
    App::Test::TFSocketServer::createISocketServer(
        const char * __port) const
{
    return new Test::TSocketServer(__port);
}
