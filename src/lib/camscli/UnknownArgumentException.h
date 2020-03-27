#ifndef _389b4910_6f37_4f7d_a4b7_5af298c97bf5
#define _389b4910_6f37_4f7d_a4b7_5af298c97bf5

// Include Project files
#include "common/exception/CamsException.h"

namespace libcams
{

namespace camscli
{

/**
 * @brief The UnknownArgumentException class
 */
class UnknownArgumentException : public common::CamsException
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

} // namespace camscli

} // namespace libcams

#endif // _389b4910_6f37_4f7d_a4b7_5af298c97bf5
