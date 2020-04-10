#define BOOST_TEST_MODULE ModuleLoggerBase

// Include Project files
#include "tests/code/lib/common/logger/FixtureLoggerBase.h"

/******************************** TEST Nominal ********************************/
/**
 * @brief Nominal test case: Constructor and Destructor
 */
BOOST_FIXTURE_TEST_CASE(Constructor, FixtureLoggerBase)
{
    // Nothing to do
}

/******************************** TEST Nominal ********************************/
/**
 * @brief Nominal test case: Log a debug message
 */
BOOST_FIXTURE_TEST_CASE(LogDebug, FixtureLoggerBase)
{
    this->_logger->debug("Test debug message");
}

/******************************** TEST Nominal ********************************/
/**
 * @brief Nominal test case: Log an info message
 */
BOOST_FIXTURE_TEST_CASE(LogInfo, FixtureLoggerBase)
{
    this->_logger->info("Test info message");
}

/******************************** TEST Nominal ********************************/
/**
 * @brief Nominal test case: Log a warning message
 */
BOOST_FIXTURE_TEST_CASE(LogWarning, FixtureLoggerBase)
{
    this->_logger->warning("Test warning message");
}

/******************************** TEST Nominal ********************************/
/**
 * @brief Nominal test case: Log an error message
 */
BOOST_FIXTURE_TEST_CASE(LogError, FixtureLoggerBase)
{
    this->_logger->error("Test error message");
}

/******************************** TEST Nominal ********************************/
/**
 * @brief Nominal test case: Log a fatal message
 */
BOOST_FIXTURE_TEST_CASE(LogFatal, FixtureLoggerBase)
{
    this->_logger->fatal("Test fatal message");
}
