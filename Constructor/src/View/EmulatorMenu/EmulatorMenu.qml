import QtQuick 2.15
import QtQuick.Window
import QtQuick.Controls
import QtQuick.Dialogs 1.3

Rectangle
{
    id: emulator_menu_main_rec
    width: 1920
    height: 1080
    property real sheight: height / 100
    property real swidth: width / 100

    Rectangle
    {
        id: em_top_rect
        width: swidth * 82.604
        height: sheight * 12.037
        Rectangle
        {
            id: em_port_rect
            width: swidth * 20
            height: sheight * 4.629
            x: swidth * 2.604
            y: sheight * 11.111
            Rectangle
            {
                width: swidth * 2.552
                height: sheight * 2.222
                anchors.left: parent.left
                y: sheight * 12.222
                Text
                {
                    text: qsTr("Порт")
                }
            }
            ComboBox
            {
                id: em_port_combobox
                width: swidth * 14.896
                height: parent.height
                anchors.right: parent.right
                model: ListModel
                {
                    id: em_port
                    ListElement
                    {
                        text: "COM4"
                    }
                }
            }
        }
        Rectangle
        {
            id: em_station_rec
            width: swidth * 20.938
            height: sheight * 4.629
            x: swidth * 25.417
            y: sheight * 11.111
            Rectangle
            {
                width: swidth * 4.375
                height: sheight * 2.222
                anchors.left: parent.left
                y: sheight * 12.222
                Text
                {
                    text: qsTr("Станция")
                }
            }
            ComboBox
            {
                id: em_station_combobox
                width: swidth * 14.896
                height: parent.height
                anchors.right: parent.right
                model: ListModel
                {
                    id: em_station
                    ListElement
                    {
                        text: "«LG» 1DI-X (LG)"
                    }
                }
            }
        }
        Button
        {
            id: em_connect_but
            width: swidth * 14.062
            height: sheight * 4.629
            x: swidth * 51.042
            y: sheight * 11.111
            text: "Подключиться"
            enabled: true
            onClicked:
            {
                em_disconnect_but.enabled = true;
                em_connect_but.enabled = false;
            }
        }
        Button
        {
            id: em_disconnect_but
            width: swidth * 14.062
            height: sheight * 4.629
            x: swidth * 66.51
            y: sheight * 11.111
            text: "Отключиться"
            enabled: true
            onClicked:
            {
                em_disconnect_but.enabled = false;
                em_connect_but.enabled = true;
            }
        }
    }
    Rectangle
    {
        id: em_middle_rect
        width: swidth * 82.604
        height: sheight * 21.111
        anchors.top: em_top_rect.bottom
        Rectangle
        {
            id: em_tests_rect
            width: swidth * 20
            height: sheight * 4.629
            x: swidth * 2.604
            y: sheight * 23.148
            Rectangle
            {
                width: swidth * 2.344
                height: sheight * 2.222
                anchors.left: parent.left
                y: sheight * 24.259
                Text
                {
                    text: qsTr("Тест")
                }
            }
            ComboBox
            {
                id: em_tests_combobox
                width: swidth * 14.896
                height: parent.height
                anchors.right: parent.right
                model: ListModel
                {
                    id: em_tests
                    ListElement
                    {
                        text: "Тест 2 (Пожар)"
                    }
                }
            }
        }
        Button
        {
            id: em_port_setting
            width: swidth * 14.063
            height: sheight * 4.629
            x: swidth * 23.854
            y: sheight * 23.148
            text: "Настройки порта"
            onClicked:
            {

            }
        }
        Button
        {
            id: em_start_but
            width: swidth * 14.062
            height: sheight * 4.629
            x: swidth * 51.042
            y: sheight * 23.148
            text: "Старт"
            enabled: true
            onClicked:
            {
                em_stop_but.enabled = true;
                em_start_but.enabled = false;
            }
        }
        Button
        {
            id: em_stop_but
            width: swidth * 14.062
            height: sheight * 4.629
            x: swidth * 66.51
            y: sheight * 23.148
            text: "Стоп"
            enabled: true
            onClicked:
            {
                em_stop_but.enabled = false;
                em_start_but.enabled = true;
            }
        }
        Rectangle
        {
            id: em_start_cycle_rect
            width: swidth * 16.354
            height: sheight * 2.407
            x: swidth * 2.604
            y: sheight * 30.37

            Rectangle
            {
                width: swidth * 12.031
                height: parent.height
                anchors.left: parent.left
                Text
                {
                    text: qsTr("Запустить тест в цикле")
                }
            }
            CheckBox
            {
                id: em_start_cycle
                width: swidth * 1.354
                height: parent.height
                enabled: false
            }
        }
        Rectangle
        {
            id: em_all_test_start_rect
            width: swidth * 16.354
            height: sheight * 2.407
            x: swidth * 2.604
            y: sheight * 35.278
            Rectangle
            {
                width: swidth * 12.031
                height: parent.height
                anchors.left: parent.left
                Text
                {
                    text: qsTr("Запустить все тесты")
                }
            }
            CheckBox
            {
                id: em_all_test_start
                width: swidth * 1.354
                height: parent.height
                enabled: false
            }
        }
        Rectangle
        {
            width: swidth * 11.406
            height: sheight * 2.222
            x: swidth * 23.854
            y: sheight * 30.37
            Text
            {
                text: qsTr("Синхронная передача")
            }
        }
        Rectangle
        {
            width: swidth * 11.406
            height: sheight * 2.222
            x: swidth * 23.854
            y: sheight * 35.926
            Text
            {
                text: qsTr("acинхронная передача")
            }
        }
        RadioButton
        {
            id: em_synchronous_radio_button
            width: swidth * 1.302
            height: sheight * 2.315
            y: sheight * 30.462
            x: swidth * 36.615
            checked: true
            onClicked:
            {
                button_group.checkedButton = this;
            }
        }
        RadioButton
        {
            id: ynchronous_radio_button
            width: swidth * 1.302
            height: sheight * 2.315
            y: sheight * 35.37
            x: swidth * 36.615
            onClicked:
            {
                button_group.checkedButton = this;
            }
        }
        ButtonGroup
        {
            id: button_group
        }
        Rectangle
        {
            width: swidth * 18.438
            height: sheight * 2.222
            x: swidth * 51.042
            y: sheight * 31.667
            Text
            {
                text: qsTr("Интервал отправки сообщений (мс)")
            }
        }
        TextInput
        {
            id: em_inter_msg
            width: swidth * 8.021
            height: sheight * 3.333
            x: swidth * 72.552
            y: sheight * 31.111
            text: "0"
        }
        Rectangle
        {
            width: swidth * 14.167
            height: sheight * 1.667
            x: swidth * 51.042
            y: sheight * 35.648
            Text
            {
                text: qsTr("Интервал отправки сообщений (мс)")
            }
        }
    }
    Rectangle
    {
        id: em_bottom_rect
        width: swidth * 82.604
        height: sheight * 59.444
        anchors.top: em_middle_rect.bottom
        Rectangle
        {
            id: em_mss_rect
            width: swidth * 15.26
            height: sheight * 4.167
            x: swidth * 2.604
            y: sheight * 44.444
            Rectangle
            {
                width: swidth * 2.291
                height: sheight * 2.222
                anchors.right: parent.right
                y: sheight * 45.463
                Text
                {
                    text: qsTr("MSS")
                }
            }
        }
        Rectangle
        {
            id: em_lb_rect
            width: swidth * 15.26
            height: sheight * 4.167
            x: swidth * 2.604
            y: sheight * 44.444
            Rectangle
            {
                width: swidth * 2.291
                height: sheight * 2.222
                anchors.right: parent.right
                y: sheight * 52315
                Text
                {
                    text: qsTr("LB")
                }
            }
        }
        Rectangle
        {
            id: em_send_msg_cnt_rect
            width: swidth * 14.375
            height: sheight * 2.222
            x: swidth * 20.833
            y: sheight * 45.463
            Text
            {
                id: em_send_msg_cnt
                text: qsTr("Кол-во принятых пакетов: 0")
            }
        }
        Rectangle
        {
            id: em_rec_msg_cnt_rect
            width: swidth * 16.771
            height: sheight * 2.222
            x: swidth * 20.833
            y: sheight * 52.315
            Text
            {
                id: em_rec_msg_cnt
                text: qsTr("Кол-во отправленных пакетов: 0")
            }
        }
        Rectangle
        {
            id: em_time_last_send_rect
            width: swidth * 24.792
            height: sheight * 2.222
            x: swidth * 51.094
            y: sheight * 45.463
            Text
            {
                id: em_time_last_send
                text: qsTr("Время от последнего отправленного пакета: 0 с")
            }
        }
        Rectangle
        {
            id: em_time_last_rec_rect
            width: swidth * 22.344
            height: sheight * 2.222
            x: swidth * 51.094
            y: sheight * 52.315
            Text
            {
                id: em_time_last_rec
                text: qsTr("Время от последнего принятого пакета: 0 с")
            }
        }
        Rectangle
        {
            id: em_cnt_msg_rec
            width: swidth * 16.094
            height: sheight * 2.222
            x: swidth * 2.604
            y: sheight * 58.333
            Text
            {
                id: em_cnt_msg
                text: qsTr("Отправлено сообщений 2 из 15")
            }
        }
        Button
        {
            id: em_log_but
            width: swidth * 21.979
            height: sheight * 4.629
            x: swidth * 2.604
            y: sheight * 66.204
            text: "Посмотреть историю обмена сообщениями"
        }
    }
    Rectangle
    {
        id: em_right_menu_rect
        width: swidth * 17.188
        height: parent.height
        anchors.right: parent.right
        Rectangle
        {
            id:em_right_menu_title
            width: parent.width
            height: sheight * 4.629
            anchors.top: parent.top
            Text
            {
                text: qsTr("Результаты тестов")
            }
        }
    }
}
