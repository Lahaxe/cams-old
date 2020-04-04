#ifndef _4dd605ca_d2ca_4bad_a171_813a924358d9
#define _4dd605ca_d2ca_4bad_a171_813a924358d9

#include <memory>
#include <string>

#include <boost/property_tree/ptree.hpp>

/// @brief Main namespace
namespace cams
{

namespace lib
{

namespace common
{

/**
 * @brief The Configuration class
 */
class INIFileParser
{
public:
    /// @brief The INIFileParser Pointer type
    typedef std::shared_ptr<INIFileParser> Pointer;

    /// @brief The INIFileParser constant Pointer type
    typedef std::shared_ptr<INIFileParser const> ConstPointer;

    static Pointer New(std::string const & filename = "");

    /**
     * @brief Destroy the instance of Configuration
     */
    virtual ~INIFileParser();

    void read();

    void write();

    bool contains_key(std::string const & key);

    std::string get_value(std::string const & key) const;

    void set_value(std::string const & key,
                   std::string const & value);

protected:

private:
    /// @brief Create an instance of INIFileParser
    INIFileParser(std::string const & filename = "");

    std::string _filename;

    boost::property_tree::ptree* _tree;

};

} // namespace common

} // namespace lib

} // namespace cams

#endif // _4dd605ca_d2ca_4bad_a171_813a924358d9
