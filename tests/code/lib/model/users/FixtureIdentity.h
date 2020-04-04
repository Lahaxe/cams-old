#ifndef _2b1f2677_5acb_4218_add2_8bfff8aeee9b
#define _2b1f2677_5acb_4218_add2_8bfff8aeee9b

// Include Project files
#include "tests/code/FixtureBase.h"
#include "src/lib/model/users/Identity.h"

class FixtureIdentity : public FixtureBase
{
public:
    FixtureIdentity(): FixtureBase(), _identity(nullptr)
    {
        this->_identity = cams::lib::model::Identity::New();
    }

    virtual ~FixtureIdentity()
    {
        // Nothing to do
    }

protected:
    cams::lib::model::Identity::Pointer _identity;

private:

};

#endif // _2b1f2677_5acb_4218_add2_8bfff8aeee9b

