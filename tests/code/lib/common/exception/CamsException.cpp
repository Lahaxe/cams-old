#define BOOST_TEST_MODULE ModuleCamsException

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
    auto exception = new libcams::common::CamsException("Mon message");
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
    BOOST_CHECK_EXCEPTION(throw libcams::common::CamsException("Mon message"),
                          libcams::common::CamsException,
                          [](libcams::common::CamsException const & exc)
                                {
                                    return std::string(exc.what()) ==
                                            std::string("Mon message");
                                });
}
