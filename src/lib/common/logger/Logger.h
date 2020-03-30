#ifndef _730ac144_2efe_44ba_a248_2e48b183a75a
#define _730ac144_2efe_44ba_a248_2e48b183a75a

// Include Standard library
#include <string>

namespace libcams
{

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

protected:
    /// Unique instance
    static Logger* _instance;

    /**
     * @brief Write line
     * @param message: Text to log
     * @param level: Log level
     */
    virtual void write(std::string const & message, std::string const & level) = 0;

private:

};

} // namespace common

} // namespace libcams

#endif // _730ac144_2efe_44ba_a248_2e48b183a75a
