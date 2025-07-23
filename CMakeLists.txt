cmake_minimum_required(VERSION 3.21)       # Qt‑6.5+ recomenda 3.21
project(MyCalculator LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)                      # signals/slots
set(CMAKE_AUTORCC ON)                      # .qrc
set(CMAKE_AUTOUIC OFF)                     # sem .ui

find_package(Qt6 REQUIRED COMPONENTS Widgets Gui LinguistTools)

add_subdirectory(src)                      # delega tudo à pasta src
