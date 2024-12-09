#include "connectionlogic.h"
#include <random>
#include <thread>
#include <chrono>

namespace cl {

ConnectionLogic::Status ConnectionLogic::currentStatus() const
{
    return m_status.isConnected;
}

bool getRandomBoolean()
{
    std::uniform_int_distribution<int> unif(0, 1);
    std::random_device device;
    std::default_random_engine rand_engine(device());
    return unif(rand_engine) == 1;
}

bool ConnectionLogic::connectToServer(const std::string &serverIp)
{
    std::this_thread::sleep_for(std::chrono::seconds(m_waitTime));

    if (currentStatus() == Status::eEnabled)
    {
        disconnectFromServer();
    }

    m_status.lastTriedIp = serverIp;
    if (getRandomBoolean())
    {
        m_status.isConnected = Status::eEnabled;
        m_status.lastSuccessfullyConnectedIp = serverIp;
    }
    else
    {
        m_status.isConnected = Status::eDisabled;
    }
    return currentStatus() == Status::eEnabled;
}

bool ConnectionLogic::disconnectFromServer()
{
    if (m_status.isConnected == Status::eEnabled)
    {
        m_status.isConnected = Status::eDisabled;
    }
    return true;
}

} // namespace cl
