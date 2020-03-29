#define BOOST_TEST_MODULE ModuleControllerBase

// Include Boost library
#include <boost/test/unit_test.hpp>

// Include Project files
#include "FixtureControllerToken.h"
#include "controller/NotImplementedActionException.h"

/******************************** TEST Nominal ********************************/
/**
 * @brief Nominal test case: Constructor and Destructor
 */
BOOST_FIXTURE_TEST_CASE(Constructor, FixtureControllerToken)
{
    BOOST_CHECK(this->_controller != nullptr);
}

/******************************** TEST Nominal ********************************/
/**
 * @brief Nominal test case: Function execute POST action
 */
BOOST_FIXTURE_TEST_CASE(ExecutePost, FixtureControllerToken)
{
    BOOST_REQUIRE(this->_controller != nullptr);

    // TODO
}

/******************************** TEST Nominal ********************************/
/**
 * @brief Nominal test case: Function execute with not implemented actions
 */
BOOST_FIXTURE_TEST_CASE(ExecuteNotImplemented, FixtureControllerToken)
{
    BOOST_REQUIRE(this->_controller != nullptr);

    BOOST_CHECK_EXCEPTION(this->_controller->execute(libcams::controller::ACTION_GET),
                          libcams::controller::NotImplementedActionException,
                          [](libcams::controller::NotImplementedActionException const & exc)
                                {
                                    return std::string(exc.what()) ==
                                            std::string("The controller does not implement the action 'GET'");
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
