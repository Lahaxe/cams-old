#define BOOST_TEST_MODULE ModuleMissingArgumentException

// Include Boost library
#include <boost/test/unit_test.hpp>

// Include Project files
#include "src/cli/arguments/MissingArgumentException.h"

/******************************** TEST Nominal ********************************/
/**
 * @brief Nominal test case: Constructor and Destructor
 */
BOOST_AUTO_TEST_CASE(Constructor)
{
    auto exception = new camscli::MissingArgumentException("Argument");
    BOOST_REQUIRE(exception != nullptr);

    BOOST_CHECK_EQUAL(std::string(exception->what()), "At least one argument is missing: Argument");

    delete exception;
}


/******************************** TEST Nominal ********************************/
/**
 * @brief Nominal test case: Throw CamsException
 */
BOOST_AUTO_TEST_CASE(ThrowMissingArgumentException)
{
    BOOST_CHECK_EXCEPTION(throw camscli::MissingArgumentException("Argument"),
                          camscli::MissingArgumentException,
                          [](camscli::MissingArgumentException const & exc)
                                {
                                    return std::string(exc.what()) ==
                                            std::string("At least one argument is missing: Argument");
                                });
}
