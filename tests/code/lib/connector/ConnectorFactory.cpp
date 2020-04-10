#define BOOST_TEST_MODULE ModuleConnectorFactory

// Include Project files
#include "src/lib/connector/ConnectorFile.h"
#include "tests/code/lib/connector/FixtureConnectorFactory.h"

/******************************** TEST Nominal ********************************/
/**
 * @brief Nominal test case: Constructor and Destructor
 */
BOOST_FIXTURE_TEST_CASE(Constructor, FixtureConnectorFactory)
{
    // Nothing to do
}

/******************************** TEST Nominal ********************************/
/**
 * @brief Nominal test case: Tests function can_create
 */
BOOST_FIXTURE_TEST_CASE(CanCreate, FixtureConnectorFactory)
{
    BOOST_CHECK(cams::lib::connector::ConnectorFactory::instance().can_create(
                    cams::lib::connector::ConnectorFile::class_name()));

    BOOST_CHECK(!cams::lib::connector::ConnectorFactory::instance().can_create("error"));
}

/******************************** TEST Nominal ********************************/
/**
 * @brief Nominal test case: Tests function create
 */
BOOST_FIXTURE_TEST_CASE(Create, FixtureConnectorFactory)
{
    auto connectorfile = cams::lib::connector::ConnectorFactory::instance().create(
                cams::lib::connector::ConnectorFile::class_name());
    BOOST_CHECK(connectorfile != nullptr);

    auto errorconnector = cams::lib::connector::ConnectorFactory::instance().create("error");
    BOOST_CHECK(errorconnector == nullptr);
}
