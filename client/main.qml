import QtQuick 2.12
import QtQuick.Window 2.12
import QtRemoteObjects 5.12
import custom 1.0

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    SimpleSwitchReplica {
        id: myType
        node: Node { registryUrl: "local:switch" }

        onCurrStateChanged: {
            // report back our change so we get nice overview
            server_slot(currState)
        }
    }

    Rectangle {
        width: 200
        height: 200
        color: "green"

        Text {
            text: myType.currState
        }

        MouseArea {
            anchors.fill: parent
            onClicked: {
                console.debug("Clicked - force state to true!")
                myType.pushCurrState(true)
            }
        }
    }

}
