#ifndef _a50c62bd_9f44_40e3_a53d_f4f1f2355a05
#define _a50c62bd_9f44_40e3_a53d_f4f1f2355a05

// Include Project files
#include "common/exception/CamsException.h"

/// @brief Main namespace
namespace cams
{

/// @brief Cams library part
namespace lib
{

/// @brief Controller part
namespace controller
{

/**
 * @brief The NotImplementedActionException class
 */
class NotImplementedActionException : public common::CamsException
{
public:
    /**
     * @brief Create an instance of NotImplementedActionException
     * @param action: Name of the action
     */
    NotImplementedActionException(std::string const & action);

    /**
     * @brief Destroy the instance of NotImplementedActionException
     */
    virtual ~NotImplementedActionException() noexcept;

protected:

private:

};

} // namespace controller

} // namespace lib

} // namespace cams

#endif // _a50c62bd_9f44_40e3_a53d_f4f1f2355a05
