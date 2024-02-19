import QtQuick 2.15
import QtQuick.Window
import QtQuick.Controls
import QtQuick.Dialogs


Rectangle
{
    id: sm_one_zone_main_rec
    width: 1230
    height: 700
    property int sheight: height / 100
    property int swidth: width / 100
    property int number_zone: 1
    property int number_lines: 1
    property int counter: 1
    Rectangle
    {
        id: package_viev_header_rec
        width: parent.width
        height: sheight * 5.714
        anchors.top: parent.top
        color: "#BBBBBB"
        Button
        {
            id: package_viev_delete_button
            width: swidth * 2.033
            height: sheight * 3.428
            x: swidth * 0732
            y: sheight * 1.143
            font.family: "Inter"
            font.pixelSize: 22 * 0.04 * swidth
            text: "-"
            onClicked:
            {
                confirmation_dialog.open()
            }
        }
        Rectangle
        {
            width: swidth * 10.081
            height: sheight * 3.428
            x: swidth * 3.739
            anchors.verticalCenter: parent.verticalCenter
            color: "#BBBBBB"
            Text
            {
                font.family: "Inter"
                font.pixelSize: 20 * 0.04 * swidth
                text: qsTr("Вид пакета ") + number_zone.toString()
            }
        }
        Button
        {
            id: package_viev_settings_button
            width: swidth * 2.033
            height: sheight * 3.428
            x: swidth * 93.496
            y: sheight * 1.143
            font.family: "Inter"
            font.pixelSize: 22 * 0.04 * swidth
            text: "Ш"
            onClicked:
            {

            }
        }

        CheckBox
        {
            id: show_package_view_rec
            width: swidth * 2.033
            height: sheight * 3.571
            x: swidth * 96.748
            y: sheight * 1.143
            onCheckedChanged:
            {
                package_view_rec.state === "opened" ? package_view_rec.state = "closed" : package_view_rec.state = "opened";
            }
        }
        Image
        {
            width: swidth * 1.302
            height: sheight * 2.315
            anchors.verticalCenter: show_package_view_rec.verticalCenter
            source: show_package_templates.checked ? "../../arrows_down.png" : "../../arrows_up.png"
            //visible: !show_package_templates.indeterminate || !show_package_templates.checked
        }
        Rectangle
        {
            id: package_view_rec
            width: parent.width
            anchors.top: parent.bottom
            height: 0
            color: "#D9D9D9"
            visible: false
            enabled: false
            states:
                [
                State
                {
                    name: "opened"
                    PropertyChanges
                    {
                        target: package_view_rec;
                        height: sheight * 64.814
                        visible: true
                        enabled: true
                    }
                    PropertyChanges {
                        target: ozr_section_title;
                        height: sheight * 3.428;
                        y: sheight * 2.714
                    }
                    PropertyChanges {
                        target: ozr_section_scrolview;
                        height: sheight * 27.857
                        y: sheight * 8.857
                    }
                    PropertyChanges
                    {
                        target: ozr_line;
                        height: 1;
                        y: sheight * 41.428
                    }
                    PropertyChanges
                    {
                        target: ozr_description;
                        height: 0;
                        y: 0
                    }
                    PropertyChanges
                    {
                        target: sm_one_zone_te;
                        height: sheight * 37.857
                        y: sheight * 51.143
                    }
                },
                State
                {
                    name: "closed"
                    PropertyChanges
                    {
                        target: package_view_rec;
                        height: sheight * 0
                        visible: false
                        enabled: false
                    }
                    PropertyChanges {
                        target: ozr_section_title;
                        height: 1;
                        y: sheight * 41.428
                    }
                    PropertyChanges {
                        target: ozr_section_scrolview;
                        height: sheight * 3.428
                        y: sheight * 45
                    }
                    PropertyChanges
                    {
                        target: ozr_line;
                        height: 0;
                        y: 0
                    }
                    PropertyChanges
                    {
                        target: ozr_description;
                        height: 0;
                        y: 0
                    }
                    PropertyChanges
                    {
                        target: sm_one_zone_te;
                        height: 0;
                        y: 0
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
            state: "closed"
            Rectangle
            {
                id: ozr_section_title
                width: swidth * 11.788
                height: 0
                x: swidth * 3.821
                y: 0
                color: "#D9D9D9"
                Text
                {
                    font.family: "Inter"
                    font.pixelSize: 20 * 0.04 * swidth
                    text: qsTr("Секции пакета")
                }
            }
            ScrollView
            {
                id: ozr_section_scrolview
                width: swidth * 90.813
                height: 0
                x: swidth * 3.821
                y: 0
                Rectangle
                {
                    id: table
                    anchors.top: parent.top
                    width: parent.width
                    height: sheight * 9.142
                    color: "#D9D9D9"
                    property real squareWidth: width / 17
                    property real squareHeight: height
                    Grid
                    {
                        id: grid_1
                        anchors.fill: parent
                        columns: 17
                        Repeater
                        {
                            model: grid_1.columns
                            Rectangle
                            {
                                width: table.squareWidth
                                height: table.squareHeight
                                color: "#D9D9D9"
                                border.color: "black"
                                border.width: 1
                                Text
                                {
                                    anchors.centerIn: parent
                                    text: index > 0 ? (index).toString() : ""
                                    font.family: "Inter"
                                    font.pixelSize: 24 * 0.04 * swidth
                                }
                            }
                        }
                    }
                }
                ListView
                {
                    width: parent.width
                    y: sheight * 18
                    model: number_lines
                    delegate: Rectangle
                    {
                        width: parent.width
                        height: sheight * 9.142
                        Grid
                        {
                            anchors.fill: parent
                            id: grid
                            columns: 17
                            Repeater
                            {
                                model: grid.columns
                                Rectangle
                                {
                                    width: parent.width / grid.columns
                                    height: parent.height
                                    color: "white"
                                    border.color: "black"
                                    border.width: 1
                                    Text
                                    {
                                        anchors.centerIn: parent
                                       text: index === 0 ? counter.toString() : ""
                                        color: "black"
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
            }
            Rectangle
            {
                id: ozr_line
                width: parent.width
                height: 0
                color: "black"
                y: 0
            }
            Rectangle
            {
                id: ozr_description
                width: swidth * 7.886
                height: 0
                x: swidth * 3.821
                y: 0
                color: "#D9D9D9"
                Text
                {
                    font.family: "Inter"
                    font.pixelSize: 20 * 0.04 * swidth
                    text: qsTr("Секции пакета")
                }
            }
            TextEdit
            {
                id: sm_one_zone_te
                width: swidth * 90.813
                height: 0
                x: swidth * 3.821
                y: 0
            }
        }
    }

    Dialog {
        id: confirmation_dialog
        title: "Удалить?"
        standardButtons: Dialog.Ok | Dialog.Cancel
        Text {
            text:  "Вы действительно хотите удалить зону?";
        }
        onAccepted:
        {
            if (confirmation_dialog.opened)
            {
                sm_one_model_rec.destroy()
            }
        }
    }
}
