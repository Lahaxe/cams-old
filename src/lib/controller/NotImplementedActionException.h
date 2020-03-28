#ifndef _a50c62bd_9f44_40e3_a53d_f4f1f2355a05
#define _a50c62bd_9f44_40e3_a53d_f4f1f2355a05

// Include Project files
#include "common/exception/CamsException.h"

namespace libcams
{

namespace controller
{

class NotImplementedActionException : public common::CamsException
{
public:
    NotImplementedActionException(std::string const & action);

    virtual ~NotImplementedActionException() noexcept;

protected:

private:

};

} // namespace controller

} // namespace libcams

#endif // _a50c62bd_9f44_40e3_a53d_f4f1f2355a05