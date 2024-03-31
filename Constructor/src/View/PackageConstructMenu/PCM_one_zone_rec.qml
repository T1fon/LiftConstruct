import QtQuick 2.15
import QtQuick.Window
import QtQuick.Controls
import QtQuick.Dialogs

Rectangle
{
    width: 1230
    height: 350
    property real swidth: width / 100
    property real sheight: height / 100
    property int counter_bytes: 1
    property string zone_name: "Префикс"
    property int counter: 1
    property int totalValue: 0
    Rectangle
    {
        id: one_zone_title_rec
        width: parent.width
        height: sheight * 14.285
        anchors.top: parent.top
        border.color: "black"
        border.width: 2
        color: "#A0A0A0"
        Rectangle
        {
            width: swidth * 12.195
            height: sheight * 6.857
            anchors.left: parent.left
            anchors.verticalCenter: parent.verticalCenter
            color: "#A0A0A0"
            Text
            {
                id: one_zone_title_rec_text
                font.family: "Inter"
                font.pixelSize: 20 * 0.04 * swidth
                text: qsTr("Зона: ") + zone_name
            }
        }
        CheckBox
        {
            id: show_one_zone_rec
            width: swidth * 2.032
            height: sheight * 7.142
            anchors.right: parent.right
            anchors.verticalCenter: parent.verticalCenter
            checked: false
            onCheckedChanged:
            {
                one_zone_rec.state === "opened" ? one_zone_rec.state = "closed" : one_zone_rec.state = "opened";
            }
        }
        Image
        {
            width: swidth * 2.032
            height: sheight * 7.142
            anchors.verticalCenter: show_one_zone_rec.verticalCenter
           // source: show_one_zone_rec.checked ? "../../arrows_down.png" : "../../arrows_up.png"
            //visible: !show_packadge_view.indeterminate || !show_packadge_view.checked
        }
    }
    Rectangle
    {
        id: one_zone_rec
        width: parent.width
        height: 0
        anchors.top: pcm_packadge_view_title_rec.bottom
        state: "closed"
        color: "#D9D9D9"
        states:
            [
            State
            {
                name: "opened"
                PropertyChanges
                {
                    target: pcm_packadge_view_rec; height: sheight * 85.714
                }
            },
            State {
                name: "closed"
                PropertyChanges
                {
                    target: pcm_packadge_view_rec; height: 0

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
            id: one_zone_color_zone
            width: parent.width
            height: sheight * 7.429
            anchors.top: parent.top
            color: "red"
        }
        Rectangle
        {
            width: parent.width
            height: parent.height - one_zone_color_zone.height
            y: one_zone_color_zone.y
            color: "#D9D9D9"
            Repeater
            {
                model: counter_bytes
                Rectangle
                {
                    id: numbers
                    anchors.top: parent.top
                    width: swidth * 41.626
                    height: sheight * 9.428
                    x: swidth * 3.021
                    y: sheight * 12
                    color: "#D9D9D9"
                    property real squareWidth: width / 8
                    property real squareHeight: height
                    Grid
                    {
                        id: grid_1
                        anchors.fill: parent
                        columns: 8
                        Repeater
                        {
                            model: grid_1.columns
                            Rectangle
                            {
                                width: table.squareWidth
                                height: table.squareHeight
                                color: "#D9D9D9"
                                Text
                                {
                                    anchors.centerIn: parent
                                    text: (grid_1.columns - index).toString()
                                    font.family: "Inter"
                                    font.pixelSize: 20 * 0.04 * swidth
                                }
                            }
                        }
                    }
                }
                Rectangle
                {
                    id: count_rect
                    width: swidth * 5.203
                    height: sheight * 18.285
                    color: "#D9D9D9"
                    y: numbers.y + numbers.height
                    x: swidth * 2.857
                    Text
                    {
                        font.family: "Inter"
                        font.pixelSize: 20 * 0.04 * swidth
                        text: qsTr(counter.toString())
                        onTextChanged:
                        {
                            counter += 1
                        }
                    }
                }
                Rectangle
                {
                    id: table_rec
                    width: swidth * 41.626
                    height: sheight * 18.285
                    x: count_rect.x + count_rect.width
                    y: numbers.y + numbers.height
                    function updateTotalValue()
                    {
                            totalValue = 0
                            for (var i = 0; i < grid.children.length; ++i)
                            {
                                totalValue += Math.pow(2, 7 - grid.children[i].inputText.text)
                            }
                        }
                    Grid
                    {
                        anchors.fill: parent
                        id: grid
                        columns: 8
                        Repeater
                        {
                            model: grid.columns
                            Rectangle
                            {
                                width: table_rec.width / grid.columns
                                height: parent.height
                                color: "white"
                                border.color: "black"
                                border.width: 1
                                TextInput
                                {
                                    width: parent.width
                                    height: parent.height
                                    Text
                                    {
                                        text: "0"
                                        font.family: "Inter"
                                        font.pixelSize: 20 * 0.04 * swidth
                                        onTextChanged:
                                        {
                                            table_rec.updateTotalValue()
                                        }
                                    }
                                    MouseArea
                                    {
                                        anchors.fill: parent
                                        onClicked:
                                        {
                                            console.log("Квадрат", index + 1, "в элементе", index + 1, "был нажат.")
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                Rectangle
                {
                    width: swidth * 9.593
                    height: sheight * 18.285
                    x: swidth * 85.935
                    y: numbers.y + numbers.height
                    color: "#D9D9D9"
                    Rectangle
                    {
                        width: swidth * 3.089
                        height: sheight * 6.857
                        anchors.left: parent.left
                        anchors.verticalCenter: parent.verticalCenter
                        Text
                        {
                            id: zone_byte_sum
                            font.family: "Inter"
                            font.pixelSize: 20 * 0.04 * swidth
                            text: qsTr(totalValue.toString())
                        }
                        Rectangle
                        {
                            height: parent.height
                            width: swidth * 5.203
                            color: "white"
                            border.color: "black"
                            border.width: 1
                            anchors.right: parent.right
                            Text {
                                id: zone_byte_sum_16
                                text: table_rec.toString(16)
                            }
                        }
                    }
                }
            }
        }
    }
}
