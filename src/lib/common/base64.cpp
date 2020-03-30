// Include Qt files
#include <QString>

// Include Project files
#include "common/base64.h"

namespace common
{

std::string to_base64(std::string const & text)
{
    QByteArray bytearray;
    bytearray.append(QString(text.c_str()));
    return bytearray.toBase64().toStdString();
}

std::string from_base64(std::string const & encoded_text)
{
    QByteArray encoded_bytearray;
    encoded_bytearray.append(QString(encoded_text.c_str()));

    auto bytearray = QByteArray::fromBase64(encoded_bytearray);
    return bytearray.toStdString();
}

}
