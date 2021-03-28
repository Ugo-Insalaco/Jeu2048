import QtQuick 2.12
import QtQuick.Controls 2.15

Item {
    visible: true
    Background{}
    Rectangle {
        id: rectangle
        color: "#7bd19c9c"
        anchors.fill: parent

        Rectangle {
            id: rectangle1
            width: 200
            height: 50
            color: "#efd083"
            radius: 5
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter

            Text {
                id: text1
                text: qsTr("Commencer")
                anchors.fill: parent
                font.pixelSize: 20
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.family: "Verdana"
            }

            Button {
                x: 0
                y: 0
                width: 200
                height: 50
                opacity: 0
                visible: true
                text: "Commencer"
                checkable: false
                display: AbstractButton.TextOnly
                layer.format: ShaderEffectSource.RGBA
                onClicked: stack.push(gameView)
            }
        }

        Text {
            id: text2
            x: 100
            y: 47
            text: qsTr("2048")
            font.pixelSize: 30
            anchors.horizontalCenterOffset: 0
            font.family: "Verdana"
            anchors.horizontalCenter: parent.horizontalCenter
        }

        Text {
            id: text3
            x: 182
            y: 121
            color: "#ffffff"
            text: qsTr("Par Mengqian Zou et Ugo Insalaco")
            font.pixelSize: 15
            anchors.horizontalCenterOffset: 0
            anchors.horizontalCenter: parent.horizontalCenter
            font.family: "Verdana"
        }
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:400;width:400}
}
##^##*/
