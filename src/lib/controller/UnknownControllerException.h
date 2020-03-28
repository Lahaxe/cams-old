#ifndef _43156d82_eaa1_4140_9fa9_1471c2f7a215
#define _43156d82_eaa1_4140_9fa9_1471c2f7a215

// Include Project files
#include "common/exception/CamsException.h"

namespace libcams
{

namespace controller
{

class UnknownControllerException : public common::CamsException
{
public:
    UnknownControllerException(std::string const & controller);

    virtual ~UnknownControllerException() noexcept;

protected:

private:

};

} // namespace controller

} // namespace libcams

#endif // _43156d82_eaa1_4140_9fa9_1471c2f7a215
