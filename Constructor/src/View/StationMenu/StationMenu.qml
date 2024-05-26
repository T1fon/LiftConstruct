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
    property string name_zone_main: ""
    color: "#D9D9D9"
    //левая панелька с названиями
    Rectangle
    {
        id: sm_left_rect
        width: station_menu_window.swidth * 17.188
        height: parent.height
        anchors.left: parent.left
        color: "#D9D9D9"
        Flickable
        {
            id: left_menu_scrollview
            height: parent.height - station_menu_window.sheight*15
            width: parent.width
            anchors.right : parent.right
            anchors.top: parent.top
            clip: true
            ScrollBar.vertical: ScrollBar {
                id: left_menu_scrollview_scrollbar
                policy: ScrollBar.AlwaysOn
                active: true
            }
            ListView
            {
                id: left_menu_listView
                width: parent.width
                height: contentHeight

                model: ListModel
                {
                    id: left_model
                }
                delegate: Rectangle
                {
                    width: left_menu_listView.width
                    height: station_menu_window.sheight * 5.556
                    color: model.color
                    border.color: "black"
                    border.width: (left_menu_listView.currentIndex === index) ? 2 : 0

                    /*port settings*/
                    property string interface_type: ""
                    property int port_index_baund_rate: 0
                    property int port_index_data_bits: 0
                    property int port_index_flow_control: 0
                    property int port_index_parity: 0
                    property int port_index_stop_bits: 0

                    Text
                    {
                        text: model.text
                        anchors.centerIn: parent
                        font.family: "Inter"
                        font.pointSize: 20 * station_menu_window.swidth * 0.035
                    }
                    MouseArea
                    {
                        anchors.fill: parent
                        onClicked:
                        {
                            station_menu_window.setVisibleActiveZone(true);
                            sm_station_name.text = model.text;
                            left_menu_listView.currentIndex = index;
                            sm_interface.text = model.interface_type;
                            bits_in_sec_cb.currentIndex = model.port_index_baund_rate;
                            data_bit_cb.currentIndex = model.port_index_data_bits;
                            parity_cb.currentIndex = model.port_index_parity;
                            stop_bits_cb.currentIndex = model.port_index_stop_bits;
                            flow_control_cb.currentIndex = model.port_index_flow_control;

                        }
                    }

                }
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

        }
        Rectangle
        {
            id: white_rect
            width: left_menu_scrollview.width - left_menu_scrollview_scrollbar.width
            height: station_menu_window.sheight * 0.9
            color: "#EFEFEF"
            x: left_menu_listView.height
            anchors.left: parent.left
        }
        Button
        {
            id: left_plus_but
            width: station_menu_window.swidth * 2.604
            height: station_menu_window.sheight * 5.37
            x: station_menu_window.swidth * 6.51
            y: left_menu_listView.contentHeight + white_rect.height
            text: "+"
            font.pointSize: 48 * station_menu_window.swidth * 0.03
            onClicked:
            {
               station_menu_window.setVisibleActiveZone(true);
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
    //правая панелька с кнопками
    Rectangle
    {
        id: buttons_right_menu
        width: station_menu_window.swidth * 17.188
        height: parent.height
        anchors.right: parent.right
        color: "#D9D9D9"

        Button
        {
            id: add_color_button
            width: station_menu_window.swidth * 14.063
            height: station_menu_window.sheight * 5.556
            x: station_menu_window.swidth * 0.833
            y: station_menu_window.sheight * 2.407
            font.pointSize: 22 * station_menu_window.swidth * 0.03
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
            width: station_menu_window.swidth * 14.063
            height: station_menu_window.sheight * 5.556
            x: station_menu_window.swidth * 0.833
            y: station_menu_window.sheight * 2.407
            font.pointSize: 22 * station_menu_window.swidth * 0.03
            text: "Изменить"
            visible: false
            enabled: false
        }
        Button
        {
            id: delete_color_button
            width: station_menu_window.swidth * 14.063
            height: station_menu_window.sheight * 5.556
            x: station_menu_window.swidth * 0.833
            y: station_menu_window.sheight * 10.74
            font.pointSize: 22 * station_menu_window.swidth * 0.03
            text: "Удалить"
            visible: false
            enabled: false
        }
    }
    //центральное окно
    function setVisibleActiveZone(visible_value){
        station_menu_scrollview_right.visible = visible_value;
        buttons_bottom_menu.visible = visible_value;

    }

    Flickable
    {
        id: station_menu_scrollview_right
        width: station_menu_window.swidth * 64.063
        height: station_menu_window.sheight * 85.315
        x: station_menu_window.swidth * 17.188
        clip: true
        visible: false
        ScrollBar.vertical: ScrollBar {
            id: station_menu_scrollview_scrollbar
            policy: ScrollBar.AlwaysOn
            active: true
        }
        function addZoneInModel(name, value_color)
        {
            left_model.append({ text: name,
                                color: value_color,
                                interface_type: sm_interface.text,
                                port_index_baund_rate: bits_in_sec_cb.currentIndex,
                                port_index_data_bits: data_bit_cb.currentIndex,
                                port_index_parity: parity_cb.currentIndex,
                                port_index_stop_bits: stop_bits_cb.currentIndex,
                                port_index_flow_control: flow_control_cb.currentIndex
                              });
            left_menu_listView.height += 5.556*station_menu_window.sheight;
            left_menu_scrollview.contentHeight = left_menu_listView.height;

            if(left_menu_scrollview.contentHeight < left_menu_scrollview.height){
                white_rect.y = left_menu_listView.height;
                left_plus_but.y = white_rect.y + white_rect.height;
            }else{
                white_rect.y = left_menu_scrollview.y + left_menu_scrollview.height;
                left_plus_but.anchors.top = white_rect.bottom;
            }
        }

        Rectangle
        {
            id: sm_name_station_rec
            width: station_menu_window.swidth * 58.698
            height: station_menu_window.sheight * 4.629
            x: station_menu_window.swidth * 4.323
            y: station_menu_window.sheight * 4.259
            color: "#D9D9D9"
            Rectangle
            {
                height: parent.height
                width: station_menu_window.swidth * 14.409
                anchors.left: parent.left
                anchors.verticalCenter: parent.verticalCenter
                color: "#D9D9D9"
                Text
                {
                    font.family: "Inter"
                    font.pixelSize: 22 * 0.04 * station_menu_window.swidth
                    text: qsTr("Наименование станции")
                }
            }
            Rectangle
            {
                height: parent.height
                width: station_menu_window.swidth * 24.884
                anchors.right: parent.right
                TextInput
                {
                    id: sm_station_name
                    width: parent.width
                    height: parent.height
                    font.family: "Inter"
                    font.pixelSize: 22 * 0.04 * station_menu_window.swidth
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    text: ""
                }
            }
        }
        Rectangle
        {
            id: sm_interface_rec
            width: station_menu_window.swidth * 58.698
            height: station_menu_window.sheight * 4.629
            x: station_menu_window.swidth * 4.323
            y: station_menu_window.sheight * 12.5
            color: "#D9D9D9"
            Rectangle
            {
                height: parent.height
                width: station_menu_window.swidth * 14.409
                anchors.left: parent.left
                anchors.verticalCenter: parent.verticalCenter
                color: "#D9D9D9"
                Text
                {
                    font.family: "Inter"
                    font.pixelSize: 22 * 0.04 * station_menu_window.swidth
                    text: qsTr("Интерфейс")
                }
            }
            Rectangle
            {
                height: parent.height
                width: station_menu_window.swidth * 24.884
                anchors.right: parent.right
                TextInput
                {
                    id: sm_interface
                    width: parent.width
                    height: parent.height
                    font.family: "Inter"
                    font.pixelSize: 22 * 0.04 * station_menu_window.swidth
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    text: ""
                }
            }
        }
        Rectangle
        {
            id: sm_crc_ok_zone
            width: station_menu_window.swidth * 58.698
            height: station_menu_window.sheight * 2.963
            x: station_menu_window.swidth * 4.323
            y: station_menu_window.sheight * 20.74
            color: "#D9D9D9"
            Rectangle
            {
                id: crc_ok_text
                height: parent.height
                width: station_menu_window.swidth * 14.409
                anchors.left: parent.left
                anchors.verticalCenter: parent.verticalCenter
                color: "#D9D9D9"
                Text
                {
                    font.family: "Inter"
                    font.pixelSize: 22 * 0.04 * station_menu_window.swidth
                    text: qsTr("Вычислять CRC")
                }
            }
            CheckBox
            {
                id: sm_crc_ok_checkbox
                width: station_menu_window.swidth * 1.354
                height: station_menu_window.sheight * 1.667
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
            height: station_menu_window.sheight * 4.629
            width: station_menu_window.swidth * 64.063
            y: station_menu_window.sheight * 25.425
            color: "#A0A0A0"
            border.width: 2
            border.color: "black"
            Rectangle
            {
                height: station_menu_window.sheight * 2.222
                width: station_menu_window.swidth * 8.802
                x: station_menu_window.swidth * 2.396
                y: station_menu_window.sheight * 1.204
                color: "#A0A0A0"
                Text
                {
                    font.family: "Inter"
                    font.pixelSize: 22 * 0.04 * station_menu_window.swidth
                    text: qsTr("Настройки порта")
                }
            }
            CheckBox
            {
                id: show_port_parametrs
                width: station_menu_window.swidth * 1.302
                height: station_menu_window.sheight * 2.315
                x: station_menu_window.swidth * 61.979
                y: station_menu_window.sheight * 1.111
                state: "closed"
                onCheckedChanged:
                {
                    port_settings_parametrs.state === "opened" ? port_settings_parametrs.state = "closed" : port_settings_parametrs.state = "opened";
                }


            }
            Image
            {
                width: station_menu_window.swidth * 1.302
                height: station_menu_window.sheight * 2.315
                //anchors.verticalCenter: show_port_parametrs.verticalCenter
                //куда закинуть картинки
                source: show_port_parametrs.checked ? "qrc:/arrows_down.png" : "qrc:/arrows_up.png"
                //visible: !show_port_parametrs.indeterminate || !show_port_parametrs.checked
            }
        }
        Rectangle
        {
            id: port_settings_parametrs
            width: station_menu_window.swidth * 64.063
            y: station_menu_window.sheight * 30
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
                        height: station_menu_window.sheight * 42.037
                    }
                    PropertyChanges
                    {
                        target: bits_in_sec_rec;
                        height: station_menu_window.sheight * 3.989;
                        y: station_menu_window.sheight * 3.796;
                        enabled: true;
                        visible: true;
                    }
                    PropertyChanges
                    {
                        target: data_bit_rec;
                        height: station_menu_window.sheight * 3.989;
                        y: station_menu_window.sheight * 11.304
                        enabled: true;
                        visible: true;
                    }
                    PropertyChanges
                    {
                        target: parity_rec;
                        height: station_menu_window.sheight * 3.989;
                        y: station_menu_window.sheight * 18.995
                        enabled: true;
                        visible: true;
                    }
                    PropertyChanges
                    {
                        target: stop_bits_rec;
                        height: station_menu_window.sheight * 3.989;
                        y: station_menu_window.sheight * 26.688
                        enabled: true;
                        visible: true;
                    }
                    PropertyChanges
                    {
                        target: flow_control_rec;
                        height: station_menu_window.sheight * 3.989;
                        y: station_menu_window.sheight * 34.379
                        enabled: true;
                        visible: true;
                    }
                    PropertyChanges
                    {
                        target: flow_control_rec;
                        height: station_menu_window.sheight * 3.989;
                        y: station_menu_window.sheight * 34.379
                        enabled: true;
                        visible: true;
                    }
                    PropertyChanges
                    {
                        target: package_templates;
                        y: station_menu_window.sheight * 70.278
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
                        y: station_menu_window.sheight * 30
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
                width: station_menu_window.swidth * 58.696
                height: 0
                x: station_menu_window.swidth * 2.865
                y: 0
                enabled: false;
                visible: false;
                color: "#D9D9D9"
                Rectangle
                {
                    width: station_menu_window.swidth * 10.26
                    height: station_menu_window.sheight * 2.778
                    anchors.left: parent.left
                    anchors.verticalCenter: parent.verticalCenter
                    color: "#D9D9D9"

                    Text
                    {
                        font.family: "Inter"
                        font.pixelSize: 22 * 0.04 * station_menu_window.swidth
                        text: qsTr("Бит в секунду")
                    }
                }
                ComboBox
                {
                    id: bits_in_sec_cb
                    width: station_menu_window.swidth * 7.945
                    height: parent.height
                    anchors.right: parent.right
                    font.pixelSize: 22 * 0.04 * station_menu_window.swidth
                    editable: true
                    model: ListModel
                    {
                        id: bits_in_sec
                        ListElement{text: "1200"}
                        ListElement{text: "2400"}
                        ListElement{text: "4800"}
                        ListElement{text: "9600"}
                        ListElement{text: "19200"}
                        ListElement{text: "38400"}
                        ListElement{text: "57600"}
                        ListElement{text: "115200"}
                    }
                    onAccepted:
                        ()=>
                        {
                            if (bits_in_sec_cb.find(bits_in_sec_cb.editText) === -1)
                                bits_in_sec.append({text: bits_in_sec_cb.editText});
                        }
                }
            }
            Rectangle
            {
                id: data_bit_rec
                width: station_menu_window.swidth * 58.696
                height: 0
                x: station_menu_window.swidth * 2.865
                y: 0
                enabled: false;
                visible: false;
                color: "#D9D9D9"
                Rectangle
                {
                    width: station_menu_window.swidth * 10.26
                    height: station_menu_window.sheight * 2.778
                    anchors.left: parent.left
                    anchors.verticalCenter: parent.verticalCenter
                    color: "#D9D9D9"
                    Text
                    {
                        font.family: "Inter"
                        font.pixelSize: 22 * 0.04 * station_menu_window.swidth
                        text: qsTr("Бит данных")
                    }
                }
                ComboBox
                {
                    id: data_bit_cb
                    width: station_menu_window.swidth * 7.945
                    height: parent.height
                    anchors.right: parent.right
                    font.pixelSize: 22 * 0.04 * station_menu_window.swidth
                    model: ListModel
                    {
                        id: data_bit
                        ListElement{text: "8"}
                        ListElement{text: "7"}
                        ListElement{text: "6"}
                        ListElement{text: "5"}
                    }
                }
            }
            Rectangle
            {
                id: parity_rec
                width: station_menu_window.swidth * 58.696
                height: 0
                x: station_menu_window.swidth * 2.865
                y: 0
                color: "#D9D9D9"
                enabled: false;
                visible: false;
                Rectangle
                {
                    width: station_menu_window.swidth * 10.26
                    height: station_menu_window.sheight * 2.778
                    anchors.left: parent.left
                    anchors.verticalCenter: parent.verticalCenter
                    color: "#D9D9D9"
                    Text
                    {
                        font.family: "Inter"
                        font.pixelSize: 22 * 0.04 * station_menu_window.swidth
                        text: qsTr("Четность")
                    }
                }
                ComboBox
                {
                    id: parity_cb
                    width: station_menu_window.swidth * 7.945
                    height: parent.height
                    anchors.right: parent.right
                    font.pixelSize: 22 * 0.04 * station_menu_window.swidth
                    model: ListModel
                    {
                        id: parity
                        ListElement{text: "None"}
                        ListElement{text: "Even"}
                        ListElement{text: "Odd"}
                        ListElement{text: "Mark"}
                        ListElement{text: "Space"}
                    }
                }
            }
            Rectangle
            {
                id: stop_bits_rec
                width: station_menu_window.swidth * 58.696
                height: 0
                x: station_menu_window.swidth * 2.865
                y: 0
                enabled: false;
                visible: false;
                color: "#D9D9D9"
                Rectangle
                {
                    width: station_menu_window.swidth * 10.26
                    height: station_menu_window.sheight * 2.778
                    anchors.left: parent.left
                    anchors.verticalCenter: parent.verticalCenter
                    color: "#D9D9D9"
                    Text
                    {
                        font.family: "Inter"
                        font.pixelSize: 22 * 0.04 * station_menu_window.swidth
                        text: qsTr("Стоповые биты")
                    }
                }
                ComboBox
                {
                    id: stop_bits_cb
                    width: station_menu_window.swidth * 7.945
                    height: parent.height
                    anchors.right: parent.right
                    font.pixelSize: 22 * 0.04 * station_menu_window.swidth
                    model: ListModel
                    {
                        id: stop_bits
                        ListElement{text: "1"}
                        ListElement{text: "1.5"}
                        ListElement{text: "2"}
                    }
                }
            }
            Rectangle
            {
                id: flow_control_rec
                width: station_menu_window.swidth * 58.696
                height: 0
                x: station_menu_window.swidth * 2.865
                y: 0
                color: "#D9D9D9"
                enabled: false;
                visible: false;
                Rectangle
                {
                    width: station_menu_window.swidth * 10.26
                    height: station_menu_window.sheight * 2.778
                    anchors.left: parent.left
                    anchors.verticalCenter: parent.verticalCenter
                    color: "#D9D9D9"
                    Text
                    {
                        font.family: "Inter"
                        font.pixelSize: 22 * 0.04 * station_menu_window.swidth
                        text: qsTr("Управление потоком")
                    }
                }
                ComboBox
                {
                    id: flow_control_cb
                    width: station_menu_window.swidth * 7.945
                    height: parent.height
                    anchors.right: parent.right
                    font.pixelSize: 22 * 0.04 * station_menu_window.swidth
                    model: ListModel
                    {
                        id: flow_control
                        ListElement{text: "None"}
                        ListElement{text: "Hardware"}
                        ListElement{text: "Xon / Xoff"}
                    }
                }
            }
        }
        //заголовок окнапакетов, здесь надо продумать как сделать таблицу пакета
        Rectangle
        {
            id: package_templates
            height: station_menu_window.sheight * 4.629
            width: station_menu_window.swidth * 64.063
            y: station_menu_window.sheight * 30
            color: "#A0A0A0"
            border.width: 2
            border.color: "black"
            Rectangle
            {
                height: station_menu_window.sheight * 2.222
                width: station_menu_window.swidth * 8.802
                color: "#A0A0A0"
                x: station_menu_window.swidth * 2.396
                y: station_menu_window.sheight * 1.204
                Text
                {
                    font.family: "Inter"
                    font.pixelSize: 22 * 0.04 * station_menu_window.swidth
                    text: qsTr("Шаблоны пакетов")
                }
            }
            CheckBox
            {
                id: show_package_templates
                width: station_menu_window.swidth * 1.302
                height: station_menu_window.sheight * 2.315
                x: station_menu_window.swidth * 61.979
                y: station_menu_window.sheight * 1.111
                onCheckedChanged:
                {
                    package_templates_parametrs.state === "opened" ? package_templates_parametrs.state = "closed" : package_templates_parametrs.state = "opened";
                }
            }
            Image
            {
                width: station_menu_window.swidth * 1.302
                height: station_menu_window.sheight * 2.315
                anchors.verticalCenter: show_package_templates.verticalCenter
                source: show_package_templates.checked ? ":/arrows_down.png" : ":/arrows_up.png"
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
                            height: station_menu_window.sheight * 50
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
                            height: station_menu_window.sheight * 5.37
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
                        //width: parent.width
                        //height: package_templates_parametrs.height
                        //visible: false
                        def_width: station_menu_window.swidth * 80
                        def_height: station_menu_window.sheight * 70
                        number_lines: station_menu_window.number_zone_main
                        name_zone: name_zone_main
                        sendDataToSMfOZR: function(box_row, box_color)
                        {
                            console.log(" Цвет:",box_color, "строка ", box_row)
                            row_pos = box_row
                            if(box_row > 0)
                            {
                                if(box_color.toString() === "#ffffff")
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
                    width: station_menu_window.swidth * 2.604
                    height: 0
                    //visible: false
                    //enabled: false
                    y: 0
                    x: station_menu_window.swidth * 30.859
                    text: "+"
                    font.pointSize: 48 * station_menu_window.swidth * 0.03
                    onClicked: {
                        addNewZone.open()
                    }
                }
            }

            //СРС
            Rectangle
            {
                id: crc_templates
                height: station_menu_window.sheight * 4.629
                width: station_menu_window.swidth * 64.063
                anchors.top: package_templates_parametrs.bottom
                color: "#A0A0A0"
                border.width: 2
                border.color: "black"
                Rectangle
                {
                    height: station_menu_window.sheight * 2.222
                    width: station_menu_window.swidth * 8.802
                    color: "#A0A0A0"
                    x: station_menu_window.swidth * 2.396
                    y: station_menu_window.sheight * 1.204
                    Text
                    {
                        font.family: "Inter"
                        font.pixelSize: 22 * 0.04 * station_menu_window.swidth
                        text: qsTr("CRC")
                    }
                }
                CheckBox
                {
                    id: show_crc
                    width: station_menu_window.swidth * 1.302
                    height: station_menu_window.sheight * 2.315
                    x: station_menu_window.swidth * 61.979
                    y: station_menu_window.sheight * 1.111
                    enabled: false
                    checked: false
                    onCheckedChanged:
                    {
                        crc_parametrs.state === "opened" ? crc_parametrs.state = "closed" : crc_parametrs.state = "opened";
                    }
                }
                Image
                {
                    width: station_menu_window.swidth * 1.302
                    height: station_menu_window.sheight * 2.315
                    anchors.verticalCenter: show_crc.verticalCenter
                    source: show_crc.checked ? ":/arrows_down.png" : ":/arrows_up.png"
                    //visible: !show_crc.indeterminate || !show_crc.checked
                }
                Rectangle
                {
                    id: crc_parametrs
                    width: station_menu_window.swidth * 64.063
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
                                height: station_menu_window.sheight * 85.533
                            }
                            PropertyChanges
                            {
                                target: byte_info_rec;
                                y: station_menu_window.sheight * 3.796
                                height: station_menu_window.sheight * 5.556
                                enabled: true
                                visible: true
                            }
                            PropertyChanges
                            {
                                target: start_count_rec;
                                y: station_menu_window.sheight * 11.667
                                height: station_menu_window.sheight * 5.556
                                enabled: true
                                visible: true
                            }
                            PropertyChanges
                            {
                                target: end_count_rec;
                                y: station_menu_window.sheight * 19.537
                                height: station_menu_window.sheight * 5.556
                                enabled: true
                                visible: true
                            }
                            PropertyChanges
                            {
                                target: code_rec;
                                y: station_menu_window.sheight * 28.056
                                height: station_menu_window.sheight * 2.5
                                enabled: true
                                visible: true
                            }
                            PropertyChanges
                            {
                                target: code_example_rec;
                                y: station_menu_window.sheight * 32.407
                                height: station_menu_window.sheight * 53.981
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
                            properties: "y"
                            duration: 300
                            easing.type: Easing.InOutQuad
                        }
                        NumberAnimation
                        {
                            properties: "height"
                            duration: 300
                            easing.type: Easing.InOutQuad
                        }
                    }
                    Rectangle
                    {
                        id: byte_info_rec
                        width: station_menu_window.swidth * 59.01
                        height: 0
                        x: station_menu_window.swidth * 2.604
                        y: 0
                        enabled: false
                        visible: false
                        color: "#D9D9D9"
                        Rectangle
                        {
                            width: station_menu_window.swidth * 14.409
                            height: 5
                            anchors.left: parent.left
                            anchors.verticalCenter: parent.verticalCenter
                            color: "#D9D9D9"
                            Text
                            {
                                font.family: "Inter"
                                font.pixelSize: 22 * 0.04 * station_menu_window.swidth
                                text: qsTr("В какой байт поместить контрольную сумму")
                            }
                        }
                        Rectangle
                        {
                            height: parent.height
                            width: station_menu_window.swidth * 3.125
                            anchors.right: parent.right
                            TextInput
                            {

                                id: byte_info
                                height: parent.height
                                width: parent.width
                                anchors.right: parent.right
                                font.family: "Inter"
                                font.pixelSize: 22 * 0.04 * station_menu_window.swidth
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                                text: ""
                            }
                        }

                    }
                    Rectangle
                    {
                        id: start_count_rec
                        width: station_menu_window.swidth * 59.01
                        height: 0
                        x: station_menu_window.swidth * 2.604
                        y: 0
                        enabled: false
                        visible: false
                        color: "#D9D9D9"
                        Rectangle
                        {
                            width: station_menu_window.swidth * 14.409
                            height: 5
                            anchors.left: parent.left
                            anchors.verticalCenter: parent.verticalCenter
                            color: "#D9D9D9"
                            Text
                            {
                                font.family: "Inter"
                                font.pixelSize: 22 * 0.04 * station_menu_window.swidth
                                text: qsTr("Начало вычисления контрольной суммы")
                            }
                        }
                        Rectangle
                        {
                            height: parent.height
                            width: station_menu_window.swidth * 3.125
                            anchors.right: parent.right
                            TextInput
                            {
                                id: start_count
                                height: parent.height
                                width: parent.width
                                anchors.right: parent.right
                                font.family: "Inter"
                                font.pixelSize: 22 * 0.04 * station_menu_window.swidth
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                                text: ""
                            }
                        }
                    }
                    Rectangle
                    {
                        id: end_count_rec
                        width: station_menu_window.swidth * 59.01
                        height: 0
                        x: station_menu_window.swidth * 2.604
                        y: 0
                        enabled: false
                        visible: false
                        color: "#D9D9D9"
                        Rectangle
                        {
                            width: station_menu_window.swidth * 14.409
                            height: 5
                            anchors.left: parent.left
                            anchors.verticalCenter: parent.verticalCenter
                            color: "#D9D9D9"
                            Text
                            {
                                font.family: "Inter"
                                font.pixelSize: 22 * 0.04 * station_menu_window.swidth
                                text: qsTr("Конец вычисления контрольной суммы")
                            }
                        }
                        Rectangle
                        {
                            height: parent.height
                            width: station_menu_window.swidth * 3.125
                            anchors.right: parent.right
                            TextInput
                            {
                                id: end_count
                                height: parent.height
                                width: parent.width
                                anchors.right: parent.right
                                font.family: "Inter"
                                font.pixelSize: 22 * 0.04 * station_menu_window.swidth
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                                text: ""
                            }
                        }
                    }
                    Rectangle
                    {
                        id: code_rec
                        width: station_menu_window.swidth * 14.409
                        height: 0
                        x: station_menu_window.swidth * 2.604
                        y: 0
                        color: "#D9D9D9"
                        enabled: false
                        visible: false
                        Text
                        {
                            font.family: "Inter"
                            font.pixelSize: 22 * 0.04 * station_menu_window.swidth
                            text: qsTr("Код")
                        }
                    }

                    Rectangle
                    {
                        id: code_example_rec
                        width: station_menu_window.swidth * 59.01
                        height: 0
                        x: station_menu_window.swidth * 2.604
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
                            font.pixelSize: 22 * 0.04 * station_menu_window.swidth
                        }
                    }
                }
            }

        }
    }
    Rectangle
    {
        id: buttons_bottom_menu
        width: station_menu_window.swidth * 64.063
        height: station_menu_window.sheight * 12.315
        y: station_menu_window.sheight * 82.259
        x: station_menu_window.swidth * 17.188
        color: "#D9D9D9"
        visible: false
        Button
        {
            id: save_station_button
            width: station_menu_window.swidth * 14.063
            height: station_menu_window.sheight * 5.556
            x: station_menu_window.swidth * 0.989
            y: station_menu_window.sheight * 3.981
            font.family: "Inter"
            font.pixelSize: 22 * 0.04 * station_menu_window.swidth
            text: "Сохранить"
            onClicked:
            {
                var itemIndex = -1;
                /*проверить что расличные поля не пустые*/
                //if()

                for (var i = 0; i < left_model.count; ++i) {
                    if (left_model.get(i).text === sm_station_name.text)
                    {
                        itemIndex = i;
                        break;
                    }
                }
                if (itemIndex !== -1)
                {
                    //package_zone_view.changePackageZone(input_name.text, color_box.color);
                    left_model.set(itemIndex, { name: sm_station_name.text,
                                                color: left_model.get(i).color,
                                                interface_type: sm_interface.text,
                                                port_index_baund_rate: bits_in_sec_cb.currentIndex,
                                                port_index_data_bits: data_bit_cb.currentIndex,
                                                port_index_parity: parity_cb.currentIndex,
                                                port_index_stop_bits: stop_bits_cb.currentIndex,
                                                port_index_flow_control: flow_control_cb.currentIndex
                                              });

                }
                else
                {
                    station_menu_scrollview_right.addZoneInModel(sm_station_name.text, left_model.count  % 2 === 0 ? "#FFFFFF" : "#ECECEC");
                    //package_zone_view.addPackageZone(input_name.text, color_box.color);
                }

                sm_station_name.text = "";
                left_menu_listView.currentIndex = -1;
                station_menu_window.setVisibleActiveZone(false);
            }
        }

        Dialog {
            id: confirmation_dialog
            title: "Удалить?"
            standardButtons: Dialog.Ok | Dialog.Cancel
            Text {
                text:  "Вы действительно хотите удалить '" + sm_station_name.text + "'?";
            }
            onAccepted:
            {
                if (confirmation_dialog.opened)
                {
                    var selectedIdx = left_menu_listView.currentIndex;

                    left_menu_listView.model.remove(selectedIdx);
                    for(var i = selectedIdx; i < left_model.count; ++i)
                    {
                        left_model.setProperty(i, "color", i % 2 == 0 ? "#FFFFFF" : "#ECECEC");
                    }
                    //package_zone_view.deletePackageZone(pzm_model.get(selectedIdx).text);
                    left_menu_listView.height -= 5.556*station_menu_window.sheight;
                    left_menu_scrollview.contentHeight = left_menu_listView.height;
                    left_menu_listView.contentHeight = left_menu_listView.height;
                    if(left_menu_scrollview.contentHeight < left_menu_scrollview.height){
                        white_rect.y = left_menu_listView.contentHeight;
                        left_plus_but.y = white_rect.y + white_rect.height;
                    }
                    left_menu_listView.currentIndex = -1;
                    station_menu_window.setVisibleActiveZone(false);
                }
            }
        }

        Button
        {
            id: delete_station_button
            width: station_menu_window.swidth * 14.063
            height: station_menu_window.sheight * 5.556
            x: station_menu_window.swidth * 49.375
            y: station_menu_window.sheight * 3.981
            font.family: "Inter"
            font.pixelSize: 22 * 0.04 * station_menu_window.swidth
            text: "Удалить"
            onClicked:
            {
                var selectedIdx = left_menu_listView.currentIndex
                if (selectedIdx >= 0 && selectedIdx < left_model.count)
                {
                    confirmation_dialog.open();
                }
            }
        }
    }
    Popup
    {
        id: addSection
        width: 700
        height: 500
        x: station_menu_window.swidth * 27.77
        y: station_menu_window.sheight * 14.851
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
        x: station_menu_window.swidth * 27.77
        y: station_menu_window.sheight * 14.851
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
                number_zone: sm_zones_lv.count + 1
                sendDataToSMfPV: function(zone_name, zone_size)
                {
                    console.log("Имя зоны: ", zone_name,  " Размер: ", Math.ceil(zone_size / 16))
                    sm_zones_lv.model.append({ name_zone: zone_name, number_lines: Math.ceil(zone_size / 16)})
                    station_menu_window.number_zone_main++
                }
                onPvClosed:
                {
                    addNewZone.close()
                }
            }
        }
    }
}



