cmake_minimum_required(VERSION 2.8.3)
project(parse_input)

add_compile_options(-std=c++11)

add_executable(${PROJECT_NAME}
    main.cpp
    input_from_txt.h
    path.h)
