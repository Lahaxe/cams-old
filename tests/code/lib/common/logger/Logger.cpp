#define BOOST_TEST_MODULE ModuleLogger

// Include Standard library
#include <iostream>

// Include Project files
#include "tests/code/lib/common/logger/FixtureLogger.h"

/******************************** TEST Nominal ********************************/
/**
 * @brief Nominal test case: Constructor and Destructor
 */
BOOST_FIXTURE_TEST_CASE(Constructor, FixtureLogger)
{
    // Nothing to do
}

/******************************** TEST Nominal ********************************/
/**
 * @brief Nominal test case: Accessors
 */
BOOST_FIXTURE_TEST_CASE(Accessors, FixtureLogger)
{
    cams::lib::common::Logger::instance().set_logger_writer(nullptr);
}

/******************************** TEST Nominal ********************************/
/**
 * @brief Nominal test case: Log a debug message
 */
BOOST_FIXTURE_TEST_CASE(LogDebug, FixtureLogger)
{
    cams::lib::common::Logger::instance().debug("Test debug message");
}

/******************************** TEST Nominal ********************************/
/**
 * @brief Nominal test case: Log an info message
 */
BOOST_FIXTURE_TEST_CASE(LogInfo, FixtureLogger)
{
    cams::lib::common::Logger::instance().info("Test info message");
}

/******************************** TEST Nominal ********************************/
/**
 * @brief Nominal test case: Log a warning message
 */
BOOST_FIXTURE_TEST_CASE(LogWarning, FixtureLogger)
{
    cams::lib::common::Logger::instance().warning("Test warning message");
}

/******************************** TEST Nominal ********************************/
/**
 * @brief Nominal test case: Log an error message
 */
BOOST_FIXTURE_TEST_CASE(LogError, FixtureLogger)
{
    cams::lib::common::Logger::instance().error("Test error message");
}

/******************************** TEST Nominal ********************************/
/**
 * @brief Nominal test case: Log a fatal message
 */
BOOST_FIXTURE_TEST_CASE(LogFatal, FixtureLogger)
{
    cams::lib::common::Logger::instance().fatal("Test fatal message");
}
