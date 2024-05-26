import QtQuick 2.15
import QtQuick.Window
import QtQuick.Controls 2.15
import QtQuick.Layouts

import Construct_View 1.0

Rectangle {

    id: construct_menu_window
    width: 1920
    height: 1000
    property real swidth: width / 100
    property real sheight: height / 100
    property int selectedRow: -1
    signal projectOpen
    color: "#D9D9D9"
    onWindowChanged:
        ()=>
        {
            console.log("load package zones");
            construct_view.loadProjects();
        }
    Construct_View
    {
        id: construct_view
        onNameProjectExist:
            (name)=>
            {

                error_project_dialog.visible = true
            }
        onProjectLoad:
            () =>
            {
                epd_text.text = "Файл с именем " + name + " уже существует";
                list_view.model = construct_view.projectModel();
            }
        onProjectFailedOpen:
            (name)=>
            {
                eopd_text.text = "Не удалось открыть файл " + name;
                error_open_project_dialog.visible = true;
            }

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
            Rectangle
            {
                width: parent.width
                height: sheight * 4
                color: "#A4A4A4"
                anchors.top: parent.top
                Row
                {
                    width: parent.width
                    height: parent.height
                    spacing: 0

                    Rectangle
                    {
                        width: parent.width / 2
                        height: parent.height
                        color: "#A4A4A4"
                        border.color: "black"
                        border.width: 2
                        Text
                        {
                            anchors.centerIn: parent
                            text: "Имя"
                            font.pixelSize: 30 * 0.05 * swidth
                            color: "#000000"
                        }
                    }

                    Rectangle {
                        width: 0
                        height: parent.height
                        color: "black"
                    }

                    Rectangle {
                        width: parent.width / 2 - 1
                        height: parent.height
                        color: "#A4A4A4"
                        border.color: "black"
                        border.width: 2


                        Text {
                            anchors.centerIn: parent
                            text: "Дата последнего изменения"
                            font.pixelSize: 30 * 0.05 * swidth
                            color: "#000000"
                        }
                    }
                }

            }
            ListView
            {
                id: list_view
                y: sheight * 4
                width: parent.width
                height: parent.height
                //anchors.fill: parent
                model: construct_view.projectModel()

                delegate: ItemDelegate
                {
                    width: list_view.width
                    height: 40


                    Rectangle
                    {
                        width: parent.width
                        height: 40
                        property color default_color: "#A4A4A4"
                        property color highlight_color: "#888888"
                        color: default_color
                        clip: true

                        MouseArea
                        {
                            anchors.fill: parent
                            onClicked:
                            {
                                list_view.currentIndex = index
                                parent.color = parent.highlight_color
                                revert_color_timer.start()
                                selectedRow = list_view.currentIndex
                            }
                        }
                        Timer
                        {
                            id: revert_color_timer
                            interval: 100 // 1 секунда
                            repeat: false
                            onTriggered:
                            {
                                parent.color = parent.default_color
                            }
                        }

                        Row
                        {
                            width: parent.width
                            height: parent.height
                            spacing: 0

                            Rectangle
                            {
                                width: parent.width / 2
                                height: parent.height
                                color: "transparent"
                                border.color: "black"
                                border.width: 2
                                Text
                                {
                                    anchors.centerIn: parent
                                    text: model.name
                                    font.pixelSize: 30 * 0.05 * swidth
                                    color: "#000000"
                                }
                            }

                            Rectangle
                            {
                                width: 0
                                height: parent.height
                                color: "black"
                            }

                            Rectangle
                            {
                                width: parent.width / 2 - 1
                                height: parent.height
                                color: "transparent"
                                border.color: "black"
                                border.width: 2


                                Text
                                {
                                    anchors.centerIn: parent
                                    text: model.date
                                    font.pixelSize: 30 * 0.05 * swidth
                                    color: "#000000"
                                }
                            }
                        }

                        Rectangle
                        {
                            width: parent.width
                            height: 1
                            color: "lightgray"
                        }
                    }
                }
            }
        }
        Button
        {
            id: add_proect
            width: swidth * 10.417
            height: sheight * 3.703
            x: swidth * 60.5
            y: sheight * 14.037
            text: "Создать"
            onClicked:
            {
                create_project_dialog.visible = true;
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
            onClicked: {
                    if (selectedRow >= 0 && !error_project_dialog.visible && !error_open_project_dialog.visible) {
                        construct_view.openProject(selectedRow)
                        projectOpen
                    }
                }
        }
    }
    Dialog {
        id: create_project_dialog
        modal: true
        visible: false
        title: "Создать проект"
        y: sheight * 30
        x: swidth * 35
        width: swidth * 20
        height: sheight * 20
        standardButtons: Dialog.Ok | Dialog.Cancel
        onAccepted: {
            construct_view.createProject(project_name_input.text)
            project_name_input.clear()
            create_project_dialog.visible = false
            projectOpen()
        }
        onRejected: {
            project_name_input.clear()
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
    Dialog {
        id: error_project_dialog
        modal: true
        visible: false
        y: sheight * 30
        x: swidth * 35
        width: swidth * 20
        height: sheight * 20
        title: "Ошибка"
        Text {
            id: epd_text
            text: qsTr("Имя уже занято ")
        }
        anchors.centerIn: parent.Center
        standardButtons: Dialog.Ok
        onAccepted:
        {
            project_name_input.clear()
            error_project_dialog.visible = false
        }
    }
    Dialog {
        id: error_open_project_dialog
        modal: true
        visible: false
        y: sheight * 30
        x: swidth * 35
        width: swidth * 20
        height: sheight * 20
        title: "Ошибка"
        Text {
            id: eopd_text
            text: qsTr("Не удалось открыть файл ")
        }
        anchors.centerIn: parent.Center
        standardButtons: Dialog.Ok
        onAccepted:
        {
            project_name_input.clear()
            error_open_project_dialog.visible = false
        }
    }
}
