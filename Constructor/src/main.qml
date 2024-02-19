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
            }
            model: ListModel
            {
                id: fail_model
                ListElement
                {
                    text: "Файл"
                }
                ListElement
                {
                    text: "Открыть"
                }
                ListElement
                {
                    text: "Закрыть"
                }
                ListElement
                {
                    text: "Сохранить"
                }
                ListElement
                {
                    text: "Сохранить как"
                }
                ListElement
                {
                    text: "Экспортировать"
                }
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
               opacity: enabled ? 1.0 : 0.3
               color: construct_menu_button.down ? "#D9D9D9" : "black"
               horizontalAlignment: Text.AlignHCenter
               verticalAlignment: Text.AlignVCenter
               elide: Text.ElideRight
           }

               background: Rectangle
               {
                   color: "#D9D9D9"
                   opacity: enabled ? 1 : 0.3
                   border.color: construct_menu_button.down ? "#D9D9D9" : "#E9E9E9"
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
               opacity: enabled ? 1.0 : 0.3
               color: packet_zone_button.down ? "#D9D9D9" : "black"
               horizontalAlignment: Text.AlignHCenter
               verticalAlignment: Text.AlignVCenter
               elide: Text.ElideRight
           }

           background: Rectangle
           {
               color: "#D9D9D9"
               opacity: enabled ? 1 : 0.3
               border.color: packet_zone_button.down ? "#D9D9D9" : "#E9E9E9"
               border.width: 1
               radius: 2
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
              opacity: enabled ? 1.0 : 0.3
              color: station_zone_button.down ? "#D9D9D9" : "black"
              horizontalAlignment: Text.AlignHCenter
              verticalAlignment: Text.AlignVCenter
              elide: Text.ElideRight
          }

              background: Rectangle
              {
                  color: "#D9D9D9"
                  opacity: enabled ? 1 : 0.3
                  border.color: station_zone_button.down ? "#D9D9D9" : "#E9E9E9"
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
              opacity: enabled ? 1.0 : 0.3
              color: package_zone_button.down ? "#D9D9D9" : "black"
              horizontalAlignment: Text.AlignHCenter
              verticalAlignment: Text.AlignVCenter
              elide: Text.ElideRight
            }

              background: Rectangle
              {
                  color: "#D9D9D9"
                  opacity: enabled ? 1 : 0.3
                  border.color: package_zone_button.down ? "#D9D9D9" : "#E9E9E9"
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
              opacity: enabled ? 1.0 : 0.3
              color: test_zone_button.down ? "#D9D9D9" : "black"
              horizontalAlignment: Text.AlignHCenter
              verticalAlignment: Text.AlignVCenter
              elide: Text.ElideRight
            }

              background: Rectangle
              {
                  color: "#D9D9D9"
                  opacity: enabled ? 1 : 0.3
                  border.color: test_zone_button.down ? "#D9D9D9" : "#E9E9E9"
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
              opacity: enabled ? 1.0 : 0.3
              color: emulator_zone_button.down ? "#D9D9D9" : "black"
              horizontalAlignment: Text.AlignHCenter
              verticalAlignment: Text.AlignVCenter
              elide: Text.ElideRight
            }
           background: Rectangle
           {
               color: "#D9D9D9"
               opacity: enabled ? 1 : 0.3
               border.color: emulator_zone_button.down ? "#D9D9D9" : "#E9E9E9"
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
