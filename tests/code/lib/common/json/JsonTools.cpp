#define BOOST_TEST_MODULE ModuleJsonTools

// Include Boost library files
#include <boost/test/unit_test.hpp>

// Include Project files
#include "tests/code/lib/common/json/FixtureJsonTools.h"

/******************************** TEST Nominal ********************************/
/**
 * @brief Nominal test case: Tests function to_file
 */
BOOST_FIXTURE_TEST_CASE(ToJsonFile, FixtureJsonTools)
{
    QJsonObject object;
    object["field"] = QString("value");
    auto result = cams::lib::common::json::to_file(object, TEST_FILE_JSONTOOLS_WRITE);
    BOOST_REQUIRE_EQUAL(result, true);

    std::ifstream expected_file(TEST_FILE_JSONTOOLS_WRITE);

    std::string file_content((std::istreambuf_iterator<char>(expected_file)),
                             (std::istreambuf_iterator<char>()));

    std::stringstream expected_result;
    expected_result << "{\n";
    expected_result << "    \"field\": \"value\"\n";
    expected_result << "}\n";

    BOOST_CHECK_EQUAL(file_content, expected_result.str());
}

/******************************** TEST Nominal ********************************/
/**
 * @brief Nominal test case: Tests function from_file
 */
BOOST_FIXTURE_TEST_CASE(FromJsonFile, FixtureJsonTools)
{
    QJsonObject object;
    auto result = cams::lib::common::json::from_file(object, TEST_FILE_JSONTOOLS_READ);
    BOOST_REQUIRE_EQUAL(result, true);

    BOOST_CHECK_EQUAL(object["field"].toString().toStdString(), std::string("value"));
}

/******************************** TEST Error **********************************/
/**
 * @brief Error test case: Tests function to_file with bad filename
 */
BOOST_FIXTURE_TEST_CASE(ToBadJsonFile, FixtureJsonTools)
{
    QJsonObject object;
    object["field"] = QString("value");
    auto result = cams::lib::common::json::to_file(object, "unkown/directory/unknown_file.json");

    BOOST_CHECK_EQUAL(result, false);
}

/******************************** TEST Error **********************************/
/**
 * @brief Error test case: Tests function from_file with bad filename
 */
BOOST_FIXTURE_TEST_CASE(FromBadJsonFile, FixtureJsonTools)
{
    QJsonObject object;
    auto result = cams::lib::common::json::from_file(object, "unknown_file.json");

    BOOST_CHECK_EQUAL(result, false);
}
