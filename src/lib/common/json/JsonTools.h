#ifndef _3ba4d15b_e468_4107_82c2_028cee8dcb3b
#define _3ba4d15b_e468_4107_82c2_028cee8dcb3b

// Include Qt files
#include <QJsonObject>

/// @brief Main namespace
namespace cams
{

/// @brief Cams library part
namespace lib
{

/// @brief Common part
namespace common
{

/// @brief Specific JSON functions
namespace json
{

/**
 * @brief Writes a given JSON in a given file
 * @param json: JSON to write
 * @param filename: Name of the file
 * @return Returns true if successful, false otherwise
 */
bool to_file(QJsonObject const & json, std::string const & filename);

/**
 * @brief Reads a JSON from a given file
 * @param json: Readed JSON
 * @param filename: Name of the file
 * @return Returns true if successful, false otherwise
 */
bool from_file(QJsonObject & json, std::string const & filename);

} // namespace json

} // namespace common

} // namespace lib

} // namespace cams

#endif // _3ba4d15b_e468_4107_82c2_028cee8dcb3b
