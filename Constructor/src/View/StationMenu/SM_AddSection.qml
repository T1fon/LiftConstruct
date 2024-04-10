import QtQuick 2.15
import QtQuick.Window
import QtQuick.Controls
import QtQuick.Dialogs

Rectangle
{
    signal addClose()
    signal sendData(int start_section, int length_section)
    id: sm_AddSection_rec
    width: 800
    height: 600
    property real swidth: width/100
    property real sheight: height/100
    color: "#D9D9D9"
    Rectangle
    {
        id: sm_add_section_section_rect
        x: swidth * 8.875
        y: sheight * 4.833
        width: swidth * 85.375
        height: sheight * 10
        color: "#D9D9D9"
        Rectangle
        {
            width: swidth * 9.125
            height: sheight * 4
            anchors.left: parent.left
            anchors.verticalCenter: parent.verticalCenter
            color: "#D9D9D9"
            Text
            {
                font.family: "Inter"
                font.pixelSize: 20 * 0.1 * swidth
                text: qsTr("Секция")
            }
        }
        ComboBox
        {
            id: sm_AddSection_section_cb
            anchors.right:parent.right
            height: parent.height
            width: swidth * 37.5
            model: ListModel
            {
                id: sm_AddSection_section_lm
            }
        }
    }
    Rectangle
    {
        id:sm_add_section_start_rect
        x: swidth * 8.875
        y: sheight * 23.167
        width: swidth * 85.375
         height: sheight * 10
        color: "#D9D9D9"
        Rectangle
        {
            width: swidth * 26.75
            height: sheight * 4
            anchors.left: parent.left
            anchors.verticalCenter: parent.verticalCenter
            color: "#D9D9D9"
            Text
            {
                font.family: "Inter"
                font.pixelSize: 20 * 0.1 * swidth
                text: qsTr("Начало секции(байт)")
            }
        }
        Rectangle
        {
            anchors.right:parent.right
            height: parent.height
            width: swidth * 25
            TextInput
            {
                id: sm_AddSection_start_ti
                anchors.right:parent.right
                height: parent.height
                width: parent.width
                font.family: "Inter"
                font.pixelSize: 20 * 0.1 * swidth
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                text: "0"
            }
        }
    }
    Rectangle
    {
        id:sm_add_section_length_rect
        x: swidth * 8.875
        y: sheight * 41.5
        width: swidth * 85.375
        height: sheight * 10
        color: "#D9D9D9"
        Rectangle
        {
            width: swidth * 25.375
            height: sheight * 4
            anchors.left: parent.left
            anchors.verticalCenter: parent.verticalCenter
            color: "#D9D9D9"
            Text
            {
                font.family: "Inter"
                font.pixelSize: 20 * 0.1 * swidth
                text: qsTr("Длина секции(байт)")
            }
        }
        Rectangle
        {
            anchors.right:parent.right
            height: parent.height
            width: swidth * 25
            TextInput
            {
                id: sm_AddSection_length_ti
                anchors.right:parent.right
                height: parent.height
                width: parent.width
                font.family: "Inter"
                font.pixelSize: 20 * 0.1 * swidth
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                text: "0"
            }
        }
    }
    Dialog {
        id: warning_dialog
        title: "ошибка"
        standardButtons: Dialog.Ok
        Text {
            text:  "Измените начало и длину секции";
        }
        onAccepted:
        {
            warning_dialog.close()
        }
    }
    Button
    {
        id:sm_AddSection_ok_but
        x: swidth * 8.875
        y: sheight * 82.333
        width: swidth * 33.75
        height: sheight * 10
        font.family: "Inter"
        font.pixelSize: 20 * 0.1 * swidth
        text: "Применить"
        onClicked:
        {
            if(sm_AddSection_start_ti.text !== "" && sm_AddSection_length_ti.text !== "" &&
                  parseInt(sm_AddSection_start_ti.text) !== 0 && parseInt(sm_AddSection_length_ti.text) !== 0
                    && !isNaN(sm_AddSection_start_ti.text) && !isNaN(sm_AddSection_length_ti.text))
            {
                sendDataToSM(parseInt(sm_AddSection_start_ti.text), parseInt(sm_AddSection_length_ti.text))
                sm_AddSection_start_ti.clear()
                sm_AddSection_length_ti.clear()
                addClose()
            }
            else
                warning_dialog.open()

        }
    }
    Button
    {
        id:sm_AddSection_cancel_but
        x: swidth * 60.5
        y: sheight * 82.333
        width: swidth * 33.75
        height: sheight * 10
        font.family: "Inter"
        font.pixelSize: 20 * 0.1 * swidth
        text: "отменить"
        onClicked:
        {
            addClose()
        }
    }

    property var sendDataToSM: undefined
}
