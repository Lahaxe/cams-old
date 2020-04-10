#ifndef _8405aba9_fb1e_4fdc_98f0_e4ed4889024b
#define _8405aba9_fb1e_4fdc_98f0_e4ed4889024b

// Include Project files
#include "tests/code/FixtureBase.h"
#include "src/lib/connector/ConnectorFile.h"

class FixtureConnectorFile : public FixtureBase
{
public:
    FixtureConnectorFile(): FixtureBase(),
        _connector(cams::lib::connector::ConnectorFile::New())
    {
        // Nothing to do
    }

    virtual ~FixtureConnectorFile()
    {
        // Nothing to do
    }

protected:
    cams::lib::connector::ConnectorFile::Pointer _connector;

private:

};

#endif // _8405aba9_fb1e_4fdc_98f0_e4ed4889024b
