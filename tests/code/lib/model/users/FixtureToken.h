#ifndef _72b65d83_9da1_4892_aa66_8b806aded3d7
#define _72b65d83_9da1_4892_aa66_8b806aded3d7

// Include Project files
#include "tests/code/FixtureBase.h"
#include "src/lib/model/users/Token.h"

class FixtureToken : public FixtureBase
{
public:
    FixtureToken(): FixtureBase(), _token(nullptr)
    {
        this->_token = cams::lib::model::Token::New();
    }

    virtual ~FixtureToken()
    {
        // Nothing to do
    }

protected:
    cams::lib::model::Token::Pointer _token;

private:

};

#endif // _72b65d83_9da1_4892_aa66_8b806aded3d7

