# src/core/CMakeLists.txt
add_library(calculator_core
    CalculatorModel.cpp
    CalculatorModel.h
)

# Apenas QtCore (nada de Widgets aqui)
target_link_libraries(calculator_core
    PUBLIC Qt6::Core
)

# Torna este diretório visível para quem linkar a lib
target_include_directories(calculator_core
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)
