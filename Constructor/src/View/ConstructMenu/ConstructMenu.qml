import QtQuick 2.15
import QtQuick.Window
import QtQuick.Controls 2.15
import QtQuick.Layouts

Rectangle {
    id: construct_menu_window
    //когда настрою все кнопки, переделать, чтобы сюда шли не тсатичные параметры, а высоты и ширины из главного окна и выделенного под окна соответствующе
    width: 1920
    height: 1000
    property real swidth: width / 100
    property real sheight: height / 100
    color: "#D9D9D9"
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
            TableView
            {
                    anchors.fill: parent

                    Row {
                        spacing: 5

                        Text {
                            text: "Имя"
                            width: table_zone_rec.width / 2
                            horizontalAlignment: Text.AlignHCenter
                            font.family: "Inter"
                            font.pixelSize: 22 * 0.05 * swidth

                        }

                        Text {
                            text: "Дата последнего изменения"
                            width: table_zone_rec.width / 2
                            horizontalAlignment: Text.AlignHCenter
                            font.family: "Inter"
                            font.pixelSize: 22 * 0.05 * swidth
                        }
                    }

                    model: ListModel {
                        id: tableModel

                    }

            }

        }


        Button
        {
            id: add_proect
            width: swidth * 10.417
            height: sheight * 3.703
            x: swidth * 60.5
            y: sheight * 12.037
            text: "Создать"
        }
        Button
        {
            id: open_proect
            width: swidth * 10.417
            height: sheight * 3.703
            x: swidth * 60.5
            y: sheight * 18.889
            text: "Открыть"
        }
    }

}
