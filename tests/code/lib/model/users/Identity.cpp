#define BOOST_TEST_MODULE ModuleIdentity

// Include Project files
#include "tests/code/lib/model/users/FixtureIdentity.h"

/******************************** TEST Nominal ********************************/
/**
 * @brief Nominal test case: Constructor and Destructor
 */
BOOST_FIXTURE_TEST_CASE(Constructor, FixtureIdentity)
{
    BOOST_CHECK(this->_identity != nullptr);
}

/******************************** TEST Nominal ********************************/
/**
 * @brief Nominal test case: Constructor and Destructor
 */
BOOST_FIXTURE_TEST_CASE(DefaultValues, FixtureIdentity)
{
}

/******************************** TEST Nominal ********************************/
/**
 * @brief Nominal test case: Constructor and Destructor
 */
BOOST_FIXTURE_TEST_CASE(Accessors, FixtureIdentity)
{
}
