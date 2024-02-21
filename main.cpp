#include "factory/fSocketServerLinux/fSocketServerLinux.h"
#include "factory/fSocketClientLinux/fSocketClientLinux.h"
#include "thread/scoped_thread/scoped_thread.h"
#include <list>
#include "fStream/fStream.h"
#include <sstream>
#include <memory>
#include <iostream>
#include <algorithm>

static bool openServer = false;

void threadClient(std::unique_ptr<App::Interface::ISocketClient> client,const std::string & fileName){
    std::string readLine = "";
    while(openServer){
        std::stringstream s;
        auto str = client->read();
        if(!str.empty()){
            s<<readLine<<str;
            while(!s.eof()){
                getline(s,readLine,s.widen('\n'));
                if(!s.eof()){
                    App::FStream fileStream(fileName,App::FStream::app);
                    std::lock_guard lock_fileStream(fileStream);
                    fileStream<<readLine<<std::endl;
                    fileStream.close();
                }
            }
        }else{
             break;
        }
    }
    client->close();
};

void threadServer(char * port,const std::string & fileName){
    std::shared_ptr<App::Interface::IFSocketClient> socketClient_ptr(new App::Factory::FSocketClientLinux());
    auto factoryServer = App::Factory::FSocketServerLinux(socketClient_ptr.get());
    std::shared_ptr<App::Interface::ISocketServer> server_ptr(factoryServer.createISocketServer(port));
    if(!server_ptr->open()){
        fprintf(stderr,"ERROR, no open server\n");
        return;
    }
    {
        std::list<App::Thread::Scoped_thread> threads;
        while(openServer){
            std::unique_ptr<App::Interface::ISocketClient> client(server_ptr->waitAndGetClient());
            if(client){
                threads.emplace_back(std::thread(threadClient,std::move(client),std::ref(fileName)));
            }
        }
    }
    server_ptr->close();
};

int main(int argc, char *argv[])
{
    if (argc < 2) {
        fprintf(stderr,"ERROR, no port provided\n");
        return 0;
    }
    char * port = argv[1];
    openServer = true;
    App::Thread::Scoped_thread thread(std::thread(threadServer,port,"log.txt"));
    while (true){
        std::string str;
        std::cout<<"close server: y?"<<std::endl;
        std::cin>>str;
        if(1==str.size()){
            std::transform(str.begin(), str.end(), str.begin(),tolower);
            if("y"==str){
                openServer = false;
                break;
            }
        }
    }
    return 0;
}
