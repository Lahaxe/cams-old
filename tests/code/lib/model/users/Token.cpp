#define BOOST_TEST_MODULE ModuleToken

// Include Project files
#include "tests/code/lib/model/users/FixtureToken.h"

/******************************** TEST Nominal ********************************/
/**
 * @brief Nominal test case: Constructor and Destructor
 */
BOOST_FIXTURE_TEST_CASE(Constructor, FixtureToken)
{
    BOOST_CHECK(this->_token != nullptr);
}

/******************************** TEST Nominal ********************************/
/**
 * @brief Nominal test case: Tests default values
 */
BOOST_FIXTURE_TEST_CASE(DefaultValues, FixtureToken)
{
    BOOST_REQUIRE(this->_token != nullptr);
    BOOST_CHECK_EQUAL(this->_token->get_username(), std::string(""));
    BOOST_CHECK_EQUAL(this->_token->get_userid(), std::string(""));
    BOOST_CHECK_EQUAL(this->_token->get_token(), std::string(""));
}

/******************************** TEST Nominal ********************************/
/**
 * @brief Nominal test case: Tests Getters and Setters
 */
BOOST_FIXTURE_TEST_CASE(Accessors, FixtureToken)
{
    BOOST_REQUIRE(this->_token != nullptr);
    this->_token->set_username("MYNAME");
    BOOST_CHECK_EQUAL(this->_token->get_username(), std::string("MYNAME"));
    this->_token->set_userid("MYID");
    BOOST_CHECK_EQUAL(this->_token->get_userid(), std::string("MYID"));
    this->_token->set_token("TOKEN");
    BOOST_CHECK_EQUAL(this->_token->get_token(), std::string("TOKEN"));
}

/******************************** TEST Nominal ********************************/
/**
 * @brief Nominal test case: Tests function from_json
 */
BOOST_FIXTURE_TEST_CASE(FromJson, FixtureToken)
{
    BOOST_REQUIRE(this->_token != nullptr);

    QJsonObject object;
    object[QString(cams::lib::model::ENTITYBASE_ID.c_str())] = QString("ID123");
    object[QString(cams::lib::model::TOKEN_USERNAME.c_str())] = QString("MYNAME");
    object[QString(cams::lib::model::TOKEN_USERID.c_str())] = QString("MYID");
    object[QString(cams::lib::model::TOKEN_TOKEN.c_str())] = QString("MYTOKEN");

    BOOST_CHECK_EQUAL(this->_token->get_username(), std::string(""));
    BOOST_CHECK_EQUAL(this->_token->get_userid(), std::string(""));
    BOOST_CHECK_EQUAL(this->_token->get_token(), std::string(""));
    this->_token->from_json(object);
    BOOST_CHECK_EQUAL(this->_token->get_username(), std::string("MYNAME"));
    BOOST_CHECK_EQUAL(this->_token->get_userid(), std::string("MYID"));
    BOOST_CHECK_EQUAL(this->_token->get_token(), std::string("MYTOKEN"));
}

/******************************** TEST Nominal ********************************/
/**
 * @brief Nominal test case: Tests function to_json
 */
BOOST_FIXTURE_TEST_CASE(ToJson, FixtureToken)
{
    BOOST_REQUIRE(this->_token != nullptr);
    this->_token->set_username("MYNAME");
    this->_token->set_userid("MYID");
    this->_token->set_token("MYTOKEN");
    BOOST_CHECK_EQUAL(this->_token->get_username(), std::string("MYNAME"));
    BOOST_CHECK_EQUAL(this->_token->get_userid(), std::string("MYID"));
    BOOST_CHECK_EQUAL(this->_token->get_token(), std::string("MYTOKEN"));

    QJsonObject object;
    this->_token->to_json(object);
    BOOST_CHECK_EQUAL(object[QString(cams::lib::model::TOKEN_USERNAME.c_str())].toString().toStdString(),
            std::string("MYNAME"));
    BOOST_CHECK_EQUAL(object[QString(cams::lib::model::TOKEN_USERID.c_str())].toString().toStdString(),
            std::string("MYID"));
    BOOST_CHECK_EQUAL(object[QString(cams::lib::model::TOKEN_TOKEN.c_str())].toString().toStdString(),
            std::string("MYTOKEN"));
}
