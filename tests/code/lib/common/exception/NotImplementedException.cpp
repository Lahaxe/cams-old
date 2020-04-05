#define BOOST_TEST_MODULE ModuleNotImplementedException

// Include Boost library
#include <boost/test/unit_test.hpp>

// Include Project files
#include "src/lib/common/exception/NotImplementedException.h"

/******************************** TEST Nominal ********************************/
/**
 * @brief Nominal test case: Constructor and Destructor
 */
BOOST_AUTO_TEST_CASE(Constructor)
{
    auto exception = new cams::lib::common::NotImplementedException();
    BOOST_REQUIRE(exception != nullptr);

    BOOST_CHECK_EQUAL(std::string(exception->what()), "Function is not yet implemented");

    delete exception;
}

/******************************** TEST Nominal ********************************/
/**
 * @brief Nominal test case: Throw CamsException
 */
BOOST_AUTO_TEST_CASE(ThrowCamsException)
{
    BOOST_CHECK_EXCEPTION(throw cams::lib::common::NotImplementedException(),
                          cams::lib::common::NotImplementedException,
                          [](cams::lib::common::NotImplementedException const & exc)
                                {
                                    return std::string(exc.what()) ==
                                            std::string("Function is not yet implemented");
                                });
}
