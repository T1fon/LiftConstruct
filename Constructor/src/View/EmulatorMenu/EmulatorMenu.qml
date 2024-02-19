import QtQuick 2.15
import QtQuick.Window
import QtQuick.Controls
import QtQuick.Dialogs

Rectangle
{
    id: emulator_menu_main_rec
    width: 1920
    height: 1000
    property real sheight: height / 100
    property real swidth: width / 100
    color: "#D9D9D9"

    Rectangle
    {
        id: em_top_rect
        width: swidth * 82.604
        height: sheight * 12.037
        anchors.top: parent.top
        color: "#D9D9D9"
        Rectangle
        {
            id: em_port_rect
            width: swidth * 20
            height: sheight * 4.629
            x: swidth * 2.604
            y: sheight * 3.703
            color: "#D9D9D9"
            Rectangle
            {
                width: swidth * 2.552
                height: sheight * 2.222
                anchors.left: parent.left
                anchors.verticalCenter: parent.verticalCenter
                color: "#D9D9D9"
                Text
                {
                    font.family: "Inter"
                    font.pixelSize: 22 * 0.04 * swidth
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
            y: sheight * 3.703
            color: "#D9D9D9"
            Rectangle
            {
                width: swidth * 4.375
                height: sheight * 2.222
                anchors.left: parent.left
                anchors.verticalCenter: parent.verticalCenter
                color: "#D9D9D9"
                Text
                {
                    font.family: "Inter"
                    font.pixelSize: 22 * 0.04 * swidth
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
            y: sheight * 3.703
            font.family: "Inter"
            font.pixelSize: 22 * 0.04 * swidth
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
            y: sheight * 3.703
            text: "Отключиться"
            font.family: "Inter"
            font.pixelSize: 22 * 0.04 * swidth
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
        id: em_first_black_line
        width: swidth * 82.604
        height: sheight * 0.125
        color: "black"
        y: em_top_rect.height + em_top_rect.y
    }

    Rectangle
    {
        id: em_middle_rect
        width: swidth * 82.604
        height: sheight * 21.111
        y:em_first_black_line.height + em_first_black_line.y
        color: "#D9D9D9"
        Rectangle
        {
            id: em_tests_rect
            width: swidth * 20
            height: sheight * 4.629
            x: swidth * 2.604
            y: sheight * 3.704
            color: "#D9D9D9"
            Rectangle
            {
                width: swidth * 2.344
                height: sheight * 2.222
                anchors.left: parent.left
                anchors.verticalCenter: parent.verticalCenter
                color: "#D9D9D9"
                Text
                {
                    font.family: "Inter"
                    font.pixelSize: 22 * 0.04 * swidth
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
            y: sheight * 3.704
            font.family: "Inter"
            font.pixelSize: 22 * 0.04 * swidth
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
            y: sheight * 3.703
            text: "Старт"
            font.family: "Inter"
            font.pixelSize: 22 * 0.04 * swidth
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
            y: sheight * 3.704
            font.family: "Inter"
            font.pixelSize: 22 * 0.04 * swidth
            text: "Стоп"
            enabled: false
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
            y: sheight * 10.926
            color: "#D9D9D9"
            Rectangle
            {
                width: swidth * 12.031
                height: parent.height
                anchors.left: parent.left
                anchors.verticalCenter: parent.verticalCenter
                color: "#D9D9D9"
                Text
                {
                    font.family: "Inter"
                    font.pixelSize: 22 * 0.04 * swidth
                    text: qsTr("Запустить тест в цикле")
                }
            }
            CheckBox
            {
                id: em_start_cycle
                width: swidth * 1.354
                height: parent.height
                anchors.right: parent.right
            }
        }
        Rectangle
        {
            id: em_all_test_start_rect
            width: swidth * 16.354
            height: sheight * 2.407
            x: swidth * 2.604
            y: sheight * 15.833
            color: "#D9D9D9"
            Rectangle
            {
                width: swidth * 12.031
                height: parent.height
                anchors.left: parent.left
                anchors.verticalCenter: parent.verticalCenter
                color: "#D9D9D9"
                Text
                {
                    font.family: "Inter"
                    font.pixelSize: 22 * 0.04 * swidth
                    text: qsTr("Запустить все тесты")
                }
            }
            CheckBox
            {
                id: em_all_test_start
                width: swidth * 1.354
                height: parent.height
                anchors.right: parent.right
            }
        }
        Rectangle
        {
            width: swidth * 11.406
            height: sheight * 2.222
            x: swidth * 23.854
            y: sheight * 10.926
            color: "#D9D9D9"
            Text
            {
                font.family: "Inter"
                font.pixelSize: 22 * 0.04 * swidth
                text: qsTr("Синхронная передача")
            }
        }
        Rectangle
        {
            width: swidth * 11.406
            height: sheight * 2.222
            x: swidth * 23.854
            y: sheight * 15.833
            color: "#D9D9D9"
            Text
            {
                font.family: "Inter"
                font.pixelSize: 22 * 0.04 * swidth
                text: qsTr("Аcинхронная передача")
            }
        }
        RadioButton
        {
            id: em_synchronous_radio_button
            width: swidth * 1.302
            height: sheight * 2.315
            y: sheight * 10.926
            x: swidth * 36.615
            checked: true
            onClicked:
            {
                button_group.checkedButton = this;
            }
        }
        RadioButton
        {
            id: em_asynchronous_radio_button
            width: swidth * 1.302
            height: sheight * 2.315
            y: sheight * 15.833
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
            y: sheight * 12.222
            color: "#D9D9D9"
            Text
            {
                font.family: "Inter"
                font.pixelSize: 22 * 0.04 * swidth
                text: qsTr("Интервал отправки сообщений (мс)")
            }
        }
        Rectangle
        {
            width: swidth * 8.021
            height: sheight * 3.333
            x: swidth * 72.552
            y: sheight * 12.222
            TextInput
            {
                id: em_inter_msg
                width: parent.width
                height: parent.height
                anchors.right: parent.right
                text: "0"
            }
        }
        Rectangle
        {
            width: swidth * 14.167
            height: sheight * 1.667
            x: swidth * 51.042
            y: sheight * 16.204
            color: "#D9D9D9"
            Text
            {
                font.family: "Inter"
                font.pixelSize: 18 * 0.04 * swidth
                color: "#676767"
                text: qsTr("0 - мгновенная отправка сообщений")
            }
        }
    }
    Rectangle
    {
        id: em_second_black_line
        width: swidth * 82.604
        height: sheight * 0.125
        color: "black"
        y: em_middle_rect.y + em_middle_rect.height
    }
    Rectangle
    {
        id: em_bottom_rect
        width: swidth * 82.604
        height: sheight * 59.444
        y: em_second_black_line.y + em_second_black_line.height
        color: "#D9D9D9"
        Rectangle
        {
            id: em_mss_rect
            width: swidth * 15.26
            height: sheight * 4.167
            x: swidth * 2.604
            y: sheight * 3.889
            color: "#D9D9D9"
            //нарисовать стрелку и кругляш в ней
            Rectangle
            {
                width: swidth * 2.291
                height: sheight * 2.222
                anchors.right: parent.right
                anchors.verticalCenter: parent.verticalCenter
                color: "#D9D9D9"
                Text
                {
                    font.family: "Inter"
                    font.pixelSize: 18 * 0.04 * swidth
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
            y: sheight * 10.833
            color: "#D9D9D9"
            Rectangle
            {
                width: swidth * 2.291
                height: sheight * 2.222
                anchors.right: parent.right
                anchors.verticalCenter: parent.verticalCenter
                color: "#D9D9D9"
                Text
                {
                    font.family: "Inter"
                    font.pixelSize: 18 * 0.04 * swidth
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
            y: sheight * 4.907
            color: "#D9D9D9"
            Text
            {
                id: em_send_msg_cnt
                font.family: "Inter"
                font.pixelSize: 18 * 0.04 * swidth
                text: qsTr("Кол-во принятых пакетов: 0")
            }
        }
        Rectangle
        {
            id: em_rec_msg_cnt_rect
            width: swidth * 16.771
            height: sheight * 2.222
            x: swidth * 20.833
            y: sheight * 11.759
            color: "#D9D9D9"
            Text
            {
                id: em_rec_msg_cnt
                font.family: "Inter"
                font.pixelSize: 18 * 0.04 * swidth
                text: qsTr("Кол-во отправленных пакетов: 0")
            }
        }
        Rectangle
        {
            id: em_time_last_send_rect
            width: swidth * 24.792
            height: sheight * 2.222
            x: swidth * 51.094
            y: sheight * 4.907
            color: "#D9D9D9"
            Text
            {
                id: em_time_last_send
                font.family: "Inter"
                font.pixelSize: 18 * 0.04 * swidth
                text: qsTr("Время от последнего отправленного пакета: 0 с")
            }
        }
        Rectangle
        {
            id: em_time_last_rec_rect
            width: swidth * 22.344
            height: sheight * 2.222
            x: swidth * 51.094
            y: sheight * 11.759
            color: "#D9D9D9"
            Text
            {
                id: em_time_last_rec
                font.family: "Inter"
                font.pixelSize: 18 * 0.04 * swidth
                text: qsTr("Время от последнего принятого пакета: 0 с")
            }
        }
        Rectangle
        {
            id: em_cnt_msg_rec
            width: swidth * 16.094
            height: sheight * 2.222
            x: swidth * 2.604
            y: sheight * 17.778
            color: "#D9D9D9"
            Text
            {
                id: em_cnt_msg
                font.family: "Inter"
                font.pixelSize: 18 * 0.04 * swidth
                text: qsTr("Отправлено сообщений 2 из 15")
            }
        }
        Button
        {
            id: em_log_but
            width: swidth * 21.979
            height: sheight * 4.629
            x: swidth * 2.604
            y: sheight * 25.648
            font.family: "Inter"
            font.pixelSize: 18 * 0.04 * swidth
            text: "Посмотреть историю обмена сообщениями"
        }
    }
    Rectangle
    {
        height: parent.height
        width: swidth * 0.5
        color: "black"
        x: em_bottom_rect.x + em_bottom_rect.width
    }

    Rectangle
    {
        id: em_right_menu_rect
        width: swidth * 17.188
        height: parent.height
        anchors.right: parent.right
        color: "#D9D9D9"
        Rectangle
        {
            id:em_right_menu_title
            width: parent.width
            height: sheight * 4.629
            anchors.top: parent.top
            color: "#A0A0A0"
            Text
            {
                font.family: "Inter"
                font.pixelSize: 18 * 0.04 * swidth
                text: qsTr("Результаты тестов")
            }
        }
        ListView
        {
            id: em_right_menu_listview
            width: parent.width
            height: contentHeight
            model: ListModel
            {
                id: em_right_menu_model
            }
        }
    }
}
