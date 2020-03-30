#ifndef _8ac46421_eb00_4ad6_81bf_8bc288caa2ae
#define _8ac46421_eb00_4ad6_81bf_8bc288caa2ae

// Include Qt files
#include <QJsonObject>

namespace common
{

namespace json
{

bool to_file(QJsonObject const & json, std::string const & filename);

bool from_file(QJsonObject & json, std::string const & filename);

}

}

#endif // _8ac46421_eb00_4ad6_81bf_8bc288caa2ae
