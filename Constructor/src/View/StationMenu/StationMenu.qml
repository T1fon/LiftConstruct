import QtQuick 2.15
import QtQuick.Window
import QtQuick.Controls
import QtQuick.Dialogs 1.3

Rectangle
{
    id: station_menu_window
    property real swidth: width / 100
    property real sheight: 1080 / 100
    width: 1920
    height: sheight * 101
    ScrollView
    {
        id: station_menu_scrollview_left
        height: parent.height
        width: swidth * 1.563
        anchors.right: parent.right
        ListView
        {
            id: station_menu_listview
            width: swidth * 15.625
            height: parent.height
            anchors.right: parent.left
            model: ListModel
            {

            }
            delegate: Rectangle
            {
                width: station_menu_listview.width
                height: sheight * 5.501
                color: model.color
                Rectangle
                {
                    height: parent.height
                    width: parent.width
                    anchors.left: parent.left
                    Text {
                        text: model.name
                    }
                }
                Rectangle
                {
                    height: parent.height
                    width: parent.width
                    anchors.right: parent.right
                    color: model.color
                }
                MouseArea
                {
                    anchors.fill: parent
                    onClicked:
                    {
                        station_name.text = model.name
                    }
                }
            }
        }
    }
    Button
    {
        id: plus_button
        height: sheight * 5.317
        width: swidth * 2.604
        x: swidth * 6.51
        y: sheight * 17.602
        anchors.top: station_menu_scrollview_left.bottom
        text: "+"
        onClicked:
        {

        }
        onAnchorsChanged:
        {
            if (station_menu_scrollview_left.contentHeight > station_menu_scrollview_left.height)
            {
                plus_button.anchors.top = station_menu_scrollview_left.contentHeight + 6.601
            }
            else
            {
                plus_button.anchors.top = station_menu_scrollview_left.bottom
            }
        }
    }
    Rectangle
    {
        id: buttons_right_menu
        width: swidth * 17.188
        height: parent.height
        anchors.right: parent.right
        Button
        {
            id: add_color_button
            width: swidth * 14.062
            height: sheight * 5.501
            y: sheight * 2.384
            x: swidth * 83.646
            text: "Добавить"
            visible: false
            enabled: false
        }
        Button
        {
            id: change_color_button
            width: swidth * 14.062
            height: sheight * 5.501
            y: sheight * 2.384
            x: swidth * 83.646
            text: "Изменить"
            visible: false
            enabled: false
        }
        Button
        {
            id: delete_color_button
            width: swidth * 14.062
            height: sheight * 5.501
            y: sheight * 9.718
            x: swidth * 83.646
            text: "Удалить"
            visible: false
            enabled: false
        }
    }
    ScrollView
    {
        id: station_menu_scrollview_right
        width: swidth * 1.563
        height: sheight * 79.116
        x: swidth * 81.25
        Rectangle
        {
            id: station_menu_main_window
            width: swidth * 64.063
            height: parent.height
            anchors.right: parent.left
            Rectangle
            {
                id: station_name_rec
                width: swidth * 58.698
                height: sheight * 4.584
                x: swidth * 20.052
                y: sheight * 2.292
                Rectangle
                {
                    height: parent.height
                    width: swidth * 14.409
                    anchors.left: parent.left
                    Text
                    {
                        text: qsTr("Наименование станции")
                    }
                }
                TextInput
                {
                    id: station_name
                    width: swidth * 24.884
                    height: parent.height
                    anchors.right: parent.right
                }
            }
            Rectangle
            {
                id: interfase_name_rec
                width: swidth * 58.698
                height: sheight * 4.584
                x: swidth * 20.052
                y: sheight * 9.626
            }
            Rectangle
            {
                height: parent.height
                width: swidth * 14.409
                anchors.left: parent.left
                Text
                {
                    text: qsTr("Интерфейс")
                }
            }
            TextInput
            {
                id: interfase_name
                width: swidth * 24.884
                height: parent.height
                anchors.right: parent.right
            }
        }
        Rectangle
        {
            id: crc_ok_zone
            width: swidth * 58.698
            height: sheight * 4.584
            x: swidth * 20.052
            y: sheight * 17.327
            Rectangle
            {
                id: crc_ok_text
                height: parent.height
                width: swidth * 14.409
                anchors.left: parent.left
                Text
                {
                    text: qsTr("Вычислять CRC")
                }
            }
            CheckBox
            {
                id: crc_ok_checkbox
                width: swidth * 1.354
                height: sheight * 1.354
                anchors.right: parent.right
            }
        }
    }
    Rectangle
    {
        id: buttons_bottom_menu
        width: swidth * 64.063
        height: sheight * 12.193
        y: sheight * 79.116
        x: swidth * 17.188
        Button
        {
            id: save_station_button
            width: swidth * 14.063
            height: sheight * 5.501
            x: swidth * 18.177
            y: sheight * 83.425
            text: "Сохранить"
            onClicked:
            {
                station_menu_listview.model.append
                        ({
                            name: station_name.text,
                            color: "white"
                         })
                zone_storage_listview.forceLayout()
            }
        }
        Button
        {
            id: delete_station_button
            width: swidth * 14.063
            height: sheight * 5.501
            x: swidth * 66.406
            y: sheight * 83.425
            text: "Удалить"
            onClicked:
            {
                var selectedIdx = station_menu_listview.currentIndex
                if (selectedIdx >= 0 && selectedIdx < station_menu_listview.model.count)
                {
                    var elementName = station_menu_listview.model.get(selectedIdx).name
                    var confirmationDialog = Qt.inputDialog(parent, "Вы действительно хотите удалить '" + elementName + "'?", "Удалить?", "Оставить")
                    if (confirmationDialog.exec() === Qt.DialogCode.Accepted)
                    {
                        station_menu_listview.model.remove(selectedIdx)
                    }
                }
            }
        }
    }
}
