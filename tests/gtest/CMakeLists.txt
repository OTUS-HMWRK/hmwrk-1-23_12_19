cmake_minimum_required(VERSION 3.12...3.16)

project( gtest_version
    VERSION 0.0.666#${TRAVIS_BUILD_NUMBER}
    DESCRIPTION "hmwrk-1-23_12_19"
    HOMEPAGE_URL "https://otus.ru/lessons/razrabotchik-cpp/?int_source=courses_catalog&int_term=programming"
    LANGUAGES CXX
)

find_package(GTest REQUIRED)

option(PROJECT_VERSION_PATCH ON)


set(
    HEADERS_TEST
    ${PROJECT_SOURCE_DIR}/../../include/version/gtests.h
    ${PROJECT_SOURCE_DIR}/../../include/version/version.h
)
add_executable(gtest_version ${HEADERS_TEST} gtests.cpp )


set_target_properties(
    gtest_version PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
)

target_include_directories(
    gtest_version
    PRIVATE 
    ${PROJECT_SOURCE_DIR}/../../include/version
    ${GTEST_INCLUDE_DIR}
)


if (UNIX)
target_link_libraries(
    gtest_version 
    PRIVATE
    ${GTEST_BOTH_LIBRARIES}
    pthread
    version
)    
endif (UNIX)

if (MSVC)
target_link_libraries(
    gtest_version 
    PRIVATE
    ${GTEST_BOTH_LIBRARIES}
    version
)
endif (MSVC)

if (MSVC)
    target_compile_options(gtest_version PRIVATE
        /W4
    )
else ()
    target_compile_options(gtest_version PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
endif()
add_test(gtest_version gtest_version)