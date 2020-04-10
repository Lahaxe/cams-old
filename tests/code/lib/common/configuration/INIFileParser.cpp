#define BOOST_TEST_MODULE ModuleINIFileParser

// Include Boost library
#include <boost/test/unit_test.hpp>

// Include Project files
#include "src/lib/common/configuration/INIFileParser.h"

/******************************** TEST Nominal ********************************/
/**
 * @brief Nominal test case: Constructor and Destructor
 */
BOOST_AUTO_TEST_CASE(Constructor)
{
    auto fileparser = cams::lib::common::INIFileParser::New("");
    BOOST_REQUIRE(fileparser != nullptr);
}

