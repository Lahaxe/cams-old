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
     * @brief Destory the unique instance of Configuration
     */
    static void delete_instance();

    /**
     * @brief Destroy the instance of Configuration
     */
    virtual ~Configuration();

    /**
     * @brief Get the Configuration connector_type
     * @return Return the Configuration connector_type
     */
    std::string get_connector_type() const;

    /**
     * @brief Set the Configuration connector_type
     * @param name: New Configuration connector_type
     */
    void set_connector_type(std::string const & connector_type);

    /**
     * @brief Get the Configuration logger_type
     * @return Return the Configuration logger_type
     */
    std::string get_logger_type() const;

    /**
     * @brief Set the Configuration logger_type
     * @param name: New Configuration logger_type
     */
    void set_logger_type(std::string const & logger_type);

    /**
     * @brief Get the Configuration connector_file_root_path
     * @return Return the Configuration connector_file_root_path
     */
    std::string get_connector_file_root_path() const;

    /**
     * @brief Set the Configuration connector_file_root_path
     * @param name: New Configuration connector_file_root_path
     */
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

    /// @brief Connector type
    std::string _connector_type;

    /// @brief Logger type
    std::string _logger_type;

    /// @brief Root path for the file connector
    std::string _connector_file_root_path;

    /**
     * @brief Reads configuration from file
     */
    void _load_configuration_file();

};

} // namespace common

} // namespace lib

} // namespace cams

#endif // _154184e2_33d1_4fce_b249_649787afaa69
