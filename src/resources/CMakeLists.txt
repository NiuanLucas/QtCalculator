# src/resources/CMakeLists.txt
qt_add_resources(styles_qrc
    PREFIX /
    FILES
        styles.qrc          # o próprio .qrc; Qt varre e gera cpp
)
