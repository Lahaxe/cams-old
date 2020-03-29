#define BOOST_TEST_MODULE ModuleControllerBase

// Include Boost library
#include <boost/test/unit_test.hpp>

// Include Project files
#include "FixtureControllerBase.h"
#include "controller/NotImplementedActionException.h"
#include "controller/UnknownActionException.h"

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
 * @brief Nominal test case: Function exists_action
 */
BOOST_FIXTURE_TEST_CASE(ExistsAction, FixtureControllerBase)
{
    BOOST_REQUIRE(this->_controller != nullptr);

    BOOST_CHECK(this->_controller->exists_action(libcams::controller::ACTION_GET) == true);
    BOOST_CHECK(this->_controller->exists_action("ERROR") == false);
}

/******************************** TEST Nominal ********************************/
/**
 * @brief Nominal test case: Function execute
 */
BOOST_FIXTURE_TEST_CASE(Execute, FixtureControllerBase)
{
    BOOST_REQUIRE(this->_controller != nullptr);

    BOOST_CHECK_EXCEPTION(this->_controller->execute(libcams::controller::ACTION_GET),
                          libcams::controller::NotImplementedActionException,
                          [](libcams::controller::NotImplementedActionException const & exc)
                                {
                                    return std::string(exc.what()) ==
                                            std::string("The controller does not implement the action 'GET'");
                                });

    BOOST_CHECK_EXCEPTION(this->_controller->execute(libcams::controller::ACTION_POST),
                          libcams::controller::NotImplementedActionException,
                          [](libcams::controller::NotImplementedActionException const & exc)
                                {
                                    return std::string(exc.what()) ==
                                            std::string("The controller does not implement the action 'POST'");
                                });

    BOOST_CHECK_EXCEPTION(this->_controller->execute(libcams::controller::ACTION_PUT),
                          libcams::controller::NotImplementedActionException,
                          [](libcams::controller::NotImplementedActionException const & exc)
                                {
                                    return std::string(exc.what()) ==
                                            std::string("The controller does not implement the action 'PUT'");
                                });

    BOOST_CHECK_EXCEPTION(this->_controller->execute(libcams::controller::ACTION_PATCH),
                          libcams::controller::NotImplementedActionException,
                          [](libcams::controller::NotImplementedActionException const & exc)
                                {
                                    return std::string(exc.what()) ==
                                            std::string("The controller does not implement the action 'PATCH'");
                                });

    BOOST_CHECK_EXCEPTION(this->_controller->execute(libcams::controller::ACTION_DELETE),
                          libcams::controller::NotImplementedActionException,
                          [](libcams::controller::NotImplementedActionException const & exc)
                                {
                                    return std::string(exc.what()) ==
                                            std::string("The controller does not implement the action 'DELETE'");
                                });

    BOOST_CHECK_EXCEPTION(this->_controller->execute(libcams::controller::ACTION_OPTIONS),
                          libcams::controller::NotImplementedActionException,
                          [](libcams::controller::NotImplementedActionException const & exc)
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
                          libcams::controller::UnknownActionException,
                          [](libcams::controller::UnknownActionException const & exc)
                                {
                                    return std::string(exc.what()) ==
                                            std::string("Given action is unknown: ERROR");
                                });
}

