#ifndef _8cb5f1d3_c27f_41fe_83e6_a8c739a77168
#define _8cb5f1d3_c27f_41fe_83e6_a8c739a77168

// Include Project files
#include "common/exception/CamsException.h"

namespace libcams
{

namespace common
{

/**
 * @brief The CamsException class
 */
class NotImplementedException : public CamsException
{
public:
    /**
     * @brief Message string constructor
     * @param message: Details of the exception
     */
    NotImplementedException();

    /**
     * @brief Destructor
     */
    virtual ~NotImplementedException() noexcept;

protected:

private:

};

} // namespace common

} // namespace libcams

#endif // _8cb5f1d3_c27f_41fe_83e6_a8c739a77168
