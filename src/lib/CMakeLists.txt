find_package(Boost REQUIRED COMPONENTS filesystem system)

file(GLOB_RECURSE Header_Files "*.h")
file(GLOB_RECURSE Source_Files "*.cpp")
file(GLOB_RECURSE templates "*.txx")

# Regroup files by folder
GroupFiles(Header_Files)
GroupFiles(Source_Files)

include_directories(${CMAKE_CURRENT_SOURCE_DIR} ${Boost_INCLUDE_DIRS})

add_library(libcams ${Source_Files} ${Header_Files} ${templates})
set_target_properties(libcams PROPERTIES OUTPUT_NAME libcams)

target_link_libraries(libcams ${Boost_LIBRARIES})

set_target_properties(libcams PROPERTIES
				 VERSION ${cams_VERSION}
				 SOVERSION ${cams_MAJOR_VERSION})
