#include "projectmanager.hpp"

ProjectModel::ProjectModel(QObject* parent)
    : QAbstractListModel(parent) {}

void ProjectModel::addProject(const Project &project)
{

    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    __projects << project;
    endInsertRows();
}

int ProjectModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return __projects.count();
}

QVariant ProjectModel::data(const QModelIndex &index, int role) const
{
    if (index.row() < 0 || index.row() >= __projects.count())
        return QVariant();

    const Project &project = __projects[index.row()];
    if (role == name_role)
        return project.name;
    else if (role == date_role)
        return project.last_date_modified;
    else if(role == path_role)
        return project.path;
    return QVariant();
}

void ProjectModel::clear()
{
    beginRemoveRows(QModelIndex(), 0, rowCount() - 1);
    __projects.clear();
    endRemoveRows();
}

QHash<int, QByteArray> ProjectModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[name_role] = "name";
    roles[date_role] = "date";
    roles[path_role] = "path";
    return roles;
}

ProjectModel* ProjectManager::__project_model = new ProjectModel();

ProjectModel* ProjectManager::projectModel()
{
    return __project_model;
}

void ProjectManager::loadProjects()
{
    __project_model->clear();

    QFile file("projects.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList parts = line.split(',');
        if (parts.size() == 2) {
            Project project;
            project.path = parts.at(0);
            project.last_date_modified = parts.at(1);
            QString file_name = QFileInfo(project.path).fileName();
            project.name = file_name.left(file_name.lastIndexOf('.'));
            __project_model->addProject(project);
        }
    }
}

void ProjectManager::createProject(const QString &name)
{
    if (name.isEmpty())
    {
        return;
    }

    QString project_path = QDir::currentPath() + "/" + name + ".proj";
    QFile file(project_path);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        return;
    }
    file.close();

    Project project;
    project.name = name;
    project.path = project_path;
    project.last_date_modified = QDate::currentDate().toString("dd-MM-yyy");
    __project_model->addProject(project);

    QFile projectsFile("projects.txt");
    if (projectsFile.open(QIODevice::Append | QIODevice::Text))
    {
        QTextStream out(&projectsFile);
        out << project_path << "," << project.last_date_modified << "\n";
        projectsFile.close();
    }
    __date = QDate::currentDate().toString("dd-MM-yyy");
    __path = project_path;

}

void ProjectManager::openProject(int index)
{
    if (index < 0 || index >= __project_model->rowCount())
        return;

    QString project_path = __project_model->data(__project_model->index(index), ProjectModel::path_role).toString();
    QFile file(project_path);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return;
    }

    __date = QDate::currentDate().toString("dd-MM-yyy");
    __path = project_path;
}

