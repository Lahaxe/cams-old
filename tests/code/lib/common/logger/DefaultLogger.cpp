#define BOOST_TEST_MODULE ModuleDefaultLogger

// Include Standard library files
#include <iostream>

// Include Project files
#include "tests/code/lib/common/logger/FixtureDefaultLogger.h"

/******************************** TEST Nominal ********************************/
/**
 * @brief Nominal test case: Constructor and Destructor
 */
BOOST_FIXTURE_TEST_CASE(Constructor, FixtureDefaultLogger)
{
    BOOST_CHECK(this->_logger != nullptr);
}

/******************************** TEST Nominal ********************************/
/**
 * @brief Nominal test case: Log a debug message
 */
BOOST_FIXTURE_TEST_CASE(LogDebug, FixtureDefaultLogger)
{
    BOOST_REQUIRE(this->_logger != nullptr);

    std::stringbuf buffer(std::ios::out);
    auto oldbuffer = std::cout.rdbuf(std::addressof(buffer));

    this->_logger->debug("Test debug message");

    std::cout.rdbuf(oldbuffer);

    auto output = buffer.str();
    BOOST_CHECK(output.find("DEBUG - Test debug message") != std::string::npos);
}

/******************************** TEST Nominal ********************************/
/**
 * @brief Nominal test case: Log an info message
 */
BOOST_FIXTURE_TEST_CASE(LogInfo, FixtureDefaultLogger)
{
    BOOST_REQUIRE(this->_logger != nullptr);

    std::stringbuf buffer(std::ios::out);
    auto oldbuffer = std::cout.rdbuf(std::addressof(buffer));

    this->_logger->info("Test info message");

    std::cout.rdbuf(oldbuffer);

    auto output = buffer.str();
    BOOST_CHECK(output.find("INFO - Test info message") != std::string::npos);
}

/******************************** TEST Nominal ********************************/
/**
 * @brief Nominal test case: Log a warning message
 */
BOOST_FIXTURE_TEST_CASE(LogWarning, FixtureDefaultLogger)
{
    BOOST_REQUIRE(this->_logger != nullptr);

    std::stringbuf buffer(std::ios::out);
    auto oldbuffer = std::cout.rdbuf(std::addressof(buffer));

    this->_logger->warning("Test warning message");

    std::cout.rdbuf(oldbuffer);

    auto output = buffer.str();
    BOOST_CHECK(output.find("WARN - Test warning message") != std::string::npos);
}

/******************************** TEST Nominal ********************************/
/**
 * @brief Nominal test case: Log an error message
 */
BOOST_FIXTURE_TEST_CASE(LogError, FixtureDefaultLogger)
{
    BOOST_REQUIRE(this->_logger != nullptr);

    std::stringbuf buffer(std::ios::out);
    auto oldbuffer = std::cout.rdbuf(std::addressof(buffer));

    this->_logger->error("Test error message");

    std::cout.rdbuf(oldbuffer);

    auto output = buffer.str();
    BOOST_CHECK(output.find("ERROR - Test error message") != std::string::npos);
}

/******************************** TEST Nominal ********************************/
/**
 * @brief Nominal test case: Log a fatal message
 */
BOOST_FIXTURE_TEST_CASE(LogFatal, FixtureDefaultLogger)
{
    BOOST_REQUIRE(this->_logger != nullptr);

    std::stringbuf buffer(std::ios::out);
    auto oldbuffer = std::cout.rdbuf(std::addressof(buffer));

    this->_logger->fatal("Test fatal message");

    std::cout.rdbuf(oldbuffer);

    auto output = buffer.str();
    BOOST_CHECK(output.find("FATAL - Test fatal message") != std::string::npos);
}
