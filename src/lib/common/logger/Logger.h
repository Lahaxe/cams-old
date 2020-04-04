#ifndef _730ac144_2efe_44ba_a248_2e48b183a75a
#define _730ac144_2efe_44ba_a248_2e48b183a75a

// Include Standard library
#include <string>

#include "common/logger/LoggerBase.h"

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
 * @brief The Logger class
 */
class Logger
{
public:
    /**
     * @brief Create and return an unique instance of Logger
     * @return unique instance of Logger
     */
    static Logger& instance();

    /**
     * @brief Remove the unique instance of Logger
     */
    static void delete_instance();

    /**
     * @brief Create an instance of Logger
     */
    Logger();

    /**
     * @brief Destructor
     */
    virtual ~Logger();

    /**
     * @brief Write DEBUG line
     * @param message: Text to log
     */
    void debug(std::string const & message);

    /**
     * @brief Write INFO line
     * @param message: Text to log
     */
    void info(std::string const & message);

    /**
     * @brief Write WARNING line
     * @param message: Text to log
     */
    void warning(std::string const & message);

    /**
     * @brief Write ERROR line
     * @param message: Text to log
     */
    void error(std::string const & message);

    /**
     * @brief Write FATAL line
     * @param message: Text to log
     */
    void fatal(std::string const & message);

    void set_logger_writer(LoggerBase::Pointer logger_writer);

protected:

private:
    /// Unique instance
    static Logger* _instance;

    LoggerBase::Pointer _logger_writer;

};

} // namespace common

} // namespace lib

} // namespace cams

#endif // _730ac144_2efe_44ba_a248_2e48b183a75a
