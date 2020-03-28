#ifndef _58338cae_774c_403e_b673_b68d789be7d5
#define _58338cae_774c_403e_b673_b68d789be7d5

// Include Project files
#include "common/exception/CamsException.h"

namespace libcams
{

namespace controller
{

class UnknownActionException : public common::CamsException
{
public:
    UnknownActionException(std::string const & action);

    virtual ~UnknownActionException() noexcept;

protected:

private:

};

} // namespace controller

} // namespace libcams

#endif // _58338cae_774c_403e_b673_b68d789be7d5
