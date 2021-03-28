import QtQuick 2.12
import QtQuick.Controls 2.15

Item {
    width: 90
    height: 90
    property alias text1Text: text1.text
    property alias  rectangleColor:  rectangle.color
    Rectangle {
        id: rectangle
        width: 90
        height: 90
        color: "#d7ccb8"
        radius: 10
        border.width: 0

        Text {
            id: text1
            x: 34
            y: 38
            text: qsTr("")
            anchors.verticalCenter: parent.verticalCenter
            font.pixelSize: 50
            font.family: "Verdana"
            minimumPixelSize: 30
            anchors.horizontalCenter: parent.horizontalCenter
        }
    }

}

