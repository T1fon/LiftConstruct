import QtQuick 2.15
import QtQuick.Window
import QtQuick.Controls
import QtQuick.Dialogs


Rectangle
{
    id: construct_menu_window

    width: 1920
    height: 1000
    property real swidth: width / 100
    property real sheight: height / 100
    color: "#D9D9D9"
    Rectangle
    {
        id: left_rect
        width: swidth * 17.188
        height: parent.height
        anchors.left: parent.left
        color: "#D9D9D9"
        ScrollView
        {
            id: left_menu_scrollview
            height: parent.height
            width: swidth * 17.188
            anchors.right : parent.right
            anchors.top: parent.top
            clip: true

            ListView
            {
                id: left_menu_listView
                width: parent.width
                height: contentHeight

                model: ListModel
                {
                    id: pzm_model
                }
                delegate: Rectangle
                {
                    width: left_menu_listView.width
                    height: sheight * 5.556
                    color: model.color
                    border.color: "black"
                    border.width: (left_menu_listView.currentIndex === index) ? 2 : 0

                    Text
                    {
                        text: model.text
                        anchors.centerIn: parent
                        font.family: "Inter"
                        font.pointSize: 20 * swidth * 0.035
                    }
                    MouseArea
                    {
                        anchors.fill: parent
                        onClicked:
                        {
                            input_name.text = model.text
                            color_box.color = model.color
                            left_menu_listView.currentIndex = index
                            color_box.enabled = true
                            delete_zone.enabled = true
                        }
                    }

                }
            }
            Rectangle
            {
                id: white_rect
                width: swidth * 17.188
                height: sheight * 0.9
                color: "white"
                x: left_menu_listView.height
                anchors.left: parent.left
            }
            onContentHeightChanged: {
                if (left_menu_scrollview.flickableItem !== undefined) {
                    if (contentHeight > left_menu_scrollview.height) {
                        left_menu_scrollview.flickableItem.interactive = true;
                    } else {
                        left_menu_scrollview.flickableItem.interactive = false;
                    }
                }
            }
            Button
            {
                id: plus_but
                width: swidth * 2.604
                height: sheight * 5.37
                x: swidth * 6.51
                y: left_menu_listView.contentHeight + white_rect.height
                text: "+"
                font.pointSize: 48 * swidth * 0.03
                onClicked:
                {
                    input_name.enabled = true
                    input_name.text = ""
                    color_box.enabled = true
                    color_box.color = "black"
                    save_zone.enabled = true
                }
                //cdelat cnachala serii kvadrat potom on sapolnitsa
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
        color: "#D9D9D9"

        Rectangle
        {
            height: parent.height
            width: swidth * 5.578
            anchors.left: parent.left
            anchors.verticalCenter: parent.verticalCenter
            color: "#D9D9D9"
            Text
            {
                id: text_name
                font.family: "Inter"
                font.pixelSize: 22 * 0.04 * swidth
                text: qsTr("Имя зоны")
            }
        }
        Rectangle
        {
            height: parent.height
            width: swidth * 29.323
            anchors.right: parent.right
            color: "white"
            border.color: "black"
            border.width: 1
            TextInput
            {
                id: input_name
                height: parent.height
                width: parent.width
                font.family: "Inter"
                font.pixelSize: 22 * 0.04 * swidth
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                text: ""
                enabled: false
            }
        }
    }

    Rectangle
    {
        id: zone_color
        width: swidth * 66.667
        height: sheight * 4.629
        y: sheight * 21.481
        x: swidth * 24.948
        color: "#D9D9D9"

        Rectangle
        {
            height: parent.height
            width: swidth * 5.578
            anchors.left: parent.left
            color: "#D9D9D9"
            Text
            {
                id: color_name
                font.family: "Inter"
                font.pixelSize: 22 * 0.04 * swidth
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
            border.color: "black"
            border.width: 1
            enabled: false

            MouseArea
            {
                anchors.fill: parent
                onClicked: {
                    colorDialog.open()
                }
            }

            ColorDialog
            {
                id: colorDialog
                onAccepted: {
                    color_box.color = colorDialog.selectedColor
                }
            }
        }
    }

    Dialog {
        id: warning_dialog
        title: "ошибка?"
        standardButtons: Dialog.Ok
        Text {
            text:  "Измените цвет (не черный) или впишите имя";
        }
        onAccepted:
        {

        }
    }

    Button {
        id: save_zone
        height: sheight * 5.556
        width: swidth * 14.063
        x: swidth * 24.948
        y: sheight * 77.685
        text: "Сохранить"
        enabled: false
        onClicked:
        {
            if(input_name.text ==  " " || color_box.color == "#000000")
            {
                warning_dialog.open()
            }
            else
            {
                console.log(input_name.text)
                console.log(color_box.color)
                var newItem = { text: input_name.text, color: color_box.color };
                var itemIndex = -1;

                for (var i = 0; i < pzm_model.count; ++i) {
                    if (pzm_model.get(i).text === input_name.text)
                    {
                        itemIndex = i;
                        break;
                    }
                }

                if (itemIndex !== -1)
                {
                    pzm_model.set(itemIndex, newItem);
                }
                else
                {
                    pzm_model.append(newItem);
                }

                left_menu_listView.height += 5.556;
                input_name.text = "";
                color_box.color = "black";
                left_menu_listView.currentIndex = -1;
                white_rect.y = left_menu_listView.contentHeight
                plus_but.y = white_rect.y + white_rect.height
                color_box.enabled = false
                input_name.enabled = false
                save_zone.enabled = false
            }
        }
    }


    Dialog {
        id: confirmation_dialog
        title: "Удалить?"
        standardButtons: Dialog.Ok | Dialog.Cancel
        Text {
            text:  "Вы действительно хотите удалить '" + input_name.text + "'?";
        }
        onAccepted:
        {
            if (confirmation_dialog.opened)
            {
                var selectedIdx = left_menu_listView.currentIndex;
                left_menu_listView.model.remove(selectedIdx);
                left_menu_listView.height = left_menu_listView.contentHeight;
                white_rect.y = left_menu_listView.height;
                plus_but.y = white_rect.y + white_rect.height;
            }
        }
    }

    Button {
        id: delete_zone
        height: sheight * 5.556
        width: swidth * 14.063
        x: swidth * 77.552
        y: sheight * 77.685
        text: "Удалить"
        enabled: false
        onClicked:
        {
            var selectedIdx = left_menu_listView.currentIndex
            if (selectedIdx >= 0 && selectedIdx < left_menu_listView.model.count) {
                confirmation_dialog.open();
            }
            delete_zone.enabled = false;
        }
    }



}

