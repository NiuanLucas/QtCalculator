# src/app/CMakeLists.txt
add_executable(calculator
    main.cpp
    StyleHelper.cpp  StyleHelper.h
    ../resources/styles.qrc        # embute os estilos no binário
)

target_link_libraries(calculator
    PRIVATE
        Qt6::Widgets
        Qt6::Gui
        calculator_ui              # traz a camada de interface (que já depende de core)
)

# Se desejar testar via "cmake --install", pode adicionar:
# install(TARGETS calculator RUNTIME DESTINATION bin)
