#ifndef CONSTRUCTVIEW_HPP
#define CONSTRUCTVIEW_HPP
#include <QObject>
#include <qqml.h>
#include <QAbstractListModel>
#include <QFile>
#include <QDir>
#include <QDateTime>
#include "../../Controller/MainManager/mainmanager.hpp"

#define FILE_PATH  "projects.txt"
#define PROJECTS_PATH "projects/"

struct Project
{
    QString name;
    QString path;
    QString date;
};

class ProjectModel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum Roles
    {
        name_role = Qt::UserRole +1,
        date_role,
        path_role
    };
    ProjectModel(QObject *parent = nullptr);

    void addProject(const Project& project);

    int rowCount(const QModelIndex &parent =QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray>roleNames() const override;

private:
    QList<Project> __projects;

};

class ConstructView : public QObject
{
    Q_OBJECT
    QML_ELEMENT

public:
    ConstructView(QObject *parent = nullptr);

public slots:
    ProjectModel* projectModel() const;
    void loadProjects();
    void createProject(const QString& name);
    void openProject(const int& index);
    QString getPath();
    QString getDate();

signals:
    void projectCreated();
    void projectOpened();
    void nameProjectExist(QString name);
    void projectLoad();
    void projectFailedOpen(QString name);

private:
    ProjectModel *__project_model;
    QString __current_path;
    QString __current_date;

};

#endif // CONSTRUCTVIEW_HPP
