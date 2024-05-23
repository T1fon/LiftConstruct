import QtQuick 2.15
import QtQuick.Window
import QtQuick.Controls 2.15
import QtQuick.Layouts
import ProjectManager 1.0

Rectangle {

    id: construct_menu_window
    width: 1920
    height: 1000
    property real swidth: width / 100
    property real sheight: height / 100
    signal projectCreate(string name, string last_date, string path)
    signal projectOpen(string path, string last_date)
    color: "#D9D9D9"
    ProjectManager
    {
        id: project_manager
    }

    Rectangle
    {
        id: proects_menu
        width:  swidth * 71.5625
        height: sheight * 74.908
        x: swidth * 15.104
        y: sheight * 18.519
        color: "#C0C0C0"
        Rectangle
        {
            id: name_zone
            width: swidth * 10.83333
            height: sheight * 5.37
            y: sheight * 3.426
            x: swidth * 2.76
            color: "#C0C0C0"
            Text
            {
                id: text_zone
                font.family: "Inter"
                font.pixelSize: 48 * 0.05 * swidth
                text: qsTr("Проекты")
            }
        }
        Rectangle
        {
            id: table_zone_rec
            width: swidth * 56.839
            height: sheight * 57.407
            x: swidth * 2.604
            y: sheight * 12.037
            color: "#A4A4A4"
            ListView
            {
                id: list_view
                anchors.fill: parent
                model: project_manager.projectModel()
                delegate: ItemDelegate {
                    width: list_view.width
                    height: 40
                    onClicked: {
                        selectedRow = index
                    }

                    Row {
                        spacing: 10
                        Text { text: model.name }
                        Text { text: model.date }
                        Text { text: model.path }
                    }

                    Rectangle {
                        width: parent.width
                        height: 1
                        color: "lightgray"
                    }
                }
            }


            Button
            {
                id: add_proect
                width: swidth * 10.417
                height: sheight * 3.703
                x: swidth * 57.91
                y: sheight * 12.037
                text: "Создать"
                onClicked:
                {
                    create_project_dialog.visible = true;
                }
            }
            }
        Button
        {
            id: open_proect
            width: swidth * 10.417
            height: sheight * 3.703
            x: swidth * 60.5
            y: sheight * 18.889
            text: "Открыть"
            onClicked:
            {
                if (selectedRow >= 0)
                {
                    project_manager.openProject(selectedRow)
                    projectOpen(project_manager.getPath(), project_manager.getDate())
                }
            }
        }
    }
    Dialog {
        id: create_project_dialog
        modal: true
        visible: false
        title: "Создать проект"
        anchors.centerIn: parent.Center
        standardButtons: Dialog.Ok | Dialog.Cancel
        onAccepted: {
            project_manager.createProject(projectNameInput.text)
            create_project_dialog.visible = false
            projectCreate(projectNameInput.text,project_manager.getDate(), project_manager.getPath())
        }
        onRejected: {
            create_project_dialog.visible = false
        }

        ColumnLayout {
            anchors.fill: parent
            spacing: 10

            TextField {
                id: project_name_input
                placeholderText: "Введите имя проекта"
                Layout.fillWidth: true
            }
        }
    }
}
