pragma Singleton
import QtQuick 2.9

QtObject {
    id: singleton

    property string font: "Roboto"

    property string signUp: "Create Map"
    property string signIn: "Load game"
    property string offline: "Start game"
    property string account: "Account"
    property string tasks: "Tasks"
    property string exit: "Exit"
    property string settings: "Settings"
    property string day: "Day"
    property string week: "Week"
    property string month: "Month"
    property string add: "Add new task"
    property string name: "Name"
    property string start: "Start time"
    property string finish: "Finish time"
    property string today: "Today"

    property string cellPath: "../svg/hexagon.svg"
    property string forest: "../svg/forest.svg"
    property string tundra: "../svg/tundra.svg"
    property string steppe: "../svg/steppe.svg"
    property string water: "../svg/water.svg"
}