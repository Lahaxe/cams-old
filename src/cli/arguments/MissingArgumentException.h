#ifndef _360d5488_4513_4b8e_8db0_5e691783d3bb
#define _360d5488_4513_4b8e_8db0_5e691783d3bb

// Include Project files
#include "common/exception/CamsException.h"

/// @brief Main namespace
namespace cams
{

/// @brief Cams Command Line Interface part
namespace cli
{

/**
 * @brief The MissingArgumentException class
 */
class MissingArgumentException : public lib::common::CamsException
{
public:
    /**
     * @brief Create an instance of MissingArgumentException
     * @param argument: The missing argument
     */
    MissingArgumentException(std::string const & argument);

    /**
     * @brief Destroy the instance of MissingArgumentException
     */
    virtual ~MissingArgumentException() noexcept;

protected:

private:

};

} // namespace cli

} // namespace cams

#endif // _360d5488_4513_4b8e_8db0_5e691783d3bb
