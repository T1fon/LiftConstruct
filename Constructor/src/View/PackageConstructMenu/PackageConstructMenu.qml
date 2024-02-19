import QtQuick 2.15
import QtQuick.Window
import QtQuick.Controls
import QtQuick.Dialogs

Rectangle
{
    id: package_zone_construct_menu_rec
    width: 1920
    height: 1080
    property real sheight: height / 100
    property real swidth: width / 100
    property int number_lines: 1
    property int counter_lines: 1
    color: "#D9D9D9"
    Rectangle
    {
        height: parent.height
        width: swidth * 17.187
        anchors.left: parent.left
        anchors.top: parent.top
        color: "#D9D9D9"
        ScrollView
        {
            id: pcm_left_menu_scrollview
            height: parent.height
            width: swidth * 17.187
            anchors.right: parent.right
            anchors.top: parent.top
            ListView
            {
                id: pcm_zone_storage_listview
                width: swidth * 15.625
                height: contentHeight
                anchors.left: parent.left
                model: ListModel
                {
                    id: pcm_zone_storage_lmodel
                }
                delegate: Item
                {
                    width: pcm_zone_storage_listview.width
                    height: sheight * 5.556
                    ComboBox
                    {
                        id: pcm_zone_storage_combobox
                        model: []
                        background: Rectangle
                        {
                            width: parent.width
                            height: parent.height
                            color: "#D9D9D9"
                        }
                    }
                }
            }
        }
    }
    Rectangle
    {
        id: pcm_right_menu_rec
        width: swidth * 17.188
        height: parent.height
        anchors.right: parent.right
        color: "#D9D9D9"
        Button
        {
            id: pcm_add_button
            width: swidth * 14.063
            height: sheight * 5.556
            x: swidth * 0.833
            y: sheight * 2.407
            font.pointSize: 22 * swidth * 0.03
            text: "Добавить"
            onClicked:
            {
                pcm_add_button.visible = false;
                pcm_add_button.enabled = false;
                pcm_save_button.visible = true;
                pcm_save_button.enabled = true;
                pcm_middle_menu_rec.visible = true;
                pcm_middle_menu_rec.enabled = true;
                pcm_zones_menu_rec.enabled = true
                pcm_zones_menu_rec.visible = true
                pcm_packadge_view_title_rec.enabled = true
                pcm_packadge_view_title_rec.visible = true
                pcm_packadge_discript_title_rec.enabled = true
                pcm_packadge_discript_title_rec.visible = true
                pcm_lift_name.text = "";
                pcm_packadge_name.text = "";
            }
        }
        Button
        {
            id: pcm_save_button
            width: swidth * 14.063
            height: sheight * 5.556
            x: swidth * 0.833
            y: sheight * 2.407
            font.pointSize: 22 * swidth * 0.03
            text: "Сохранить"
            visible: false
            enabled: false
        }
        Button
        {
            id: pcm_change_button
            width: swidth * 14.063
            height: sheight * 5.556
            x: swidth * 0.833
            y: sheight * 10.74
            font.pointSize: 22 * swidth * 0.03
            text: "Изменить"
        }
        Button
        {
            id: pcm_insert_button
            width: swidth * 14.063
            height: sheight * 5.556
            x: swidth * 0.833
            y: sheight * 19.074
            font.pointSize: 22 * swidth * 0.03
            text: "Вставить"
        }
        Button
        {
            id: pcm_delete_button
            width: swidth * 14.063
            height: sheight * 5.556
            x: swidth * 0.833
            y: sheight * 27.407
            font.pointSize: 22 * swidth * 0.03
            text: "Удалить"
        }
    }
    //центр
    ScrollView
    {
        id: pcm_middle_menu_scrollview
        height: parent.height
        width: swidth * 65.625
        x: swidth * 17.187
        Rectangle
        {
            id: pcm_middle_menu_rec
            width: swidth * 64.063
            height: parent.height
            anchors.top: parent.top
            color: "#D9D9D9"
            visible: false
            enabled: false
            Rectangle
            {
                id: pcm_upper_boxes_menu_rec
                width: parent.width
                height: sheight * 29.444
                anchors.top: parent.top
                color: "#D9D9D9"
                Rectangle
                {
                    id: pcm_lift_name_rec
                    width: swidth * 58.698
                    height: sheight * 4.629
                    x: swidth * 4.323
                    y: sheight * 4.259
                    color: "#D9D9D9"
                    Rectangle
                    {
                        width: swidth * 14.409
                        height: sheight * 2.5
                        anchors.left: parent.left
                        anchors.verticalCenter: parent.verticalCenter
                        color: "#D9D9D9"
                        Text
                        {
                            font.family: "Inter"
                            font.pixelSize: 22 * 0.04 * swidth
                            text: qsTr("Наименование лифта")
                        }
                    }
                    Rectangle
                    {
                        width: swidth * 24.884
                        height: parent.height
                        anchors.right: parent.right
                        TextInput
                        {
                            id: pcm_lift_name
                            width: parent.width
                            height: parent.height
                            anchors.right: parent.right
                            font.family: "Inter"
                            font.pixelSize: 22 * 0.04 * swidth
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                        }
                    }
                }
                Rectangle
                {
                    id: pcm_packadge_name_rec
                    width: swidth * 58.698
                    height: sheight * 4.629
                    x: swidth * 4.323
                    y: sheight * 12.5
                    color: "#D9D9D9"
                    Rectangle
                    {
                        width: swidth * 14.409
                        height: sheight * 2.5
                        x: swidth * 21.51
                        y: sheight * 20.926
                        anchors.left: parent.left
                        anchors.verticalCenter: parent.verticalCenter
                        color: "#D9D9D9"
                        Text
                        {
                            font.family: "Inter"
                            font.pixelSize: 22 * 0.04 * swidth
                            text: qsTr("Название пакета")
                        }
                    }
                    Rectangle
                    {
                        width: swidth * 24.884
                        height: parent.height
                        anchors.right: parent.right
                        TextInput
                        {
                            id: pcm_packadge_name
                            width: parent.width
                            height: parent.height
                            anchors.right: parent.right
                            font.family: "Inter"
                            font.pixelSize: 22 * 0.04 * swidth
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                        }
                    }
                }
                Rectangle
                {
                    id: pcm_packadge_type_rec
                    width: swidth * 58.698
                    height: sheight * 4.629
                    x: swidth * 4.323
                    y: sheight * 20.74
                    color: "#D9D9D9"
                    Rectangle
                    {
                        width: swidth * 14.409
                        height: sheight * 2.5
                        x: swidth * 23.5
                        y: sheight * 29.167
                        anchors.left: parent.left
                        anchors.verticalCenter: parent.verticalCenter
                        color: "#D9D9D9"
                        Text
                        {
                            font.family: "Inter"
                            font.pixelSize: 22 * 0.04 * swidth
                            text: qsTr("Тип пакета")
                        }
                    }
                    ListView
                    {
                        id: pcm_packadge_type_listView
                        width: swidth * 24.884
                        height: parent.height
                        anchors.right: parent.right
                        model: ListModel
                        {
                            id: pcm_packadge_type
                        }
                    }
                }
            }
        }
        Rectangle
        {
            id: pcm_zones_menu_rec
            width: parent.width
            height: sheight * 20
            y: sheight * 29.444
            color: "red"
            enabled: false
            visible: false
            //здесь лежит listview в который пихнуть надо зоны от их кол-ва
        }
        Rectangle
        {
            id: pcm_packadge_view_title_rec
            width: parent.width
            height: sheight * 4.629
            y: pcm_zones_menu_rec.y + pcm_zones_menu_rec.height
            border.color: "black"
            border.width: 2
            color: "#A0A0A0"
            enabled: false
            visible: false
            Rectangle
            {
                width: swidth * 7.813
                height: sheight * 2.222
                anchors.left: parent.left
                anchors.verticalCenter: parent.verticalCenter
                color: "#A0A0A0"
                Text
                {
                    font.family: "Inter"
                    font.pixelSize: 20 * 0.04 * swidth
                    text: qsTr("Обзор всего пакета")
                }
            }
            CheckBox
            {
                id: show_packadge_view
                width: swidth * 1.302
                height: sheight * 2.315
                anchors.right: parent.right
                anchors.verticalCenter: parent.verticalCenter
                checked: false
                onCheckedChanged:
                {
                    pcm_packadge_view_rec.state === "opened" ? pcm_packadge_view_rec.state = "closed" : pcm_packadge_view_rec.state = "opened";
                }
            }
            Image
            {
                width: swidth * 1.302
                height: sheight * 2.315
                anchors.verticalCenter: show_packadge_view.verticalCenter
                source: show_packadge_view.checked ? "../../arrows_down.png" : "../../arrows_up.png"
                //visible: !show_packadge_view.indeterminate || !show_packadge_view.checked
            }
            Rectangle
            {
                id: pcm_packadge_view_rec
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
                            target: pcm_packadge_view_rec; height: sheight * 25.741
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
                    width: parent.width
                    height: parent.height
                    color: "#D9D9D9"
                    y: sheight * 4.907
                    ScrollView
                    {
                        width: parent.width
                        height: parent.height
                        Rectangle
                        {
                            id: table
                            anchors.top: parent.top
                            width: swidth * 58.177
                            height: sheight * 7
                            x: swidth * 3.021
                            y: sheight * 4.907
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
                            width: swidth * 58.177
                            y: table.y + table.height
                            x: swidth * 3.021
                            model: number_lines //вводить кол-во строк отсюда
                            delegate: Rectangle
                            {
                                width: parent.width
                                height: sheight * 7
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
                                               text: index === 0 ? counter_lines.toString() : ""
                                                color: "black"
                                                font.family: "Inter"
                                                font.pixelSize: 24 * 0.04 * swidth
                                                onTextChanged:
                                                {
                                                    if (text !== "")
                                                        counter_lines += 1
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
                    }
                }
            }
        }
        Rectangle
        {
            id: pcm_packadge_discript_title_rec
            width: parent.width
            height: sheight * 4.629
            y: pcm_packadge_view_title_rec.y + pcm_packadge_view_title_rec.height + pcm_packadge_view_rec.height
            border.color: "black"
            border.width: 2
            color: "#A0A0A0"
            enabled: false
            visible: false
            Rectangle
            {
                width: swidth * 7.813
                height: sheight * 2.222
                anchors.left: parent.left
                anchors.verticalCenter: parent.verticalCenter
                color: "#A0A0A0"
                Text
                {
                    font.family: "Inter"
                    font.pixelSize: 20 * 0.04 * swidth
                    text: qsTr("Описание пакета")
                }
            }
            CheckBox
            {
                id: show_packadge_discript
                width: swidth * 1.302
                height: sheight * 2.315
                anchors.right: parent.right
                anchors.verticalCenter: parent.verticalCenter
                checked: false
                onCheckedChanged:
                {
                    pcm_packadge_discript_rec.state === "opened" ? pcm_packadge_discript_rec.state = "closed" : pcm_packadge_discript_rec.state = "opened";
                }
            }
            Image
            {
                width: swidth * 1.302
                height: sheight * 2.315
                anchors.verticalCenter: show_packadge_discript.verticalCenter
                source: show_packadge_discript.checked ? "../../arrows_down.png" : "../../arrows_up.png"
                //visible: !show_packadge_discript.indeterminate || !show_packadge_view.checked
            }
        }
        Rectangle
        {
            id: pcm_packadge_discript_rec
            width: swidth * 64.063
            height: 0
            anchors.top: pcm_packadge_discript_title_rec.bottom
            color: "#D9D9D9"
            states:
                [
                State
                {
                    name: "opened"
                    PropertyChanges
                    {
                        target: pcm_packadge_discript_rec;
                        height: sheight * 30
                    }
                    PropertyChanges
                    {
                        target: pcm_packadge_discript_text_rec;
                        height: sheight * 24.537
                        y: sheight * 3.518
                    }
                },
                State {
                    name: "closed"
                    PropertyChanges
                    {
                        target: pcm_packadge_discript_rec;
                        height: 0
                    }
                    PropertyChanges
                    {
                        target: pcm_packadge_discript_text_rec;
                        height: 0
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
                id: pcm_packadge_discript_text_rec
                width: swidth * 58.177
                height: 0
                y: 0
                x: swidth * 3.021
                TextEdit
                {
                    id: pcm_packadge_discript
                    width: parent.width
                    height: parent.height
                    anchors.top: parent.top
                }
            }
        }
    }
}
