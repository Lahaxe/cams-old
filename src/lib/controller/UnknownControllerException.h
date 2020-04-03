#ifndef _43156d82_eaa1_4140_9fa9_1471c2f7a215
#define _43156d82_eaa1_4140_9fa9_1471c2f7a215

// Include Project files
#include "common/exception/CamsException.h"

namespace cams
{

namespace lib
{

namespace controller
{

/**
 * @brief The UnknownControllerException class
 */
class UnknownControllerException : public common::CamsException
{
public:
    /**
     * @brief Create an instance of UnknownControllerException
     * @param controller: Name of the controller
     */
    UnknownControllerException(std::string const & controller);

    /**
     * @brief Destructor
     */
    virtual ~UnknownControllerException() noexcept;

protected:

private:

};

} // namespace controller

}

} // namespace libcams

#endif // _43156d82_eaa1_4140_9fa9_1471c2f7a215
