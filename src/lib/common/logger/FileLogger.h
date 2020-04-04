#ifndef _82610f19_e640_4e65_bd75_049dfa0b9170
#define _82610f19_e640_4e65_bd75_049dfa0b9170

#include "common/logger/LoggerBase.h"

namespace cams
{

namespace lib
{

namespace common
{

/**
 * @brief The FileLogger class
 */
class FileLogger : public LoggerBase
{
public:
    /// @brief The FileLogger Pointer type
    typedef std::shared_ptr<FileLogger> Pointer;

    /// @brief The FileLogger constante Pointer type
    typedef std::shared_ptr<FileLogger const> ConstPointer;

    /**
     * @brief Create pointer to a new instance of FileLogger
     * @return Return Pointer to new instance of FileLogger
     */
    static Pointer New();

    /**
     * @brief Destructor
     */
    virtual ~FileLogger();

    /**
     * @brief Return the name of this class
     * @return Return name of this class
     */
    static std::string class_name();

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

} // namespace lib

} // namespace cams

#endif // _82610f19_e640_4e65_bd75_049dfa0b9170
