#define BOOST_TEST_MODULE ModuleUnknownControllerException

// Include Boost library
#include <boost/test/unit_test.hpp>

// Include Project files
#include "src/lib/controller/UnknownControllerException.h"

/******************************** TEST Nominal ********************************/
/**
 * @brief Nominal test case: Constructor and Destructor
 */
BOOST_AUTO_TEST_CASE(Constructor)
{
    auto exception = new cams::lib::controller::UnknownControllerException("controller");
    BOOST_REQUIRE(exception != nullptr);

    BOOST_CHECK_EQUAL(std::string(exception->what()), "Given controller is unknown: controller");

    delete exception;
}


/******************************** TEST Nominal ********************************/
/**
 * @brief Nominal test case: Throw CamsException
 */
BOOST_AUTO_TEST_CASE(ThrowNotImplementedActionException)
{
    BOOST_CHECK_EXCEPTION(throw cams::lib::controller::UnknownControllerException("controller"),
                          cams::lib::controller::UnknownControllerException,
                          [](cams::lib::controller::UnknownControllerException const & exc)
                                {
                                    return std::string(exc.what()) ==
                                            std::string("Given controller is unknown: controller");
                                });
}
