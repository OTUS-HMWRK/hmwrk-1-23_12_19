cmake_minimum_required(VERSION 3.12...3.16)

set(
    MY_PROJECT_NAME
        HelloWorld   
)
set(
    DESCRIPTION
        hmwrk-1-23_12_19    
)

set(
    GIT_USER
        OTUS-HMWRK
)


if("" STREQUAL "$ENV{TRAVIS_BUILD_NUMBER}")
set(
        TRAVIS_BUILD_NUMBER 
        0
    )
else()
set(
        TRAVIS_BUILD_NUMBER 
            "$ENV{TRAVIS_BUILD_NUMBER}"
    )
endif()

    set(
        TRAVIS_BUILD_NUMBER 
            $ENV{TRAVIS_BUILD_NUMBER}
    )

set(
    CMAKE_TOOLCHAIN_FILE
    $ENV{VCPKG_PATH}
)

set(
    CMAKE_BUILD_TYPE
    Debug
)


project( ${MY_PROJECT_NAME}
    VERSION 0.0.${TRAVIS_BUILD_NUMBER}
    DESCRIPTION "hmwrk-1-23_12_19"
    HOMEPAGE_URL "https://otus.ru/lessons/razrabotchik-cpp/?int_source=courses_catalog&int_term=programming"
    LANGUAGES CXX
)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin/exe)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin/lib)

add_subdirectory(lib/version)
add_subdirectory(app)
add_subdirectory(tests/boost)
add_subdirectory(tests/gtest)

option(PROJECT_VERSION_PATCH ON)

configure_file(
    ${PROJECT_SOURCE_DIR}/conf/git_create_repo.txt.in 
    ${PROJECT_SOURCE_DIR}/conf/git_create_repo.txt)

configure_file(
    ${PROJECT_SOURCE_DIR}/conf/.travis.yml.in 
    ${PROJECT_SOURCE_DIR}/.travis.yml)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH ${TRAVIS_BUILD_NUMBER})

set(CPACK_PACKAGE_CONTACT yudov@hotmail.com)

include(CPack)

enable_testing()