import QtQuick
import QtQuick.Window
import QtQuick.Controls

Window{
    width: 1920
    height: 1080
    visible: true
    property int swidth: this.width / 100
    property int sheight: this.height / 100
    Rectangle{
        id: help_and_fail_menu
        width: parent.width
        height: sheight * 4
        anchors.top: parent.top
        ComboBox
        {
            height: parent.height
            width: swidth * 9
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
            width: swidth * 9
            x:swidth * 9
            text: "Помощь"
        }
    }
    Rectangle
    {
        id: widows_buttons
        width: parent.width
        height: sheight * 4
        y: sheight * 4
        anchors.left: parent.left
        Button
        {
            id:construct_menu_button
            height: parent.height
            width: swidth * 9
            text: "Конструктор"
        }
        Button
        {
            id: packet_zone_button
            height: parent.height
            width: swidth * 9
            x:swidth * 9
            text: "Зон пакетов"
        }
        Button
        {
           id: station_zone_button
           height: parent.height
           width: swidth * 9
           x:swidth * 18
           text: "Станций"
        }
        Button
        {
           id: package_zone_button
           height: parent.height
           width: swidth * 9
           x:swidth * 27
           text: "Пакетов"
        }
        Button
        {
           id: test_zone_button
           height: parent.height
           width: swidth * 9
           x:swidth * 36
           text: "Тестов"
        }
        Button
        {
           id: emulator_zone_button
           height: parent.height
           width: swidth * 9
           x:swidth * 45
           text: "Эмулятор"
        }
    }
    Rectangle
    {
        id: windows_zone
        width: parent.width
        height: sheight * 100
        color: "red"
        anchors.bottom: parent.bottom

    }
}
