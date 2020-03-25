find_package(Boost COMPONENTS unit_test_framework REQUIRED)

file(GLOB headers code/*.h)
file(GLOB_RECURSE tests code/*.cpp)

include_directories(${CMAKE_SOURCE_DIR}/src/
                    ${CMAKE_SOURCE_DIR}/tests/code/
                    ${Boost_INCLUDE_DIRS})

add_definitions(
    -D BOOST_ASIO_DYN_LINK
    -D cams_MAJOR_VERSION=${cams_MAJOR_VERSION}
    -DBOOST_TEST_DYN_LINK)

link_directories(${Boost_LIBRARY_DIRS})

foreach(test_file ${tests})
    get_filename_component(test ${test_file} NAME_WE)

    add_executable(test_${test} ${test_file} ${headers} ${extra_files})
    target_link_libraries(test_${test} libcams ${Boost_LIBRARIES})
    set_target_properties(test_${test} PROPERTIES OUTPUT_NAME ${test} FOLDER "Tests")

    file(READ ${test_file} content)

    set(pattern "BOOST_(AUTO|FIXTURE)_TEST_CASE\\(([^),]+)")

    string(REGEX MATCHALL ${pattern} cases ${content})

    foreach(case ${cases})
        string(REGEX REPLACE ${pattern} "\\2" case ${cases})
        if(NOT ${case} MATCHES "##")
            add_test("${test}_${case}" "${test}" "--run_test=${case}")
        endif()
    endforeach()

endforeach()
