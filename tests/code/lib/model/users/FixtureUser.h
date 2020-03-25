#ifndef _03e7bd32_bb7a_47e2_8fa9_5ae22fa68ead
#define _03e7bd32_bb7a_47e2_8fa9_5ae22fa68ead

// Include Project files
#include "FixtureBase.h"
#include "lib/model/users/User.h"

class FixtureUser : public FixtureBase
{
public:
    FixtureUser(): FixtureBase(), _user(nullptr)
    {
        this->_user = new libcams::model::User();
    }

    virtual ~FixtureUser()
    {
        if (this->_user != nullptr)
        {
            delete this->_user;
            this->_user = nullptr;
        }
    }

protected:
    libcams::model::User* _user;

private:

};

#endif // _03e7bd32_bb7a_47e2_8fa9_5ae22fa68ead

