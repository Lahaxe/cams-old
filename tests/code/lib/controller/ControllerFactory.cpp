#define BOOST_TEST_MODULE ModuleControllerFactory

// Include Standard library
#include <iostream>

// Include Project files
#include "tests/code/lib/controller/FixtureControllerFactory.h"
#include "src/lib/controller/ControllerToken.h"

/******************************** TEST Nominal ********************************/
/**
 * @brief Nominal test case: Constructor and Destructor
 */
BOOST_FIXTURE_TEST_CASE(Constructor, FixtureControllerFactory)
{
    // Nothing to do
}

/******************************** TEST Nominal ********************************/
/**
 * @brief Nominal test case: Function can_create
 */
BOOST_FIXTURE_TEST_CASE(CanCreate, FixtureControllerFactory)
{
    BOOST_CHECK(cams::lib::controller::ControllerFactory::instance().can_create(
                    cams::lib::controller::ControllerToken::class_name()) == true);
    BOOST_CHECK(cams::lib::controller::ControllerFactory::instance().can_create(
                    "error") == false);
}

/******************************** TEST Nominal ********************************/
/**
 * @brief Nominal test case: Function create
 */
BOOST_FIXTURE_TEST_CASE(Create, FixtureControllerFactory)
{
    BOOST_CHECK(cams::lib::controller::ControllerFactory::instance().create(
                    cams::lib::controller::ControllerToken::class_name()) != nullptr);
    BOOST_CHECK(cams::lib::controller::ControllerFactory::instance().create(
                    "error") == nullptr);
}
