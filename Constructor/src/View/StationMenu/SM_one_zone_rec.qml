import QtQuick 2.15
import QtQuick.Window
import QtQuick.Controls
import QtQuick.Dialogs


Rectangle
{
    property var sendDataToSMfOZR: undefined
    id: sm_one_zone_main_rec
    width: 1230
    height: 700
    property int sheight: height / 100
    property int swidth: width / 100
    property int number_zone: 1
    property int number_lines: 1
    property int counter: 1
    color: "#D9D9D9"
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
            x: swidth * 0.731
            anchors.verticalCenter: parent.verticalCenter
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
                font.pixelSize: 20 * 0.08 * swidth
                text: qsTr("Вид пакета ") + qsTr(number_zone.toString())
            }
        }
        Button
        {
            id: package_viev_settings_button
            width: swidth * 2.033
            height: sheight * 3.428
            x: swidth * 95
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
            x: swidth * 98
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
            //source: show_package_view_rec.checked ? "../../arrows_down.png" : "../../arrows_up.png"
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
                        height: sheight * 24.083
                        y: ozr_section_title.height + ozr_section_title.y + sheight * 3
                    }
                    PropertyChanges
                    {
                        target: ozr_line;
                        height: 1;
                        y: ozr_section_scrolview.y + ozr_section_scrolview.height
                    }
                    PropertyChanges
                    {
                        target: ozr_description;
                        height: 0;
                        y: ozr_line.height + ozr_line.y + sheight * 3;
                    }
                    PropertyChanges
                    {
                        target: sm_one_zone_te_rec;
                        height: sheight * 37.857
                        y: ozr_description.height + ozr_description.y + sheight * 3
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
                        target: sm_one_zone_te_rec;
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
                    font.pixelSize: 20 * 0.08 * swidth
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
                    height: sheight * 7.142
                    color: "#D9D9D9"
                    property real squareWidth: width / 17
                    property real squareHeight: table.height
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
                                    font.pixelSize: 24 * 0.06 * swidth
                                }
                            }
                        }
                    }
                }
                ListView
                {
                    width: parent.width
                    anchors.top: table.bottom
                    model: number_lines
                    height: contentHeight
                    delegate: Rectangle
                    {
                        width: parent.width
                        height: sheight * 7.142
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
                                    id: grid_rec
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
                                            console.log("Квадрат", index, "в элементе", model.index, "был нажат.")

                                            sendDataToSMfOZR(index, grid_rec.color)

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
                    font.pixelSize: 20 * 0.08 * swidth
                    text: qsTr("Описание")
                }
            }
            Rectangle
            {
                id: sm_one_zone_te_rec
                width: swidth * 90.813
                x: swidth * 3.821
                y: 0
                height: 0
                TextEdit
                {
                    id: sm_one_zone_te
                    width: parent.width
                    height: parent.height
                    anchors.centerIn: parent.Center
                }
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
    function sendDataToOZR(currentRowIndex, start_section, length_section, color)
    {
        var current_index = start_section;
        var current_row = currentRowIndex;

        while (length_section > 0) {
            if (current_index >= grid_1.columns) {
                current_index = 1;
                current_row++;
            }

            if (current_row < number_lines.count) {
                number_lines.set(current_row, {index: current_index, color: color});
            } else {
                number_lines.append({index: current_index, color: color});
            }

            current_index++;
            length_section--;
        }
    }
}
