#define BOOST_TEST_MODULE ModuleEntityBase

// Include Project files
#include "tests/code/lib/model/core/FixtureEntityBase.h"

/******************************** TEST Nominal ********************************/
/**
 * @brief Nominal test case: Constructor and Destructor
 */
BOOST_FIXTURE_TEST_CASE(Constructor, FixtureEntityBase)
{
    BOOST_CHECK(this->_entity != nullptr);

    auto entity = new cams::lib::model::EntityBase("ID456");
    BOOST_CHECK(entity != nullptr);
    delete entity;
}

/******************************** TEST Nominal ********************************/
/**
 * @brief Nominal test case: Tests default values
 */
BOOST_FIXTURE_TEST_CASE(DefaultValues, FixtureEntityBase)
{
    BOOST_REQUIRE(this->_entity != nullptr);
    BOOST_CHECK_EQUAL(this->_entity->get_id(), std::string(""));
}

/******************************** TEST Nominal ********************************/
/**
 * @brief Nominal test case: Tests Getters and Setters
 */
BOOST_FIXTURE_TEST_CASE(Accessors, FixtureEntityBase)
{
    BOOST_REQUIRE(this->_entity != nullptr);
    this->_entity->set_id("ID456");
    BOOST_CHECK_EQUAL(this->_entity->get_id(), std::string("ID456"));
}

/******************************** TEST Nominal ********************************/
/**
 * @brief Nominal test case: Tests function from_json
 */
BOOST_FIXTURE_TEST_CASE(FromJson, FixtureEntityBase)
{
    BOOST_REQUIRE(this->_entity != nullptr);

    QJsonObject object;
    object[QString(cams::lib::model::ENTITYBASE_ID.c_str())] = QString("ID123");

    BOOST_CHECK_EQUAL(this->_entity->get_id(), std::string(""));
    this->_entity->from_json(object);
    BOOST_CHECK_EQUAL(this->_entity->get_id(), std::string("ID123"));
}

/******************************** TEST Nominal ********************************/
/**
 * @brief Nominal test case: Tests function to_json
 */
BOOST_FIXTURE_TEST_CASE(ToJson, FixtureEntityBase)
{
    BOOST_REQUIRE(this->_entity != nullptr);
    this->_entity->set_id("ID123");
    BOOST_CHECK_EQUAL(this->_entity->get_id(), std::string("ID123"));

    QJsonObject object;
    this->_entity->to_json(object);
    BOOST_CHECK_EQUAL(object[QString(cams::lib::model::ENTITYBASE_ID.c_str())].toString().toStdString(),
            std::string("ID123"));
}
