#define BOOST_TEST_MODULE ModuleUnknownActionException

// Include Boost library
#include <boost/test/unit_test.hpp>

// Include Project files
#include "src/lib/controller/UnknownActionException.h"

/******************************** TEST Nominal ********************************/
/**
 * @brief Nominal test case: Constructor and Destructor
 */
BOOST_AUTO_TEST_CASE(Constructor)
{
    auto exception = new libcams::controller::UnknownActionException("action");
    BOOST_REQUIRE(exception != nullptr);

    BOOST_CHECK_EQUAL(std::string(exception->what()), "Given action is unknown: action");

    delete exception;
}


/******************************** TEST Nominal ********************************/
/**
 * @brief Nominal test case: Throw CamsException
 */
BOOST_AUTO_TEST_CASE(ThrowNotImplementedActionException)
{
    BOOST_CHECK_EXCEPTION(throw libcams::controller::UnknownActionException("action"),
                          libcams::controller::UnknownActionException,
                          [](libcams::controller::UnknownActionException const & exc)
                                {
                                    return std::string(exc.what()) ==
                                            std::string("Given action is unknown: action");
                                });
}
