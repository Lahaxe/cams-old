#define BOOST_TEST_MODULE ModuleUser

// Include Project files
#include "FixtureUser.h"

/******************************** TEST Nominal ********************************/
/**
 * @brief Nominal test case: Constructor and Destructor
 */
BOOST_FIXTURE_TEST_CASE(Constructor, FixtureUser)
{
    BOOST_CHECK(this->_user != nullptr);
}

/******************************** TEST Nominal ********************************/
/**
 * @brief Nominal test case: Constructor and Destructor
 */
BOOST_FIXTURE_TEST_CASE(DefaultValues, FixtureUser)
{
    BOOST_REQUIRE(this->_user != nullptr);
    BOOST_CHECK_EQUAL(this->_user->get_name(), std::string(""));
}

/******************************** TEST Nominal ********************************/
/**
 * @brief Nominal test case: Constructor and Destructor
 */
BOOST_FIXTURE_TEST_CASE(Accessors, FixtureUser)
{
    BOOST_REQUIRE(this->_user != nullptr);
    this->_user->set_name("MYNAME");
    BOOST_CHECK_EQUAL(this->_user->get_name(), std::string("MYNAME"));
}
