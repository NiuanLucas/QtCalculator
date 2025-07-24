import QtQuick 2.15
import QtQuick.Controls.Material 2.15

QtObject {
    // Material change: define Material 3 color tokens
    property color primary: "#6200EE"
    property color secondary: "#03DAC6"
    property color error: "#B00020"
    // Material change: define typography sizes
    property int headlineLargeSize: 32
    property int labelLargeSize: 18
    property int theme: Material.Light
    Component.onCompleted: {
        // Material change: apply theme colors globally
        Material.primary = primary
        Material.accent = secondary
        Material.theme = theme
        Material.foreground = "white"
    }
}
