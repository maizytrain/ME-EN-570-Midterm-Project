cmake_minimum_required(VERSION 3.23)
project(AntSimulator LANGUAGES CXX VERSION 0.1.0)
configure_file(${PROJECT_NAME}Config.h.in ${PROJECT_NAME}Config.h)

FIND_PACKAGE(Qt6 REQUIRED COMPONENTS GUI Widgets )
find_package(GTest REQUIRED)

SET(CMAKE_INCLUDE_CURRENT_DIR ON)

SET(CMAKE_AUTOMOC ON)
SET(CMAKE_AUTOUIC ON)
SET(CMAKE_AUTORCC ON)

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
)

add_executable(AntSimulator_unittests)
target_sources(AntSimulator_unittests PRIVATE AntSimulator_unittests.cpp)
target_include_directories(AntSimulator_unittests PRIVATE "${GTEST_INCLUDE_DIRS}")

target_link_libraries(AntSimulator_unittests
    PRIVATE
        ${GTEST_LIBRARIES}
        ${GTEST_MAIN_LIBRARIES}
        Qt6::Widgets
        Qt6::Gui
        AntSimulator
)

install(TARGETS ${PROJECT_NAME}
    EXPORT ${PROJECT_NAME}Targets
    FILE_SET HEADERS
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
    INCLUDES DESTINATION include)

