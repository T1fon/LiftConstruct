import QtQuick 2.15
import QtQuick.Window
import QtQuick.Controls

Rectangle {
    id: construct_menu_window
    property int swidth: width / 100
    property int sheight: 1080 / 100
    width: 1920
    height: sheight * 101
    Rectangle
    {
        id: proects_menu
        width:  swidth * 71.5625
        height: sheight * 80.9
        anchors.centerIn: parent.Center
        Rectangle
        {
            id: name_zone
            width: swidth * 10.83333
            height: sheight * 5.8
            y: sheight * 14.438
            x: swidth * 17.865
            Text {
                id: text_zone
                text: qsTr("Проекты")
            }
        }
        Rectangle
        {
            id: table_zone
            width: swidth * 56.839
            height: sheight * 62
            x: swidth * 17.865
            y: sheight * 22.918
        }
        Button
        {
            id: add_proect
            width: swidth * 10.417
            height: sheight * 3.667
            x: swidth * 73.542
            y: sheight * 22.918
            text: "Создать"
        }
        Button
        {
            id: open_proect
            width: swidth * 10.417
            height: sheight * 3.667
            x: swidth * 73.542
            y: sheight * 29.703
            text: "Открыть"
        }
    }

}
