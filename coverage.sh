#!/bin/bash

export WORKSPACE=$PWD

cd build

# Generate Makefile
cmake -G Ninja -D BUILD_TESTING=ON -D CMAKE_CXX_FLAGS="-std=c++0x --coverage" ../

# Delete coverage data
lcov -z -d .

# Compile
ninja

# Run unit tests
../run_tests.sh

# Generate coverage data
lcov -c -d . -o cams.info

# Remove unused data
lcov -r cams.info '/usr*' -d . -o cams.info
lcov -r cams.info '/*/tests/code/*' -d . -o cams.info

# Generate a web page
genhtml -o lcov cams.info

cppcheck -q --xml --xml-version=2 --enable=all --inconclusive -i ${WORKSPACE}/src/ ${WORKSPACE}/tests/ 2> ${WORKSPACE}/build/cppcheck.xml

