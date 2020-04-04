#ifndef _58338cae_774c_403e_b673_b68d789be7d5
#define _58338cae_774c_403e_b673_b68d789be7d5

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
 * @brief The UnknownActionException class
 */
class UnknownActionException : public common::CamsException
{
public:
    /**
     * @brief Create an isntance of UnknownActionException
     * @param action: Name of the action
     */
    UnknownActionException(std::string const & action);

    /**
     * @brief Destructor
     */
    virtual ~UnknownActionException() noexcept;

protected:

private:

};

} // namespace controller

} // namespace lib

} // namespace cams

#endif // _58338cae_774c_403e_b673_b68d789be7d5
