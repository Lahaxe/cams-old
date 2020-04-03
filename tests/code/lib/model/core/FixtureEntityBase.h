#ifndef _cddd19da_852a_492d_a8f7_e26e7b812292
#define _cddd19da_852a_492d_a8f7_e26e7b812292

// Include Project files
#include "tests/code/FixtureBase.h"
#include "src/lib/model/core/EntityBase.h"

class FixtureEntityBase : public FixtureBase
{
public:
    FixtureEntityBase(): FixtureBase(), _entity(nullptr)
    {
        this->_entity = new cams::lib::model::EntityBase();
    }

    virtual ~FixtureEntityBase()
    {
        if (this->_entity != nullptr)
        {
            delete this->_entity;
            this->_entity = nullptr;
        }
    }

protected:
    cams::lib::model::EntityBase* _entity;

private:

};

#endif // _cddd19da_852a_492d_a8f7_e26e7b812292

