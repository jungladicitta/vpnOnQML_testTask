#include "appengine.h"

AppEngine::AppEngine(QObject *parent)
    : QObject{parent}
{}

void AppEngine::handleServerConnection(QString ipAddress)
{
    // connection to server...
    if (isEnabled() && ipAddress.isEmpty())
        m_connectionLogic.disconnectFromServer();
    else
        m_connectionLogic.connectToServer(ipAddress.toStdString());

    QString statusMsg = m_connStatusToString[m_connectionLogic.currentStatus()];
    if (isEnabled())
    {
        statusMsg += QStringLiteral(" on ") + ipAddress;
    }

    emit connectionStatusChanged(statusMsg);
}

bool AppEngine::isEnabled() const
{
    return m_connectionLogic.currentStatus() == cl::ConnectionLogic::eEnabled;
}
