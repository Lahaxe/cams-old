#ifndef _ee2e1f99_f819_4364_b320_5a8cf51afb13
#define _ee2e1f99_f819_4364_b320_5a8cf51afb13

// Include Project files
#include "tests/code/FixtureBase.h"
#include "src/lib/common/logger/DefaultLogger.h"

class FixtureDefaultLogger : public FixtureBase
{
public:
    FixtureDefaultLogger(): FixtureBase(),
        _logger(cams::lib::common::DefaultLogger::New())
    {
        // Nothing to do
    }

    virtual ~FixtureDefaultLogger()
    {
        // Nothing to do
    }

protected:
    cams::lib::common::DefaultLogger::Pointer _logger;

private:

};

#endif // _ee2e1f99_f819_4364_b320_5a8cf51afb13
