
#include <experimental/filesystem>

#include <boost/property_tree/ini_parser.hpp>

#include "common/configuration/INIFileParser.h"

namespace libcams
{

namespace common
{

INIFileParser::Pointer
INIFileParser
::New(std::string const & filename)
{
    return Pointer(new INIFileParser(filename));
}

INIFileParser
::INIFileParser(std::string const & filename):
    _filename(filename), _tree(new boost::property_tree::ptree())
{
    // Nothing to do
}

INIFileParser
::~INIFileParser()
{
    if (this->_tree != nullptr)
    {
        delete this->_tree;
        this->_tree = nullptr;
    }
}

void
INIFileParser
::read()
{
    if (this->_filename.empty())
    {
        throw std::exception();
    }

    if (!std::experimental::filesystem::v1::exists(this->_filename))
    {
        throw std::exception();
    }

    if (this->_tree == nullptr)
    {
        this->_tree = new boost::property_tree::ptree();
    }

    boost::property_tree::ini_parser::read_ini(this->_filename, *this->_tree);
}

void
INIFileParser
::write()
{
    if (this->_filename.empty())
    {
        throw std::exception();
    }

    boost::property_tree::ini_parser::write_ini(this->_filename, *this->_tree);
}

bool
INIFileParser
::contains_key(std::string const & key)
{
    return (this->_tree->find(key) != this->_tree->not_found());
}

std::string
INIFileParser
::get_value(std::string const & key) const
{
    return this->_tree->get<std::string>(key);
}

void
INIFileParser
::set_value(std::string const & key, std::string const & value)
{
    this->_tree->put(key, value);
}

} // namespace common

} // namespace libcams
