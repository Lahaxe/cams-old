#ifndef _389b4910_6f37_4f7d_a4b7_5af298c97bf5
#define _389b4910_6f37_4f7d_a4b7_5af298c97bf5

// Include Project files
#include "common/exception/CamsException.h"

/// @brief Main namespace
namespace cams
{

namespace cli
{

/**
 * @brief The UnknownArgumentException class
 */
class UnknownArgumentException : public lib::common::CamsException
{
public:
    /**
     * @brief Constructor
     * @param argument: Unknown argument
     */
    UnknownArgumentException(std::string const & argument);

    /**
     * @brief Destructor
     */
    virtual ~UnknownArgumentException() noexcept;

protected:

private:

};

} // namespace cli

} // namespace cams

#endif // _389b4910_6f37_4f7d_a4b7_5af298c97bf5
