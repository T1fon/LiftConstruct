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
        id: port_settings
        height: sheight * 4.584
        width: swidth * 64.063
        x: swidth * 17.188
        y: sheight * 23.194
        Rectangle
        {
            height: sheight * 2.2
            width: swidth * 8.802
            x: swidth * 19.583
            y: sheight * 24.386
            Text
            {
                text: qsTr("Настройки порта")
            }
        }
        CheckBox
        {
            id: show_port_parametrs
            width: swidth * 1.302
            height: sheight * 2.292
            x: swidth * 79.167
            y: sheight * 24.294
            checked: false
            onCheckedChanged:
            {
                port_settings_parametrs.state === "closed" ? port_settings_parametrs.state = "opened" : port_settings_parametrs.state = "closed";
            }
        }
        Image
        {
            width: swidth * 1.302
            height: sheight * 2.292
            anchors.verticalCenter: show_port_parametrs.verticalCenter
            source: show_port_parametrs.checked ? "../../arrows_down.png" : "../../arrows_up.png"
            //visible: !show_port_parametrs.indeterminate || !show_port_parametrs.checked
        }
        Rectangle
        {
            id: port_settings_parametrs
            width: swidgth * 17.188
            height: 0
            states:
                [
                State
                {
                    name: "opened"
                    PropertyChanges
                    {
                        target: port_settings_parametrs; height: sheight * 41.621
                    }
                },
                State {
                    name: "closed"
                    PropertyChanges
                    {
                        target: port_settings_parametrs; height: 0

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
                id: bits_in_sec_rec
                width: pwidth * 91.623
                height: pheight * 9.489
                x: pwidth * 4.472
                y: pheight * 8.59
                Rectangle
                {
                    width: pwidth * 16.016
                    height: pheight * 6.608
                    anchors.left: parent.left
                    Text
                    {
                        text: qsTr("Бит в секунду")
                    }
                }
                ComboBox
                {
                    id: bits_in_sec_cb
                    width: pwidth * 12.402
                    height: parent.height
                    anchors.right: parent.right
                    model: ListModel
                    {
                        id: bits_in_sec
                        ListElement
                        {
                            text: "9600"
                        }
                    }
                }
            }
            Rectangle
            {
                id: data_bit_rec
                width: pwidth * 91.623
                height: pheight * 9.489
                x: pwidth * 4.472
                y: pheight * 26.889
                Rectangle
                {
                    width: pwidth * 16.016
                    height: pheight * 6.608
                    anchors.left: parent.left
                    Text
                    {
                        text: qsTr("Бит данных")
                    }
                }
                ComboBox
                {
                    id: data_bit_cb
                    width: pwidth * 12.402
                    height: parent.height
                    anchors.right: parent.right
                    model: ListModel
                    {
                        id: data_bit
                        ListElement
                        {
                            text: "8"
                        }
                    }
                }
            }
            Rectangle
            {
                id: parity_rec
                width: pwidth * 91.623
                height: pheight * 9.489
                x: pwidth * 4.472
                y: pheight * 26.889
                Rectangle
                {
                    width: pwidth * 16.016
                    height: pheight * 6.608
                    anchors.left: parent.left
                    Text
                    {
                        text: qsTr("Четность")
                    }
                }
                ComboBox
                {
                    id: parity_cb
                    width: pwidth * 12.402
                    height: parent.height
                    anchors.right: parent.right
                    model: ListModel
                    {
                        id: parity
                        ListElement
                        {
                            text: "Нет"
                        }
                        ListElement
                        {
                            text: "Да"
                        }
                    }
                }
            }
            Rectangle
            {
                id: stop_bits_rec
                width: pwidth * 91.623
                height: pheight * 9.489
                x: pwidth * 4.472
                y: pheight * 63.487
                Rectangle
                {
                    width: pwidth * 16.016
                    height: pheight * 6.608
                    anchors.left: parent.left
                    Text
                    {
                        text: qsTr("Стоповые биты")
                    }
                }
                ComboBox
                {
                    id: stop_bits_cb
                    width: pwidth * 12.402
                    height: parent.height
                    anchors.right: parent.right
                    model: ListModel
                    {
                        id: stop_bits
                        ListElement
                        {
                            text: "1"
                        }
                    }
                }
            }
            Rectangle
            {
                id: flow_control_rec
                width: pwidth * 91.623
                height: pheight * 9.489
                x: pwidth * 4.472
                y: pheight * 81.786
                Rectangle
                {
                    width: pwidth * 16.016
                    height: pheight * 6.608
                    anchors.left: parent.left
                    Text
                    {
                        text: qsTr("Управление потоком")
                    }
                }
                ComboBox
                {
                    id: flow_control_cb
                    width: pwidth * 12.402
                    height: parent.height
                    anchors.right: parent.right
                    model: ListModel
                    {
                        id: flow_control
                        ListElement
                        {
                            text: "Нет"
                        }
                        ListElement
                        {
                            text: "Да"
                        }
                    }
                }
            }
        }
    }
    Rectangle
    {
        id: package_templates
        height: sheight * 4.584
        width: swidth * 64.063
        anchors.top: port_settings_parametrs.bottom
        Rectangle
        {
            height: sheight * 2.2
            width: swidth * 8.802
            anchors.verticalCenter: parent.left
            Text
            {
                text: qsTr("Настройки порта")
            }
        }
        CheckBox
        {
            id: show_package_templates
            width: swidth * 1.302
            height: sheight * 2.292
            anchors.verticalCenter: parent.right
            checked: false
            onCheckedChanged:
            {
                package_templates_parametrs.state === "closed" ? package_templates_parametrs.state = "opened" : package_templates_parametrs.state = "closed";
            }
        }
        Image
        {
            width: swidth * 1.302
            height: sheight * 2.292
            anchors.verticalCenter: show_package_templates.verticalCenter
            source: show_package_templates.checked ? "../../arrows_down.png" : "../../arrows_up.png"
            //visible: !show_package_templates.indeterminate || !show_package_templates.checked
        }
        Rectangle
        {
            id: package_templates_parametrs
            width: swidgth * 17.188
            height: 0
            states:
                [
                State
                {
                    name: "opened"
                    PropertyChanges
                    {
                        target: package_templates_parametrs; height: sheight * 64.356
                    }
                },
                State {
                    name: "closed"
                    PropertyChanges
                    {
                        target: package_templates_parametrs; height: 0
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
        }
    }
    Rectangle
    {
        id: crc_templates
        height: sheight * 4.584
        width: swidth * 64.063
        anchors.top: package_templates_parametrs.bottom
        Rectangle
        {
            height: sheight * 2.2
            width: swidth * 8.802
            anchors.verticalCenter: parent.left
            Text
            {
                text: qsTr("Настройки порта")
            }
        }
        CheckBox
        {
            id: show_crc
            width: swidth * 1.302
            height: sheight * 2.292
            anchors.verticalCenter: parent.right
            checked: false
            onCheckedChanged:
            {
                crc_parametrs.state === "closed" ? crc_parametrs.state = "opened" : crc_parametrs.state = "closed";
            }
        }
        Image
        {
            width: swidth * 1.302
            height: sheight * 2.292
            anchors.verticalCenter: show_crc.verticalCenter
            source: show_crc.checked ? "../../arrows_down.png" : "../../arrows_up.png"
            //visible: !show_crc.indeterminate || !show_crc.checked
        }
        Rectangle
        {
            id: crc_parametrs
            width: swidgth * 17.188
            height: 0
            states:
                [
                State
                {
                    name: "opened"
                    PropertyChanges
                    {
                        target: package_templates_parametrs; height: sheight * 85.533
                    }
                },
                State {
                    name: "closed"
                    PropertyChanges
                    {
                        target: package_templates_parametrs; height: 0

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
                id: byte_info_rec
                width: swidth * 59.01
                height: sheight * 5.501
                Rectangle
                {
                    width: swidth * 14.409
                    height: 4.95
                    anchors.verticalCenter: parent.left
                    Text
                    {
                        text: qsTr("В какой байт поместить
                                    контрольную сумму")
                    }
                }
                TextInput
                {
                    id: byte_info
                    height: parent.height
                    width: swidth * 3.125
                    anchors.right: parent.right
                }
            }
            Rectangle
            {
                id: start_count_rec
                width: swidth * 59.01
                height: sheight * 5.501
                anchors.horizontalCenter: byte_info_rec.bottom
                Rectangle
                {
                    width: swidth * 14.409
                    height: 4.95
                    anchors.verticalCenter: parent.left
                    Text
                    {
                        text: qsTr("Начало вычисления
                                    контрольной суммы")
                    }
                }
                TextInput
                {
                    id: start_count
                    height: parent.height
                    width: swidth * 3.125
                    anchors.right: parent.right
                }
            }
            Rectangle
            {
                id: end_count_rec
                width: swidth * 59.01
                height: sheight * 5.501
                anchors.horizontalCenter: start_count_rec.bottom
                Rectangle
                {
                    width: swidth * 14.409
                    height: 4.95
                    anchors.verticalCenter: parent.left
                    Text
                    {
                        text: qsTr("Конец вычисления
                                    контрольной суммы")
                    }
                }
                TextInput
                {
                    id: end_count
                    height: parent.height
                    width: swidth * 3.125
                    anchors.right: parent.right
                }
            }
            Rectangle
            {
                id: code_rec
                width: swidth * 14.409
                height: sheight * 2.475
                anchors.top:  end_count_rec.bottom
                Text
                {
                    text: qsTr("Код")
                }
            }

            TextEdit
            {
                id: cod_example
                width: swidth * 59.01
                height: sheight * 53.447
                anchors.top: code_rec.bottom
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
