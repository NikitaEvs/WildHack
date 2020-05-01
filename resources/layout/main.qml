import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.0
import QtQuick.Controls.Material 2.1
import QtQuick.Window 2.2

import "../colors"
import "../string"


ApplicationWindow {
    id: applicationWindow

    visible: true

    Material.theme: Material.Light
    Material.accent: Light.accent
    Material.background: Light.background
    Material.primary: Light.primary
    Material.foreground: Light.foreground

    height: Screen.height / 2
    width: Screen.width / 2

    minimumWidth: Screen.width / 3
    minimumHeight: Screen.height / 3

    StackView {
        id: stack
        initialItem: enterView
        anchors.fill: parent
    }

    Column {
        id: enterView

        Item {
            width: 1
            height: applicationWindow.height / 2 - Screen.height / 10
        }

        Image {
            source: "../svg/punck.svg"
            width: Screen.width / 5; height: Screen.height / 5
            fillMode: Image.PreserveAspectFit
            anchors.horizontalCenter: parent.horizontalCenter
        }

        Button {
            id: signInBtn
            text: qsTr(String.signIn)
            Material.background: "transparent"
            anchors.horizontalCenter: parent.horizontalCenter
        }

        Button {
            id: signUpBtn
            text: qsTr(String.signUp)
            Material.background: "transparent"
            anchors.horizontalCenter: parent.horizontalCenter
        }

        Button {
            id: offlineBtn
            text: qsTr(String.offline)
            Material.background: "transparent"
            anchors.horizontalCenter: parent.horizontalCenter
            onClicked: switchToMainScreen()
        }
    }

    Component {
        id: gameLayout

        Column {
            height: stack.height
            width: stack.width

            ToolBar {
                id: toolbar
                anchors.left: parent.left
                anchors.right: parent.right
                Material.elevation: 0

                Row {
                    anchors.left: parent.left
                    anchors.right: parent.right

                    ToolButton {
                        onClicked: drawer.open()
                        text: "◀"
                    }
                }
            }

            Canvas {
                id: canvas
                width: parent.width
                height: parent.height - toolbar.height

                onPaint: {
                    var ctx = canvas.getContext("2d");
                    var map = gui.map

                    drawCells(map, ctx, canvas.height / 2, canvas.width / 2, canvas.height, canvas.width)
                }

                Component.onCompleted: {
                    loadImage("../svg/hexagon.svg")
                    loadImage(String.forest)
                    loadImage(String.steppe)
                    loadImage(String.tundra)
                    loadImage(String.water)

                }
                onImageLoaded: requestPaint()
            }

            Drawer {
                id: drawer
                width: 0.1 * Screen.width
                height: applicationWindow.height


                Button {
                    text: qsTr(String.exit)
                    anchors.bottom: parent.bottom
                    Material.background: "transparent"
                    onClicked: stack.pop()
                }
            }


        }
    }


    function switchToMainScreen() {
       stack.push(gameLayout);
    }

    function drawCells(map, ctx, yCenter, xCenter, height, width) {
           var yCount = map.length
           var xCount = map[0].length

           var a, hexWidth, hexHeight

           var calculatedHeightA = Math.ceil(height / (yCount * 2 - (yCount - 1) * 0.25))
           var calculatedHexWidth = 2 * Math.ceil(width / (2 * xCount + 1))
           var calculatedWidthA = Math.ceil(calculatedHexWidth / (2 * Math.cos(Math.PI / 6)))

           if (calculatedHeightA < calculatedWidthA) {
                a = calculatedHeightA
           } else {
                a = calculatedWidthA
           }

           hexHeight = a + Math.ceil(2 * a * Math.cos(Math.PI / 3))
           hexWidth = Math.ceil(2 * a * Math.cos(Math.PI / 6))

           var mapHeight = yCount * hexHeight - (yCount - 1) * hexHeight * 0.25
           var mapWidth = xCount * hexWidth + Math.ceil(hexWidth / 2)

           var x0 = xCenter - Math.ceil(mapWidth / 2)
           var y0 = yCenter - Math.ceil(mapHeight / 2)

           for (var row = 0; row < yCount; ++row) {
                for (var column = 0; column < xCount; ++ column) {
                    var currentX = x0 + column * hexWidth;
                    if (row % 2 === 1) {
                        currentX += Math.ceil(hexWidth / 2);
                    }

                    var currentY = y0 + row * hexHeight - Math.ceil(a * Math.sin(Math.PI / 6)) * row

                    var drawPath;
                    if (map[row][column] === 0) {
                        drawPath = String.water;
                    } else if (map[row][column] === 1) {
                        drawPath = String.forest
                    } else if (map[row][column] === 2) {
                        drawPath = String.steppe
                    } else if (map[row][column] === 3) {
                        drawPath = String.tundra
                    }

                    ctx.drawImage(drawPath, currentX, currentY, hexWidth, hexHeight)
                }
           }
    }
}