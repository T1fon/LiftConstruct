import QtQuick 2.15
import QtQuick.Window
import QtQuick.Controls
import QtQuick.Dialogs

Rectangle
{
    width: 1106
    height: 96
    property real swidth: width / 100
    property real sheight: height / 100
    color: "#D9D9D9"
    property int counter_zone: 1
    Rectangle
    {
        id: prim_box
        width: swidth * 9.584
        height: sheight * 25.167
        x: swidth * 15.823
        anchors.top: parent.top
        color: "#D9D9D9"
        Text
        {
            font.family: "Inter"
            font.pixelSize: 22 * 0.04 * swidth
            text: qsTr("Примечание")
        }
    }
    Rectangle
    {
        id: action_box
        width: swidth * 9.584
        height: sheight * 25.167
        x: swidth * 45.118
        anchors.top: parent.top
        color: "#D9D9D9"
        Text
        {
            font.family: "Inter"
            font.pixelSize: 22 * 0.04 * swidth
            text: qsTr("Действие")
        }
    }
    Rectangle
    {
        id: pack_box
        width: swidth * 5.244
        height: sheight * 25.167
        x: swidth * 75.089
        anchors.top: parent.top
        color: "#D9D9D9"
        Text
        {
            font.family: "Inter"
            font.pixelSize: 22 * 0.04 * swidth
            text: qsTr("Пакет")
        }
    }
    Rectangle
    {
        width: swidth * 1.613
        height: sheight * 25
        anchors.left: parent.left
        y: sheight * 60
        Text
        {
            font.family: "Inter"
            font.pixelSize: 20 * 0.04 * swidth
            text: counter_zone.toString()
        }
    }
    Rectangle
    {
        width: swidth * 26.882
        height: sheight * 52.448
        y: sheight * 46.875
        x: swidth * 7.795
        TextInput
        {
            id: tcm_discription_text
            width: parent.width
            height: parent.height
            font.family: "Inter"
            font.pixelSize: 22 * 0.04 * swidth
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            anchors.right: parent.right
        }
    }
    Rectangle
    {
        width: swidth * 16.487
        height: sheight * 52.448
        y: sheight * 46.875
        x: swidth * 41.219
        ComboBox
        {
            id: tcm_action_combobox
            width: parent.width
            height: parent.height
            anchors.right: parent.right
            model: ListElement
            {
                id: tcm_act_model
                ListElement
                {
                    text: "Не выбрано"
                }
                ListElement
                {
                    text: "Принять"
                }
                ListElement
                {
                    text: "Отправить"
                }
            }
        }
    }
    Rectangle
    {
        width: swidth * 26.882
        height: sheight * 52.448
        y: sheight * 46.875
        x: swidth * 64.247
        TextInput
        {
            id: tcm_pack_combobox
            width: parent.width
            height: parent.height
            font.family: "Inter"
            font.pixelSize: 22 * 0.04 * swidth
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            anchors.right: parent.right
        }
    }
    Rectangle
    {
        width: swidth * 4.48
        height: sheight * 52.448
        anchors.left: parent.left
        y: sheight * 46.875
        anchors.right: parent.right
        Button
        {
            id: tcm_del_but
            width: parent.width
            height: parent.height
            font.family: "Inter"
            font.pixelSize: 22 * 0.04 * swidth
            anchors.right: parent.right
            text: "-"
            onClicked:
            {

            }
        }
    }
}
