import QtQuick 2.15
import QtQuick.Window
import QtQuick.Controls
import QtQuick.Dialogs

Rectangle
{
    signal pvClosed()
    property var sendDataToSMfPV: undefined
    id: sm_package_view_rec
    width: 800
    height: 600
    property real swidth: width/100
    property real sheight: height/100
    property int number_zone: 1
    color: "#D9D9D9"
    Rectangle
    {
        id: sm_package_name_rec
        width: swidth * 85.375
        height: sheight * 10
        x: swidth * 8.875
        y: sheight * 4.833
        color: "#D9D9D9"
        Rectangle
        {
            width: swidth * 18.25
            height: sheight * 4
            anchors.left: parent.left
            anchors.verticalCenter: parent.verticalCenter
            color: "#D9D9D9"
            Text
            {
                font.family: "Inter"
                font.pixelSize: 20 * 0.1 * swidth
                text: qsTr("Наименование")
            }
        }
        Rectangle
        {
            anchors.right:parent.right
            height: parent.height
            width: swidth * 37.5
            TextInput
            {
                id: sm_package_view_name_ti
                anchors.right:parent.right
                height: parent.height
                width: parent.width
                font.family: "Inter"
                font.pixelSize: 20 * 0.1 * swidth
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                text: qsTr("Вид пакета ") + qsTr(number_zone.toString())
            }
        }
    }
    Rectangle
    {
        id: sm_package_size_rec
        width: swidth * 85.375
        height: sheight * 10
        x: swidth * 8.875
        y: sheight * 23.167
        color: "#D9D9D9"
        Rectangle
        {
            width: swidth * 26.25
            height: sheight * 4
            anchors.left: parent.left
            anchors.verticalCenter: parent.verticalCenter
            color: "#D9D9D9"
            Text
            {
                font.family: "Inter"
                font.pixelSize: 20 * 0.1 * swidth
                text: qsTr("Размер пакета(байт)")
            }
        }
        Rectangle
        {
            anchors.right:parent.right
            height: parent.height
            width: swidth * 25
            TextInput
            {
                id: sm_package_view_size_ti
                anchors.right:parent.right
                height: parent.height
                width: parent.width
                font.family: "Inter"
                font.pixelSize: 20 * 0.1 * swidth
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                text: ""
            }
        }
    }
    Dialog {
        id: warning_dialog
        title: "ошибка"
        standardButtons: Dialog.Ok
        Text {
            font.pixelSize: 20 * 0.1 * swidth
            text:  "Измените наименование или размер пакета";
        }
        onAccepted:
        {

        }
    }
    Button
    {
        id:sm_package_view_ok_but
        x: swidth * 8.875
        y: sheight * 82.333
        width: swidth * 33.75
        height: sheight * 10
        font.family: "Inter"
        font.pixelSize: 20 * 0.1 * swidth
        text: "Применить"
        onClicked:
        {
            console.log(sm_package_view_name_ti.text, sm_package_view_size_ti.text)
            if(sm_package_view_name_ti.text != "" && sm_package_view_size_ti != ""
                    && parseInt(sm_package_view_size_ti.text) !== 0 && !isNaN(sm_package_view_size_ti.text) )
            {
                sendDataToSMfPV(sm_package_view_name_ti.text, parseInt(sm_package_view_size_ti.text))
                pvClosed()
                sm_package_view_size_ti.clear()
            }
            else
                warning_dialog.open()
        }
    }
    Button
    {
        id:sm_package_view_cancel_but
        x: swidth * 60.5
        y: sheight * 82.333
        width: swidth * 33.75
        height: sheight * 10
        font.family: "Inter"
        font.pixelSize: 20 * 0.1 * swidth
        text: "отменить"
        onClicked:
        {
            pvClosed()
        }
    }
}
