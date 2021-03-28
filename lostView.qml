import QtQuick 2.12
import QtQuick.Controls 2.15

Item {
    Background{}
    Rectangle {
        id: rectangle
        color: "#7bd19c9c"
        anchors.fill: parent
        anchors.rightMargin: 0
        anchors.bottomMargin: 0
        anchors.leftMargin: 0
        anchors.topMargin: 0
        layer.format: ShaderEffectSource.Alpha

        Text {
            id: text1
            x: 35
            y: 54
            width: 330
            height: 46
            text: qsTr("Vous avez perdu")
            font.pixelSize: 30
            horizontalAlignment: Text.AlignHCenter
            font.family: "Verdana"
        }

        Row {
            x: 0
            width: 319
            height: 52
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter
            layoutDirection: Qt.LeftToRight
            spacing: 20

            Rectangle {
                id: rectangle1
                width: 150
                height: 50
                color: "#efd083"
                radius: 6
                border.color: "#f9cb8e"

                Text {
                    id: text2
                    width: 151
                    height: 50
                    text: qsTr("Recommencer")
                    anchors.verticalCenter: parent.verticalCenter
                    font.pixelSize: 20
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    font.family: "Verdana"
                    anchors.horizontalCenter: parent.horizontalCenter
                }

                MouseArea {
                    id: mouseArea
                    x: 0
                    y: 0
                    width: 151
                    height: 50
                    onClicked: {
                        vueObjetCpt.restart();
                        stack.pop()
                    }
                }
            }

            Rectangle {
                id: rectangle2
                width: 150
                height: 50
                color: "#efd083"
                radius: 5

                Text {
                    id: text3
                    x: -171
                    y: 0
                    width: 151
                    height: 50
                    text: qsTr("Quitter")
                    anchors.verticalCenter: parent.verticalCenter
                    font.pixelSize: 20
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    anchors.horizontalCenter: parent.horizontalCenter
                    font.family: "Verdana"
                }

                MouseArea {
                    id: mouseArea1
                    x: 0
                    y: 0
                    width: 151
                    height: 50
                    onClicked: Qt.quit();
                }

            }
        }

        Text {
            id: text4
            x: 40
            y: 98
            width: 319
            height: 31
            text: qsTr("Votre score est de :")
            font.pixelSize: 20
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
        }

        Text {
            id: text5
            x: 108
            y: 129
            width: 184
            height: 39
            text: qsTr(vueObjetCpt.ScoreQML)
            font.pixelSize: 20
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
        }
    }
}
