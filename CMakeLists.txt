cmake_minimum_required(VERSION 3.16.0)
project(new_project VERSION 0.1.0)

# include(CTest)
# enable_testing()

add_executable(main
    src/main.cpp
    src/Lexer.cpp
    src/Parser.cpp
    src/BantamParser.cpp

    src/parselets/AssignParselet.cpp
    src/parselets/BinaryOperatorParselet.cpp
    src/parselets/CallParselet.cpp
    src/parselets/ConditionalParselet.cpp
    src/parselets/GroupParselet.cpp
    src/parselets/PrefixOperatorParselet.cpp
)
set_target_properties(main PROPERTIES CXX_STANDARD 20)
target_include_directories(main PRIVATE ${CMAKE_SOURCE_DIR}/include)

# set(CPACK_PROJECT_NAME ${PROJECT_NAME})
# set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
# include(CPack)
