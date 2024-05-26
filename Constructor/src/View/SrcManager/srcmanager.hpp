#ifndef SRCMANAGER_H
#define SRCMANAGER_H

#include <QObject>
#include <QColor>
#include "../../Controller/MainManager/mainmanager.hpp"
#include "../../View/ProjectManager/projectmanager.hpp"

class SRCManager : public QObject
{
    Q_OBJECT
public:
    SRCManager();
};

#endif // SRCMANAGER_H
