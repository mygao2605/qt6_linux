import QtQuick
import QtQuick.Window

Window {
    width: 800
    height: 480
    visible: true
    title: "i.MX8 Qt6 App"

    Rectangle {
        anchors.fill: parent
        color: "#2196F3"

        Text {
            anchors.centerIn: parent
            text: "Qt 6 Running on i.MX8!"
            color: "white"
            font.pointSize: 24
        }
    }
}