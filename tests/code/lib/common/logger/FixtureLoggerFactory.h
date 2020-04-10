#ifndef _64f16e83_c777_4e0d_8791_97c75ba41243
#define _64f16e83_c777_4e0d_8791_97c75ba41243

// Include Project files
#include "tests/code/FixtureBase.h"
#include "src/lib/common/logger/LoggerFactory.h"

class FixtureLoggerFactory : public FixtureBase
{
public:
    FixtureLoggerFactory(): FixtureBase()
    {
        cams::lib::common::LoggerFactory::instance();
    }

    virtual ~FixtureLoggerFactory()
    {
        cams::lib::common::LoggerFactory::delete_instance();
    }

protected:

private:

};

#endif // _64f16e83_c777_4e0d_8791_97c75ba41243
