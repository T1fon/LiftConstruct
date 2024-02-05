import QtQuick 2.15
import QtQuick.Window
import QtQuick.Controls

Rectangle {
    id: construct_menu_window
    //когда настрою все кнопки, переделать, чтобы сюда шли не тсатичные параметры, а высоты и ширины из главного окна и выделенного под окна соответствующе
    property real swidth: width / 100
    property real sheight: 1080 / 100
    width: 1920
    height: 1000
    Rectangle
    {
        id: proects_menu
        width:  swidth * 71.5625
        height: sheight * 74.908
        anchors.centerIn: parent.Center
        Rectangle
        {
            id: name_zone
            width: swidth * 10.83333
            height: sheight * 5.37
            y: sheight * 21.944
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
            height: sheight * 57.407
            x: swidth * 17.865
            y: sheight * 30.556
            //сюда вставится таблица проектов
        }
        Button
        {
            id: add_proect
            width: swidth * 10.417
            height: sheight * 3.703
            x: swidth * 73.542
            y: sheight * 30.556
            text: "Создать"
        }
        Button
        {
            id: open_proect
            width: swidth * 10.417
            height: sheight * 3.703
            x: swidth * 73.542
            y: sheight * 37.407
            text: "Открыть"
        }
    }

}
