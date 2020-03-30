#ifndef _82610f19_e640_4e65_bd75_049dfa0b9170
#define _82610f19_e640_4e65_bd75_049dfa0b9170

#include "common/logger/Logger.h"

namespace libcams
{

namespace common
{

/**
 * @brief The FileLogger class
 */
class FileLogger : public Logger
{
public:
    /**
     * @brief Create and return an unique instance of FileLogger
     */
    static void create_instance();

    /**
     * @brief Destructor
     */
    virtual ~FileLogger();

protected:

private:
    /**
     * @brief Create an instance of FileLogger
     */
    FileLogger();

    /**
     * @brief Write line
     * @param message: Text to log
     * @param level: Log level
     */
    virtual void write(std::string const & message, std::string const & level);

};

} // namespace common

} // namespace libcams

#endif // _82610f19_e640_4e65_bd75_049dfa0b9170
