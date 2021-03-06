#ifndef _d9181d75_5870_4005_9d6e_768b17f4d6ea
#define _d9181d75_5870_4005_9d6e_768b17f4d6ea

// Include Project files
#include "tests/code/FixtureBase.h"
#include "src/lib/controller/ControllerBase.h"

class FixtureControllerBase : public FixtureBase
{
public:
    FixtureControllerBase(): FixtureBase(), _controller(new cams::lib::controller::ControllerBase())
    {
        // Nothing to do
    }

    virtual ~FixtureControllerBase()
    {
        if (this->_controller != nullptr)
        {
            delete this->_controller;
        }
    }

protected:
    cams::lib::controller::ControllerBase* _controller;

private:

};

#endif // _d9181d75_5870_4005_9d6e_768b17f4d6ea
