cmake_minimum_required(VERSION 3.10)

project(ProjectName)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(${PROJECT_NAME}

    main.cpp

    src/Student.cpp

    src/StudentGroup.cpp

    include/Student.h

    include/StudentGroup.h

)