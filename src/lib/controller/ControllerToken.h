#ifndef _d3ed60ca_8ce4_4dce_a886_8f98ed87cb61
#define _d3ed60ca_8ce4_4dce_a886_8f98ed87cb61

//Include Project files
#include "controller/ControllerBase.h"

namespace libcams
{

namespace controller
{

class ControllerToken : public ControllerBase
{
public:
    typedef std::shared_ptr<ControllerToken> Pointer;

    typedef std::shared_ptr<ControllerToken const> ConstPointer;

    static Pointer New();

    virtual ~ControllerToken();

    static std::string class_name();

protected:

private:
    ControllerToken();

    ControllerToken(ControllerToken const & other);

    ControllerToken& operator=(ControllerToken const & other);

};

}

}

#endif // _d3ed60ca_8ce4_4dce_a886_8f98ed87cb61
