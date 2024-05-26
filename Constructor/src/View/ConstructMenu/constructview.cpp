#include "constructview.hpp"


ProjectModel::ProjectModel(QObject *parent){}

void ProjectModel::addProject(const Project &project)
{
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    __projects << project;
    endInsertRows();
}

int ProjectModel::rowCount(const QModelIndex &parent) const
{
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
        return project.date;
    else if (role == path_role)
        return project.path;

    return QVariant();
}
QHash<int, QByteArray> ProjectModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[name_role] = "name";
    roles[date_role] = "date";
    roles[path_role] = "path";
    return roles;
}

ConstructView::ConstructView(QObject *parent) : QObject(parent), __project_model(new ProjectModel(this)){}

ProjectModel* ConstructView::projectModel() const
{
    return __project_model;
}

void ConstructView::loadProjects()
{
    QFile file(FILE_PATH);
    QFileInfo fileInfo(file);
    qDebug() << "Абсолютный путь к файлу loadProjects:" << fileInfo.absoluteFilePath();
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        emit projectFailedOpen(FILE_PATH);
        qDebug() << "Ошибка открытия файла с проектами";
        return;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split(' ', Qt::SkipEmptyParts);
        if (fields.size() == 3) {
            QString name = fields[0];
            QString path = fields[1];
            QString date = fields[2];
            __project_model->addProject({name, path, date});
        }
    }
    emit projectLoad();
}

void ConstructView::createProject(const QString &name)
{
    for (int i = 0; i < __project_model->rowCount(); ++i)
    {
        QModelIndex modelIndex = __project_model->index(i, 0);
        QString existingName = __project_model->data(modelIndex, ProjectModel::name_role).toString();
        if (existingName == name)
        {
            qWarning() << "Проект с таким именем уже существует";
            emit nameProjectExist(name);
            return;
        }
    }

    __current_path = PROJECTS_PATH + name + ".json";
    QDir().mkdir(__current_path);
    __current_date = QDateTime::currentDateTime().toString("dd/MM/yyyy");
    __project_model->addProject({name, __current_path, __current_date});


    QFile file(FILE_PATH);
    QFileInfo fileInfo(file);
    qDebug() << "Абсолютный путь к файлу:" << fileInfo.absoluteFilePath();
    if (file.open(QIODevice::Append | QIODevice::Text))
    {
        QTextStream out(&file);
        out << name << ' ' << __current_path << ' ' << __current_date << '\n';
        file.close();
    }
    else
    {
        qDebug() << "Ошибка открытия файла с проектами";
        emit projectFailedOpen(name);
        return;
    }
    MainManager::constructFromJson(QJsonObject());
    MainManager::setName(name);
    MainManager::setDate(__current_date);
    MainManager::setPath(__current_path);
    emit projectCreated();
}

void ConstructView::openProject(const int& index)
{
    if (index >= 0 && index < __project_model->rowCount()) {

        QModelIndex model_index = __project_model->index(index, 0);
        __current_path = __project_model->data(model_index, ProjectModel::path_role).toString();
        __current_date = __project_model->data(model_index, ProjectModel::date_role).toString();
        QString name = __project_model->data(model_index, ProjectModel::name_role).toString();

        QFile file(__current_path);
        QFileInfo fileInfo(file);
        qDebug() << "Абсолютный путь к файлу:" << fileInfo.absoluteFilePath();
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            emit projectFailedOpen(__project_model->data(model_index, ProjectModel::name_role).toString());
            qWarning() << "Failed to open project file:" << __current_path;
            return;
        }

        QByteArray json_data = file.readAll();
        file.close();

        QJsonParseError json_error;
        QJsonDocument json_doc = QJsonDocument::fromJson(json_data, &json_error);
        if (json_error.error != QJsonParseError::NoError)
        {
            qWarning() << "Error parsing JSON:" << json_error.errorString();
            return;
        }

        QJsonObject project_json = json_doc.object();


        MainManager::constructFromJson(project_json);
        MainManager::setDate(__current_date);
        MainManager::setPath(__current_path);
        MainManager::setName(name);

        emit projectOpened();
    }
}

QString ConstructView::getPath() { return __current_path;}

QString ConstructView::getDate() { return __current_date;}

