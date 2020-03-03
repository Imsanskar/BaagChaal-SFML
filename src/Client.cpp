//
// Created by udeshya on 3/1/20.
//

#include <iostream>
#include "Client.h"

Client::Client(const sf::IpAddress& ip,unsigned short port)
{
    recievedData.x = recievedData.y = 0;
    m_connected=false;
    m_running2=true;
//connection(ip,port);
    t1=std::thread(&Client::connection,this,ip,port);
    t1.detach();
}

Client::~Client() {
    m_running2=false;
//m_socket.disconnect();
}

void Client::connection(const sf::IpAddress& ip, unsigned short port)
{
    unsigned short initPort = port;
    std::cout << "About to begin connection\n";
    while (!m_connected){
        static int checkLoop=0;
        if (m_socket.connect(ip, port, sf::seconds(15)) != sf::Socket::Done)
        {
            if(checkLoop<2) {
//                std::cout << "Error connecting to port " << port <<std::endl;
                port++;
                checkLoop++;
            }
            else
            {
                checkLoop = 0;
                port = initPort;
//                std::cout << "Error connecting to server" << std::endl;
            }
        }
        else {
            m_connected = true;
            std::cout << "Connected to the server" << std::endl;
        }
    }
    while (this->m_running2 && m_connected ) {
        std::cout << "Server connected\n";
        this->recievedData  = recieveData();
    }

}

sf::Vector2f &Client::getRecievedData() {
    return recievedData;
}

sf::Vector2f Client::recieveData(){
    m_socket.setBlocking(true);
    sf::Vector2f position;
    sf::Packet Sam;

    if (m_socket.receive(Sam) == sf::Socket::Done) {
    	std::cout << "Data received successfully\n";
        Sam >> position.x >> position.y;
        return position;
    } else
    {
        position.x = position.y = 0;
        return position;
    }
}

void Client::setIsRunning(bool x) {
    m_mutex2.lock();
    m_running2 = x;
    m_mutex2.unlock();
}

