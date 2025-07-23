# src/ui/CMakeLists.txt
add_library(calculator_ui
    CalcWidget.cpp   CalcWidget.h
    MainWindow.cpp   MainWindow.h
)

target_link_libraries(calculator_ui
    PUBLIC
        Qt6::Widgets
        calculator_core         # usa o modelo de cálculo
)

# Expõe este diretório a quem linkar a lib
target_include_directories(calculator_ui
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)
