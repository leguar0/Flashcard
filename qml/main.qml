import QtQuick 2.0
import QtQuick.Controls 2.15

ApplicationWindow {
    visible: true
    width: 800
    height: 450
    title: "Flashcards"
    color: "#FAF3E0"

    Column {
        anchors.fill: parent
        spacing: 20

        Rectangle {
            width: 150
            height: 50
            radius: 45
            color: "#A99AC1"
            anchors.right: parent.right

            Row {
                anchors.centerIn: parent
                spacing: 10

                Rectangle {
                    width: 35
                    height: 35
                    radius: 45
                    color: mouseArea0.containsMouse ? "#F6CFFF" : "#F6C1C1"

                    Button {
                        anchors.centerIn: parent
                        text: "☼"
                        flat: true
                    }

                    MouseArea {
                        id: mouseArea0
                        anchors.fill: parent
                    }
                }

                Rectangle {
                    width: 35
                    height: 35
                    radius: 45
                    color: mouseArea1.containsMouse ? "#F6CFFF" : "#F6C1C1"

                    Button {
                        anchors.centerIn: parent
                        text: "P"
                        flat: true
                    }

                    MouseArea {
                        id: mouseArea1
                        anchors.fill: parent
                    }
                }
            }
        }

        Rectangle {
            width: 630
            height: 240
            radius: 45
            color: "#A99AC1"
            anchors.horizontalCenter: parent.horizontalCenter

            Rectangle {
                width: 35
                height: 35
                radius: 45
                color: mouseArea3.containsMouse ? "#F6CFFF" : "#F6C1C1"

                Button {
                    anchors.centerIn: parent
                    text: "?"
                    flat: true
                }

                MouseArea {
                    id: mouseArea3
                    anchors.fill: parent
                }
            }

            Text {
                id: flashcard
                anchors.centerIn: parent
                text: "Flashcard"
                font.pointSize: 32
                color: "#4B4B4B"
            }
        }

        Row {
            anchors.horizontalCenter: parent.horizontalCenter
            spacing: 20

            Rectangle {
                width: 260
                height: 50
                radius: 45
                color: mouseArea2.containsMouse ? "#B9A9D5" : "#A8A8D5"

                Button {
                    id: button_yes
                    anchors.centerIn: parent
                    text: "I know"
                    flat: true
                }

                MouseArea {
                    id: mouseArea2
                    anchors.fill: parent
                }
            }

            Rectangle {
                width: 260
                height: 50
                radius: 45
                color: mouseArea4.containsMouse ? "#B9A9D5" : "#A8A8D5"

                Button {
                    id: button_no
                    anchors.centerIn: parent
                    text: "Turn over"
                    flat: true
                }

                MouseArea {
                    id: mouseArea4
                    anchors.fill: parent
                }
            }
        }
    }
}
