#ifndef _03e7bd32_bb7a_47e2_8fa9_5ae22fa68ead
#define _03e7bd32_bb7a_47e2_8fa9_5ae22fa68ead

// Include Project files
#include "tests/code/FixtureBase.h"
#include "src/lib/model/users/User.h"

class FixtureUser : public FixtureBase
{
public:
    FixtureUser(): FixtureBase(), _user(nullptr)
    {
        this->_user = cams::lib::model::User::New();
    }

    virtual ~FixtureUser()
    {
        // Nothing to do
    }

protected:
    cams::lib::model::User::Pointer _user;

private:

};

#endif // _03e7bd32_bb7a_47e2_8fa9_5ae22fa68ead

