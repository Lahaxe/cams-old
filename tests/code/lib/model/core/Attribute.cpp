#define BOOST_TEST_MODULE ModuleAttribute

// Include Boost files
#include <boost/test/unit_test.hpp>

// Include Qt files
#include <QJsonObject>

// Include Project files
#include "src/lib/model/core/Attribute.h"

/******************************** TEST Nominal ********************************/
/**
 * @brief Nominal test case: Constructor and Destructor
 */
BOOST_AUTO_TEST_CASE(Constructor)
{
    // Test String Attribute
    auto string_attribute =
            cams::lib::model::Attribute<std::string>::New("string_attribute");
    BOOST_CHECK(string_attribute != nullptr);

    auto string_attribute2 =
            cams::lib::model::Attribute<std::string>::New("string_attribute",
                                                          std::string("string_value"));
    BOOST_CHECK(string_attribute2 != nullptr);

    // Test Int Attribute
    auto int_attribute =
            cams::lib::model::Attribute<int>::New("int_attribute");
    BOOST_CHECK(int_attribute != nullptr);

    auto int_attribute2 =
            cams::lib::model::Attribute<int>::New("int_attribute", 1);
    BOOST_CHECK(int_attribute2 != nullptr);

    // Test Bool Attribute
    auto bool_attribute =
            cams::lib::model::Attribute<bool>::New("bool_attribute");
    BOOST_CHECK(bool_attribute != nullptr);

    auto bool_attribute2 =
            cams::lib::model::Attribute<bool>::New("bool_attribute", true);
    BOOST_CHECK(bool_attribute2 != nullptr);

    // Test Double Attribute
    auto double_attribute =
            cams::lib::model::Attribute<int>::New("double_attribute");
    BOOST_CHECK(double_attribute != nullptr);

    auto double_attribute2 =
            cams::lib::model::Attribute<int>::New("double_attribute", (double)1.0);
    BOOST_CHECK(double_attribute2 != nullptr);
}

/******************************** TEST Nominal ********************************/
/**
 * @brief Nominal test case: Tests default values
 */
BOOST_AUTO_TEST_CASE(DefaultValues)
{
    // Test String Attribute
    auto string_attribute =
            cams::lib::model::Attribute<std::string>::New("string_attribute");
    BOOST_REQUIRE(string_attribute != nullptr);
    BOOST_CHECK_EQUAL(string_attribute->get_name(), std::string("string_attribute"));
    BOOST_CHECK_EQUAL(string_attribute->get_value(), std::string(""));
    BOOST_CHECK_EQUAL(string_attribute->is_set(), false);

    auto string_attribute2 =
            cams::lib::model::Attribute<std::string>::New("string_attribute",
                                                          std::string("string_value"));
    BOOST_REQUIRE(string_attribute2 != nullptr);
    BOOST_CHECK_EQUAL(string_attribute2->get_name(), std::string("string_attribute"));
    BOOST_CHECK_EQUAL(string_attribute2->get_value(), std::string("string_value"));
    BOOST_CHECK_EQUAL(string_attribute2->is_set(), true);

    // Test Int Attribute
    auto int_attribute =
            cams::lib::model::Attribute<int>::New("int_attribute");
    BOOST_REQUIRE(int_attribute != nullptr);
    BOOST_CHECK_EQUAL(int_attribute->get_name(), std::string("int_attribute"));
    BOOST_CHECK_EQUAL(int_attribute->get_value(), 0);
    BOOST_CHECK_EQUAL(int_attribute->is_set(), false);

    auto int_attribute2 =
            cams::lib::model::Attribute<int>::New("int_attribute", 1);
    BOOST_REQUIRE(int_attribute2 != nullptr);
    BOOST_CHECK_EQUAL(int_attribute2->get_name(), std::string("int_attribute"));
    BOOST_CHECK_EQUAL(int_attribute2->get_value(), 1);
    BOOST_CHECK_EQUAL(int_attribute2->is_set(), true);

    // Test Bool Attribute
    auto bool_attribute =
            cams::lib::model::Attribute<bool>::New("bool_attribute");
    BOOST_REQUIRE(bool_attribute != nullptr);
    BOOST_CHECK_EQUAL(bool_attribute->get_name(), std::string("bool_attribute"));
    BOOST_CHECK_EQUAL(bool_attribute->get_value(), false);
    BOOST_CHECK_EQUAL(bool_attribute->is_set(), false);

    auto bool_attribute2 =
            cams::lib::model::Attribute<bool>::New("bool_attribute", true);
    BOOST_REQUIRE(bool_attribute2 != nullptr);
    BOOST_CHECK_EQUAL(bool_attribute2->get_name(), std::string("bool_attribute"));
    BOOST_CHECK_EQUAL(bool_attribute2->get_value(), true);
    BOOST_CHECK_EQUAL(bool_attribute2->is_set(), true);

    // Test Double Attribute
    auto double_attribute =
            cams::lib::model::Attribute<int>::New("double_attribute");
    BOOST_REQUIRE(double_attribute != nullptr);
    BOOST_CHECK_EQUAL(double_attribute->get_name(), std::string("double_attribute"));
    BOOST_CHECK_EQUAL(double_attribute->get_value(), (double)0);
    BOOST_CHECK_EQUAL(double_attribute->is_set(), false);

    auto double_attribute2 =
            cams::lib::model::Attribute<int>::New("double_attribute", (double)1.0);
    BOOST_REQUIRE(double_attribute2 != nullptr);
    BOOST_CHECK_EQUAL(double_attribute2->get_name(), std::string("double_attribute"));
    BOOST_CHECK_EQUAL(double_attribute2->get_value(), (double)1.0);
    BOOST_CHECK_EQUAL(double_attribute2->is_set(), true);
}

/******************************** TEST Nominal ********************************/
/**
 * @brief Nominal test case: Tests Getters and Setters
 */
BOOST_AUTO_TEST_CASE(Accessors)
{
    // Test String Attribute
    auto string_attribute =
            cams::lib::model::Attribute<std::string>::New("string_attribute");
    BOOST_REQUIRE(string_attribute != nullptr);
    BOOST_CHECK_EQUAL(string_attribute->get_name(), std::string("string_attribute"));
    BOOST_CHECK_EQUAL(string_attribute->get_value(), std::string(""));
    BOOST_CHECK_EQUAL(string_attribute->is_set(), false);
    string_attribute->set_name("new_string_attribute");
    string_attribute->set_value(std::string("new_value"));
    BOOST_CHECK_EQUAL(string_attribute->get_name(), std::string("new_string_attribute"));
    BOOST_CHECK_EQUAL(string_attribute->get_value(), std::string("new_value"));
    BOOST_CHECK_EQUAL(string_attribute->is_set(), true);

    // Test Int Attribute
    auto int_attribute =
            cams::lib::model::Attribute<int>::New("int_attribute");
    BOOST_REQUIRE(int_attribute != nullptr);
    BOOST_CHECK_EQUAL(int_attribute->get_name(), std::string("int_attribute"));
    BOOST_CHECK_EQUAL(int_attribute->get_value(), 0);
    BOOST_CHECK_EQUAL(int_attribute->is_set(), false);
    int_attribute->set_name("new_int_attribute");
    int_attribute->set_value(1);
    BOOST_CHECK_EQUAL(int_attribute->get_name(), std::string("new_int_attribute"));
    BOOST_CHECK_EQUAL(int_attribute->get_value(), 1);
    BOOST_CHECK_EQUAL(int_attribute->is_set(), true);

    // Test Bool Attribute
    auto bool_attribute =
            cams::lib::model::Attribute<bool>::New("bool_attribute");
    BOOST_REQUIRE(bool_attribute != nullptr);
    BOOST_CHECK_EQUAL(bool_attribute->get_name(), std::string("bool_attribute"));
    BOOST_CHECK_EQUAL(bool_attribute->get_value(), false);
    BOOST_CHECK_EQUAL(bool_attribute->is_set(), false);
    bool_attribute->set_name("new_bool_attribute");
    bool_attribute->set_value(true);
    BOOST_CHECK_EQUAL(bool_attribute->get_name(), std::string("new_bool_attribute"));
    BOOST_CHECK_EQUAL(bool_attribute->get_value(), true);
    BOOST_CHECK_EQUAL(bool_attribute->is_set(), true);

    // Test Double Attribute
    auto double_attribute =
            cams::lib::model::Attribute<int>::New("double_attribute");
    BOOST_REQUIRE(double_attribute != nullptr);
    BOOST_CHECK_EQUAL(double_attribute->get_name(), std::string("double_attribute"));
    BOOST_CHECK_EQUAL(double_attribute->get_value(), (double)0);
    BOOST_CHECK_EQUAL(double_attribute->is_set(), false);
    double_attribute->set_name("new_double_attribute");
    double_attribute->set_value((double)1.0);
    BOOST_CHECK_EQUAL(double_attribute->get_name(), std::string("new_double_attribute"));
    BOOST_CHECK_EQUAL(double_attribute->get_value(), (double)1.0);
    BOOST_CHECK_EQUAL(double_attribute->is_set(), true);
}

/******************************** TEST Nominal ********************************/
/**
 * @brief Nominal test case: Tests function from_json
 */
BOOST_AUTO_TEST_CASE(FromJson)
{
    QJsonObject object;
    object["string_attribute"] = QString("string_value");
    object["int_attribute"] = 1;
    object["bool_attribute"] = true;
    object["double_attribute"] = (double)2.0;

    // Test String Attribute
    auto string_attribute =
            cams::lib::model::Attribute<std::string>::New("string_attribute");
    BOOST_REQUIRE(string_attribute != nullptr);
    BOOST_CHECK_EQUAL(string_attribute->get_value(), std::string(""));

    string_attribute->from_json(object);

    BOOST_CHECK_EQUAL(string_attribute->get_value(), std::string("string_value"));

    // Test Int Attribute
    auto int_attribute =
            cams::lib::model::Attribute<int>::New("int_attribute");
    BOOST_REQUIRE(int_attribute != nullptr);
    BOOST_CHECK_EQUAL(int_attribute->get_value(), 0);

    int_attribute->from_json(object);

    BOOST_CHECK_EQUAL(int_attribute->get_value(), 1);

    // Test Bool Attribute
    auto bool_attribute =
            cams::lib::model::Attribute<bool>::New("bool_attribute");
    BOOST_REQUIRE(bool_attribute != nullptr);
    BOOST_CHECK_EQUAL(bool_attribute->get_value(), false);

    bool_attribute->from_json(object);

    BOOST_CHECK_EQUAL(bool_attribute->get_value(), true);

    // Test Int Attribute
    auto double_attribute =
            cams::lib::model::Attribute<double>::New("double_attribute");
    BOOST_REQUIRE(double_attribute != nullptr);
    BOOST_CHECK_EQUAL(double_attribute->get_value(), (double)0);

    double_attribute->from_json(object);

    BOOST_CHECK_EQUAL(double_attribute->get_value(), (double)2.0);
}

/******************************** TEST Nominal ********************************/
/**
 * @brief Nominal test case: Tests function to_json
 */
BOOST_AUTO_TEST_CASE(ToJson)
{
    QJsonObject object;

    // Test String Attribute
    auto string_attribute =
            cams::lib::model::Attribute<std::string>::New("string_attribute", "string_value");
    BOOST_REQUIRE(string_attribute != nullptr);

    string_attribute->to_json(object);

    BOOST_CHECK_EQUAL(object["string_attribute"].toString().toStdString(),
            std::string("string_value"));

    // Test Int Attribute
    auto int_attribute =
            cams::lib::model::Attribute<int>::New("int_attribute", 1);
    BOOST_REQUIRE(int_attribute != nullptr);

    int_attribute->to_json(object);

    BOOST_CHECK_EQUAL(object["int_attribute"].toInt(), 1);

    // Test Bool Attribute
    auto bool_attribute =
            cams::lib::model::Attribute<bool>::New("bool_attribute", true);
    BOOST_REQUIRE(bool_attribute != nullptr);

    bool_attribute->to_json(object);

    BOOST_CHECK_EQUAL(object["bool_attribute"].toBool(), true);

    // Test Int Attribute
    auto double_attribute =
            cams::lib::model::Attribute<double>::New("double_attribute", (double)2.0);
    BOOST_REQUIRE(double_attribute != nullptr);

    double_attribute->to_json(object);

    BOOST_CHECK_EQUAL(object["double_attribute"].toDouble(), (double)2.0);
}

/******************************** TEST Nominal ********************************/
/**
 * @brief Nominal test case: Tests function patch_from_other
 */
BOOST_AUTO_TEST_CASE(PatchFromOther)
{
    // Test String Attribute
    auto string_attribute =
            cams::lib::model::Attribute<std::string>::New("string_attribute");
    BOOST_REQUIRE(string_attribute != nullptr);
    auto other_string_attribute =
            cams::lib::model::Attribute<std::string>::New("string_attribute", "string_value");
    BOOST_REQUIRE(other_string_attribute != nullptr);
    BOOST_CHECK_EQUAL(string_attribute->get_value(), std::string(""));

    string_attribute->patch_from_other(other_string_attribute);
    BOOST_CHECK_EQUAL(string_attribute->get_value(), std::string("string_value"));

    // Test Int Attribute
    auto int_attribute =
            cams::lib::model::Attribute<int>::New("int_attribute");
    BOOST_REQUIRE(int_attribute != nullptr);
    auto other_int_attribute =
            cams::lib::model::Attribute<int>::New("int_attribute", 1);
    BOOST_REQUIRE(other_int_attribute != nullptr);
    BOOST_CHECK_EQUAL(int_attribute->get_value(), 0);

    int_attribute->patch_from_other(other_int_attribute);
    BOOST_CHECK_EQUAL(int_attribute->get_value(), 1);

    // Test Bool Attribute
    auto bool_attribute =
            cams::lib::model::Attribute<bool>::New("bool_attribute");
    BOOST_REQUIRE(bool_attribute != nullptr);
    auto other_bool_attribute =
            cams::lib::model::Attribute<bool>::New("bool_attribute", true);
    BOOST_REQUIRE(other_bool_attribute != nullptr);
    BOOST_CHECK_EQUAL(bool_attribute->get_value(), false);

    bool_attribute->patch_from_other(other_bool_attribute);
    BOOST_CHECK_EQUAL(bool_attribute->get_value(), true);

    // Test Double Attribute
    auto double_attribute =
            cams::lib::model::Attribute<double>::New("double_attribute");
    BOOST_REQUIRE(double_attribute != nullptr);
    auto other_double_attribute =
            cams::lib::model::Attribute<double>::New("double_attribute", (double)2.0);
    BOOST_REQUIRE(other_double_attribute != nullptr);
    BOOST_CHECK_EQUAL(double_attribute->get_value(), (double)0);

    double_attribute->patch_from_other(other_double_attribute);
    BOOST_CHECK_EQUAL(double_attribute->get_value(), (double)2.0);
}
