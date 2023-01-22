cmake_minimum_required(VERSION 3.16)
project(sw_areachart VERSION 0.1 LANGUAGES CXX)
#确保在类定义中使用了Q_OBJECT宏
#Qt信号槽机制依赖moc_xxx.cpp文件，请尝试在CmakeLists.txt文件中添加set(CMAKE_AUTOMOC ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

if(NOT DEFINED INSTALL_EXAMPLESDIR)
    set(INSTALL_EXAMPLESDIR "examples")
endif()

set(TS_FILES sw_areachart_zh_CN.ts)
set(INSTALL_EXAMPLEDIR "${INSTALL_EXAMPLESDIR}/charts/areachart")
set(ui ${CMAKE_SOURCE_DIR}/widget.ui)
set(CMAKE_AUTOUIC_SEARCH_PATHS "ui")
set(PROJECT_SOURCES
        main.cpp
        widget.cpp
        widget.h
        myqlineseries.cpp
        myqlineseries.h
        widget.ui
        ${TS_FILES}
)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt6 REQUIRED COMPONENTS SerialPort)
find_package(Qt6 REQUIRED COMPONENTS Widgets Charts Core Gui)
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets LinguistTools)

qt_add_executable(sw_areachart
    ${PROJECT_SOURCES}
)

target_link_libraries(sw_areachart
  PRIVATE
  Qt${QT_VERSION_MAJOR}::Core
  Qt${QT_VERSION_MAJOR}::Widgets
  Qt${QT_VERSION_MAJOR}::Charts
  Qt${QT_VERSION_MAJOR}::Gui
)

MESSAGE( STATUS "=======INSTALL_EXAMPLEDIR = ${INSTALL_EXAMPLEDIR}")
MESSAGE( STATUS "CMAKE_SOURCE_DIR} = ${CMAKE_SOURCE_DIR}")

set_target_properties(sw_areachart PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)
