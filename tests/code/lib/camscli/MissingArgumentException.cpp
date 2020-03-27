#define BOOST_TEST_MODULE ModuleMissingArgumentException

// Include Boost library
#include <boost/test/unit_test.hpp>

// Include Project files
#include "lib/camscli/MissingArgumentException.h"

/******************************** TEST Nominal ********************************/
/**
 * @brief Nominal test case: Constructor and Destructor
 */
BOOST_AUTO_TEST_CASE(Constructor)
{
    auto exception = new libcams::camscli::MissingArgumentException("Argument");
    BOOST_REQUIRE(exception != nullptr);

    BOOST_CHECK_EQUAL(std::string(exception->what()), "At least one argument is missing: Argument");

    delete exception;
}


/******************************** TEST Nominal ********************************/
/**
 * @brief Nominal test case: Throw CamsException
 */
BOOST_AUTO_TEST_CASE(ThrowCamsException)
{
    BOOST_CHECK_EXCEPTION(throw libcams::camscli::MissingArgumentException("Argument"),
                          libcams::camscli::MissingArgumentException,
                          [](libcams::camscli::MissingArgumentException const & exc)
                                {
                                    return std::string(exc.what()) ==
                                            std::string("At least one argument is missing: Argument");
                                });
}
