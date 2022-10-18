cmake_minimum_required(VERSION 3.23)
project(AntSimulator LANGUAGES CXX VERSION 0.1.0)
configure_file(${PROJECT_NAME}Config.h.in ${PROJECT_NAME}Config.h)

FIND_PACKAGE(Qt6 REQUIRED COMPONENTS GUI Widgets )

SET(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

SET(CMAKE_AUTOMOC ON)
SET(CMAKE_AUTOUIC ON)
SET(CMAKE_AUTORCC ON)

#add_library(AntSimulatorPieces SHARED)
#target_sources(AntSimulatorPieces
#PRIVATE

#)
#target_compile_features(AntSimulatorPieces PUBLIC cxx_std_17)
#target_link_libraries(AntSimulatorPieces PRIVATE

#)

#install(TARGETS AntSimulatorPieces
#    EXPORT AntSimulatorPieces
#    FILE_SET HEADERS
#    LIBRARY DESTINATION lib
#    ARCHIVE DESTINATION lib
#    RUNTIME DESTINATION bin
#    INCLUDES DESTINATION include)

#install(EXPORT AntSimulatorPieces
#    FILE AntSimulatorPieces.cmake
#    NAMESPACE AntSimulatorPieces::
#    DESTINATION lib/cmake/AntSimulatorPieces)

#include(CMakePackageConfigHelpers)
#write_basic_package_version_file(
#    "AntSimulatorPiecesConfigVersion.cmake"
#    VERSION ${AntSimulatorPieces_VERSION}
#    COMPATIBILITY AnyNewerVersion)

#install(
#    FILES
#        "AntSimulatorPiecesConfig.cmake"
#    "${CMAKE_CURRENT_BINARY_DIR}/AntSimulatorPiecesConfigVersion.cmake"
#    DESTINATION lib/cmake/${PROJECT_NAME}
#)




add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME} 
PRIVATE
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindowform.ui
    resources.qrc
    ant.h ant.cpp
    colony.h colony.cpp
) 
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)
target_include_directories(${PROJECT_NAME} PRIVATE)

target_link_libraries(${PROJECT_NAME} PRIVATE
    Qt6::Widgets
    Qt6::Gui
    #AntSimulatorPieces
)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(AntSimulator_unittests)
target_sources(AntSimulator_unittests PRIVATE AntSimulator_unittests.cpp)
target_include_directories(AntSimulator_unittests PRIVATE "${GTEST_INCLUDE_DIRS}")

target_link_libraries(AntSimulator_unittests
    PRIVATE
        ${GTEST_LIBRARIES}
        ${GTEST_MAIN_LIBRARIES}
        #AntSimulatorPieces
)

install(TARGETS ${PROJECT_NAME}
    EXPORT ${PROJECT_NAME}Targets
    FILE_SET HEADERS
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
    INCLUDES DESTINATION include)

