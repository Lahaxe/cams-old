#define BOOST_TEST_MODULE ModuleCamsException

// Include Standard library files
#include <sstream>

// Include Boost library
#include <boost/test/unit_test.hpp>

// Include Project files
#include "src/lib/common/exception/CamsException.h"

/******************************** TEST Nominal ********************************/
/**
 * @brief Nominal test case: Constructor and Destructor
 */
BOOST_AUTO_TEST_CASE(Constructor)
{
    auto exception = new cams::lib::common::CamsException("Mon message");
    BOOST_REQUIRE(exception != nullptr);

    BOOST_CHECK_EQUAL(std::string(exception->what()), "Mon message");

    delete exception;
}

/******************************** TEST Nominal ********************************/
/**
 * @brief Nominal test case: Throw CamsException
 */
BOOST_AUTO_TEST_CASE(ThrowCamsException)
{
    BOOST_CHECK_EXCEPTION(throw cams::lib::common::CamsException("Mon message"),
                          cams::lib::common::CamsException,
                          [](cams::lib::common::CamsException const & exc)
                                {
                                    return std::string(exc.what()) ==
                                            std::string("Mon message");
                                });
}

/******************************** TEST Nominal ********************************/
/**
 * @brief Nominal test case: Tests function to_json
 */
BOOST_AUTO_TEST_CASE(ToJson)
{
    auto exception = new cams::lib::common::CamsException("Mon message", 404);
    BOOST_REQUIRE(exception != nullptr);

    auto json_exception = exception->to_json();

    std::stringstream expected_result;
    expected_result << "{\n";
    expected_result << "    \"error\": \"Mon message\",\n";
    expected_result << "    \"errorcode\": \"404\"\n";
    expected_result << "}\n";

    BOOST_CHECK_EQUAL(json_exception, expected_result.str());

    delete exception;
}
