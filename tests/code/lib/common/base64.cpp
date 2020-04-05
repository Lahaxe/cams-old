#define BOOST_TEST_MODULE ModuleBase64

// Include Boost library
#include <boost/test/unit_test.hpp>

// Include Project files
#include "src/lib/common/base64.h"

const std::string CLEAR_TEXT = "clear text";
const std::string BASE64_TEXT = "Y2xlYXIgdGV4dA==";

/******************************** TEST Nominal ********************************/
/**
 * @brief Nominal test case: Tests function to_base64
 */
BOOST_AUTO_TEST_CASE(ToBase64)
{
    BOOST_CHECK_EQUAL(cams::lib::common::to_base64(CLEAR_TEXT), BASE64_TEXT);
}

/******************************** TEST Nominal ********************************/
/**
 * @brief Nominal test case: Tests function from_base64
 */
BOOST_AUTO_TEST_CASE(FromBase64)
{
    BOOST_CHECK_EQUAL(cams::lib::common::from_base64(BASE64_TEXT), CLEAR_TEXT);
}
