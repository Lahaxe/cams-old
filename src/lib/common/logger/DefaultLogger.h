#ifndef _365e5589_7aa8_448f_8bfd_ceae68ac3a10
#define _365e5589_7aa8_448f_8bfd_ceae68ac3a10

#include "common/logger/Logger.h"

namespace libcams
{

namespace common
{

/**
 * @brief The Logger class
 */
class DefaultLogger : public Logger
{
public:
    /**
     * @brief Create and return an unique instance of Logger
     * @return unique instance of Logger
     */
    static void create_instance();

    /**
     * @brief Destructor
     */
    virtual ~DefaultLogger();

protected:

private:
    /**
     * @brief Create an instance of Logger
     */
    DefaultLogger();

    /**
     * @brief Write line
     * @param message: Text to log
     * @param level: Log level
     */
    virtual void write(std::string const & message, std::string const & level);

};

} // namespace common

} // namespace libcams

#endif // _365e5589_7aa8_448f_8bfd_ceae68ac3a10
