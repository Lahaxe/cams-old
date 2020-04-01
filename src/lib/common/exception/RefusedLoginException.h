#ifndef _420d8c94_a9d0_4e88_97e1_8eb81886c656
#define _420d8c94_a9d0_4e88_97e1_8eb81886c656

// Include Project files
#include "common/exception/CamsException.h"

namespace libcams
{

namespace common
{

/**
 * @brief The RefusedLoginException class
 */
class RefusedLoginException : public common::CamsException
{
public:
    /**
     * @brief Create an instance of RefusedLoginException
     */
    RefusedLoginException();

    /**
     * @brief Destructor
     */
    virtual ~RefusedLoginException() noexcept;

protected:

private:

};

} // namespace common

} // namespace libcams

#endif // _420d8c94_a9d0_4e88_97e1_8eb81886c656
