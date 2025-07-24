import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Controls.Material 2.15

ApplicationWindow {
    id: window
    Accessible.name: "Calculator Window"
    visible: true
    width: 360
    height: 640
    title: qsTr("Calculadora Qt")

    Theme { id: theme }

    ColumnLayout {
        anchors.fill: parent
        spacing: 8
        padding: 16

        TextField {
            id: fieldA
            // Material change: focus outline and accessible name
            Accessible.name: "numero1"
            placeholderText: qsTr("Número 1")
            inputMethodHints: Qt.ImhFormattedNumbersOnly
            focusPolicy: Qt.StrongFocus
            minimumHeight: 56
            Layout.fillWidth: true
        }

        TextField {
            id: fieldB
            // Material change: focus outline and accessible name
            Accessible.name: "numero2"
            placeholderText: qsTr("Número 2")
            inputMethodHints: Qt.ImhFormattedNumbersOnly
            focusPolicy: Qt.StrongFocus
            minimumHeight: 56
            Layout.fillWidth: true
        }

        GridLayout {
            id: buttonRow
            columns: window.width > window.height ? 4 : 2  // Material change: responsive column count
            Layout.fillWidth: true
            rowSpacing: 8
            columnSpacing: 8

            CalcButton {
                text: qsTr("+")
                Accessible.name: "add"
                onClicked: result.text = qsTr("Resultado: %1").arg(calcModel.sum(fieldA.text, fieldB.text))
            }
            CalcButton {
                text: qsTr("-")
                Accessible.name: "subtract"
                onClicked: result.text = qsTr("Resultado: %1").arg(calcModel.subtract(fieldA.text, fieldB.text))
            }
            CalcButton {
                text: qsTr("×")
                Accessible.name: "multiply"
                onClicked: result.text = qsTr("Resultado: %1").arg(calcModel.multiply(fieldA.text, fieldB.text))
            }
            CalcButton {
                text: qsTr("÷")
                Accessible.name: "divide"
                onClicked: {
                    if (fieldB.text === "0") {
                        result.text = qsTr("Divisão por zero")
                    } else {
                        result.text = qsTr("Resultado: %1").arg(calcModel.divide(fieldA.text, fieldB.text))
                    }
                }
            }
        }

        Pane {
            id: displayPane
            Layout.fillWidth: true
            padding: 16
            // Material change: elevated display container
            elevation: 4
            Label {
                id: result
                text: qsTr("Resultado: —")
                // Material change: use headlineLarge font
                font.pixelSize: theme.headlineLargeSize
                horizontalAlignment: Text.AlignRight
                verticalAlignment: Text.AlignVCenter
                Accessible.name: "display"
            }
        }
    }
}
