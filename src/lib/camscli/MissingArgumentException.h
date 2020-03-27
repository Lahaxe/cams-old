#ifndef _360d5488_4513_4b8e_8db0_5e691783d3bb
#define _360d5488_4513_4b8e_8db0_5e691783d3bb

// Include Project files
#include "common/exception/CamsException.h"

namespace libcams
{

namespace camscli
{

/**
 * @brief The MissingArgumentException class
 */
class MissingArgumentException : public common::CamsException
{
public:
    /**
     * @brief Constructor
     * @param argument: Unknown argument
     */
    MissingArgumentException(std::string const & argument);

    /**
     * @brief Destructor
     */
    virtual ~MissingArgumentException() noexcept;

protected:

private:

};

} // namespace camscli

} // namespace libcams

#endif // _360d5488_4513_4b8e_8db0_5e691783d3bb
