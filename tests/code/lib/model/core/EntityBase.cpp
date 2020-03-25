#define BOOST_TEST_MODULE ModuleEntityBase

// Include Project files
#include "FixtureEntityBase.h"

/******************************** TEST Nominal ********************************/
/**
 * @brief Nominal test case: Constructor and Destructor
 */
BOOST_FIXTURE_TEST_CASE(Constructor, FixtureEntityBase)
{
    BOOST_CHECK(this->_entity != nullptr);
}

/******************************** TEST Nominal ********************************/
/**
 * @brief Nominal test case: Constructor and Destructor
 */
BOOST_FIXTURE_TEST_CASE(DefaultValues, FixtureEntityBase)
{
    BOOST_REQUIRE(this->_entity != nullptr);
    BOOST_CHECK_EQUAL(this->_entity->get_id(), std::string(""));
}

/******************************** TEST Nominal ********************************/
/**
 * @brief Nominal test case: Constructor and Destructor
 */
BOOST_FIXTURE_TEST_CASE(Accessors, FixtureEntityBase)
{
    BOOST_REQUIRE(this->_entity != nullptr);
    this->_entity->set_id("ID456");
    BOOST_CHECK_EQUAL(this->_entity->get_id(), std::string("ID456"));
}
