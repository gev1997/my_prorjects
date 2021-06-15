import QtQuick 2.9
import QtQuick.Window 2.2

Window {
    id: root
    width: 640
    height: 480
    visible: true
    title: qsTr("Chess")

    Grid {
        model: 1
        columns: 2


        spacing: 2
        id: board_1
        width: 50
        height: 50


        Rectangle { color: "red"; width: 50; height: 50 }
        Rectangle { color: "green"; width: 50; height: 50 }
        Rectangle { color: "blue"; width: 50; height: 50 }
    }

}
