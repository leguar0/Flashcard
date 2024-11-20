cmake_minimum_required(VERSION 3.10)

project(Flashcards)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# define source files
set(SOURCES 
	src/main.cpp
	src/Flashcard.cpp
	src/StatInfo.h
	src/User.cpp
)

# create the executable with the source files
add_executable(${CMAKE_PROJECT_NAME} ${SOURCES})