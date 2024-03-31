import QtQuick 2.15
import QtQuick.Window
import QtQuick.Controls
import QtQuick.Dialogs


Rectangle
{
    property int row_pos
    id: station_menu_window
    //когда настрою все кнопки, переделать, чтобы сюда шли не тсатичные параметры, а высоты и ширины из главного окна и выделенного под окна соответствующе
    width: 1920
    height: 1080
    property real swidth: width / 100
    property real sheight: height / 100
    property int number_zone_main: 1
    property int number_lines_main: 1
    color: "#D9D9D9"
    //левая панелька с названиями
    Rectangle
    {
        id: sm_left_rect
        width: swidth * 17.188
        height: parent.height
        anchors.left: parent.left
        color: "#D9D9D9"
        ScrollView
        {
            id: sm_left_menu_scrollview
            height: parent.height
            width: parent.width
            anchors.right : parent.right
            anchors.top: parent.top
            clip: true

            ListView
            {
                id: sm_left_menu_listView
                width: parent.width
                height: contentHeight

                model: ListModel
                {
                    id: sm_left_model
                }
                delegate: Rectangle
                {
                    width: sm_left_menu_listView.width
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
                            sm_left_menu_listView.currentIndex = index
                            //color_box.enabled = true
                            //delete_zone.enabled = true
                        }
                    }

                }
            }
            Rectangle
            {
                id: sm_white_rect
                width: swidth * 17.188
                height: sheight * 0.9
                color: "white"
                x: sm_left_menu_listView.height
                anchors.left: parent.left
            }
            onContentHeightChanged: {
                if (sm_left_menu_scrollview.flickableItem !== undefined) {
                    if (contentHeight > sm_left_menu_scrollview.height) {
                        sm_left_menu_scrollview.flickableItem.interactive = true;
                    } else {
                        sm_left_menu_scrollview.flickableItem.interactive = false;
                    }
                }
            }
            Button
            {
                id: sm_left_plus_but
                width: swidth * 2.604
                height: sheight * 5.37
                x: swidth * 6.51
                y: sm_left_menu_listView.contentHeight + sm_white_rect.height
                text: "+"
                font.pointSize: 48 * swidth * 0.03
                onClicked:
                {
                   sm_station_name.text = ""
                   sm_interface.text = ""
                   sm_crc_ok_checkbox.checked = false
                   byte_info.text = ""
                   start_count.text = ""
                   end_count.text = ""
                }
                //cdelat cnachala serii kvadrat potom on sapolnitsa
            }
        }
    }
    //правая панелька с кнопками
    Rectangle
    {
        id: buttons_right_menu
        width: swidth * 17.188
        height: parent.height
        anchors.right: parent.right
        color: "#D9D9D9"
        Button
        {
            id: add_color_button
            width: swidth * 14.063
            height: sheight * 5.556
            x: swidth * 0.833
            y: sheight * 2.407
            font.pointSize: 22 * swidth * 0.03
            text: "Добавить"
            visible: false
            enabled: false
            onClicked:
            {
                    addSection.open()
            }
        }
        Button
        {
            id: change_color_button
            width: swidth * 14.063
            height: sheight * 5.556
            x: swidth * 0.833
            y: sheight * 2.407
            font.pointSize: 22 * swidth * 0.03
            text: "Изменить"
            visible: false
            enabled: false
        }
        Button
        {
            id: delete_color_button
            width: swidth * 14.063
            height: sheight * 5.556
            x: swidth * 0.833
            y: sheight * 10.74
            font.pointSize: 22 * swidth * 0.03
            text: "Удалить"
            visible: false
            enabled: false
        }
    }
    //центральное окно
    ScrollView
    {
        id: station_menu_scrollview_right
        width: swidth * 64.063
        height: sheight * 87.315
        x: swidth * 17.188
        clip: true


        Rectangle
        {
            id: sm_name_station_rec
            width: swidth * 58.698
            height: sheight * 4.629
            x: swidth * 4.323
            y: sheight * 4.259
            color: "#D9D9D9"
            Rectangle
            {
                height: parent.height
                width: swidth * 14.409
                anchors.left: parent.left
                anchors.verticalCenter: parent.verticalCenter
                color: "#D9D9D9"
                Text
                {
                    font.family: "Inter"
                    font.pixelSize: 22 * 0.04 * swidth
                    text: qsTr("Наименование станции")
                }
            }
            Rectangle
            {
                height: parent.height
                width: swidth * 24.884
                anchors.right: parent.right
                TextInput
                {
                    id: sm_station_name
                    width: parent.width
                    height: parent.height
                    font.family: "Inter"
                    font.pixelSize: 22 * 0.04 * swidth
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    text: ""
                }
            }
        }
        Rectangle
        {
            id: sm_interface_rec
            width: swidth * 58.698
            height: sheight * 4.629
            x: swidth * 4.323
            y: sheight * 12.5
            color: "#D9D9D9"
            Rectangle
            {
                height: parent.height
                width: swidth * 14.409
                anchors.left: parent.left
                anchors.verticalCenter: parent.verticalCenter
                color: "#D9D9D9"
                Text
                {
                    font.family: "Inter"
                    font.pixelSize: 22 * 0.04 * swidth
                    text: qsTr("Интерфейс")
                }
            }
            Rectangle
            {
                height: parent.height
                width: swidth * 24.884
                anchors.right: parent.right
                TextInput
                {
                    id: sm_interface
                    width: parent.width
                    height: parent.height
                    font.family: "Inter"
                    font.pixelSize: 22 * 0.04 * swidth
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    text: ""
                }
            }
        }
        Rectangle
        {
            id: sm_crc_ok_zone
            width: swidth * 58.698
            height: sheight * 2.963
            x: swidth * 4.323
            y: sheight * 20.74
            color: "#D9D9D9"
            Rectangle
            {
                id: crc_ok_text
                height: parent.height
                width: swidth * 14.409
                anchors.left: parent.left
                anchors.verticalCenter: parent.verticalCenter
                color: "#D9D9D9"
                Text
                {
                    font.family: "Inter"
                    font.pixelSize: 22 * 0.04 * swidth
                    text: qsTr("Вычислять CRC")
                }
            }
            CheckBox
            {
                id: sm_crc_ok_checkbox
                width: swidth * 1.354
                height: sheight * 1.667
                anchors.right: parent.right
                checked: false
                onCheckedChanged:
                {
                    if (sm_crc_ok_checkbox.checked === true)
                    {
                        show_crc.enabled = true
                    }
                    else
                    {
                        show_crc.enabled = false
                        crc_parametrs.state = "closed"
                        show_package_templates.checked = false
                        byte_info.text = ""
                        start_count.text = ""
                        end_count.text = ""
                    }
                }
            }
        }
        //верхняя панелька настроек порта
        Rectangle
        {
            id: port_settings
            height: sheight * 4.629
            width: swidth * 64.063
            y: sheight * 23.425
            color: "#A0A0A0"
            border.width: 2
            border.color: "black"
            Rectangle
            {
                height: sheight * 2.222
                width: swidth * 8.802
                x: swidth * 2.396
                y: sheight * 1.204
                color: "#A0A0A0"
                Text
                {
                    font.family: "Inter"
                    font.pixelSize: 22 * 0.04 * swidth
                    text: qsTr("Настройки порта")
                }
            }
            CheckBox
            {
                id: show_port_parametrs
                width: swidth * 1.302
                height: sheight * 2.315
                x: swidth * 61.979
                y: sheight * 1.111
                state: "closed"
                onCheckedChanged:
                {
                    port_settings_parametrs.state === "opened" ? port_settings_parametrs.state = "closed" : port_settings_parametrs.state = "opened";
                }
            }
            Image
            {
                width: swidth * 1.302
                height: sheight * 2.315
                anchors.verticalCenter: show_port_parametrs.verticalCenter
                //куда закинуть картинки
                source: show_port_parametrs.checked ? "../Constructor/arrows_down.png" : "../Constructor/arrows_up.png"
                //visible: !show_port_parametrs.indeterminate || !show_port_parametrs.checked
            }
        }
        Rectangle
        {
            id: port_settings_parametrs
            width: swidth * 64.063
            y: sheight * 28
            color: "#D9D9D9"
            height: 0
            states:
                [
                State
                {
                    name: "opened"
                    PropertyChanges
                    {
                        target: port_settings_parametrs;
                        height: sheight * 42.037
                    }
                    PropertyChanges
                    {
                        target: bits_in_sec_rec;
                        height: sheight * 3.989;
                        y: sheight * 3.796;
                        enabled: true;
                        visible: true;
                    }
                    PropertyChanges
                    {
                        target: data_bit_rec;
                        height: sheight * 3.989;
                        y: sheight * 11.304
                        enabled: true;
                        visible: true;
                    }
                    PropertyChanges
                    {
                        target: parity_rec;
                        height: sheight * 3.989;
                        y: sheight * 18.995
                        enabled: true;
                        visible: true;
                    }
                    PropertyChanges
                    {
                        target: stop_bits_rec;
                        height: sheight * 3.989;
                        y: sheight * 26.688
                        enabled: true;
                        visible: true;
                    }
                    PropertyChanges
                    {
                        target: flow_control_rec;
                        height: sheight * 3.989;
                        y: sheight * 34.379
                        enabled: true;
                        visible: true;
                    }
                    PropertyChanges
                    {
                        target: flow_control_rec;
                        height: sheight * 3.989;
                        y: sheight * 34.379
                        enabled: true;
                        visible: true;
                    }
                    PropertyChanges
                    {
                        target: package_templates;
                        y: sheight * 70.278
                    }

                },
                State {
                    name: "closed"
                    PropertyChanges
                    {
                        target: port_settings_parametrs;
                        height: 0

                    }
                    PropertyChanges
                    {
                        target: bits_in_sec_rec;
                        height: 0;
                        y: 0;
                        enabled: false;
                        visible: false;
                    }
                    PropertyChanges
                    {
                        target: parity_rec;
                        height: 0;
                        y: 0;
                        enabled: false;
                        visible: false;
                    }
                    PropertyChanges
                    {
                        target: stop_bits_rec;
                        height: 0;
                        y: 0;
                        enabled: false;
                        visible: false;
                    }
                    PropertyChanges
                    {
                        target: flow_control_rec;
                        height: 0;
                        y: 0;
                        enabled: false;
                        visible: false;
                    }
                    PropertyChanges
                    {
                        target: package_templates;
                        y: sheight * 28
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
                NumberAnimation
                {
                    properties: "y"
                    duration: 300
                    easing.type: Easing.InOutQuad
                }
            }
            //Начинка под настройки порта
            Rectangle
            {
                id: bits_in_sec_rec
                width: swidth * 58.696
                height: 0
                x: swidth * 2.865
                y: 0
                enabled: false;
                visible: false;
                color: "#D9D9D9"
                Rectangle
                {
                    width: swidth * 10.26
                    height: sheight * 2.778
                    anchors.left: parent.left
                    anchors.verticalCenter: parent.verticalCenter
                    color: "#D9D9D9"

                    Text
                    {
                        font.family: "Inter"
                        font.pixelSize: 22 * 0.04 * swidth
                        text: qsTr("Бит в секунду")
                    }
                }
                ComboBox
                {
                    id: bits_in_sec_cb
                    width: swidth * 7.945
                    height: parent.height
                    anchors.right: parent.right
                    font.pixelSize: 22 * 0.04 * swidth

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
                width: swidth * 58.696
                height: 0
                x: swidth * 2.865
                y: 0
                enabled: false;
                visible: false;
                color: "#D9D9D9"
                Rectangle
                {
                    width: swidth * 10.26
                    height: sheight * 2.778
                    anchors.left: parent.left
                    anchors.verticalCenter: parent.verticalCenter
                    color: "#D9D9D9"
                    Text
                    {
                        font.family: "Inter"
                        font.pixelSize: 22 * 0.04 * swidth
                        text: qsTr("Бит данных")
                    }
                }
                ComboBox
                {
                    id: data_bit_cb
                    width: swidth * 7.945
                    height: parent.height
                    anchors.right: parent.right
                    font.pixelSize: 22 * 0.04 * swidth
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
                width: swidth * 58.696
                height: 0
                x: swidth * 2.865
                y: 0
                color: "#D9D9D9"
                enabled: false;
                visible: false;
                Rectangle
                {
                    width: swidth * 10.26
                    height: sheight * 2.778
                    anchors.left: parent.left
                    anchors.verticalCenter: parent.verticalCenter
                    color: "#D9D9D9"
                    Text
                    {
                        font.family: "Inter"
                        font.pixelSize: 22 * 0.04 * swidth
                        text: qsTr("Четность")
                    }
                }
                ComboBox
                {
                    id: parity_cb
                    width: swidth * 7.945
                    height: parent.height
                    anchors.right: parent.right
                    font.pixelSize: 22 * 0.04 * swidth
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
                width: swidth * 58.696
                height: 0
                x: swidth * 2.865
                y: 0
                enabled: false;
                visible: false;
                color: "#D9D9D9"
                Rectangle
                {
                    width: swidth * 10.26
                    height: sheight * 2.778
                    anchors.left: parent.left
                    anchors.verticalCenter: parent.verticalCenter
                    color: "#D9D9D9"
                    Text
                    {
                        font.family: "Inter"
                        font.pixelSize: 22 * 0.04 * swidth
                        text: qsTr("Стоповые биты")
                    }
                }
                ComboBox
                {
                    id: stop_bits_cb
                    width: swidth * 7.945
                    height: parent.height
                    anchors.right: parent.right
                    font.pixelSize: 22 * 0.04 * swidth
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
                width: swidth * 58.696
                height: 0
                x: swidth * 2.865
                y: 0
                color: "#D9D9D9"
                enabled: false;
                visible: false;
                Rectangle
                {
                    width: swidth * 10.26
                    height: sheight * 2.778
                    anchors.left: parent.left
                    anchors.verticalCenter: parent.verticalCenter
                    color: "#D9D9D9"
                    Text
                    {
                        font.family: "Inter"
                        font.pixelSize: 22 * 0.04 * swidth
                        text: qsTr("Управление потоком")
                    }
                }
                ComboBox
                {
                    id: flow_control_cb
                    width: swidth * 7.945
                    height: parent.height
                    anchors.right: parent.right
                    font.pixelSize: 22 * 0.04 * swidth
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
        //заголовок окнапакетов, здесь надо продумать как сделать таблицу пакета
        Rectangle
        {
            id: package_templates
            height: sheight * 4.629
            width: swidth * 64.063
            y: sheight * 28
            color: "#A0A0A0"
            border.width: 2
            border.color: "black"
            Rectangle
            {
                height: sheight * 2.222
                width: swidth * 8.802
                color: "#A0A0A0"
                x: swidth * 2.396
                y:sheight * 1.204
                Text
                {
                    font.family: "Inter"
                    font.pixelSize: 22 * 0.04 * swidth
                    text: qsTr("Шаблоны пакетов")
                }
            }
            CheckBox
            {
                id: show_package_templates
                width: swidth * 1.302
                height: sheight * 2.315
                x: swidth * 61.979
                y: sheight * 1.111
                onCheckedChanged:
                {
                    package_templates_parametrs.state === "opened" ? package_templates_parametrs.state = "closed" : package_templates_parametrs.state = "opened";
                }
            }
            Image
            {
                width: swidth * 1.302
                height: sheight * 2.315
                anchors.verticalCenter: show_package_templates.verticalCenter
                source: show_package_templates.checked ? "../../arrows_down.png" : "../../arrows_up.png"
                //visible: !show_package_templates.indeterminate || !show_package_templates.checked
            }
            Rectangle
            {
                id: package_templates_parametrs
                width: parent.width
                height: 0
                anchors.top: parent.bottom
                color: "#D9D9D9"
                states:
                    [
                    State
                    {
                        name: "opened"
                        PropertyChanges
                        {
                            target: package_templates_parametrs
                            height: sheight * 50
                        }
                        PropertyChanges
                        {
                            target: sm_zones_lv
                            height: contentHeight
                            visible: true
                        }
                        PropertyChanges
                        {
                            target: add_zone_but
                            height: sheight * 5.37
                            y: sm_zones_lv.y + sm_zones_lv.height
                            visible: true
                            enabled: true
                        }
                        PropertyChanges
                        {
                            target: crc_templates
                            y: package_templates_parametrs.y
                        }
                    },
                    State
                    {
                        name: "closed"
                        PropertyChanges
                        {
                            target: package_templates_parametrs
                            height: 0
                        }
                        PropertyChanges
                        {
                            target: sm_zones_lv
                            height: 0
                            visible: false
                        }
                        PropertyChanges
                        {
                            target: add_zone_but
                            height: 0
                            y: 0
                            visible: false
                            enabled: false
                        }
                        PropertyChanges
                        {
                            target: crc_templates
                            y: package_templates_parametrs.y
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
                    NumberAnimation
                    {
                        properties: "y"
                        duration: 300
                        easing.type: Easing.InOutQuad
                    }

                }
                ListView {
                    id: sm_zones_lv
                    width: parent.width
                    height: 0
                    model: ListModel {
                        //ListElement { number_zone: 1; number_lines: 1 }
                    }
                    delegate: SM_one_zone_rec
                    {
                        width: parent.width
                        //height: package_templates_parametrs.height
                        //visible: false
                        number_zone: model.number_zone
                        number_lines: model.number_lines
                        sendDataToSMfOZR: function(box_row, box_color)
                        {
                            console.log(" Цвет:",box_color, "строка ", box_row)
                            row_pos = box_row
                            if(box_row > 0)
                            {
                                if(box_color == "#ffffff")
                                {
                                    add_color_button.visible = true;
                                    add_color_button.enabled = true;
                                    delete_color_button.visible = false;
                                    delete_color_button.enabled = false;
                                    change_color_button.enabled = false;
                                    change_color_button.visible = false;
                                }
                                else
                                {
                                    add_color_button.visible =false;
                                    add_color_button.enabled = false;
                                    delete_color_button.visible = true;
                                    delete_color_button.enabled = true;
                                    change_color_button.enabled = true;
                                    change_color_button.visible = true;
                                }
                            }
                            else if(box_row == 0)
                            {
                                add_color_button.visible = false;
                                add_color_button.enabled = false;
                                delete_color_button.visible = false;
                                delete_color_button.enabled = false;
                                change_color_button.enabled = false;
                                change_color_button.visible = false;
                            }
                        }
                    }
                }

                Button {
                    id: add_zone_but
                    width: swidth * 2.604
                    height: 0
                    //visible: false
                    //enabled: false
                    y: 0
                    x: swidth * 45.859
                    text: "+"
                    font.pointSize: 48 * swidth * 0.03
                    onClicked: {
                        addNewZone.open()
                    }
                }
            }

            //СРС
            Rectangle
            {
                id: crc_templates
                height: sheight * 4.629
                width: swidth * 64.063
                anchors.top: package_templates_parametrs.bottom
                color: "#A0A0A0"
                border.width: 2
                border.color: "black"
                Rectangle
                {
                    height: sheight * 2.222
                    width: swidth * 8.802
                    color: "#A0A0A0"
                    x: swidth * 2.396
                    y: sheight * 1.204
                    Text
                    {
                        font.family: "Inter"
                        font.pixelSize: 22 * 0.04 * swidth
                        text: qsTr("CRC")
                    }
                }
                CheckBox
                {
                    id: show_crc
                    width: swidth * 1.302
                    height: sheight * 2.315
                    x: swidth * 61.979
                    y: sheight * 1.111
                    enabled: false
                    checked: false
                    onCheckedChanged:
                    {
                        crc_parametrs.state === "opened" ? crc_parametrs.state = "closed" : crc_parametrs.state = "opened";
                    }
                }
                Image
                {
                    width: swidth * 1.302
                    height: sheight * 2.315
                    anchors.verticalCenter: show_crc.verticalCenter
                    source: show_crc.checked ? "../../arrows_down.png" : "../../arrows_up.png"
                    //visible: !show_crc.indeterminate || !show_crc.checked
                }
                Rectangle
                {
                    id: crc_parametrs
                    width: swidth * 64.063
                    anchors.top: parent.bottom
                    height: 0
                    color: "#D9D9D9"
                    states:
                        [
                        State
                        {
                            name: "opened"
                            PropertyChanges
                            {
                                target: crc_parametrs;
                                height: sheight * 85.533
                            }
                            PropertyChanges
                            {
                                target: byte_info_rec;
                                y: sheight * 3.796
                                height: sheight * 5.556
                                enabled: true
                                visible: true
                            }
                            PropertyChanges
                            {
                                target: start_count_rec;
                                y: sheight * 11.667
                                height: sheight * 5.556
                                enabled: true
                                visible: true
                            }
                            PropertyChanges
                            {
                                target: end_count_rec;
                                y: sheight * 19.537
                                height: sheight * 5.556
                                enabled: true
                                visible: true
                            }
                            PropertyChanges
                            {
                                target: code_rec;
                                y: sheight * 28.056
                                height: sheight * 2.5
                                enabled: true
                                visible: true
                            }
                            PropertyChanges
                            {
                                target: code_example_rec;
                                y: sheight * 32.407
                                height: sheight * 53.981
                                enabled: true
                                visible: true
                            }
                        },
                        State {
                            name: "closed"
                            PropertyChanges
                            {
                                target: crc_parametrs;
                                height: 0
                            }
                            PropertyChanges
                            {
                                target: byte_info_rec;
                                y: 0
                                height: 0
                                enabled: false
                                visible: false
                            }
                            PropertyChanges
                            {
                                target: start_count_rec;
                                y: 0
                                height: 0
                                enabled: false
                                visible: false
                            }
                            PropertyChanges
                            {
                                target: end_count_rec;
                                y: 0
                                height: 0
                                enabled: false
                                visible: false
                            }
                            PropertyChanges
                            {
                                target: code_rec;
                                y: 0
                                height: 0
                                enabled: false
                                visible: false
                            }
                            PropertyChanges
                            {
                                target: code_example_rec;
                                y: 0
                                height: 0
                                enabled: false
                                visible: false
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
                        NumberAnimation
                        {
                            properties: "y"
                            duration: 300
                            easing.type: Easing.InOutQuad
                        }

                    }
                    Rectangle
                    {
                        id: byte_info_rec
                        width: swidth * 59.01
                        height: 0
                        x: swidth * 2.604
                        y: 0
                        enabled: false
                        visible: false
                        color: "#D9D9D9"
                        Rectangle
                        {
                            width: swidth * 14.409
                            height: 5
                            anchors.left: parent.left
                            anchors.verticalCenter: parent.verticalCenter
                            color: "#D9D9D9"
                            Text
                            {
                                font.family: "Inter"
                                font.pixelSize: 22 * 0.04 * swidth
                                text: qsTr("В какой байт поместить контрольную сумму")
                            }
                        }
                        Rectangle
                        {
                            height: parent.height
                            width: swidth * 3.125
                            anchors.right: parent.right
                            TextInput
                            {

                                id: byte_info
                                height: parent.height
                                width: parent.width
                                anchors.right: parent.right
                                font.family: "Inter"
                                font.pixelSize: 22 * 0.04 * swidth
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                                text: ""
                            }
                        }

                    }
                    Rectangle
                    {
                        id: start_count_rec
                        width: swidth * 59.01
                        height: 0
                        x: swidth * 2.604
                        y: 0
                        enabled: false
                        visible: false
                        color: "#D9D9D9"
                        Rectangle
                        {
                            width: swidth * 14.409
                            height: 5
                            anchors.left: parent.left
                            anchors.verticalCenter: parent.verticalCenter
                            color: "#D9D9D9"
                            Text
                            {
                                font.family: "Inter"
                                font.pixelSize: 22 * 0.04 * swidth
                                text: qsTr("Начало вычисления контрольной суммы")
                            }
                        }
                        Rectangle
                        {
                            height: parent.height
                            width: swidth * 3.125
                            anchors.right: parent.right
                            TextInput
                            {
                                id: start_count
                                height: parent.height
                                width: parent.width
                                anchors.right: parent.right
                                font.family: "Inter"
                                font.pixelSize: 22 * 0.04 * swidth
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                                text: ""
                            }
                        }
                    }
                    Rectangle
                    {
                        id: end_count_rec
                        width: swidth * 59.01
                        height: 0
                        x: swidth * 2.604
                        y: 0
                        enabled: false
                        visible: false
                        color: "#D9D9D9"
                        Rectangle
                        {
                            width: swidth * 14.409
                            height: 5
                            anchors.left: parent.left
                            anchors.verticalCenter: parent.verticalCenter
                            color: "#D9D9D9"
                            Text
                            {
                                font.family: "Inter"
                                font.pixelSize: 22 * 0.04 * swidth
                                text: qsTr("Конец вычисления контрольной суммы")
                            }
                        }
                        Rectangle
                        {
                            height: parent.height
                            width: swidth * 3.125
                            anchors.right: parent.right
                            TextInput
                            {
                                id: end_count
                                height: parent.height
                                width: parent.width
                                anchors.right: parent.right
                                font.family: "Inter"
                                font.pixelSize: 22 * 0.04 * swidth
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                                text: ""
                            }
                        }
                    }
                    Rectangle
                    {
                        id: code_rec
                        width: swidth * 14.409
                        height: 0
                        x: swidth * 2.604
                        y: 0
                        color: "#D9D9D9"
                        enabled: false
                        visible: false
                        Text
                        {
                            font.family: "Inter"
                            font.pixelSize: 22 * 0.04 * swidth
                            text: qsTr("Код")
                        }
                    }

                    Rectangle
                    {
                        id: code_example_rec
                        width: swidth * 59.01
                        height: 0
                        x: swidth * 2.604
                        y: 0
                        enabled: false
                        visible: false
                        TextEdit
                        {

                            id: code_example
                            width: parent.width
                            height: parent.height
                            anchors.right: parent.right
                            font.family: "Inter"
                            font.pixelSize: 22 * 0.04 * swidth
                        }
                    }
                }
            }

        }
    }
    Rectangle
    {
        id: buttons_bottom_menu
        width: swidth * 64.063
        height: sheight * 12.315
        y: sheight * 84.259
        x: swidth * 17.188
        color: "#D9D9D9"
        Button
        {
            id: save_station_button
            width: swidth * 14.063
            height: sheight * 5.556
            x: swidth * 0.989
            y: sheight * 3.981
            font.family: "Inter"
            font.pixelSize: 22 * 0.04 * swidth
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
            height: sheight * 5.556
            x: swidth * 49.375
            y: sheight * 3.981
            font.family: "Inter"
            font.pixelSize: 22 * 0.04 * swidth
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
    Popup
    {
        id: addSection
        width: 700
        height: 500
        x: swidth * 27.77
        y: sheight * 14.851
        modal: true
        focus: true
        closePolicy: Popup.CloseOnEscape
        Rectangle
        {
            width: parent.width
            height: parent.height
            anchors.fill: parent
            SM_AddSection
            {
                width: parent.width
                height: parent.height
                onAddClose: {
                    addSection.close()
                }
                sendDataToSM: function(start_section, length_section)
                {
                    console.log("Начальний бит: ", start_section,  " Длина: ", length_section)
                    SM_one_zone_rec.sendDataToOZR(row_pos, start_section, length_section, "red")
                }
            }
        }
    }
    Popup
    {
        id: addNewZone
        width: 700
        height: 500
        x: swidth * 27.77
        y: sheight * 14.851
        modal: true
        focus: true
        closePolicy: Popup.CloseOnEscape
        Rectangle
        {
            width: parent.width
            height: parent.height
            anchors.fill: parent
            SM_Package_View
            {
                width: parent.width
                height: parent.height
            }
        }
    }
}



