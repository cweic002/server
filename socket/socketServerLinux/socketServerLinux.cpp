#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <fcntl.h>

#include "socketServerLinux.h"

constexpr int INIT = 0;

App::Socket::SocketServerLinux::SocketServerLinux(
        const char * __port,
        App::Interface::IFSocketClient * __factory):_factory(__factory),_portno(atoi(__port)){
    memset((char *) &_serv_addr,INIT,sizeof(_serv_addr));
}

App::Socket::SocketServerLinux::~SocketServerLinux(){
    SocketServerLinux::close();
}

bool App::Socket::SocketServerLinux::open(){
    _sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(_sockfd < 0)
        return false;
    int flags = fcntl(_sockfd, F_GETFL);
    fcntl(_sockfd, F_SETFL, flags | O_NONBLOCK);
    _serv_addr.sin_family = AF_INET;
    _serv_addr.sin_addr.s_addr = INADDR_ANY;
    _serv_addr.sin_port = htons(_portno);
    if (bind(_sockfd, (struct sockaddr *) &_serv_addr,sizeof(_serv_addr)) < 0)
        return false;
    listen(_sockfd,5);
    return true;
}

void App::Socket::SocketServerLinux::close(){
    ::close(_sockfd);
}

App::Interface::ISocketClient * App::Socket::SocketServerLinux::waitAndGetClient(){
    _clilen = sizeof(_cli_addr);
    auto socketClient = accept(_sockfd,(struct sockaddr *) &_cli_addr,&_clilen);
    if(socketClient < 0)
        return nullptr;
    return _factory->createISocketClient(socketClient);
}
