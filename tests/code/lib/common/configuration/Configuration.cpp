#define BOOST_TEST_MODULE ModuleConfiguration

// Include Boost library
#include <boost/test/unit_test.hpp>

// Include Project files
#include "tests/code/lib/common/configuration/FixtureConfiguration.h"

/******************************** TEST Nominal ********************************/
/**
 * @brief Nominal test case: Constructor and Destructor
 */
BOOST_FIXTURE_TEST_CASE(Constructor, FixtureConfiguration)
{
    cams::lib::common::Configuration::instance();
    cams::lib::common::Configuration::delete_instance();
}

/******************************** TEST Nominal ********************************/
/**
 * @brief Nominal test case: Constructor and Destructor
 */
BOOST_FIXTURE_TEST_CASE(Accessors, FixtureConfiguration)
{
    cams::lib::common::Configuration::instance();

    BOOST_CHECK_EQUAL(cams::lib::common::Configuration::instance().get_logger_type(), "file");
    cams::lib::common::Configuration::instance().set_logger_type("cout");
    BOOST_CHECK_EQUAL(cams::lib::common::Configuration::instance().get_logger_type(), "cout");

    BOOST_CHECK_EQUAL(cams::lib::common::Configuration::instance().get_connector_type(), "file");
    cams::lib::common::Configuration::instance().set_connector_type("cout");
    BOOST_CHECK_EQUAL(cams::lib::common::Configuration::instance().get_connector_type(), "cout");

    BOOST_CHECK_EQUAL(cams::lib::common::Configuration::instance().get_connector_file_root_path(), "./data");
    cams::lib::common::Configuration::instance().set_connector_file_root_path("./otherdir");
    BOOST_CHECK_EQUAL(cams::lib::common::Configuration::instance().get_connector_file_root_path(), "./otherdir");
    cams::lib::common::Configuration::delete_instance();
}
