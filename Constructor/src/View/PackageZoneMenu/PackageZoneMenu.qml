import QtQuick 2.15
import QtQuick.Window
import QtQuick.Controls
import QtQuick.Dialogs 1.3


Rectangle
{
    id: construct_menu_window
    //когда настрою все кнопки, переделать, чтобы сюда шли не тсатичные параметры, а высоты и ширины из главного окна и выделенного под окна соответствующе
    property real swidth: width / 100
    property real sheight: 1080 / 100
    width: 1920
    height: 1000

    ScrollView
    {
        id: left_menu_scrollview
        height: parent.height
        width: swidth * 1.563
        anchors.right: parent.right
        ListView
        {
            id: left_menu_listview
            width: swidth * 15.625
            height: parent.height
            anchors.right: parent.left
            model: ListModel
            {

            }
            delegate: Rectangle
            {
                width: left_menu_listview.width
                height: sheight * 5.556
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
        Button
        {
            id: plus_button
            height: sheight * 5.37
            width: swidth * 2.604
            anchors.top: left_menu_listview.bottom
            text: "+"
            onClicked:
            {
                input_name.text = ""
                color_box.color = "black"
            }
            onAnchorsChanged:
            {
                if (left_menu_listview.contentHeight > left_menu_listview.height)
                    //будет ли так работать, или в listview поставить высоту 0
                {
                    plus_button.anchors.top = left_menu_listview.contentHeight + 7.407
                }
                else
                {
                    plus_button.anchors.top = left_menu_listview.bottom
                }
            }
        }
    }

    Rectangle
    {
        id: zone_name
        width: swidth * 66.667
        height: sheight * 4.629
        y: sheight * 12.129
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
        height: sheight * 4.629
        y: sheight * 21.481
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
        height: sheight * 5.556
        width: swidth * 14.063
        x: swidth * 24.948
        y: sheight * 85.093
        text: "Сохранить"
        onClicked:
        {
            left_menu_listview.model.append
                    ({
                        name: input_name.text,
                        color: color_box.color
                     })
            left_menu_listview.forceLayout();
            input_name.text = ""
            color_box.color = "black"
        }
    }

    Button
    {
        id: delete_zone
        height: sheight * 5.556
        width: swidth * 14.063
        x: swidth * 77.552
        y: sheight * 85.093
        text: "Удалить"
        onClicked:
        {
            var selectedIdx = left_menu_listview.currentIndex
            if (selectedIdx >= 0 && selectedIdx < left_menu_listview.model.count)
            {
                var elementName = left_menu_listview.model.get(selectedIdx).name
                var confirmationDialog = Qt.inputDialog(parent, "Вы действительно хотите удалить '" + elementName + "'?", "Удалить?", "Оставить")
                if (confirmationDialog.exec() === Qt.DialogCode.Accepted)
                {
                    left_menu_listview.model.remove(selectedIdx)
                }
            }
        }
    }
}

