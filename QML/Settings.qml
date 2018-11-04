import QtQuick 2.0
import QtQuick.Controls 2.2

Rectangle {
    anchors.fill: parent

    color: "transparent"

    Column {
        id: textFieldEntries
        width: parent.width / 2 - x
        height: parent.height - x
        x: 40
        y: x
        spacing: 10

        SettingsTextFieldEntry {
            description: "Iterations (full simulation)"
            minVal: 100
            maxVal: 10000
            valueText: settings.combatIterationsFullSim
            placeholderText: settings.combatIterationsFullSim
            unitText: "iterations"

            onAcceptedInput: settings.setCombatIterationsFullSim(value)
        }

        SettingsTextFieldEntry {
            description: "Iterations (quick simulation)"
            minVal: 100
            maxVal: 10000
            valueText: settings.combatIterationsQuickSim
            placeholderText: settings.combatIterationsQuickSim
            unitText: "iterations"

            onAcceptedInput: settings.setCombatIterationsQuickSim(value)
        }

        SettingsTextFieldEntry {
            description: "Combat length"
            minVal: 30
            maxVal: 600
            valueText: settings.combatLength
            placeholderText: settings.combatLength
            unitText: "seconds"

            onAcceptedInput: settings.setCombatLength(value)
        }

        SettingsTextFieldEntry {
            description: "Active threads"
            minVal: 1
            maxVal: settings.maxThreads
            valueText: settings.numThreads
            placeholderText: settings.numThreads
            unitText: "threads"

            onAcceptedInput: settings.setNumThreads(value)
        }
    }

    ListView {
        id: scaleModel
        anchors {
            left: textFieldEntries.right
            top: parent.top
            topMargin: 40
            bottom: parent.bottom
        }

        boundsBehavior: Flickable.StopAtBounds

        implicitHeight: contentHeight

        model: simScaleModel
        delegate: RectangleBorders {
            rectColor: _active ? "#134f00" : root.darkDarkGray
            height: 30
            width: 150
            TextSmall {
                text: _name
            }

            onRectangleClicked: simScaleModel.toggleOption(_enum)
        }
    }
}
