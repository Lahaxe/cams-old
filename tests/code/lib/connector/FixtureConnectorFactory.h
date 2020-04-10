#ifndef _f0e9f743_7a21_4d72_a30f_5bcb3fe6d962
#define _f0e9f743_7a21_4d72_a30f_5bcb3fe6d962

// Include Project files
#include "tests/code/FixtureBase.h"
#include "src/lib/connector/ConnectorFactory.h"

class FixtureConnectorFactory : public FixtureBase
{
public:
    FixtureConnectorFactory(): FixtureBase()
    {
        cams::lib::connector::ConnectorFactory::instance();
    }

    virtual ~FixtureConnectorFactory()
    {
        cams::lib::connector::ConnectorFactory::delete_instance();
    }

protected:

private:

};

#endif // _f0e9f743_7a21_4d72_a30f_5bcb3fe6d962
