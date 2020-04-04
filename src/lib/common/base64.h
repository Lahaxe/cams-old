#ifndef _6b3ce989_7683_4220_9287_e4d218abedf1
#define _6b3ce989_7683_4220_9287_e4d218abedf1

// Include Standard library
#include <string>

/// @brief Main namespace
namespace cams
{

namespace lib
{

namespace common
{

std::string to_base64(std::string const & text);

std::string from_base64(std::string const & encoded_text);

} // namespace common

} // namespace lib

} // namespace cams

#endif // _6b3ce989_7683_4220_9287_e4d218abedf1
