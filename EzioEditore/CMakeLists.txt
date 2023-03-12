cmake_minimum_required(VERSION 3.16)
project(EzioEditore LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)

if(NOT DEFINED INSTALL_EXAMPLESDIR)
    set(INSTALL_EXAMPLESDIR "examples")
endif()

set(INSTALL_EXAMPLEDIR "${INSTALL_EXAMPLESDIR}")

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets PrintSupport)

qt_add_executable(application
    main.cpp
    mainwindow.cpp mainwindow.h
    drucken.h drucken.cpp
    EzioEditore.rc
)

set_target_properties(application PROPERTIES
    WIN32_EXECUTABLE TRUE
    MACOSX_BUNDLE TRUE
    OUTPUT_NAME "EzioEditore"
)

target_link_libraries(application PUBLIC
    Qt::Core
    Qt::Gui
    Qt::Widgets
    Qt6::PrintSupport
)

# Resources:
set(application_resource_files
    "images/copy.png"
    "images/cut.png"
    "images/new.png"
    "images/open.png"
    "images/paste.png"
    "images/save.png"
    "images/print.png"
    "images/undo.png"
    "images/redo.png"
    "images/icon.png"
    "images/styleSheet.qss"
)

qt_add_resources(application "application"
    PREFIX
        "/"
    FILES
        ${application_resource_files}
)

install(TARGETS application
    RUNTIME DESTINATION "${INSTALL_EXAMPLEDIR}"
    BUNDLE DESTINATION "${INSTALL_EXAMPLEDIR}"
    LIBRARY DESTINATION "${INSTALL_EXAMPLEDIR}"
)
