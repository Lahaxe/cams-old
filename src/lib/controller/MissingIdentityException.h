#ifndef _9c9f7b09_66c1_4619_8108_7abc426dc22c
#define _9c9f7b09_66c1_4619_8108_7abc426dc22c

// Include Project files
#include "common/exception/CamsException.h"

namespace libcams
{

namespace controller
{

/**
 * @brief The MissingIdentityException class
 */
class MissingIdentityException : public common::CamsException
{
public:
    /**
     * @brief Create an instance of MissingIdentityException
     */
    MissingIdentityException();

    /**
     * @brief Destructor
     */
    virtual ~MissingIdentityException() noexcept;

protected:

private:

};

} // namespace controller

} // namespace libcams

#endif // _9c9f7b09_66c1_4619_8108_7abc426dc22c
