import QtQuick
import QtQuick.Window
import QtQuick.Controls

Window{
    width: 1920
    height: 1080
    visible: true
    property real swidth: this.width / 100
    property real sheight: this.height / 100
    Rectangle{
        id: help_and_fail_menu
        width: parent.width
        height: sheight * 3.704
        anchors.top: parent.top
        ComboBox
        {
            height: parent.height
            width: swidth * 7.813
            anchors.left: parent.left
            id: fail_box
            model: ListModel
            {
                id: fail_model
                ListElement
                {
                    text: "Файл"
                }
                ListElement
                {
                    text: "Открыть"
                }
                ListElement
                {
                    text: "Закрыть"
                }
                ListElement
                {
                    text: "Сохранить"
                }
                ListElement
                {
                    text: "Сохранить как"
                }
                ListElement
                {
                    text: "Экспортировать"
                }
            }
        }
        Button
        {
            id: help_button;
            height: parent.height
            width: swidth * 7.813
            x: swidth * 7.813
            text: "Помощь"
        }
    }
    Rectangle
    {
        id: widows_buttons
        width: parent.width
        height: sheight * 3.704
        y: sheight * 3.704
        anchors.left: parent.left
        Button
        {
            id:construct_menu_button
            height: parent.height
            width: swidth * 12.5
            text: "Конструктор"
        }
        Button
        {
            id: packet_zone_button
            height: parent.height
            width: swidth * 12.5
            x: swidth * 12.5
            text: "Зон пакетов"
        }
        Button
        {
           id: station_zone_button
           height: parent.height
           width: swidth * 18.385
           x:swidth * 25
           text: "Станций"
        }
        Button
        {
           id: package_zone_button
           height: parent.height
           width: swidth * 12.5
           x:swidth * 43.385
           text: "Пакетов"
        }
        Button
        {
           id: test_zone_button
           height: parent.height
           width: swidth * 12.5
           x:swidth * 55.885
           text: "Тестов"
        }
        Button
        {
           id: emulator_zone_button
           height: parent.height
           width: swidth * 12.5
           x:swidth * 68.385
           text: "Эмулятор"
        }
    }
    Rectangle
    {
        id: windows_zone
        width: parent.width
        height: sheight * 92.593
        y: sheight * 7.407
        color: "red"

    }
}
