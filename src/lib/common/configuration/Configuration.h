#ifndef _154184e2_33d1_4fce_b249_649787afaa69
#define _154184e2_33d1_4fce_b249_649787afaa69

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
 * @brief The Configuration class
 */
class Configuration
{
public:
    /**
     * @brief Create an unique instance of Configuration
     * @return Return the instance of Configuration
     */
    static Configuration & instance();

    /**
     * @brief Destory the instance of Configuration
     */
    static void delete_instance();

    /**
     * @brief Destroy the instance of Configuration
     */
    virtual ~Configuration();

    std::string get_connector_type() const;

    void set_connector_type(std::string const & connector_type);

    std::string get_logger_type() const;

    void set_logger_type(std::string const & logger_type);

    std::string get_connector_file_root_path() const;

    void set_connector_file_root_path(std::string const & connector_file_root_path);

protected:

private:
    /// @brief Create an instance of Configuration
    Configuration();

    /// @brief Unique instance of Configuration
    static Configuration* _instance;

    /**
     * @brief Copy constructor: purposely not implemented
     * @param other: Object to copy
     */
    Configuration(Configuration const & other);

    /**
     * @brief operator =: purposely not implemented
     * @param other: Object to copy
     */
    void operator=(Configuration const & other);

    std::string _connector_type;

    std::string _logger_type;

    std::string _connector_file_root_path;

    void _load_configuration_file();

};

} // namespace common

} // namespace lib

} // namespace cams

#endif // _154184e2_33d1_4fce_b249_649787afaa69
