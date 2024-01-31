import QtQuick 2.15
import QtQuick.Window
import QtQuick.Controls
import QtQuick.Dialogs 1.3

Rectangle
{
    visible: true
    width: 1920
    height: 1080

    Rectangle
    {
        id: construct_menu_window
        property real swidth: width / 100
        property real sheight: 1080 / 100
        width: 1920
        height: sheight * 101

        ScrollView
        {
            id: zone_storage_scrollview
            height: parent.height
            width: swidth * 1.563
            anchors.right: parent.right
            ListView
            {
                id: zone_storage_listview
                width: swidth * 15.625
                height: parent.height
                anchors.right: parent.left
                model: ListModel
                {

                }
                delegate: Rectangle
                {
                    width: zone_storage_listview.width
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
                            input_name.text = model.name
                            color_box.color = model.color
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
            anchors.top: zone_storage_listview.bottom
            text: "+"
            onClicked:
            {
                input_name.text = ""
                color_box.color = "black"
            }
            onAnchorsChanged:
            {
                if (zone_storage_listview.contentHeight > zone_storage_listview.height)
                {
                    plus_button.anchors.top = zone_storage_listview.contentHeight + 6.601
                }
                else
                {
                    plus_button.anchors.top = zone_storage_listview.bottom
                }
            }
        }

        Rectangle
        {
            id: zone_name
            width: swidth * 66.667
            height: sheight * 4.584
            y: sheight * 4.675
            x: swidth * 24.948

            Rectangle
            {
                height: parent.height
                width: swidth * 5.578
                anchors.left: parent.left
                Text
                {
                    id: text_name
                    text: qsTr("Имя зоны")
                }
            }

            TextInput
            {
                id: input_name
                height: parent.height
                width: swidth * 29.323
                anchors.right: parent.right
            }
        }

        Rectangle
        {
            id: zone_color
            width: swidth * 66.667
            height: sheight * 4.584
            y: sheight * 13.935
            x: swidth * 24.948

            Rectangle
            {
                height: parent.height
                width: swidth * 5.578
                anchors.left: parent.left
                Text
                {
                    id: color_name
                    text: qsTr("Цвет")
                }
            }

            Rectangle
            {
                id: color_box
                height: parent.height
                width: swidth * 3.147
                anchors.right: parent.right
                color: "#ff0000"

                MouseArea
                {
                    anchors.fill: parent
                    onClicked:
                    {
                        var color = Qt.inputDialog(parent, "Выберите цвет", "Цвет", color_box.color)
                        if (color.exec() === Qt.DialogCode.Accepted)
                        {
                            color_box.color = color.inputField.text
                        }
                    }
                }
            }
        }

        Button
        {
            id: save_zone
            height: sheight * 5.501
            width: swidth * 14.063
            x: swidth * 24.948
            y: sheight * 76.916
            text: "Сохранить"
            onClicked:
            {
                zone_storage_listview.model.append
                        ({
                            name: input_name.text,
                            color: color_box.color
                         })
                zone_storage_listview.forceLayout();
                input_name.text = ""
                color_box.color = "black"
            }
        }

        Button
        {
            id: delete_zone
            height: sheight * 5.501
            width: swidth * 14.063
            x: swidth * 77.552
            y: sheight * 76.916
            text: "Удалить"
            onClicked:
            {
                var selectedIdx = zone_storage_listview.currentIndex
                if (selectedIdx >= 0 && selectedIdx < zone_storage_listview.model.count)
                {
                    var elementName = zone_storage_listview.model.get(selectedIdx).name
                    var confirmationDialog = Qt.inputDialog(parent, "Вы действительно хотите удалить '" + elementName + "'?", "Удалить?", "Оставить")
                    if (confirmationDialog.exec() === Qt.DialogCode.Accepted)
                    {
                        zone_storage_listview.model.remove(selectedIdx)
                    }
                }
            }
        }
    }
}
