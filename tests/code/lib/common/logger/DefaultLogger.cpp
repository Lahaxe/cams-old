#define BOOST_TEST_MODULE ModuleDefaultLogger

// Include Boost library
#include <boost/test/unit_test.hpp>

// Include Project files
#include "src/lib/common/logger/DefaultLogger.h"

/******************************** TEST Nominal ********************************/
/**
 * @brief Nominal test case: Constructor and Destructor
 */
BOOST_AUTO_TEST_CASE(Constructor)
{
    auto logger = cams::lib::common::DefaultLogger::New();
    BOOST_REQUIRE(logger != nullptr);
}
