//
// Created by udeshya on 2/29/20.
//

#ifndef PLEASEWORK69_SERVER_H
#define PLEASEWORK69_SERVER_H


#include <SFML/System/Time.hpp>
#include <SFML/Network.hpp>
#include <queue>
#include <vector>
#include <thread>
#include <mutex>
#include <SFML/Network/TcpSocket.hpp>

class Server {
public:
//    Server(){};
    explicit Server(unsigned short port);
    ~Server();

    void receive();
    void update(sf::Packet &p);
    int getM_playersConnected() const;
    void listenPort(unsigned short port);
    void setIsRunning(bool x);
private:
    bool m_running;
    bool m_dataWaiting;
    sf::Packet m_toSend;
    int m_playersConnected;
    sf::TcpListener m_listener;
    sf::SocketSelector m_selector;
    std::thread t0;
    std::mutex m_mutex;
    sf::TcpSocket socket;
};

#endif //PLEASEWORK69_SERVER_H
