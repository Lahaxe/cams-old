#ifndef _953b5ef5_b3bc_48a4_adba_db1c158d4a64
#define _953b5ef5_b3bc_48a4_adba_db1c158d4a64

// Include Project files
#include "tests/code/FixtureBase.h"
#include "src/lib/controller/ControllerToken.h"

class FixtureControllerToken : public FixtureBase
{
public:
    FixtureControllerToken():
        FixtureBase(), _controller(cams::lib::controller::ControllerToken::New())
    {
        // Nothing to do
    }

    virtual ~FixtureControllerToken()
    {
        // Nothing to do
    }

protected:
    cams::lib::controller::ControllerToken::Pointer _controller;

private:

};

#endif // _953b5ef5_b3bc_48a4_adba_db1c158d4a64
