#define BOOST_TEST_MODULE ModuleRefusedLoginException

// Include Boost library
#include <boost/test/unit_test.hpp>

// Include Project files
#include "src/lib/common/exception/RefusedLoginException.h"

/******************************** TEST Nominal ********************************/
/**
 * @brief Nominal test case: Constructor and Destructor
 */
BOOST_AUTO_TEST_CASE(Constructor)
{
    auto exception = new cams::lib::common::RefusedLoginException();
    BOOST_REQUIRE(exception != nullptr);

    BOOST_CHECK_EQUAL(std::string(exception->what()), "Login and/or password are invalid");

    delete exception;
}

/******************************** TEST Nominal ********************************/
/**
 * @brief Nominal test case: Throw CamsException
 */
BOOST_AUTO_TEST_CASE(ThrowCamsException)
{
    BOOST_CHECK_EXCEPTION(throw cams::lib::common::RefusedLoginException(),
                          cams::lib::common::RefusedLoginException,
                          [](cams::lib::common::RefusedLoginException const & exc)
                                {
                                    return std::string(exc.what()) ==
                                            std::string("Login and/or password are invalid");
                                });
}
