#define BOOST_TEST_MODULE ModuleINIFileParser

// Include Boost library
#include <boost/test/unit_test.hpp>

// Include Project files
#include "tests/code/lib/common/configuration/FixtureINIFileParser.h"

/******************************** TEST Nominal ********************************/
/**
 * @brief Nominal test case: Constructor and Destructor
 */
BOOST_FIXTURE_TEST_CASE(Constructor, FixtureINIFileParser)
{
    BOOST_CHECK(this->_fileparser != nullptr);
}

/******************************** TEST Nominal ********************************/
/**
 * @brief Nominal test case: Tests function read
 */
BOOST_FIXTURE_TEST_CASE(Read, FixtureINIFileParser)
{
    BOOST_REQUIRE(this->_fileparser != nullptr);

    this->_fileparser->read();
    BOOST_CHECK_EQUAL(this->_fileparser->contains_key("section.field"), true);
}

/******************************** TEST Nominal ********************************/
/**
 * @brief Nominal test case: Tests function write
 */
BOOST_FIXTURE_TEST_CASE(Write, FixtureINIFileParser)
{
    auto fileparser =
            cams::lib::common::INIFileParser::New(TEST_FILE_INIFILEPARSER_WRITE);
    BOOST_REQUIRE(fileparser != nullptr);

    fileparser->set_value("section.writefield", "writevalue");
    fileparser->write();

    std::ifstream expected_file(TEST_FILE_INIFILEPARSER_WRITE);

    std::string file_content((std::istreambuf_iterator<char>(expected_file)),
                             (std::istreambuf_iterator<char>()));

    std::stringstream expected_result;
    expected_result << "[section]\n";
    expected_result << "writefield=writevalue\n";

    BOOST_CHECK_EQUAL(file_content, expected_result.str());
}

/******************************** TEST Nominal ********************************/
/**
 * @brief Nominal test case: Tests function contains_key
 */
BOOST_FIXTURE_TEST_CASE(ContainsKey, FixtureINIFileParser)
{
    BOOST_REQUIRE(this->_fileparser != nullptr);
    this->_fileparser->read();

    BOOST_CHECK_EQUAL(this->_fileparser->contains_key("section.field"), true);
    BOOST_CHECK_EQUAL(this->_fileparser->contains_key("section.notfield"), false);
}

/******************************** TEST Nominal ********************************/
/**
 * @brief Nominal test case: Tests function get_value
 */
BOOST_FIXTURE_TEST_CASE(GetValue, FixtureINIFileParser)
{
    BOOST_REQUIRE(this->_fileparser != nullptr);
    this->_fileparser->read();

    BOOST_CHECK_EQUAL(this->_fileparser->get_value("section.field"), "value");
}

/******************************** TEST Nominal ********************************/
/**
 * @brief Nominal test case: Tests function set_value
 */
BOOST_FIXTURE_TEST_CASE(SetValue, FixtureINIFileParser)
{
    BOOST_REQUIRE(this->_fileparser != nullptr);
    this->_fileparser->read();

    BOOST_CHECK_EQUAL(this->_fileparser->get_value("section.field"), "value");
    this->_fileparser->set_value("section.field", "newvalue");
    BOOST_CHECK_EQUAL(this->_fileparser->get_value("section.field"), "newvalue");
}

/******************************** TEST Error **********************************/
/**
 * @brief Error test case: Read empty filename
 */
BOOST_AUTO_TEST_CASE(ReadEmptyfilename)
{
    auto fileparser = cams::lib::common::INIFileParser::New("");
    BOOST_REQUIRE(fileparser != nullptr);
    BOOST_CHECK_EXCEPTION(fileparser->read(),
                          std::exception,
                          [](std::exception const & __attribute__((unused))exc)
                                {
                                    return true;
                                });
}

/******************************** TEST Error **********************************/
/**
 * @brief Error test case: Read unknown file
 */
BOOST_AUTO_TEST_CASE(ReadUnkownFile)
{
    auto fileparser = cams::lib::common::INIFileParser::New("unknown_file.ini");
    BOOST_REQUIRE(fileparser != nullptr);
    BOOST_CHECK_EXCEPTION(fileparser->read(),
                          std::exception,
                          [](std::exception const & __attribute__((unused))exc)
                                {
                                    return true;
                                });
}

/******************************** TEST Error **********************************/
/**
 * @brief Error test case: Write empty filename
 */
BOOST_AUTO_TEST_CASE(WriteEmptyfilename)
{
    auto fileparser = cams::lib::common::INIFileParser::New("");
    BOOST_REQUIRE(fileparser != nullptr);
    BOOST_CHECK_EXCEPTION(fileparser->write(),
                          std::exception,
                          [](std::exception const & __attribute__((unused))exc)
                                {
                                    return true;
                                });
}
