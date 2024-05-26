#ifndef PROJECTMANAGER_HPP
#define PROJECTMANAGER_HPP
#include <QString>
#include <QObject>
#include <QAbstractListModel>
#include <QStringList>
#include <QFile>
#include <QTextStream>
#include <QDesktopServices>
#include <QUrl>
#include <QFileInfo>
#include <QDir>
#include <QJsonObject>
#include <QJsonDocument>

class Project
{
public:

    QString name;
    QString last_date_modified;
    QString path;
};

class ProjectModel : public QAbstractListModel
{
    Q_OBJECT

public:

    enum Roles
    {
        path_role = Qt::UserRole + 1,
        date_role,
        name_role
    };
    ProjectModel(QObject* parent = nullptr);

    void addProject(const Project &project);
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    void clear();
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

protected:
    QHash<int, QByteArray> roleNames() const override;

private:
    QList<Project> __projects;
};

class ProjectManager : public QObject {

    Q_OBJECT

public:
    ProjectManager();
    ProjectModel* projectModel() const;

public slots:
    static void loadProjects();
    static void createProject(const QString &name);
    static void openProject(int index);
    static QString getDate();
    static QString getPath();


private:
    static ProjectModel* __project_model;
    static QString __date;
    static QString __path;
};

#endif // PROJECTMANAGER_HPP
