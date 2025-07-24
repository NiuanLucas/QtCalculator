import QtQuick 2.15
import QtQuick.Controls.Material 2.15

Button {
    id: button
    // Material change: touch-friendly minimum size
    minimumWidth: 56
    minimumHeight: 56
    // Material change: bold labelLarge typography
    font.pixelSize: Theme.labelLargeSize
    font.bold: true
    // Material change: apply slight elevation
    elevation: 2
    focusPolicy: Qt.StrongFocus
    Accessible.name: text
}
