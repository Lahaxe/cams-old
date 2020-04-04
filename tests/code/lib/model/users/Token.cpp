#define BOOST_TEST_MODULE ModuleToken

// Include Project files
#include "tests/code/lib/model/users/FixtureToken.h"

/******************************** TEST Nominal ********************************/
/**
 * @brief Nominal test case: Constructor and Destructor
 */
BOOST_FIXTURE_TEST_CASE(Constructor, FixtureToken)
{
    BOOST_CHECK(this->_token != nullptr);
}

/******************************** TEST Nominal ********************************/
/**
 * @brief Nominal test case: Constructor and Destructor
 */
BOOST_FIXTURE_TEST_CASE(DefaultValues, FixtureToken)
{
}

/******************************** TEST Nominal ********************************/
/**
 * @brief Nominal test case: Constructor and Destructor
 */
BOOST_FIXTURE_TEST_CASE(Accessors, FixtureToken)
{
}
