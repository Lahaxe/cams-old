#define BOOST_TEST_MODULE ModuleUser

// Include Project files
#include "tests/code/lib/model/users/FixtureUser.h"

/******************************** TEST Nominal ********************************/
/**
 * @brief Nominal test case: Constructor and Destructor
 */
BOOST_FIXTURE_TEST_CASE(Constructor, FixtureUser)
{
    BOOST_CHECK(this->_user != nullptr);
}

/******************************** TEST Nominal ********************************/
/**
 * @brief Nominal test case: Tests default values
 */
BOOST_FIXTURE_TEST_CASE(DefaultValues, FixtureUser)
{
    BOOST_REQUIRE(this->_user != nullptr);
    BOOST_CHECK_EQUAL(this->_user->get_name()->get_value(), std::string(""));
    BOOST_CHECK_EQUAL(this->_user->get_password()->get_value(), std::string(""));
}

/******************************** TEST Nominal ********************************/
/**
 * @brief Nominal test case: Tests Getters and Setters
 */
BOOST_FIXTURE_TEST_CASE(Accessors, FixtureUser)
{
    BOOST_REQUIRE(this->_user != nullptr);
    this->_user->set_name("MYNAME");
    BOOST_CHECK_EQUAL(this->_user->get_name()->get_value(), std::string("MYNAME"));
    this->_user->set_password("MYPWD");
    BOOST_CHECK_EQUAL(this->_user->get_password()->get_value(), std::string("MYPWD"));
}

/******************************** TEST Nominal ********************************/
/**
 * @brief Nominal test case: Tests function from_json
 */
BOOST_FIXTURE_TEST_CASE(FromJson, FixtureUser)
{
    BOOST_REQUIRE(this->_user != nullptr);

    QJsonObject object;
    object[QString(cams::lib::model::ENTITYBASE_ID.c_str())] = QString("ID123");
    object[QString(cams::lib::model::USER_NAME.c_str())] = QString("MYNAME");
    object[QString(cams::lib::model::USER_PASSWORD.c_str())] = QString("MYPWD");

    BOOST_CHECK_EQUAL(this->_user->get_name()->get_value(), std::string(""));
    BOOST_CHECK_EQUAL(this->_user->get_password()->get_value(), std::string(""));
    this->_user->from_json(object);
    BOOST_CHECK_EQUAL(this->_user->get_name()->get_value(), std::string("MYNAME"));
    BOOST_CHECK_EQUAL(this->_user->get_password()->get_value(), std::string("MYPWD"));
}

/******************************** TEST Nominal ********************************/
/**
 * @brief Nominal test case: Tests function to_json
 */
BOOST_FIXTURE_TEST_CASE(ToJson, FixtureUser)
{
    BOOST_REQUIRE(this->_user != nullptr);
    this->_user->set_id("ID123");
    this->_user->set_name("MYNAME");
    this->_user->set_password("MYPWD");
    BOOST_CHECK_EQUAL(this->_user->get_name()->get_value(), std::string("MYNAME"));
    BOOST_CHECK_EQUAL(this->_user->get_password()->get_value(), std::string("MYPWD"));

    QJsonObject object;
    this->_user->to_json(object);
    BOOST_CHECK_EQUAL(object[QString(cams::lib::model::USER_NAME.c_str())].toString().toStdString(),
            std::string("MYNAME"));
    BOOST_CHECK_EQUAL(object[QString(cams::lib::model::USER_PASSWORD.c_str())].toString().toStdString(),
            std::string("MYPWD"));
}
