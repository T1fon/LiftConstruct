import QtQuick 2.15
import QtQuick.Window
import QtQuick.Controls
import QtQuick.Dialogs 1.3

Rectangle
{
    id: package_zone_construct_menu_rec
    width: 1920
    height: 1080
    property real sheight: height / 100
    property real swidth: width / 100
    ScrollView
    {
        id: pcm_left_menu_scrollview
        height: parent.height
        width: swidth * 1.563
        x: swidth * 15.625
        ListView
        {
            id: pcm_zone_storage_listview
            width: swidth * 15.625
            height: parent.height
            anchors.right: parent.left
            model: ListModel
            {

            }
            delegate: Rectangle
            {
                width: pcm_zone_storage_listview.width
                height: sheight * 5.556
                color: model.color
                Rectangle
                {
                    height: parent.height
                    width: parent.width
                    anchors.left: parent.left
                    Text {
                        text: model.name
                    }
                }
                Rectangle
                {
                    height: parent.height
                    width: parent.width
                    anchors.right: parent.right
                    color: model.color
                }
                MouseArea
                {
                    anchors.fill: parent
                    onClicked:
                    {
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
        x: swidth * 82.813
        Button
        {
            id: pcm_add_button
            width: swidth * 14.063
            height: sheight * 5.556
            x: swidth * 83.646
            y: sheight * 9.815
            text: "Добавить"
            onClicked:
            {
                pcm_add_button.visible = false;
                pcm_add_button.enabled = false;
                pcm_save_button.visible = true;
                pcm_save_button.enabled = true;
                pcm_middle_menu_rec.visible = true;
                pcm_middle_menu_rec.enabled = true;
                pcm_lift_name = "";
                pcm_packadge_name = "";
            }
        }
        Button
        {
            id: pcm_save_button
            width: swidth * 14.063
            height: sheight * 5.556
            x: swidth * 83.646
            y: sheight * 9.815
            text: "Сохранить"
            visible: false
            enabled: false
        }
        Button
        {
            id: pcm_change_button
            width: swidth * 14.063
            height: sheight * 5.556
            x: swidth * 83.646
            y: sheight * 18.148
            text: "Изменить"
        }
        Button
        {
            id: pcm_insert_button
            width: swidth * 14.063
            height: sheight * 5.556
            x: swidth * 83.646
            y: sheight * 26.481
            text: "вставить"
        }
        Button
        {
            id: pcm_delete_button
            width: swidth * 14.063
            height: sheight * 5.556
            x: swidth * 83.646
            y: sheight * 34815
            text: "Удалить"
        }
    }
    ScrollView
    {
        id: pcm_middle_menu_scrollview
        height: parent.height
        width: swidth * 1.563
        x: swidth * 64.063
        Rectangle
        {
            id: pcm_middle_menu_rec
            width: swidth * 64.063
            height: parent.height
            x: swidth * 17.188
            visible: false
            enabled: false
            Rectangle
            {
                id: pcm_upper_boxes_menu_rec
                width: parent.width
                height: sheight * 29.444
                x: swidth * 17.188
                y: sheight * 7.407

                Rectangle
                {
                    id: pcm_lift_name_rec
                    width: swidth * 58.698
                    height: sheight * 4.629
                    x: swidth * 21.51
                    y: sheight * 11.667
                    Rectangle
                    {
                        width: swidth * 14.409
                        height: sheight * 2.5
                        x: swidth * 21.51
                        y: sheight * 12.685
                        Text
                        {
                            text: qsTr("Наименование лифта")
                        }
                    }
                    TextInput
                    {
                        id: pcm_lift_name
                        width: swidth * 24.884
                        height: parent.height
                        anchors.right: parent.right
                    }
                }
                Rectangle
                {
                    id: pcm_packadge_name_rec
                    width: swidth * 58.698
                    height: sheight * 4.629
                    x: swidth * 21.51
                    y: sheight * 19.907
                    Rectangle
                    {
                        width: swidth * 14.409
                        height: sheight * 2.5
                        x: swidth * 21.51
                        y: sheight * 20.926
                        Text
                        {
                            text: qsTr("Название пакета")
                        }
                    }
                    TextInput
                    {
                        id: pcm_packadge_name
                        width: swidth * 24.884
                        height: parent.height
                        anchors.right: parent.right
                    }
                }
                Rectangle
                {
                    id: pcm_packadge_type_rec
                    width: swidth * 58.698
                    height: sheight * 4.629
                    x: swidth * 21.51
                    y: sheight * 28.148
                    Rectangle
                    {
                        width: swidth * 14.409
                        height: sheight * 2.5
                        x: swidth * 23.5
                        y: sheight * 29.167
                        Text
                        {
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
        //как их добавлять пока хз, и зоны тоже, нужно посоветоваться, предположительно через listview и там и там
        Rectangle
        {
            id: pcm_zones_menu_title_rec
            width: swidth * 64.063
            height: sheight * 4.629
            anchors.top: pcm_upper_boxes_menu_rec.bottom
        }
        Rectangle
        {
            id: pcm_packadge_view_title_rec
            width: swidth * 64.063
            height: sheight * 4.629
            anchors.top: pcm_zones_menu_rec.bottom
            Rectangle
            {
                //как настроить без смещения через anchors я не понял
                width: swidth * 7.813
                height: sheight * 2.222
                Text
                {
                    text: qsTr("Обзор всего пакета")
                }
            }
            CheckBox
            {
                id: show_packadge_view
                width: swidth * 1.302
                height: sheight * 2.315
                checked: false
                onCheckedChanged:
                {
                    pcm_packadge_view_rec.state === "closed" ? pcm_packadge_view_rec.state = "opened" : pcm_packadge_view_rec.state = "closed";
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
        }
        Rectangle
        {
            id: pcm_packadge_view_rec
            width: swidth * 64.063
            height: 0
            anchors.top: pcm_packadge_view_title_rec.bottom
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
            /*transitions: Transition
            {
                NumberAnimation
                {
                    properties: "height"
                    duration: 300
                    easing.type: Easing.InOutQuad
                }
            }*/
            Rectangle
            {
                //через что задать табличку пока не придумал
            }
        }
        Rectangle
        {
            id: pcm_packadge_discript_title_rec
            width: swidth * 64.063
            height: sheight * 4.629
            anchors.top: pcm_packadge_view_rec.bottom
            Rectangle
            {
                //как настроить без смещения через anchors я не понял
                width: swidth * 7.813
                height: sheight * 2.222
                Text
                {
                    text: qsTr("Описание пакета")
                }
            }
            CheckBox
            {
                id: show_packadge_discript
                width: swidth * 1.302
                height: sheight * 2.315
                checked: false
                onCheckedChanged:
                {
                    pcm_packadge_discript_rec.state === "closed" ? pcm_packadge_discript_rec.state = "opened" : pcm_packadge_discript_rec.state = "closed";
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
            width: swidgth * 64.063
            height: 0
            anchors.top: pcm_packadge_discript_title_rec.bottom
            states:
                [
                State
                {
                    name: "opened"
                    PropertyChanges
                    {
                        target: pcm_packadge_discript_rec; height: sheight * 25.741
                    }
                },
                State {
                    name: "closed"
                    PropertyChanges
                    {
                        target: pcm_packadge_discript_rec; height: 0

                    }
                }
            ]
            /*transitions: Transition
            {
                NumberAnimation
                {
                    properties: "height"
                    duration: 300
                    easing.type: Easing.InOutQuad
                }
            }*/
            TextEdit
            {
                id: pcm_packadge_discript
                width: swidth * 58.177
                height: sheight * 24.537
                anchors.centerIn: parent.Center
            }
        }
    }

}
