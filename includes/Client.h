//
// Created by udeshya on 3/1/20.
//

#ifndef PLEASEWORK69_CLIENT_H
#define PLEASEWORK69_CLIENT_H

#include <thread>
#include <SFML/Network.hpp>
#include <mutex>

class Client {

public:
//    Client(){}
    Client(const sf::IpAddress& ip, unsigned short port);
    void connection(const sf::IpAddress& ip, unsigned short port);
    sf::Vector2f recieveData();
    bool isConnected() { return m_connected; }
    virtual ~Client();
    sf::Vector2f &getRecievedData();
    void setIsRunning(bool x);
private:
    sf::TcpSocket m_socket;
    bool m_connected;
    bool m_running2;
    sf::Vector2f recievedData;
    std::thread t1;
    std::mutex m_mutex2;
};


#endif //PLEASEWORK69_CLIENT_H
