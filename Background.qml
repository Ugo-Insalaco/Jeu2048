import QtQuick 2.12

Item {
    width: 400
    height: 400
    Grid {
        id: grid
        anchors.fill: parent

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
            }
        }
    }
}
