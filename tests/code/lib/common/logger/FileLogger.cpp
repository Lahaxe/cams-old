#define BOOST_TEST_MODULE ModuleFileLogger

// Include Project files
#include "tests/code/lib/common/logger/FixtureFileLogger.h"

/******************************** TEST Nominal ********************************/
/**
 * @brief Nominal test case: Constructor and Destructor
 */
BOOST_FIXTURE_TEST_CASE(Constructor, FixtureFileLogger)
{
    BOOST_CHECK(this->_logger != nullptr);
}

/******************************** TEST Nominal ********************************/
/**
 * @brief Nominal test case: Log a debug message
 */
BOOST_FIXTURE_TEST_CASE(LogDebug, FixtureFileLogger)
{
    BOOST_REQUIRE(this->_logger != nullptr);
    this->_logger->debug("Test debug message");

    auto result = this->_get_file_content();
    BOOST_CHECK(result.find("DEBUG - Test debug message") != std::string::npos);
}

/******************************** TEST Nominal ********************************/
/**
 * @brief Nominal test case: Log an info message
 */
BOOST_FIXTURE_TEST_CASE(LogInfo, FixtureFileLogger)
{
    BOOST_REQUIRE(this->_logger != nullptr);
    this->_logger->info("Test info message");

    auto result = this->_get_file_content();
    BOOST_CHECK(result.find("INFO - Test info message") != std::string::npos);
}

/******************************** TEST Nominal ********************************/
/**
 * @brief Nominal test case: Log a warning message
 */
BOOST_FIXTURE_TEST_CASE(LogWarning, FixtureFileLogger)
{
    BOOST_REQUIRE(this->_logger != nullptr);
    this->_logger->warning("Test warning message");

    auto result = this->_get_file_content();
    BOOST_CHECK(result.find("WARN - Test warning message") != std::string::npos);
}

/******************************** TEST Nominal ********************************/
/**
 * @brief Nominal test case: Log an error message
 */
BOOST_FIXTURE_TEST_CASE(LogError, FixtureFileLogger)
{
    BOOST_REQUIRE(this->_logger != nullptr);
    this->_logger->error("Test error message");

    auto result = this->_get_file_content();
    BOOST_CHECK(result.find("ERROR - Test error message") != std::string::npos);
}

/******************************** TEST Nominal ********************************/
/**
 * @brief Nominal test case: Log a fatal message
 */
BOOST_FIXTURE_TEST_CASE(LogFatal, FixtureFileLogger)
{
    BOOST_REQUIRE(this->_logger != nullptr);
    this->_logger->fatal("Test fatal message");

    auto result = this->_get_file_content();
    BOOST_CHECK(result.find("FATAL - Test fatal message") != std::string::npos);
}
