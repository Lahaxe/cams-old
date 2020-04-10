#ifndef _4dd605ca_d2ca_4bad_a171_813a924358d9
#define _4dd605ca_d2ca_4bad_a171_813a924358d9

// Include Standrard library
#include <memory>
#include <string>

// Include Boost files
#include <boost/property_tree/ptree.hpp>

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
 * @brief The INIFileParser class
 */
class INIFileParser
{
public:
    /// @brief The INIFileParser Pointer type
    typedef std::shared_ptr<INIFileParser> Pointer;

    /// @brief The INIFileParser constant Pointer type
    typedef std::shared_ptr<INIFileParser const> ConstPointer;

    /**
     * @brief Create pointer to a new instance of INIFileParser
     * @param filename: Configuration file
     * @return Return a Pointer to new instance of INIFileParser
     */
    static Pointer New(std::string const & filename = "");

    /**
     * @brief Destroy the instance of Configuration
     */
    virtual ~INIFileParser();

    /**
     * @brief Read the configuration file
     */
    void read();

    /**
     * @brief Write the configuration into a file
     */
    void write();

    /**
     * @brief Indicates whether configuration contains the given key
     * @param key: Name of the key
     * @return Returns true if configuration contains the given key, false otherwise
     */
    bool contains_key(std::string const & key);

    /**
     * @brief Get the value of a given key
     * @param key: Name of the key
     * @return Returns the value of a given key
     */
    std::string get_value(std::string const & key) const;

    /**
     * @brief Set the value of a given key
     * @param key: Name of the key
     * @param value: New value of the key
     */
    void set_value(std::string const & key,
                   std::string const & value);

protected:

private:
    /// @brief Create an instance of INIFileParser
    INIFileParser(std::string const & filename = "");

    /// @brief Configuration filename
    std::string _filename;

    /// @brief Configuration tree
    boost::property_tree::ptree* _tree;

};

} // namespace common

} // namespace lib

} // namespace cams

#endif // _4dd605ca_d2ca_4bad_a171_813a924358d9
