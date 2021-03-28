import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.15

Window {
    id: window
    width: 400
    height: 400
    visible: true
    color: "#959090"
    title: qsTr("Jeu2048")




    Component{
        id: gameView
        Grid {
            id: grid
            x: 94
            y: 161
            width: 380
            height: 380

            spacing: 8
            topPadding: 9
            leftPadding: 9
            padding: 0
            rows: 4
            columns: 4

            focus: true
            Repeater{
                model: 16
                delegate:Case {
                    rectangleColor: vueObjetCpt.ColorQML[index]
                    text1Text: vueObjetCpt.ValuesQML[index]
                }
            }
            Keys.onPressed: {
                if(vueObjetCpt.GamecheckQML==="true"){
                    switch(event.key){
                        case Qt.Key_Up:
                            vueObjetCpt.up();
                            break;
                        case Qt.Key_Down:
                            vueObjetCpt.down();
                            break;
                        case Qt.Key_Left:
                            vueObjetCpt.left();
                            break;
                        case Qt.Key_Right:
                            vueObjetCpt.right();
                            break;
                    }

                }
                else{
                    stack.push('lostView.qml')
                }
            }
        }
    }

    StackView{
        id: stack
        anchors.fill: parent
        initialItem: "startView.qml"
        pushEnter: Transition {
            PropertyAnimation {
                property: "opacity"
                from: 0
                to:1
                duration: 200
            }
        }
        pushExit: Transition {
            PropertyAnimation {
                property: "opacity"
                from: 1
                to:0
                duration: 200
            }
        }
        popEnter: Transition {
            PropertyAnimation {
                property: "opacity"
                from: 0
                to:1
                duration: 200
            }
        }
        popExit: Transition {
            PropertyAnimation {
                property: "opacity"
                from: 1
                to:0
                duration: 200
            }
        }
    }
}


