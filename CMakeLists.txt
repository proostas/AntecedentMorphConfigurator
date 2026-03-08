cmake_minimum_required(VERSION 3.19)
project(AntecedentMorphConfigurator LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

if(NOT WIN32)
    set(CMAKE_INSTALL_PREFIX "/opt/prokofyev.me/${PROJECT_NAME}")
endif()

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets)

qt_standard_project_setup()

qt_add_executable(AntecedentMorphConfigurator
    WIN32 MACOSX_BUNDLE
    main.cpp
    mainwindow.cpp
    mainwindow.hpp

    schema.hpp schema.cpp
    schemamodel.hpp schemamodel.cpp
    schemaview.hpp schemaview.cpp
    schemapropertiesdialog.hpp schemapropertiesdialog.cpp
    lineedit.hpp lineedit.cpp
    codegeneratordialog.hpp codegeneratordialog.cpp
    codegenerator.hpp codegenerator.cpp
    zmkcodegenerator.hpp zmkcodegenerator.cpp
    qmkcodegenerator.hpp qmkcodegenerator.cpp
    preferencesdialog.hpp preferencesdialog.cpp
)

target_link_libraries(AntecedentMorphConfigurator
    PRIVATE
        Qt::Core
        Qt::Widgets
)

include(GNUInstallDirs)

install(TARGETS AntecedentMorphConfigurator
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET AntecedentMorphConfigurator
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
