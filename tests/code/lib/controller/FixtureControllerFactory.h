#ifndef _60193dfb_2138_4124_936c_1f607a8fb297
#define _60193dfb_2138_4124_936c_1f607a8fb297

// Include Project files
#include "FixtureBase.h"
#include "lib/controller/ControllerFactory.h"

class FixtureControllerFactory : public FixtureBase
{
public:
    FixtureControllerFactory(): FixtureBase()
    {
        libcams::controller::ControllerFactory::instance();
    }

    virtual ~FixtureControllerFactory()
    {
        libcams::controller::ControllerFactory::delete_instance();
    }

protected:

private:

};

#endif // _60193dfb_2138_4124_936c_1f607a8fb297
