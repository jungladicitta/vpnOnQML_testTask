import QtQuick
import QtQuick.Controls

Window {
    id: root
    width: 640
    height: 480
    visible: true
    title: qsTr("VPN test")

    Connections {
        target: appEngine
        function onConnectionStatusChanged(statusMsg) {
            statusText.placeholderText = statusMsg
            if (appEngine.isEnabled()) {
                connectButton.text = "Disconnect"
                enterIP.clear()
                enterIP.readOnly = true
            }
            else {
                connectButton.text = "Connect"
                enterIP.readOnly = false
            }
        }
    }

    Column {
        id: column
        width: 125
        height: 75
        anchors.centerIn: parent

        TextField {
            id: enterIP
            placeholderText: "Enter IP address:"
        }
        Row {
            Button {
                id: connectButton
                text: "Connect"
                onClicked: {
                    appEngine.handleServerConnection(enterIP.text)
                }
            }
            TextArea {
                id: statusText
                placeholderText: "Disabled"
                readOnly: true
                width: 240
            }
        }
    }
}
