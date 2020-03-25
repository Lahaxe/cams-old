#ifndef _1d4da5e6_5f16_4e41_bea7_da787d780f32
#define _1d4da5e6_5f16_4e41_bea7_da787d780f32

// Include Project files
#include "FixtureBase.h"
#include "lib/common/logger/Logger.h"

class FixtureLogger : public FixtureBase
{
public:
    FixtureLogger(): FixtureBase()
    {
        libcams::common::Logger::instance();
    }

    virtual ~FixtureLogger()
    {
        libcams::common::Logger::delete_instance();
    }

protected:

private:

};

#endif // _1d4da5e6_5f16_4e41_bea7_da787d780f32
