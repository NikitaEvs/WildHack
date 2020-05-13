import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3
import QtQuick.Controls.Material 2.1
import QtQuick.Window 2.2

import "../colors"
import "../string"

ApplicationWindow {
    id: applicationWindow
    objectName: "applicationWindow"

    title: qsTr("WildHack")

    Text {
        id: canvasLoad
        objectName: "canvasLoad"
        visible: false
        text: "false"
    }

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
        objectName: "enterView"

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
            objectName: "enter"
            text: qsTr(String.offline)
            Material.background: "transparent"
            anchors.horizontalCenter: parent.horizontalCenter
            onClicked: switchToMainScreen()
        }
    }

    Component {
        id: gameLayout

        Column {
            id: gameColumn
            objectName: "gameColumn"

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
                objectName: "canvas"
                width: parent.width
                height: parent.height - toolbar.height - bottomBar.height

                property variant centerMap
                property variant cellSize

                property variant additional

                onPaint: {
                    var ctx = canvas.getContext("2d");
                    var map = gui.map

                    var cellSize = { "width" : 0, "height" : 0}

                    canvas.centerMap =
                                   drawCells(map, ctx,
                                             canvas.height / 2, canvas.width / 2,
                                             canvas.height, canvas.width,
                                             cellSize)

                    canvas.cellSize = cellSize

                    for (var pointIndex = 0; pointIndex < canvas.additional.length; ++pointIndex) {
                        var point = canvas.additional[pointIndex]["point"]
                        console.log(point["x"], point["y"])
                        drawCell(canvas, ctx, canvas.centerMap, point["x"], point["y"], canvas.cellSize)
                    }
                }

                Component.onCompleted: {
                    loadImage("../svg/hexagon.svg")
                    loadImage(String.forest)
                    loadImage(String.steppe)
                    loadImage(String.tundra)
                    loadImage(String.water)
                    canvasLoad.text = "true"
                    canvas.additional = []
                }

                onImageLoaded: {
                    requestPaint()
                }

                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        console.log("Clicked on " + mouse.x + " " + mouse.y)

                        var area = canvas.cellSize["width"]
                        var point = getClickCell(canvas.centerMap, mouse.x, mouse.y, area)

                        console.log("Find cell on  " + point["x"] + " " + point["y"])

                        if (point["x"] !== -1) {
                            var additionItem = {"point" : point, "filled" : String.cellPath}
                            canvas.additional.push(additionItem)
                            bottomBody.currentIndex = 1
                        }

                        var points = getArea(canvas.centerMap, point)

                        for (var pointIndex = 0; pointIndex < points.length; ++pointIndex) {
                            var additionItem = {"point" : points[pointIndex], "filled" : String.cellPath}
                            canvas.additional.push(additionItem)
                        }

                        canvas.requestPaint()
                    }
                }
            }

            Pane {
                id: bottomBar
                width: parent.width
                height: Screen.height / 10

                Material.elevation: 3
                Material.background: Light.background

                StackLayout {
                    id: bottomBody
                    width: parent.width
                    height: parent.height

                    currentIndex: 0

                    Item {
                        id: emptyBody
                    }

                    Item {
                        id: populationBody

                        Row {
                            anchors.top: parent.top
                            anchors.bottom: parent.bottom

                            Button {
                                id: mutationControl
                                Material.background: "transparent"
                                anchors.top: parent.top
                                anchors.bottom: parent.bottom
                                width: Screen.width / 9

                                contentItem: Item {
                                    Row {
                                        anchors.fill: parent
                                        Image {
                                            anchors.top: parent.top
                                            anchors.bottom: parent.bottom
                                            fillMode: Image.PreserveAspectFit
                                            width: parent.width / 2
                                            source: "../svg/punck.svg"
                                        }

                                        Rectangle {
                                            anchors.top: parent.top
                                            anchors.bottom: parent.bottom
                                            width: parent.width / 2
                                            color: "transparent"

                                            Text {
                                                text: qsTr(String.mutate)
                                                anchors.centerIn: parent

                                                font: mutationControl.font
                                                opacity: enabled ? 1.0 : 0.3
                                                color: mutationControl.down ? Light.accent : Light.foreground
                                            }
                                        }
                                    }
                                }
                            }

                            Button {
                                id: multiplyControl
                                Material.background: "transparent"
                                anchors.top: parent.top
                                anchors.bottom: parent.bottom
                                width: Screen.width / 9

                                contentItem: Item {
                                    Row {
                                        anchors.fill: parent
                                        Image {
                                            anchors.top: parent.top
                                            anchors.bottom: parent.bottom
                                            fillMode: Image.PreserveAspectFit
                                            width: parent.width / 2
                                            source: "../svg/punck.svg"
                                        }

                                        Rectangle {
                                            anchors.top: parent.top
                                            anchors.bottom: parent.bottom
                                            width: parent.width / 2
                                            color: "transparent"

                                            Text {
                                                text: qsTr(String.multiply)
                                                anchors.centerIn: parent

                                                font: multiplyControl.font
                                                opacity: enabled ? 1.0 : 0.3
                                                color: multiplyControl.down ? Light.accent : Light.foreground
                                            }
                                        }
                                    }
                                }
                            }

                            Button {
                                id: moveControl
                                Material.background: "transparent"
                                anchors.top: parent.top
                                anchors.bottom: parent.bottom
                                width: Screen.width / 9

                                contentItem: Item {
                                    Row {
                                        anchors.fill: parent
                                        Image {
                                            anchors.top: parent.top
                                            anchors.bottom: parent.bottom
                                            fillMode: Image.PreserveAspectFit
                                            width: parent.width / 2
                                            source: "../svg/punck.svg"
                                        }

                                        Rectangle {
                                            anchors.top: parent.top
                                            anchors.bottom: parent.bottom
                                            width: parent.width / 2
                                            color: "transparent"

                                            Text {
                                                text: qsTr(String.migrate)
                                                anchors.centerIn: parent

                                                font: moveControl.font
                                                opacity: enabled ? 1.0 : 0.3
                                                color: moveControl.down ? Light.accent : Light.foreground
                                            }
                                        }
                                    }
                                }
                            }

                            Rectangle {
                                anchors.top: parent.top
                                anchors.bottom: parent.bottom
                                width: Screen.width * 0.53

                            }

                            Button {
                                id: endControl
                                Material.background: "transparent"
                                anchors.top: parent.top
                                anchors.bottom: parent.bottom
                                width: Screen.width / 9

                                contentItem: Item {
                                    Row {
                                        anchors.fill: parent
                                        Image {
                                            anchors.top: parent.top
                                            anchors.bottom: parent.bottom
                                            fillMode: Image.PreserveAspectFit
                                            width: parent.width / 2
                                            source: "../svg/punck.svg"
                                        }

                                        Rectangle {
                                            anchors.top: parent.top
                                            anchors.bottom: parent.bottom
                                            width: parent.width / 2
                                            color: "transparent"

                                            Text {
                                                text: qsTr(String.finish)
                                                anchors.centerIn: parent

                                                font: endControl.font
                                                opacity: enabled ? 1.0 : 0.3
                                                color: endControl.down ? Light.accent : Light.foreground
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }

                    Item {
                        id: cellBody
                    }
                }
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

    function drawCells(map, ctx, yCenter, xCenter, height, width, size) {
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

       size["width"] = hexWidth / 2
       size["height"] = hexHeight / 2

       var mapHeight = yCount * hexHeight - (yCount - 1) * hexHeight * 0.25
       var mapWidth = xCount * hexWidth + Math.ceil(hexWidth / 2)

       var x0 = xCenter - Math.ceil(mapWidth / 2)
       var y0 = yCenter - Math.ceil(mapHeight / 2)

       var centerMap = []

       for (var row = 0; row < yCount; ++row) {
            centerMap[row] = []
       }

       for (var row = 0; row < yCount; ++row) {
            for (var column = 0; column < xCount; ++ column) {
                var currentX = x0 + column * hexWidth
                if (row % 2 === 1) {
                    currentX += Math.ceil(hexWidth / 2)
                }

                var currentY = y0 + row * hexHeight - Math.ceil(a * Math.sin(Math.PI / 6)) * row

                centerMap[row][column] = {"x": currentX + hexWidth / 2, "y": currentY + hexHeight / 2}

                var drawPath;
                if (map[row][column] === 0) {
                    drawPath = String.water
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

       return centerMap
    }

    function drawCell(canvas, ctx, centerMap, x, y, size) {
        var center = centerMap[y][x]
        var leftCorner = {"x" : center["x"] - size["width"], "y" : center["y"] - size["height"]}

        console.log(leftCorner["x"], leftCorner["y"], size["width"], size["height"])

        var drawPath = String.cellPath

        ctx.drawImage(drawPath, leftCorner["x"], leftCorner["y"], size["width"] * 2, size["height"] * 2)
        canvas.requestPaint()
    }


    function getDistance2(point, x, y) {
        return (point["x"] - x) * (point["x"] - x) + (point["y"] - y) * (point["y"] - y)
    }

    function getClickCell(map, posX, posY, minArea) {
        var minDist = 1000000
        var minCellX = 0
        var minCellY = 0


        for (var row = 0; row < map.length; ++row) {
            for (var column = 0; column < map[0].length; ++column) {
                var distance = getDistance2(map[row][column], posX, posY)
                if (distance < minDist) {
                    minDist = distance

                    minCellX = column
                    minCellY = row
                }
            }
        }

        var point = {}
        if (minDist < minArea * minArea) {
            point["x"] = minCellX
            point["y"] = minCellY
        } else {
            point["x"] = -1
            point["y"] = -1
        }

        return point
    }

    function getArea(map, point) {
        var points = []
        var pointX = point["x"]
        var pointY = point["y"]

        if(point["x"] === -1) {
            return points
        }

        if (checkCell(map, pointX + 1, pointY)) {
            points.push({"x" : pointX + 1, "y" : pointY})
        }

        if (checkCell(map, pointX, pointY + 1)) {
            points.push({"x" : pointX, "y" : pointY + 1})
        }

        if (checkCell(map, pointX - 1, pointY)) {
            points.push({"x" : pointX - 1, "y" : pointY})
        }

        if (checkCell(map, pointX, pointY - 1)) {
            points.push({"x" : pointX, "y" : pointY - 1})
        }

        if (pointY % 2 === 0) {
            if (checkCell(map, pointX - 1, pointY + 1)) {
                points.push({"x" : pointX - 1, "y" : pointY + 1})
            }

            if (checkCell(map, pointX - 1, pointY - 1)) {
                points.push({"x" : pointX - 1, "y" : pointY - 1})
            }
        } else {
            if (checkCell(map, pointX + 1, pointY + 1)) {
                points.push({"x" : pointX + 1, "y" : pointY + 1})
            }

            if (checkCell(map, pointX + 1, pointY - 1)) {
                points.push({"x" : pointX + 1, "y" : pointY - 1})
            }
        }


        return points
    }

    function checkCell(map, posX, posY) {
        console.log("Size:", map.length, map[0].length)
        if ((posY < map.length) && (posX < map[0].length) && (posX >= 0) && (posY >= 0)) {
            return true
        } else {
            return false
        }
    }
}