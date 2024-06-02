cmake_minimum_required(VERSION 3.10)

project(OOPHomework2)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(MyExecutable
        Main.cpp
        PartialFunction.h
        CriteriaPartialFunction.hpp
        Criteria1Func.h
        Criteria2Func.h
        Criteria3Func.h
        MaxPartialFunction.h
        MinPartialFunction.h
        Criteria1Func.cpp
        Criteria2Func.cpp
        Criteria3Func.cpp
        MaxPartialFunction.cpp
        MinPartialFunction.cpp CriteriaType.h CriteriaType.cpp resultPair.h)