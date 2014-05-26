#include "serverconnectapi.h"
namespace SSJ {
sf::TcpSocket *ServerConnectAPI::Socket = NULL;



    void ServerConnectAPI::ServerListener(){
        sf::TcpSocket socket;
        sf::IpAddress ip =  sf::IpAddress("127.0.0.1");
        socket.connect(ip, 2004);
        sf::Packet packet;
        packet << "klient";
        socket.send(packet);
        socket.setBlocking(false);
        ServerConnectAPI::Socket = &socket;
        while(true)
        {
           if(ServerConnectAPI::Socket->receive(packet) == sf::Socket::Done){
                std::string temptext;
                if(packet >> temptext)
                {
                     cout << temptext << endl;
                }
           }
            sf::sleep(sf::milliseconds(10));


        }
    }

    void ServerConnectAPI::SendToServer(string json){

        sf::Packet packet;
        packet << json;
        ServerConnectAPI::Socket->send(packet);
    }
}
