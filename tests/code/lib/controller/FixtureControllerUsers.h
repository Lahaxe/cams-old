#ifndef _29299f81_76f9_4816_b50c_94f671c94f85
#define _29299f81_76f9_4816_b50c_94f671c94f85

// Include Project files
#include "tests/code/FixtureBase.h"
#include "src/lib/controller/ControllerUsers.h"

class FixtureControllerUsers : public FixtureBase
{
public:
    FixtureControllerUsers():
        FixtureBase(), _controller(cams::lib::controller::ControllerUsers::New())
    {
        // Nothing to do
    }

    virtual ~FixtureControllerUsers()
    {
        // Nothing to do
    }

protected:
    cams::lib::controller::ControllerUsers::Pointer _controller;

private:

};

#endif // _29299f81_76f9_4816_b50c_94f671c94f85
