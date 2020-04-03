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
 * @brief Nominal test case: Log a debug message
 */
BOOST_FIXTURE_TEST_CASE(LogDebug, FixtureLogger)
{
    std::stringbuf buffer(std::ios::out);
    auto oldbuffer = std::cout.rdbuf(std::addressof(buffer));

    cams::lib::common::Logger::instance().debug("Test debug message");

    std::cout.rdbuf(oldbuffer);

    auto output = buffer.str();
    BOOST_CHECK(output.find("DEBUG - Test debug message") != std::string::npos);
}

/******************************** TEST Nominal ********************************/
/**
 * @brief Nominal test case: Log an info message
 */
BOOST_FIXTURE_TEST_CASE(LogInfo, FixtureLogger)
{
    std::stringbuf buffer(std::ios::out);
    auto oldbuffer = std::cout.rdbuf(std::addressof(buffer));

    cams::lib::common::Logger::instance().info("Test info message");

    std::cout.rdbuf(oldbuffer);

    auto output = buffer.str();
    BOOST_CHECK(output.find("INFO - Test info message") != std::string::npos);
}

/******************************** TEST Nominal ********************************/
/**
 * @brief Nominal test case: Log a warning message
 */
BOOST_FIXTURE_TEST_CASE(LogWarning, FixtureLogger)
{
    std::stringbuf buffer(std::ios::out);
    auto oldbuffer = std::cout.rdbuf(std::addressof(buffer));

    cams::lib::common::Logger::instance().warning("Test warning message");

    std::cout.rdbuf(oldbuffer);

    auto output = buffer.str();
    BOOST_CHECK(output.find("WARN - Test warning message") != std::string::npos);
}

/******************************** TEST Nominal ********************************/
/**
 * @brief Nominal test case: Log an error message
 */
BOOST_FIXTURE_TEST_CASE(LogError, FixtureLogger)
{
    std::stringbuf buffer(std::ios::out);
    auto oldbuffer = std::cout.rdbuf(std::addressof(buffer));

    cams::lib::common::Logger::instance().error("Test error message");

    std::cout.rdbuf(oldbuffer);

    auto output = buffer.str();
    BOOST_CHECK(output.find("ERROR - Test error message") != std::string::npos);
}

/******************************** TEST Nominal ********************************/
/**
 * @brief Nominal test case: Log a fatal message
 */
BOOST_FIXTURE_TEST_CASE(LogFatal, FixtureLogger)
{
    std::stringbuf buffer(std::ios::out);
    auto oldbuffer = std::cout.rdbuf(std::addressof(buffer));

    cams::lib::common::Logger::instance().fatal("Test fatal message");

    std::cout.rdbuf(oldbuffer);

    auto output = buffer.str();
    BOOST_CHECK(output.find("FATAL - Test fatal message") != std::string::npos);
}
