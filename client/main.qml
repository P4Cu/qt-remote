import QtQuick 2.12
import QtQuick.Window 2.12
import QtRemoteObjects 5.12

// get our custom QML object
import custom 1.0

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    SimpleSwitchReplica {
        id: myType
        node: Node {
            // even though it says registry we can do a direct connection like below
            registryUrl: "local:switch"
        }

        onCurrStateChanged: {
            // report back our change so we get nice overview
            // and also demonstrates how to call slots of remote object
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
                // !! do not assign to property! it's a READPUSH not READWRITE property
                myType.pushCurrState(true)
            }
        }
    }

}
