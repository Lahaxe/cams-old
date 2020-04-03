#ifndef _360d5488_4513_4b8e_8db0_5e691783d3bb
#define _360d5488_4513_4b8e_8db0_5e691783d3bb

// Include Project files
#include "common/exception/CamsException.h"

namespace cams
{

namespace cli
{

/**
 * @brief The MissingArgumentException class
 */
class MissingArgumentException : public lib::common::CamsException
{
public:
    /**
     * @brief Constructor
     * @param argument: The missing argument
     */
    MissingArgumentException(std::string const & argument);

    /**
     * @brief Destructor
     */
    virtual ~MissingArgumentException() noexcept;

protected:

private:

};

}

}

#endif // _360d5488_4513_4b8e_8db0_5e691783d3bb