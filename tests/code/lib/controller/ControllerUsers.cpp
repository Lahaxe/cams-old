#define BOOST_TEST_MODULE ModuleControllerUsers

// Include Project files
#include "tests/code/lib/controller/FixtureControllerUsers.h"

/******************************** TEST Nominal ********************************/
/**
 * @brief Nominal test case: Constructor and Destructor
 */
BOOST_FIXTURE_TEST_CASE(Constructor, FixtureControllerUsers)
{
    BOOST_CHECK(this->_controller != nullptr);
}
