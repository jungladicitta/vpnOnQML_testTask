#ifndef CONNECTIONLOGIC_H
#define CONNECTIONLOGIC_H

#include <string>
#include <map>

namespace cl {

class ConnectionLogic
{
public:
    enum Status {
        eDisabled,
        eEnabled
    };
    ConnectionLogic(int waitTime = 3) : m_waitTime(waitTime) {}
    Status currentStatus() const;
    bool connectToServer(const std::string& serverIp);
    bool disconnectFromServer();

private:
    struct ConnectionStatus {
        Status isConnected = eDisabled;
        std::string lastSuccessfullyConnectedIp;
        std::string lastTriedIp;
    };
    ConnectionStatus m_status;
    int m_waitTime;
};
} // namespace cl

#endif // CONNECTIONLOGIC_H
