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
 * @brief Nominal test case: Tests default values
 */
BOOST_FIXTURE_TEST_CASE(DefaultValues, FixtureIdentity)
{
    BOOST_REQUIRE(this->_identity != nullptr);
    BOOST_CHECK_EQUAL(this->_identity->get_login(), std::string(""));
    BOOST_CHECK_EQUAL(this->_identity->get_password(), std::string(""));
    BOOST_CHECK_EQUAL(this->_identity->get_token(), std::string(""));
}

/******************************** TEST Nominal ********************************/
/**
 * @brief Nominal test case: Tests Getters and Setters
 */
BOOST_FIXTURE_TEST_CASE(Accessors, FixtureIdentity)
{
    BOOST_REQUIRE(this->_identity != nullptr);
    this->_identity->set_login("MYLOGIN");
    BOOST_CHECK_EQUAL(this->_identity->get_login(), std::string("MYLOGIN"));
    this->_identity->set_password("MYPWD");
    BOOST_CHECK_EQUAL(this->_identity->get_password(), std::string("MYPWD"));
    this->_identity->set_token("TOKEN");
    BOOST_CHECK_EQUAL(this->_identity->get_token(), std::string("TOKEN"));
}
