#define BOOST_TEST_MODULE ModuleControllerBase

// Include Project files
#include "tests/code/lib/controller/FixtureControllerBase.h"
#include "src/lib/controller/NotImplementedActionException.h"
#include "src/lib/controller/UnknownActionException.h"
#include "src/lib/connector/ConnectorFile.h"

/******************************** TEST Nominal ********************************/
/**
 * @brief Nominal test case: Constructor and Destructor
 */
BOOST_FIXTURE_TEST_CASE(Constructor, FixtureControllerBase)
{
    BOOST_CHECK(this->_controller != nullptr);
}

/******************************** TEST Nominal ********************************/
/**
 * @brief Nominal test case: Tests Getters and Setters
 */
BOOST_FIXTURE_TEST_CASE(Accessors, FixtureControllerBase)
{
    BOOST_CHECK(this->_controller->get_connector() == nullptr);
    this->_controller->set_connector(cams::lib::connector::ConnectorFile::New());
    BOOST_CHECK(this->_controller->get_connector() != nullptr);
}

/******************************** TEST Nominal ********************************/
/**
 * @brief Nominal test case: Function exists_action
 */
BOOST_FIXTURE_TEST_CASE(ExistsAction, FixtureControllerBase)
{
    BOOST_REQUIRE(this->_controller != nullptr);

    BOOST_CHECK(this->_controller->exists_action(cams::lib::controller::ACTION_GET) == true);
    BOOST_CHECK(this->_controller->exists_action("ERROR") == false);
}

/******************************** TEST Nominal ********************************/
/**
 * @brief Nominal test case: Function execute
 */
BOOST_FIXTURE_TEST_CASE(Execute, FixtureControllerBase)
{
    BOOST_REQUIRE(this->_controller != nullptr);

    BOOST_CHECK_EXCEPTION(this->_controller->execute(cams::lib::controller::ACTION_GET),
                          cams::lib::controller::NotImplementedActionException,
                          [](cams::lib::controller::NotImplementedActionException const & exc)
                                {
                                    return std::string(exc.what()) ==
                                            std::string("The controller does not implement the action 'GET'");
                                });

    BOOST_CHECK_EXCEPTION(this->_controller->execute(cams::lib::controller::ACTION_POST),
                          cams::lib::controller::NotImplementedActionException,
                          [](cams::lib::controller::NotImplementedActionException const & exc)
                                {
                                    return std::string(exc.what()) ==
                                            std::string("The controller does not implement the action 'POST'");
                                });

    BOOST_CHECK_EXCEPTION(this->_controller->execute(cams::lib::controller::ACTION_PUT),
                          cams::lib::controller::NotImplementedActionException,
                          [](cams::lib::controller::NotImplementedActionException const & exc)
                                {
                                    return std::string(exc.what()) ==
                                            std::string("The controller does not implement the action 'PUT'");
                                });

    BOOST_CHECK_EXCEPTION(this->_controller->execute(cams::lib::controller::ACTION_PATCH),
                          cams::lib::controller::NotImplementedActionException,
                          [](cams::lib::controller::NotImplementedActionException const & exc)
                                {
                                    return std::string(exc.what()) ==
                                            std::string("The controller does not implement the action 'PATCH'");
                                });

    BOOST_CHECK_EXCEPTION(this->_controller->execute(cams::lib::controller::ACTION_DELETE),
                          cams::lib::controller::NotImplementedActionException,
                          [](cams::lib::controller::NotImplementedActionException const & exc)
                                {
                                    return std::string(exc.what()) ==
                                            std::string("The controller does not implement the action 'DELETE'");
                                });

    BOOST_CHECK_EXCEPTION(this->_controller->execute(cams::lib::controller::ACTION_OPTIONS),
                          cams::lib::controller::NotImplementedActionException,
                          [](cams::lib::controller::NotImplementedActionException const & exc)
                                {
                                    return std::string(exc.what()) ==
                                            std::string("The controller does not implement the action 'OPTIONS'");
                                });
}

/******************************** TEST Error **********************************/
/**
 * @brief Error test case: Function execute
 */
BOOST_FIXTURE_TEST_CASE(ExecuteUnkownAction, FixtureControllerBase)
{
    BOOST_REQUIRE(this->_controller != nullptr);

    BOOST_CHECK_EXCEPTION(this->_controller->execute("ERROR"),
                          cams::lib::controller::UnknownActionException,
                          [](cams::lib::controller::UnknownActionException const & exc)
                                {
                                    return std::string(exc.what()) ==
                                            std::string("Given action is unknown: ERROR");
                                });
}

