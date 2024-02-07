import QtQuick 2.15
import QtQuick.Window
import QtQuick.Controls
import QtQuick.Dialogs 1.3

Rectangle
{
    id: test_construct_menu_window
    //когда настрою все кнопки, переделать, чтобы сюда шли не тсатичные параметры, а высоты и ширины из главного окна и выделенного под окна соответствующе
    property real swidth: width / 100
    property real sheight: 1080 / 100
    width: 1920
    height: 1000
    //правое меню проверить, если хорошо работает комбобох поставить везде.Если нет - поправить и переделать везде
    ScrollView
    {
        id: test_construct_menu_scrollview_left
        height: parent.height
        width: swidth * 1.563
        x: swidth * 15.625
        ListView
        {
            id: station_menu_listview
            width: swidth * 15.625
            height: parent.height
            anchors.right: parent.left
            model: ListModel
            {

            }
            delegate: Item
            {
                width: station_menu_listview.width
                height: combo_box_row.height
                Row
                {
                    id: combo_box_row
                    Text
                    {
                        text: model.name
                    }
                    ComboBox
                    {
                        id: combo_box
                        width: parent.width
                    }
                }
            }
        }
    }
    //Центральное окно
    Rectangle
    {
        id: tcm_up_zone_rec
        width: swidth * 65.625
        height: sheight * 20.833
        x: swidth * 17.188
        y: sheight * 7.407
        visible: false
        enabled: false
        Rectangle
        {
            id: tcm_name_lift_rec
            width: swidth * 58.698
            height: sheight * 5.556
            x: swidth * 21.51
            y: sheight * 11.667
            Rectangle
            {
                width: swidth * 14.409
                height: sheight * 2.5
                x: swidth * 21.51
                y: sheight * 13.148
                Text
                {
                    text: qsTr("Название лифта")
                }
            }
            TextInput
            {
                id: tcm_name_lift
                width: swidth * 24.884
                height: parent.height
                anchors.right: parent.right
            }
        }
        Rectangle
        {
            id: tcm_name_test_rec
            width: swidth * 58.698
            height: sheight * 5.556
            x: swidth * 21.51
            y: sheight * 19.907
            Rectangle
            {
                width: swidth * 14.409
                height: sheight * 2.5
                x: swidth * 21.51
                y: sheight * 21.389
                Text
                {
                    text: qsTr("Название лифта")
                }
            }
            TextInput
            {
                id: tcm_name_test
                width: swidth * 24.884
                height: parent.height
                anchors.right: parent.right
            }
        }
    }
    Rectangle
    {
        id: tcm_up_sequence_rect
        width: swidth * 65.625
        height: sheight * 4.629
        anchors.top: tcm_up_zone_rec.bottom
        visible: false
        enabled: false
        Rectangle
        {
            width: swidth * 15.208
            height: sheight * 2.237
            x: swidth * 19.583
            y: sheight * 29.452
            Text
            {
                text: qsTr("Последоваткльность пакетов")
            }
        }
        CheckBox
        {
            id: show_sequence_rect
            width: swidth * 1.302
            height: sheight * 2.315
            x: swidth * 79.167
            y: sheight * 32.037
            checked: false
            onCheckedChanged:
            {
                //tcm_sequence_rect.state === "closed" ? tcm_sequence_rect.state = "opened" : tcm_sequence_rect.state = "closed";
                tcm_sequence_scrollview.state === "closed" ? tcm_sequence_scrollview.state = "opened" : tcm_sequence_scrollview.state = "closed";
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
    ScrollView
    {
        id: tcm_sequence_scrollview
        width: swidth * 1.042
        height: 0
        anchors.right: tcm_buttonsr_right.left
        visible: false
        enabled: false
        states:
            [
            State
            {
                name: "opened"
                PropertyChanges
                {
                    target: tcm_sequence_scrollview; height: sheight * 67.47
                }
            },
            State {
                name: "closed"
                PropertyChanges
                {
                    target: tcm_sequence_scrollview; height: 0
                }
            }
        ]
        /*transitions: Transition
        {
            NumberAnimation
            {
                properties: "height"
                duration: 300
                easing.type: Easing.InOutQuad
            }
        }*/

        Rectangle
        {
            id: tcm_sequence_rect
            width: swidgth * 62.5
            height: parent.height
            anchors.right: parent.left
            anchors.top: tcm_up_sequence_rect.bottom
            /*states:
                [
                State
                {
                    name: "opened"
                    PropertyChanges
                    {
                        target: tcm_sequence_rect; height: sheight * 42.037
                    }
                },
                State {
                    name: "closed"
                    PropertyChanges
                    {
                        target: tcm_sequence_rect; height: 0

                    }
                }
            ]*/
            /*transitions: Transition
            {
                NumberAnimation
                {
                    properties: "height"
                    duration: 300
                    easing.type: Easing.InOutQuad
                }
            }*/
        }
    }
    //описание
    Rectangle
    {
        id: tcm_up_text_description_rect
        width: swidth * 65.625
        height: sheight * 4.629
        anchors.top: tcm_sequence_rect.bottom
        visible: false
        enabled: false
        Rectangle
        {
            width: swidth * 15.208
            height: sheight * 2.237
            //настроить отступы
            Text
            {
                text: qsTr("Последоваткльность пакетов")
            }
        }
        CheckBox
        {
            id: show_text_description_rect
            width: swidth * 1.302
            height: sheight * 2.315
            //настроить отступы
            checked: false
            onCheckedChanged:
            {
                tcm_sequence_scrollview.state === "closed" ? tcm_sequence_scrollview.state = "opened" : tcm_sequence_scrollview.state = "closed";
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
    Rectangle
    {
        id: text_description_rect
        width: swidgth * 62.5
        height: 0
        anchors.top: tcm_up_text_description_rect.bottom
        states:
            [
            State
            {
                name: "opened"
                PropertyChanges
                {
                    target: tcm_sequence_rect; height: sheight * 33.704
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
        /*transitions: Transition
        {
            NumberAnimation
            {
                properties: "height"
                duration: 300
                easing.type: Easing.InOutQuad
            }
        }*/
        TextEdit
        {
            id: text_description
            width: parent.width
            height: sheight * 24.537
            anchors.centerIn: parent.Center
        }
    }


    //Правые кнопки
    Rectangle
    {
        id:tcm_buttonsr_right
        width: swidth * 17.1875
        height: parent.height
        x: swidth * 82.8125
        Button
        {
            id: tcm_add_button
            width: swidth * 14.063
            height: sheight * 5.556
            x: swidth * 83.646
            y: sheight * 9.815
            enabled: true
            visible: true
            text: "Добавить"
        }
        Button
        {
            id: tcm_save_button
            width: swidth * 14.063
            height: sheight * 5.556
            x: swidth * 83.646
            y: sheight * 9.815
            enabled: false
            visible: false
            text: "Сохранить"
        }
        Button
        {
            id: tcm_redact_button
            width: swidth * 14.063
            height: sheight * 5.556
            x: swidth * 83.646
            y: sheight * 19.629
            text: "Редактировать"
        }
        Button
        {
            id: tcm_delete_button
            width: swidth * 14.063
            height: sheight * 5.556
            x: swidth * 83.646
            y: sheight * 29.444
            text: "Удалить"
        }
    }
}

