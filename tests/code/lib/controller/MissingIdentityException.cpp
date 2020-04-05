#define BOOST_TEST_MODULE ModuleMissingIdentityException

// Include Boost library
#include <boost/test/unit_test.hpp>

// Include Project files
#include "src/lib/controller/MissingIdentityException.h"

/******************************** TEST Nominal ********************************/
/**
 * @brief Nominal test case: Constructor and Destructor
 */
BOOST_AUTO_TEST_CASE(Constructor)
{
    auto exception = new cams::lib::controller::MissingIdentityException();
    BOOST_REQUIRE(exception != nullptr);

    //BOOST_CHECK_EQUAL(std::string(exception->what()), "Login and/or password are invalid");

    delete exception;
}

/******************************** TEST Nominal ********************************/
/**
 * @brief Nominal test case: Throw CamsException
 */
BOOST_AUTO_TEST_CASE(ThrowCamsException)
{
    /*BOOST_CHECK_EXCEPTION(throw cams::lib::controller::MissingIdentityException(),
                          cams::lib::controller::MissingIdentityException,
                          [](cams::lib::controller::MissingIdentityException const & exc)
                                {
                                    return std::string(exc.what()) ==
                                            std::string("Login and/or password are invalid");
                                });*/
}
