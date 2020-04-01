#ifndef _3ba4d15b_e468_4107_82c2_028cee8dcb3b
#define _3ba4d15b_e468_4107_82c2_028cee8dcb3b

// Include Qt files
#include <QJsonObject>

namespace libcams
{

namespace common
{

namespace json
{

bool to_file(QJsonObject const & json, std::string const & filename);

bool from_file(QJsonObject & json, std::string const & filename);

}

}

}

#endif // _3ba4d15b_e468_4107_82c2_028cee8dcb3b
