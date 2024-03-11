import QtQuick
import QtQuick.Window
import QtQuick.Controls
import "View/ConstructMenu"
import "View/PackageZoneMenu"
import "View/StationMenu"

Window
{
    width: 1920
    height: 1080
    visible: true
    property real swidth: this.width / 100
    property real sheight: this.height / 100
    Rectangle
    {
        id: help_and_fail_menu
        width: parent.width
        height: sheight * 3.704
        anchors.top: parent.top
        color: "#E9E9E9"
        ComboBox
        {
            height: parent.height
            width: swidth * 7.813
            anchors.left: parent.left
            id: fail_box

            background: Rectangle
            {
                color: "#D9D9D9"
                border.width: 1
                border.color: "black"
            }

            model: ListModel
            {
                id: fail_model
                ListElement { text: "Файл" }
                ListElement { text: "Открыть" }
                ListElement { text: "Закрыть" }
                ListElement { text: "Сохранить" }
                ListElement { text: "Сохранить как" }
                ListElement { text: "Экспортировать" }

            }
            onActivated:
            {
                   if (currentIndex !== 0) {
                       console.log("Выбран элемент:", currentItem.text);
                       fail_box.text = "Файл"; // Установка текста ComboBox обратно на "Файл"
                   }
               }

            delegate: Text
            {
                text: model.text
                width: parent.width
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                padding: 5
            }
        }

        Button
        {
            id: help_button;
            height: parent.height
            width: swidth * 7.813
            x: swidth * 7.813
            text: "Помощь"
            background: Rectangle
            {
                color: "#D9D9D9"
                border.color: "black"
                border.width: 1
            }
        }
    }
    Rectangle
    {
        id: widows_buttons
        width: parent.width
        height: sheight * 3.704
        y: sheight * 3.704
        anchors.left: parent.left
        color: "#E9E9E9"
        Button
        {
            id:construct_menu_button
            height: parent.height
            width: swidth * 12.5

            text: "Конструктор"
            contentItem: Text
            {
               text: construct_menu_button.text
               font: construct_menu_button.font
               color: "black"
               horizontalAlignment: Text.AlignHCenter
               verticalAlignment: Text.AlignVCenter
               elide: Text.ElideRight
           }

               background: Rectangle
               {
                   id: construct_menu_button_rec
                   color: "#D9D9D9"
                   border.color: "black"
                   border.width: 1
                   radius: 2
               }
            onClicked:
            {
                loader.source = "View/ConstructMenu/ConstructMenu.qml";
                construct_menu_button.enabled = false
                packet_zone_button.enabled = true
                station_zone_button.enabled = true
                package_zone_button.enabled = true
                test_zone_button.enabled = true
                emulator_zone_button.enabled = true

                construct_menu_button_rec.border.color = "#D9D9D9"
                packet_zone_button_rec.border.color = "black"
                station_zone_button_rec.border.color = "black"
                package_zone_button_rec.border.color = "black"
                test_zone_button_rec.border.color = "black"
                emulator_zone_button_rec.border.color = "black"
            }
        }
        Button
        {
            id: packet_zone_button
            height: parent.height
            width: swidth * 12.5
            x: swidth * 12.5
            text: "Зон пакетов"
            contentItem: Text
            {
               text: packet_zone_button.text
               font: packet_zone_button.font
               //opacity: enabled ? 1.0 : 0.3
               color: "black"
               horizontalAlignment: Text.AlignHCenter
               verticalAlignment: Text.AlignVCenter
               elide: Text.ElideRight
           }

           background: Rectangle
           {
               id: packet_zone_button_rec
               color: "#D9D9D9"
               //opacity: enabled ? 1 : 0.3
               border.color: "black"
               border.width: 1
               radius: 2
               Behavior on border.color
               {
                    ColorAnimation { duration: 100 }
                }
           }
            onClicked:
            {
                loader.source = "View/PackageZoneMenu/PackageZoneMenu.qml";
                construct_menu_button.enabled = true
                packet_zone_button.enabled = false
                station_zone_button.enabled = true
                package_zone_button.enabled = true
                test_zone_button.enabled = true
                emulator_zone_button.enabled = true

                construct_menu_button_rec.border.color = "black"
                packet_zone_button_rec.border.color = "#D9D9D9"
                station_zone_button_rec.border.color = "black"
                package_zone_button_rec.border.color = "black"
                test_zone_button_rec.border.color = "black"
                emulator_zone_button_rec.border.color = "black"
            }

        }
        Button
        {
           id: station_zone_button
           height: parent.height
           width: swidth * 18.385
           x:swidth * 25
           text: "Станций"
           contentItem: Text
           {
              text: station_zone_button.text
              font: station_zone_button.font
              color: "black"
              horizontalAlignment: Text.AlignHCenter
              verticalAlignment: Text.AlignVCenter
              elide: Text.ElideRight
          }

              background: Rectangle
              {
                  id: station_zone_button_rec
                  color: "#D9D9D9"
                  border.color: "black"
                  border.width: 1
                  radius: 2
              }
           onClicked:
           {
               loader.source = "View/StationMenu/StationMenu.qml";
               construct_menu_button.enabled = true
               packet_zone_button.enabled = true
               station_zone_button.enabled = false
               package_zone_button.enabled = true
               test_zone_button.enabled = true
               emulator_zone_button.enabled = true

               construct_menu_button_rec.border.color = "black"
               packet_zone_button_rec.border.color = "black"
               station_zone_button_rec.border.color = "#D9D9D9"
               package_zone_button_rec.border.color = "black"
               test_zone_button_rec.border.color = "black"
               emulator_zone_button_rec.border.color = "black"
           }
        }
        Button
        {
           id: package_zone_button
           height: parent.height
           width: swidth * 12.5
           x:swidth * 43.385
           text: "Пакетов"
           contentItem: Text
           {
              text: package_zone_button.text
              font: package_zone_button.font
              color: "black"
              horizontalAlignment: Text.AlignHCenter
              verticalAlignment: Text.AlignVCenter
              elide: Text.ElideRight
            }

              background: Rectangle
              {
                  id: package_zone_button_rec
                  color: "#D9D9D9"
                  border.color: "black"
                  border.width: 1
                  radius: 2
              }
              onClicked:
              {
                  loader.source = "View/PackageConstructMenu/PackageConstructMenu.qml";
                  construct_menu_button.enabled = true
                  packet_zone_button.enabled = true
                  station_zone_button.enabled = true
                  package_zone_button.enabled = false
                  test_zone_button.enabled = true
                  emulator_zone_button.enabled = true

                  construct_menu_button_rec.border.color = "black"
                  packet_zone_button_rec.border.color = "black"
                  station_zone_button_rec.border.color = "black"
                  package_zone_button_rec.border.color = "#D9D9D9"
                  test_zone_button_rec.border.color = "black"
                  emulator_zone_button_rec.border.color = "black"
              }
        }
        Button
        {
           id: test_zone_button
           height: parent.height
           width: swidth * 12.5
           x:swidth * 55.885
           text: "Тестов"
           contentItem: Text
           {
              text: test_zone_button.text
              font: test_zone_button.font
              color: "black"
              horizontalAlignment: Text.AlignHCenter
              verticalAlignment: Text.AlignVCenter
              elide: Text.ElideRight
            }

              background: Rectangle
              {
                  id: test_zone_button_rec
                  color: "#D9D9D9"
                  border.color: "black"
                  border.width: 1
                  radius: 2
              }
              onClicked:
              {
                  loader.source = "View/TestConstructMenu/TestConstructMenu.qml";
                  construct_menu_button.enabled = true
                  packet_zone_button.enabled = true
                  station_zone_button.enabled = true
                  package_zone_button.enabled = true
                  test_zone_button.enabled = false
                  emulator_zone_button.enabled = true

                  construct_menu_button_rec.border.color = "black"
                  packet_zone_button_rec.border.color = "black"
                  station_zone_button_rec.border.color = "black"
                  package_zone_button_rec.border.color = "black"
                  test_zone_button_rec.border.color = "#D9D9D9"
                  emulator_zone_button_rec.border.color = "black"
              }

        }
        Button
        {
           id: emulator_zone_button
           height: parent.height
           width: swidth * 12.5
           x:swidth * 68.385
           text: "Эмулятор"
           contentItem: Text
           {
              text: emulator_zone_button.text
              font: emulator_zone_button.font
              color: "black"
              horizontalAlignment: Text.AlignHCenter
              verticalAlignment: Text.AlignVCenter
              elide: Text.ElideRight
            }
           background: Rectangle
           {
               id: emulator_zone_button_rec
               color: "#D9D9D9"
               border.color: "black"
               border.width: 1
               radius: 2
           }
           onClicked:
           {
               loader.source = "View/EmulatorMenu/EmulatorMenu.qml";
               construct_menu_button.enabled = true
               packet_zone_button.enabled = true
               station_zone_button.enabled = true
               package_zone_button.enabled = true
               test_zone_button.enabled = true
               emulator_zone_button.enabled = false

               construct_menu_button_rec.border.color = "black"
               packet_zone_button_rec.border.color = "black"
               station_zone_button_rec.border.color = "black"
               package_zone_button_rec.border.color = "black"
               test_zone_button_rec.border.color = "black"
               emulator_zone_button_rec.border.color = "#D9D9D9"
           }
        }
    }
    Rectangle
    {
        id: windows_zone
        width: parent.width
        height: sheight * 92.593
        y: sheight * 7.407
        color: "#F5F5F5"
        Loader
        {
            id: loader
            anchors.fill: parent
            source:  ""
        }
    }
}
