#define BOOST_TEST_MODULE ModuleLoggerFactory

// Include Project files
#include "src/lib/common/logger/DefaultLogger.h"
#include "src/lib/common/logger/FileLogger.h"
#include "tests/code/lib/common/logger/FixtureLoggerFactory.h"

/******************************** TEST Nominal ********************************/
/**
 * @brief Nominal test case: Constructor and Destructor
 */
BOOST_FIXTURE_TEST_CASE(Constructor, FixtureLoggerFactory)
{
    // Nothing to do
}

/******************************** TEST Nominal ********************************/
/**
 * @brief Nominal test case: Tests function can_create
 */
BOOST_FIXTURE_TEST_CASE(CanCreate, FixtureLoggerFactory)
{
    BOOST_CHECK(cams::lib::common::LoggerFactory::instance().can_create(
                    cams::lib::common::DefaultLogger::class_name()));
    BOOST_CHECK(cams::lib::common::LoggerFactory::instance().can_create(
                    cams::lib::common::FileLogger::class_name()));

    BOOST_CHECK(!cams::lib::common::LoggerFactory::instance().can_create("error"));
}

/******************************** TEST Nominal ********************************/
/**
 * @brief Nominal test case: Tests function create
 */
BOOST_FIXTURE_TEST_CASE(Create, FixtureLoggerFactory)
{
    auto defaultlogger = cams::lib::common::LoggerFactory::instance().create(
                cams::lib::common::DefaultLogger::class_name());
    BOOST_CHECK(defaultlogger != nullptr);

    auto filelogger = cams::lib::common::LoggerFactory::instance().create(
                cams::lib::common::FileLogger::class_name());
    BOOST_CHECK(filelogger != nullptr);

    auto errorlogger = cams::lib::common::LoggerFactory::instance().create("error");
    BOOST_CHECK(errorlogger == nullptr);
}
