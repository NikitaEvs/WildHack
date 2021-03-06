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
    property string today: "Today"
    property string mutate: "Mutate"
    property string multiply: "Multiply"
    property string migrate: "Migrate"
    property string finish: "Finish step"
    property string choose: "Choose a new mutation"
    property string mutateSize: "Mutate size"
    property string mutateSafety: "Mutate safety"
    property string mutateCover: "Mutate cover"
    property string mutateVelocity: "Mutate velocity"
    property string endGame: "End gane"

    property string cellPath: "../svg/shape.svg"
    property string forest: "../svg/forest.svg"
    property string tundra: "../svg/water.svg"
    property string steppe: "../svg/steppe.svg"
    property string water: "../svg/tundra.svg"

    property string capybara: "../svg/animals/capybara.svg"
    property string elephant: "../svg/animals/elephant.svg"
    property string horse: "../svg/animals/horse.svg"
    property string bear: "../svg/animals/bear.svg"
    property string lion: "../svg/animals/lion.svg"
    property string wolf: "../svg/animals/wolf.svg"
}