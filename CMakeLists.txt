cmake_minimum_required(VERSION 3.29)
project(CS415_Project)

set(CMAKE_CXX_STANDARD 20)

add_executable(CS415_Project_Component1
        sortAlgsForPersons.cpp
        first-names.c
        surnames.c
        states.c
        Person.cpp
        Person.hpp
        first-names.h
        surnames.h
        states.h
)
