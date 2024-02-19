import QtQuick 2.15
import QtQuick.Window
import QtQuick.Controls
import QtQuick.Dialogs

Rectangle
{
    id: test_construct_menu_window
    property real swidth: width / 100
    property real sheight: 1080 / 100
    property int counter_seq: 1
    width: 1920
    height: 1000
    color: "#D9D9D9"
    Rectangle
    {
        height: parent.height
        width: swidth * 17.187
        anchors.left: parent.left
        anchors.top: parent.top
        color: "#D9D9D9"
        ScrollView
        {
            id: tcm_left_menu_scrollview
            height: parent.height
            width: swidth * 17.187
            anchors.right: parent.right
            anchors.top: parent.top
            ListView
            {
                id: tcm_zone_storage_listview
                width: swidth * 15.625
                height: contentHeight
                anchors.left: parent.left
                model: ListModel
                {
                    id: tcm_zone_storage_lmodel

                }
                delegate: Item
                {
                    width: pcm_zone_storage_listview.width
                    height: sheight * 5.556
                    ComboBox
                    {
                        id: tcm_zone_storage_combobox
                        model: []
                        background: Rectangle
                        {
                            width: parent.width
                            height: parent.height
                            color: "#D9D9D9"
                        }
                    }
                }
            }
        }
    }
    //Центральное окно
    Rectangle
    {
        id: tcm_middle_rec
        width: swidth * 65.625
        height: parent.height
        x: swidth * 17.187
        color: "#D9D9D9"
        visible: false
        enabled: false
        ScrollView
        {
            width: parent.width
            height: parent.height
            anchors.top: parent.top
            Rectangle
            {
                id: tcm_up_zone_rec
                width: swidth * 65.625
                height: sheight * 20.833
                anchors.top: parent.top
                color: "#D9D9D9"
                Rectangle
                {
                    id: tcm_name_lift_rec
                    width: swidth * 58.698
                    height: sheight * 5.556
                    x: swidth * 4.322
                    y: sheight * 4.259
                    color: "#D9D9D9"
                    Rectangle
                    {
                        width: swidth * 14.409
                        height: sheight * 2.5
                        anchors.left: parent.left
                        anchors.verticalCenter: parent.verticalCenter
                        color: "#D9D9D9"
                        Text
                        {
                            font.family: "Inter"
                            font.pixelSize: 22 * 0.04 * swidth
                            text: qsTr("Название лифта")
                        }
                    }
                    Rectangle
                    {
                        width: swidth * 24.884
                        height: parent.height
                        anchors.right: parent.right
                        TextInput
                        {
                            id: tcm_lift_name
                            width: parent.width
                            height: parent.height
                            anchors.right: parent.right
                            font.family: "Inter"
                            font.pixelSize: 22 * 0.04 * swidth
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                        }
                    }
                }
                Rectangle
                {
                    id: tcm_name_test_rec
                    width: swidth * 58.698
                    height: sheight * 5.556
                    x: swidth * 4.322
                    y: sheight * 12.5
                    color: "#D9D9D9"
                    Rectangle
                    {
                        width: swidth * 14.409
                        height: sheight * 2.5
                        anchors.left: parent.left
                        anchors.verticalCenter: parent.verticalCenter
                        color: "#D9D9D9"
                        Text
                        {
                            font.family: "Inter"
                            font.pixelSize: 22 * 0.04 * swidth
                            text: qsTr("Название лифта")
                        }
                    }
                    Rectangle
                    {
                        width: swidth * 24.884
                        height: parent.height
                        anchors.right: parent.right
                        TextInput
                        {
                            id: tcm_test_name
                            width: parent.width
                            height: parent.height
                            anchors.right: parent.right
                            font.family: "Inter"
                            font.pixelSize: 22 * 0.04 * swidth
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                        }
                    }
                }
            }
            //центр тут
            Rectangle
            {
                id: tcm_up_sequence_rect
                width: swidth * 65.625
                height: sheight * 4.629
                y: sheight * 20.833
                color: "#A0A0A0"
                border.color: "black"
                border.width: 2
                Rectangle
                {
                    width: swidth * 15.208
                    height: sheight * 2.237
                    anchors.left: parent.left
                    anchors.verticalCenter: parent.verticalCenter
                    color: "#A0A0A0"
                    Text
                    {
                        font.family: "Inter"
                        font.pixelSize: 20 * 0.04 * swidth
                        text: qsTr("Последоваткльность пакетов")
                    }
                }
                CheckBox
                {
                    id: show_sequence_rect
                    width: swidth * 1.302
                    height: sheight * 2.315
                    anchors.right: parent.right
                    anchors.verticalCenter: parent.verticalCenter
                    checked: false
                    onCheckedChanged:
                    {
                        tcm_sequence_rect.state === "closed" ? tcm_sequence_rect.state = "opened" : tcm_sequence_rect.state = "closed";

                    }
                }
                Image
                {
                    width: swidth * 1.302
                    height: sheight * 2.315
                    anchors.verticalCenter: show_sequence_rect.verticalCenter
                    source: show_sequence_rect.checked ? "../../arrows_down.png" : "../../arrows_up.png"
                    //visible: !show_port_parametrs.indeterminate || !show_port_parametrs.checked
                }
            }
            //проверить заработает ли так или убрать коммиты
            Rectangle
            {
                id: tcm_sequence_rect
                width: swidth * 65.625
                height: 0
                y: tcm_up_sequence_rect.y + tcm_up_sequence_rect.height
                color: "#D9D9D9"
                state: "closed"
                states:
                    [
                    State
                    {
                        name: "opened"
                        PropertyChanges
                        {
                            target: tcm_sequence_rect; height: sheight * 67.655
                        }
                    },
                    State {
                        name: "closed"
                        PropertyChanges
                        {
                            target: tcm_sequence_rect; height: 0
                        }
                    }
                ]
                transitions: Transition
                {
                    NumberAnimation
                    {
                        properties: "height"
                        duration: 300
                        easing.type: Easing.InOutQuad
                    }
                }
                ScrollView
                {
                    id: tcm_sequence_scrollview
                    width: parent.width
                    height: parent.height
                    anchors.top: parent.top
                    Rectangle
                    {
                        id: tcm_sequence_listview_rect
                        width: parent.width
                        height: sheight * 8.575
                        color: "red"
                        ListView
                        {
                            id: tcm_sequence_listview
                            width: swidth * 57.604
                            height: contentHeight
                            y: sheight * 10.344
                            x: swidth * 3.854
                            //сюда вставлять файлы от количества
                            model: ListModel
                            {
                                id: tcm_sequence_model
                            }
                        }
                        Rectangle
                        {
                            id: tcm_white_line
                            width: parent.width
                            height: sheight * 0.3703
                            color: "white"
                            y: tcm_sequence_listview_rect.y + tcm_sequence_listview_rect.height + 2.87 * sheight
                        }
                        Button
                        {
                            id: plus_but
                            width: swidth * 2.604
                            height: sheight * 4.629
                            x: swidth * 30.729
                            y: tcm_white_line.y + tcm_white_line.height + sheight * 2.315
                            Text
                            {
                                font.family: "Inter"
                                font.pixelSize: 24 * 0.04 * swidth
                                text: "+"
                            }
                            onClicked:
                            {
                                tcm_sequence_listview_rect.height += sheight * 8.575
                                counter_seq ++;
                            }
                        }
                    }
                }
            }
            //описание
            Rectangle
            {
                id: tcm_text_description_rect
                width: swidth * 65.625
                height: sheight * 4.629
                y: tcm_up_sequence_rect.y + tcm_up_sequence_rect.height + tcm_sequence_rect.height
                color: "#A0A0A0"
                border.color: "black"
                border.width: 2
                Rectangle
                {
                    width: swidth * 15.208
                    height: sheight * 2.237
                    anchors.left: parent.left
                    anchors.verticalCenter: parent.verticalCenter
                    color: "#A0A0A0"
                    Text
                    {
                        font.family: "Inter"
                        font.pixelSize: 20 * 0.04 * swidth
                        text: qsTr("Описание текста")
                    }
                }
                CheckBox
                {
                    id: show_text_description_rect
                    width: swidth * 1.302
                    height: sheight * 2.315
                    anchors.right: parent.right
                    anchors.verticalCenter: parent.verticalCenter
                    checked: false
                    onCheckedChanged:
                    {
                        text_description_rect.state === "opened" ? text_description_rect.state = "closed" : text_description_rect.state = "opened";
                    }
                }
                Image
                {
                    width: swidth * 1.302
                    height: sheight * 2.315
                    anchors.verticalCenter: show_text_description_rect.verticalCenter
                    source: show_text_description_rect.checked ? "../../arrows_down.png" : "../../arrows_up.png"
                    //visible: !show_port_parametrs.indeterminate || !show_port_parametrs.checked
                }
            }
            Rectangle
            {
                id: text_description_rect
                width: swidth * 65.625
                height: 0
                y: tcm_text_description_rect.y + tcm_text_description_rect.height
                color: "#D9D9D9"
                state: "closed"
                states:
                    [
                    State
                    {
                        name: "opened"
                        PropertyChanges
                        {
                            target: text_description_rect;
                            height: sheight * 33.704
                        }
                        PropertyChanges
                        {
                            target: text_description_box;
                            height: sheight * 24.537;
                            y: sheight * 3.518
                        }
                    },
                    State {
                        name: "closed"
                        PropertyChanges
                        {
                            target: text_description_rect; height: 0

                        }
                        PropertyChanges
                        {
                            target: text_description_box;
                            height: 0;
                            y: 0
                        }
                    }
                ]
                transitions: Transition
                {
                    NumberAnimation
                    {
                        properties: "height"
                        duration: 300
                        easing.type: Easing.InOutQuad
                    }
                }
                Rectangle
                {
                    id: text_description_box
                    width: swidth * 58.177
                    height: 0
                    y: 0
                    x: swidth * 3.854
                    TextEdit
                    {
                        id: text_description
                        width: parent.width
                        height: parent.height
                        anchors.top: parent.top
                    }
                }
            }
        }
    }
    //Правые кнопки
    Rectangle
    {
        id: tcm_right_menu_rec
        width: swidth * 17.188
        height: parent.height
        anchors.right: parent.right
        color: "#D9D9D9"
        Button
        {
            id: tcm_add_button
            width: swidth * 14.063
            height: sheight * 5.556
            x: swidth * 0.833
            y: sheight * 2.407
            font.pointSize: 22 * swidth * 0.03
            text: "Добавить"
            onClicked:
            {
                tcm_add_button.visible = false;
                tcm_add_button.enabled = false;
                tcm_save_button.visible = true;
                tcm_save_button.enabled = true;
                tcm_middle_rec.visible = true;
                tcm_middle_rec.enabled = true;
                tcm_lift_name.text = "";
                tcm_test_name.text = "";
                counter_seq = 1;
            }
        }
        Button
        {
            id: tcm_save_button
            width: swidth * 14.063
            height: sheight * 5.556
            x: swidth * 0.833
            y: sheight * 2.407
            font.pointSize: 22 * swidth * 0.03
            text: "Сохранить"
            visible: false
            enabled: false
        }
        Button
        {
            id: pcm_change_button
            width: swidth * 14.063
            height: sheight * 5.556
            x: swidth * 0.833
            y: sheight * 10.74
            font.pointSize: 22 * swidth * 0.03
            text: "Изменить"
        }
        Button
        {
            id: pcm_delete_button
            width: swidth * 14.063
            height: sheight * 5.556
            x: swidth * 0.833
            y: sheight * 19.074
            font.pointSize: 22 * swidth * 0.03
            text: "Удалить"
        }
    }
}

