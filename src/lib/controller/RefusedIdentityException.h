#ifndef _ee917d34_e696_4254_9682_ec9f1c27145c
#define _ee917d34_e696_4254_9682_ec9f1c27145c

// Include Project files
#include "common/exception/CamsException.h"

namespace libcams
{

namespace controller
{

/**
 * @brief The RefusedIdentityException class
 */
class RefusedIdentityException : public common::CamsException
{
public:
    /**
     * @brief Create an instance of RefusedIdentityException
     */
    RefusedIdentityException();

    /**
     * @brief Destructor
     */
    virtual ~RefusedIdentityException() noexcept;

protected:

private:

};

} // namespace controller

} // namespace libcams

#endif // _ee917d34_e696_4254_9682_ec9f1c27145c
