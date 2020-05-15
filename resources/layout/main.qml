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

    height: Screen.height / 1.1
    width: Screen.width / 1.1

    minimumWidth: Screen.width / 1.1
    minimumHeight: Screen.height / 1.1

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

                property variant migrateMode
                property variant selectedNode

                onPaint: {
                    var ctx = canvas.getContext("2d");
                    var map = gui.map
                    var populations = gui.populations

                    var cellSize = { "width" : 0, "height" : 0}

                    canvas.centerMap =
                                   drawCells(map, ctx,
                                             canvas.height / 2, canvas.width / 2,
                                             canvas.height, canvas.width,
                                             cellSize)

                    canvas.cellSize = cellSize

                    drawPopulations(ctx, centerMap, populations, cellSize)

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

                    loadImage(String.capybara)
                    loadImage(String.elephant)
                    loadImage(String.horse)
                    loadImage(String.lion)
                    loadImage(String.wolf)
                    loadImage(String.bear)

                    canvasLoad.text = "true"
                    canvas.migrateMode = false
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
                        canvas.selectedNode = point

                        gui.x = point["x"]
                        gui.y = point["y"]

                        console.log("Find cell on  " + point["x"] + " " + point["y"])

                        if (canvas.migrateMode && checkPointerExist(canvas.additional, point["x"], point["y"])) {
                            gui.migrate()

                            canvas.migrateMode = false
                            canvas.additional = []
                            canvas.requestPaint()

                            return
                        }
                        canvas.additional = []

                        if (point["x"] !== -1) {
                            var additionItem = {"point" : point, "filled" : String.cellPath}
                            canvas.additional.push(additionItem)
                        } else {
                            bottomBody.currentIndex = 0
                            return
                        }

                        var currentPopulation = gui.currentPopulation
                        if (currentPopulation[0] === -1) {
                            bottomBody.currentIndex = 2
                            var currentCell = gui.currentCell

                            var climateStr
                            var climateInt = currentCell[0]

                            if (climateInt === 0) {
                                climateStr = "hot"
                            } else if (climateInt === 1) {
                                climateStr = "temperate"
                            } else if (climateInt === 2) {
                                climateStr = "cold"
                            }

                            var typeStr
                            var typeInt = currentCell[1]

                            if (typeInt === 0) {
                                typeStr = "water"
                            } else if (typeInt === 1) {
                                typeStr = "forest"
                            } else if (typeInt === 2) {
                                typeStr = "steppe"
                            } else if (typeInt === 3) {
                                typeStr = "tundra"
                            }

                            cellMainText.text = climateStr + " " + typeStr

                            waterText.text = "water level: " + currentCell[2]
                            plantsCountText.text = "plants count: " + currentCell[3]
                            carnivoreCountText.text = "carnivore count: " + currentCell[4]
                            herbivoreCountText.text = "herbivore count: " + currentCell[5]

                        } else {
                            bottomBody.currentIndex = 1

                            if (gui.id !== currentPopulation[11]) {
                                mutationControl.visible = false
                                multiplyControl.visible = false
                                moveControl.visible = false
                            } else {
                                mutationControl.visible = true
                                multiplyControl.visible = true
                                moveControl.visible = true
                            }

                            var sizeStr
                            var sizeInt = currentPopulation[0]

                            if (sizeInt === 0) {
                                sizeStr = "very small"
                            } else if (sizeInt === 1) {
                                sizeStr = "small"
                            } else if (sizeInt === 2) {
                                sizeStr = "average"
                            } else if (sizeInt === 3) {
                                sizeStr = "big"
                            } else if (sizeInt === 4) {
                                sizeStr = "very big";
                            }

                            var typeStr
                            var typeInt = currentPopulation[1]

                            if (typeInt === 0) {
                                typeStr = "hervibore"
                            } else if (typeInt === 1) {
                                typeStr = "carnivore"
                            }

                            var name = currentPopulation[2]
                            mainText.text = currentPopulation[10] + " " + sizeStr + " " + typeStr + " " + name

                            safetyText.text = "Safety: " + getString(currentPopulation[3])
                            velocityText.text = "Velocity: " + getString(currentPopulation[4])
                            coverText.text = "Cover: " + getString(currentPopulation[5])
                            healthText.text = "Health: " + currentPopulation[6]
                            productivityText.text = "Productivity: " + currentPopulation[7]
                            bioText.text = "Bio score: " + currentPopulation[8]
                            stepText.text = "Steps: " + currentPopulation[9]
                        }


                        canvas.requestPaint()
                    }
                }

                Connections {
                    target: gui
                    onRequestUpdate: {
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

                            Rectangle {
                                anchors.top: parent.top
                                anchors.bottom: parent.bottom
                                width: bottomBody.width * 0.6
                                color: "transparent"

                                Column {
                                    anchors.fill: parent

                                    Rectangle {
                                        anchors.left: parent.left
                                        anchors.right: parent.right
                                        height: parent.height / 3
                                        color: "transparent"

                                        Text {
                                            id: mainText
                                            anchors.centerIn: parent
                                            text: "kek"
                                            font: moveControl.font
                                            color: Light.foreground
                                        }
                                    }

                                    Row {
                                        anchors.left: parent.left
                                        anchors.right: parent.right
                                        height: parent.height * 2 / 3

                                        Rectangle {
                                            anchors.top: parent.top
                                            anchors.bottom: parent.bottom
                                            width: parent.width / 7
                                            color: "transparent"

                                            Text {
                                                id: safetyText
                                                anchors.centerIn: parent
                                                text: "safety:"
                                                font: moveControl.font
                                                color: Light.foreground
                                            }
                                        }

                                        Rectangle {
                                            anchors.top: parent.top
                                            anchors.bottom: parent.bottom
                                            width: parent.width / 7
                                            color: "transparent"

                                            Text {
                                                id: velocityText
                                                anchors.centerIn: parent
                                                text: "velocity: "
                                                font: moveControl.font
                                                color: Light.foreground
                                            }
                                        }

                                        Rectangle {
                                            anchors.top: parent.top
                                            anchors.bottom: parent.bottom
                                            width: parent.width / 7
                                            color: "transparent"

                                            Text {
                                                id: coverText
                                                anchors.centerIn: parent
                                                text: "cover: "
                                                font: moveControl.font
                                                color: Light.foreground
                                            }
                                        }

                                        Rectangle {
                                            anchors.top: parent.top
                                            anchors.bottom: parent.bottom
                                            width: parent.width / 7
                                            color: "transparent"

                                            Text {
                                                id: healthText
                                                anchors.centerIn: parent
                                                text: "health: "
                                                font: moveControl.font
                                                color: Light.foreground
                                            }
                                        }

                                        Rectangle {
                                            anchors.top: parent.top
                                            anchors.bottom: parent.bottom
                                            width: parent.width / 7
                                            color: "transparent"

                                            Text {
                                                id: productivityText
                                                anchors.centerIn: parent
                                                text: "productivity: "
                                                font: moveControl.font
                                                color: Light.foreground
                                            }
                                        }

                                        Rectangle {
                                            anchors.top: parent.top
                                            anchors.bottom: parent.bottom
                                            width: parent.width / 7
                                            color: "transparent"

                                            Text {
                                                id: bioText
                                                anchors.centerIn: parent
                                                text: "bio score: "
                                                font: moveControl.font
                                                color: Light.foreground
                                            }
                                        }

                                        Rectangle {
                                            anchors.top: parent.top
                                            anchors.bottom: parent.bottom
                                            width: parent.width / 7
                                            color: "transparent"

                                            Text {
                                                id: stepText
                                                anchors.centerIn: parent
                                                text: "steps: "
                                                font: moveControl.font
                                                color: Light.foreground
                                            }
                                        }
                                    }
                                }
                            }

                            Button {
                                id: endControl
                                Material.background: "transparent"
                                anchors.top: parent.top
                                anchors.bottom: parent.bottom
                                width: bottomBody.width / 10

                                contentItem: Item {
                                    Row {
                                        anchors.fill: parent

                                        Rectangle {
                                            anchors.top: parent.top
                                            anchors.bottom: parent.bottom
                                            width: parent.width
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

                                onClicked: {
                                    gui.stop()
                                }
                            }

                            Button {
                                id: mutationControl
                                Material.background: "transparent"
                                anchors.top: parent.top
                                anchors.bottom: parent.bottom
                                width: bottomBody.width / 10

                                contentItem: Item {
                                    Row {
                                        anchors.fill: parent

                                        Rectangle {
                                            anchors.top: parent.top
                                            anchors.bottom: parent.bottom
                                            width: parent.width
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

                                onClicked: {
                                    mutateDialog.open()
                                }
                            }

                            Button {
                                id: multiplyControl
                                Material.background: "transparent"
                                anchors.top: parent.top
                                anchors.bottom: parent.bottom
                                width: bottomBody.width / 10

                                contentItem: Item {
                                    Row {
                                        anchors.fill: parent

                                        Rectangle {
                                            anchors.top: parent.top
                                            anchors.bottom: parent.bottom
                                            width: parent.width
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

                                onClicked: {
                                    gui.multiply()
                                }
                            }

                            Button {
                                id: moveControl
                                Material.background: "transparent"
                                anchors.top: parent.top
                                anchors.bottom: parent.bottom
                                width: bottomBody.width / 10

                                contentItem: Item {
                                    Row {
                                        anchors.fill: parent

                                        Rectangle {
                                            anchors.top: parent.top
                                            anchors.bottom: parent.bottom
                                            width: parent.width
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

                                onClicked: {
                                    gui.select()

                                    var points = getArea(canvas.centerMap, canvas.selectedNode)

                                    for (var pointIndex = 0; pointIndex < points.length; ++pointIndex) {
                                        var additionItem = {"point" : points[pointIndex], "filled" : String.cellPath}
                                        canvas.additional.push(additionItem)
                                    }

                                    canvas.migrateMode = true

                                    canvas.requestPaint()
                                }
                            }
                        }
                    }

                    Item {
                        id: cellBody

                        Rectangle {
                            anchors.top: parent.top
                            anchors.bottom: parent.bottom
                            width: bottomBody.width
                            color: "transparent"

                            Column {
                                anchors.fill: parent

                                Rectangle {
                                    anchors.left: parent.left
                                    anchors.right: parent.right
                                    height: parent.height / 3
                                    color: "transparent"

                                    Text {
                                        id: cellMainText
                                        anchors.centerIn: parent
                                        text: "kek"
                                        font: moveControl.font
                                        color: Light.foreground
                                    }
                                }

                                Row {
                                    anchors.left: parent.left
                                    anchors.right: parent.right
                                    height: parent.height * 2 / 3

                                    Rectangle {
                                        anchors.top: parent.top
                                        anchors.bottom: parent.bottom
                                        width: parent.width / 4
                                        color: "transparent"

                                        Text {
                                            id: waterText
                                            anchors.centerIn: parent
                                            text: "waterLevel:"
                                            font: moveControl.font
                                            color: Light.foreground
                                        }
                                    }

                                    Rectangle {
                                        anchors.top: parent.top
                                        anchors.bottom: parent.bottom
                                        width: parent.width / 4
                                        color: "transparent"

                                        Text {
                                            id: plantsCountText
                                            anchors.centerIn: parent
                                            text: "plant count: "
                                            font: moveControl.font
                                            color: Light.foreground
                                        }
                                    }

                                    Rectangle {
                                        anchors.top: parent.top
                                        anchors.bottom: parent.bottom
                                        width: parent.width / 4
                                        color: "transparent"

                                        Text {
                                            id: carnivoreCountText
                                            anchors.centerIn: parent
                                            text: "carnivore count: "
                                            font: moveControl.font
                                            color: Light.foreground
                                        }
                                    }

                                    Rectangle {
                                        anchors.top: parent.top
                                        anchors.bottom: parent.bottom
                                        width: parent.width / 4
                                        color: "transparent"

                                        Text {
                                            id: herbivoreCountText
                                            anchors.centerIn: parent
                                            text: "herbivore count: "
                                            font: moveControl.font
                                            color: Light.foreground
                                        }
                                    }
                                }
                            }
                        }
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

    Connections {
        target: gui
        onEndGame: {
            endDialog.open()
        }
    }

    Dialog {
        id: endDialog
        width: Screen.width / 2
        height: Screen.height / 2
        x: (parent.width - width) / 2
        y: (parent.height - height) / 2

        contentItem: Rectangle {
            id: endView
            anchors.fill: parent
            color: "transparent"

            Column {
                ListView {
                    id: playerList
                    width: endView.width
                    height: endView.height * 5 / 6

                    model: playerModel
                    delegate: Pane {
                        width: parent.width
                        height: parent.height / 5

                        Row {
                            Rectangle {
                                height: parent.height
                                width: playerList.width / 2

                                Text {
                                    anchors.centerIn: parent
                                    text: model.name
                                }
                            }

                            Rectangle {
                                height: parent.height
                                width: playerList.width / 2

                                Text {
                                    anchors.centerIn: parent
                                    text: model.score
                                }
                            }
                        }
                    }
                }

                Button {
                    id: endButton
                    text: qsTr(String.endGame)
                    width: endView.width
                    height: endView.height / 6
                    Material.background: "transparent"

                    onClicked: {
                        stack.pop()
                    }
                }
            }
        }
    }

    Dialog {
        id: mutateDialog
        width: Screen.width / 2
        height: Screen.height / 2
        x: (parent.width - width) / 2
        y: (parent.height - height) / 2

        contentItem: Column {
            Pane {
                width: parent.width
                height: parent.height / 5

                Text {
                    text: qsTr(String.choose)
                    anchors.centerIn: parent
                    font: mutateSize.font
                    color: Light.foreground
                }
            }

            Pane {
                width: parent.width
                height: parent.height / 5

                Button {
                    id: mutateSize
                    text: qsTr(String.mutateSize)
                    anchors.fill: parent
                    Material.background: "transparent"

                    onClicked: {
                        mutateDialog.close()
                    }
                }
            }

            Pane {
                width: parent.width
                height: parent.height / 5

                Button {
                    text: qsTr(String.mutateSafety)
                    anchors.fill: parent
                    Material.background: "transparent"

                    onClicked: {
                        mutateDialog.close()
                    }
                }
            }

            Pane {
                width: parent.width
                height: parent.height / 5

                Button {
                    text: qsTr(String.mutateCover)
                    anchors.fill: parent
                    Material.background: "transparent"

                    onClicked: {
                        mutateDialog.close()
                    }
                }
            }

            Pane {
                width: parent.width
                height: parent.height / 5

                Button {
                    text: qsTr(String.mutateVelocity)
                    anchors.fill: parent
                    Material.background: "transparent"

                    onClicked: {
                        mutateDialog.close()
                    }
                }
            }
        }
    }

    function switchToMainScreen() {
       stack.push(gameLayout);
    }

    function drawPopulations(ctx, centerMap, pattern, cellSize) {
        console.log("Pattern size", pattern.length)
        for (var populationInd = 0; populationInd < pattern.length; ++populationInd) {
            var name = pattern[populationInd][0]
            var xPos = pattern[populationInd][1]
            var yPos = pattern[populationInd][2]
            console.log(name, " x: ", xPos, " y: ", yPos)

            var x = centerMap[yPos][xPos]["x"] - cellSize["width"] / 2
            var y = centerMap[yPos][xPos]["y"] - cellSize["height"] / 2

            console.log("I draw ", name)

            var drawPath = "../svg/animals/" + name + ".svg"

            ctx.drawImage(drawPath, x, y, cellSize["width"], cellSize["height"])
        }
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
        if ((posY < map.length) && (posX < map[0].length) && (posX >= 0) && (posY >= 0) && gui.checkPopulation(posX, posY)) {
            return true
        } else {
            return false
        }
    }

    function checkPointerExist(additional, posX, posY) {
        var flgExist = false

        for (var index = 0; index < additional.length; ++index) {
            var x = additional[index]["point"]["x"]
            var y = additional[index]["point"]["y"]

            if ((posX === x) && (posY === y)) {
                flgExist = true
            }
        }

        return flgExist
    }

    function getString(index) {
        var safetyStr
        if (index === 0) {
            safetyStr = "very small"
        } else if (index === 1) {
            safetyStr = "small"
        } else if (index === 2) {
            safetyStr = "average"
        } else if (index === 3) {
            safetyStr = "big"
        } else if (index === 4) {
            safetyStr = "very big";
        }
        return safetyStr
    }
}