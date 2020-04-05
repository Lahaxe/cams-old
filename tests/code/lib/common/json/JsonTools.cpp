#define BOOST_TEST_MODULE ModuleJsonTools

// Include Standard library files
#include <fstream>

// Include Boost library files
#include <boost/test/unit_test.hpp>

// Include Project files
#include "tests/code/lib/common/json/FixtureJsonTools.h"

/******************************** TEST Nominal ********************************/
/**
 * @brief Nominal test case: Tests function to_file
 */
BOOST_AUTO_TEST_CASE(ToJsonFile)
{
    QJsonObject object;
    object["field"] = QString("value");
    cams::lib::common::json::to_file(object, TEST_FILE_JSONTOOLS_WRITE);

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
BOOST_AUTO_TEST_CASE(FromJsonFile)
{
    std::stringstream file_content;
    file_content << "{\n";
    file_content << "    \"field\": \"value\"\n";
    file_content << "}\n";

    std::ofstream test_file(TEST_FILE_JSONTOOLS_READ);
    test_file << file_content.str().c_str();
    test_file.close();

    QJsonObject object;
    cams::lib::common::json::from_file(object, TEST_FILE_JSONTOOLS_READ);

    BOOST_CHECK_EQUAL(object["field"].toString().toStdString(), std::string("value"));
}
