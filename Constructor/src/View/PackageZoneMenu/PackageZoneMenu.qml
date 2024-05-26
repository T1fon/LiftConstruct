import QtQuick 2.15
import QtQuick.Window
import QtQuick.Controls
import QtQuick.Dialogs
import Package_Zone_View 1.0

Rectangle
{
    id: construct_menu_window

    width: 1920
    height: 1000
    property real swidth: width / 100
    property real sheight: height / 100
    color: "#D9D9D9"
    onWindowChanged:
        ()=>
        {
            console.log("load package zones");
            package_zone_view.loadPackageZones();
        }
    Package_Zone_View{
        id: package_zone_view

        onClearPackageZone: ()=>{pzm_model.clear();}
        onAddPackageZoneSig:
            (name, color)=>
            {
                active_zone.addZoneInModel(name, color);
                white_rect.y = left_menu_listView.height;
                plus_but.y = white_rect.y + white_rect.height;
            }
    }

    Rectangle{
        id: active_zone
        visible: false
        width: construct_menu_window.width - left_rect.width
        height: construct_menu_window.height

        color: "#D9D9D9"

        function addZoneInModel(name, ccolor)
        {
            pzm_model.append({ text: name, color: ccolor });
            left_menu_listView.height += 5.556*construct_menu_window.sheight;
            left_menu_scrollview.contentHeight = left_menu_listView.height;

            if(left_menu_scrollview.contentHeight < left_menu_scrollview.height){
                white_rect.y = left_menu_listView.height;
                plus_but.y = white_rect.y + white_rect.height;
            }else{
                white_rect.y = left_menu_scrollview.y + left_menu_scrollview.height;
                plus_but.anchors.top = white_rect.bottom;
            }
        }

        Rectangle
        {
            id: zone_name
            width: construct_menu_window.swidth * 66.667
            height: construct_menu_window.sheight * 4.629
            y: construct_menu_window.sheight * 12.129
            x: construct_menu_window.swidth * 24.948
            color: "#D9D9D9"
            Rectangle
            {
                height: parent.height
                width: construct_menu_window.swidth * 5.578
                anchors.left: parent.left
                anchors.verticalCenter: parent.verticalCenter
                color: "#D9D9D9"
                Text
                {
                    id: text_name
                    font.family: "Inter"
                    font.pixelSize: 22 * 0.04 * construct_menu_window.swidth
                    text: qsTr("Имя зоны")
                }
            }
            Rectangle
            {
                height: parent.height
                width: construct_menu_window.swidth * 29.323
                anchors.right: parent.right
                color: "white"
                border.color: "black"
                border.width: 1
                TextInput
                {
                    id: input_name
                    height: parent.height
                    width: parent.width
                    font.family: "Inter"
                    font.pixelSize: 22 * 0.04 * construct_menu_window.swidth
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    text: ""
                    enabled: false
                }
            }
        }

        Rectangle
        {
            id: zone_color
            width: construct_menu_window.swidth * 66.667
            height: construct_menu_window.sheight * 4.629
            y: construct_menu_window.sheight * 21.481
            x: construct_menu_window.swidth * 24.948
            color: "#D9D9D9"

            Rectangle
            {
                height: parent.height
                width: construct_menu_window.swidth * 5.578
                anchors.left: parent.left
                color: "#D9D9D9"
                Text
                {
                    id: color_name
                    font.family: "Inter"
                    font.pixelSize: 22 * 0.04 * construct_menu_window.swidth
                    text: qsTr("Цвет")
                }
            }

            Rectangle
            {
                id: color_box
                height: parent.height
                width: construct_menu_window.swidth * 3.147
                anchors.right: parent.right
                color: "#ff0000"
                border.color: "black"
                border.width: 1
                enabled: false

                MouseArea
                {
                    anchors.fill: parent
                    onClicked: {
                        colorDialog.open()
                    }
                }

                ColorDialog
                {
                    id: colorDialog
                    onAccepted: {
                        color_box.color = colorDialog.selectedColor
                    }
                }
            }
        }

        Dialog {
            id: warning_dialog
            title: "Ошибка?"
            standardButtons: Dialog.Ok
            Text {
                text:  "Измените цвет (не черный) или впишите имя";
            }
            onAccepted:
            {

            }
        }

        Button {
            id: save_zone
            height: construct_menu_window.sheight * 5.556
            width: construct_menu_window.swidth * 14.063
            x: construct_menu_window.swidth * 24.948
            y: construct_menu_window.sheight * 77.685
            text: "Сохранить"
            enabled: false
            onClicked:
            {
                if(input_name.text ===  " " || color_box.color === "#000000")
                {
                    warning_dialog.open()
                    return;
                }
                active_zone.visible = false;

                console.log(input_name.text)
                console.log(color_box.color)
                var newItem = { text: input_name.text, color: color_box.color };
                var itemIndex = -1;

                for (var i = 0; i < pzm_model.count; ++i) {
                    if (pzm_model.get(i).text === input_name.text)
                    {
                        itemIndex = i;
                        break;
                    }
                }

                if (itemIndex !== -1)
                {
                    package_zone_view.changePackageZone(input_name.text, color_box.color);
                    pzm_model.set(itemIndex, newItem);
                }
                else
                {
                    active_zone.addZoneInModel(input_name.text, color_box.color);
                    package_zone_view.addPackageZone(input_name.text, color_box.color);
                }
                input_name.text = "";
                color_box.color = "black";
                left_menu_listView.currentIndex = -1;
                color_box.enabled = false;
                input_name.enabled = false;
                save_zone.enabled = false;
            }
        }


        Dialog {
            id: confirmation_dialog
            title: "Удалить?"
            standardButtons: Dialog.Ok | Dialog.Cancel
            Text {
                text:  "Вы действительно хотите удалить '" + input_name.text + "'?";
            }
            onAccepted:
            {
                if (confirmation_dialog.opened)
                {
                    var selectedIdx = left_menu_listView.currentIndex;
                    package_zone_view.deletePackageZone(pzm_model.get(selectedIdx).text);
                    left_menu_listView.model.remove(selectedIdx);

                    left_menu_listView.height -= 5.556*construct_menu_window.sheight;
                    left_menu_scrollview.contentHeight = left_menu_listView.height;
                    left_menu_listView.contentHeight = left_menu_listView.height;
                    if(left_menu_scrollview.contentHeight < left_menu_scrollview.height){
                        white_rect.y = left_menu_listView.contentHeight;
                        plus_but.y = white_rect.y + white_rect.height;
                    }
                    active_zone.visible = false;

                }
            }
        }

        Button {
            id: delete_zone
            height: sheight * 5.556
            width: swidth * 14.063
            x: swidth * 77.552
            y: sheight * 77.685
            text: "Удалить"
            enabled: false
            onClicked:
            {
                var selectedIdx = left_menu_listView.currentIndex
                if (selectedIdx >= 0 && selectedIdx < left_menu_listView.model.count) {
                    confirmation_dialog.open();
                }
                delete_zone.enabled = false;
            }
        }
    }
    Rectangle
    {
        id: left_rect
        width: construct_menu_window.swidth * 17.188
        height: parent.height
        anchors.left: parent.left
        color: "#D9D9D9"

        Flickable
        {
            id: left_menu_scrollview
            height: parent.height - construct_menu_window.sheight*15
            width: construct_menu_window.swidth * 17.188
            anchors.right : parent.right
            anchors.top: parent.top
            ScrollBar.vertical: ScrollBar {
                id:left_menu_scrollview_scrollbar
                policy: ScrollBar.AlwaysOn
                active: true
            }

            contentHeight: height
            contentWidth: width

            clip: true

            ListView
            {
                id: left_menu_listView
                width: parent.width

                model: ListModel
                {
                    id: pzm_model
                }
                delegate: Rectangle
                {
                    width: left_menu_listView.width - left_menu_scrollview_scrollbar.width
                    height: construct_menu_window.sheight * 5.556
                    color: model.color
                    border.color: "black"
                    border.width: (left_menu_listView.currentIndex === index) ? 2 : 0

                    Text
                    {
                        text: model.text
                        anchors.centerIn: parent
                        font.family: "Inter"
                        font.pointSize: 20 * construct_menu_window.swidth * 0.035
                    }
                    MouseArea
                    {
                        anchors.fill: parent
                        onClicked:
                        {
                            input_name.text = model.text;
                            color_box.color = model.color;
                            left_menu_listView.currentIndex = index;
                            color_box.enabled = true;
                            delete_zone.enabled = true;
                            active_zone.visible = true;
                            save_zone.enabled = true;
                        }
                    }

                }
            }

            onContentHeightChanged: {
                if (left_menu_scrollview.flickableItem !== undefined) {
                    if (left_menu_scrollview.contentHeight > left_menu_scrollview.height) {
                        left_menu_scrollview.flickableItem.interactive = true;
                    } else {
                        left_menu_scrollview.flickableItem.interactive = false;
                    }
                }
            }

        }
        Rectangle
        {
            id: white_rect
            width: left_menu_scrollview.width - left_menu_scrollview_scrollbar.width
            height: construct_menu_window.sheight * 0.9
            color: "white"
            x: left_menu_listView.height
            anchors.left: parent.left
        }
        Button
        {
            id: plus_but
            width: construct_menu_window.swidth * 2.604
            height: construct_menu_window.sheight * 5.37
            x: construct_menu_window.swidth * 6.51
            y: left_menu_listView.contentHeight + white_rect.height
            text: "+"

            font.pointSize: 48 * construct_menu_window.swidth * 0.03
            onClicked:
            {
                active_zone.visible = true
                input_name.enabled = true
                input_name.text = ""
                color_box.enabled = true
                color_box.color = "black"
                save_zone.enabled = true
            }
        }
    }








}

