#ifndef APPENGINE_H
#define APPENGINE_H

#include <map>
#include <string>

#include <QObject>
#include "connectionlogic.h"

class AppEngine : public QObject
{
    Q_OBJECT
public:
    explicit AppEngine(QObject *parent = nullptr);

public slots:
    void handleServerConnection(QString ipAddress);
    bool isEnabled() const;

signals:
    void connectionStatusChanged(QString statusMsg);
private:
    cl::ConnectionLogic m_connectionLogic = cl::ConnectionLogic();
    std::map<cl::ConnectionLogic::Status, QString> m_connStatusToString =
        {   { cl::ConnectionLogic::eDisabled, QStringLiteral("Disabled")  },
            { cl::ConnectionLogic::eEnabled,  QStringLiteral("Enabled")   } };
};

#endif // APPENGINE_H
