#ifndef _8cb5f1d3_c27f_41fe_83e6_a8c739a77168
#define _8cb5f1d3_c27f_41fe_83e6_a8c739a77168

// Include Project files
#include "common/exception/CamsException.h"

/// @brief Main namespace
namespace cams
{

/// @brief Cams library part
namespace lib
{

/// @brief Common part
namespace common
{

/**
 * @brief The NotImplementedException class
 */
class NotImplementedException : public CamsException
{
public:
    /**
     * @brief Create an instance of NotImplementedException
     */
    NotImplementedException();

    /**
     * @brief Destroy the instance of NotImplementedException
     */
    virtual ~NotImplementedException() noexcept;

protected:

private:

};

} // namespace common

} // namespace lib

} // namespace cams

#endif // _8cb5f1d3_c27f_41fe_83e6_a8c739a77168
