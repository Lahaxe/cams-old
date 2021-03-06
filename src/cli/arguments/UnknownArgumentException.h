#ifndef _389b4910_6f37_4f7d_a4b7_5af298c97bf5
#define _389b4910_6f37_4f7d_a4b7_5af298c97bf5

// Include Project files
#include "common/exception/CamsException.h"

/// @brief Main namespace
namespace cams
{

/// @brief Cams Command Line Interface part
namespace cli
{

/**
 * @brief The UnknownArgumentException class
 */
class UnknownArgumentException : public lib::common::CamsException
{
public:
    /**
     * @brief Create an instance of UnknownArgumentException
     * @param argument: The unknown argument
     */
    UnknownArgumentException(std::string const & argument);

    /**
     * @brief Destroy the instance of UnknownArgumentException
     */
    virtual ~UnknownArgumentException() noexcept;

protected:

private:

};

} // namespace cli

} // namespace cams

#endif // _389b4910_6f37_4f7d_a4b7_5af298c97bf5
