#ifndef _6b3ce989_7683_4220_9287_e4d218abedf1
#define _6b3ce989_7683_4220_9287_e4d218abedf1

// Include Standard library
#include <string>

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
 * @brief Encodes a given string into Base 64 string
 * @param text: text to convert
 * @return Returns the Base 64 encoded string
 */
std::string to_base64(std::string const & text);

/**
 * @brief Decodes a given base 64 string into string
 * @param encoded_text: text to decode
 * @return Returns the decoded string
 */
std::string from_base64(std::string const & encoded_text);

} // namespace common

} // namespace lib

} // namespace cams

#endif // _6b3ce989_7683_4220_9287_e4d218abedf1
