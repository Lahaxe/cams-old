#define BOOST_TEST_MODULE ModuleNotImplementedActionException

// Include Boost library
#include <boost/test/unit_test.hpp>

// Include Project files
#include "src/lib/controller/NotImplementedActionException.h"

/******************************** TEST Nominal ********************************/
/**
 * @brief Nominal test case: Constructor and Destructor
 */
BOOST_AUTO_TEST_CASE(Constructor)
{
    auto exception = new cams::lib::controller::NotImplementedActionException("action");
    BOOST_REQUIRE(exception != nullptr);

    BOOST_CHECK_EQUAL(std::string(exception->what()), "The controller does not implement the action 'action'");

    delete exception;
}


/******************************** TEST Nominal ********************************/
/**
 * @brief Nominal test case: Throw CamsException
 */
BOOST_AUTO_TEST_CASE(ThrowNotImplementedActionException)
{
    BOOST_CHECK_EXCEPTION(throw cams::lib::controller::NotImplementedActionException("action"),
                          cams::lib::controller::NotImplementedActionException,
                          [](cams::lib::controller::NotImplementedActionException const & exc)
                                {
                                    return std::string(exc.what()) ==
                                            std::string("The controller does not implement the action 'action'");
                                });
}
