#define BOOST_TEST_MODULE ModuleConnectorFile

// Include Project files
#include "tests/code/lib/connector/FixtureConnectorFile.h"

/******************************** TEST Nominal ********************************/
/**
 * @brief Nominal test case: Constructor and Destructor
 */
BOOST_FIXTURE_TEST_CASE(Constructor, FixtureConnectorFile)
{
    BOOST_CHECK(this->_connector != nullptr);
}

/******************************** TEST Nominal ********************************/
/**
 * @brief Nominal test case: Tests Getters and Setters
 */
BOOST_FIXTURE_TEST_CASE(Accessors, FixtureConnectorFile)
{
    BOOST_CHECK(this->_connector->get_identity() == nullptr);
    this->_connector->set_identity(cams::lib::model::Identity::New());
    BOOST_CHECK(this->_connector->get_identity() != nullptr);
}
