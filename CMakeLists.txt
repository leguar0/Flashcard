cmake_minimum_required(VERSION 3.17)

project(Flashcards VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOMOC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# define source files
set(SOURCES 
	src/main.cpp
	src/Flashcard.cpp
	src/FlashHandler.cpp
	src/StatsManager.cpp
	src/User.cpp
	qml/main.qml
	qml/qml.qrc
)

# qt libraries
find_package(Qt6 6.7.2 REQUIRED COMPONENTS Core Quick)

# create the executable with the source files
add_executable(${CMAKE_PROJECT_NAME} ${SOURCES})
target_link_libraries(${CMAKE_PROJECT_NAME} Qt6::Core Qt6::Quick)