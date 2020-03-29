#define BOOST_TEST_MODULE ModuleUnknownArgumentException

// Include Boost library
#include <boost/test/unit_test.hpp>

// Include Project files
#include "lib/camscli/UnknownArgumentException.h"

/******************************** TEST Nominal ********************************/
/**
 * @brief Nominal test case: Constructor and Destructor
 */
BOOST_AUTO_TEST_CASE(Constructor)
{
    auto exception = new libcams::camscli::UnknownArgumentException("Argument");
    BOOST_REQUIRE(exception != nullptr);

    BOOST_CHECK_EQUAL(std::string(exception->what()), "At least one argument is unknown: Argument");

    delete exception;
}


/******************************** TEST Nominal ********************************/
/**
 * @brief Nominal test case: Throw CamsException
 */
BOOST_AUTO_TEST_CASE(ThrowUnknownArgumentException)
{
    BOOST_CHECK_EXCEPTION(throw libcams::camscli::UnknownArgumentException("Argument"),
                          libcams::camscli::UnknownArgumentException,
                          [](libcams::camscli::UnknownArgumentException const & exc)
                                {
                                    return std::string(exc.what()) ==
                                            std::string("At least one argument is unknown: Argument");
                                });
}
