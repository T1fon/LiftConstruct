#include "PackageZoneView.h"

PackageZoneView::PackageZoneView(QObject *parent): QObject(parent) {}

void PackageZoneView::loadPackageZones()
{
    emit clearPackageZone();

    auto data = MainManager::getZoneManager().getModels();
    for(auto i = data.begin(), end_i = data.end(); i != end_i; i++ )
    {
        emit addPackageZoneSig(i->name(),i->color());
    }
}
void PackageZoneView::addPackageZone(const QString& name, const QColor& color)
{
    MainManager::getZoneManager().addElement(name,color);
}
void PackageZoneView::deletePackageZone(const QString& name)
{
    MainManager::getZoneManager().deleteElement(name);
}
void PackageZoneView::changePackageZone(const QString& name, const QColor& color)
{
    MainManager::getZoneManager().changeElement(name, color);
}
