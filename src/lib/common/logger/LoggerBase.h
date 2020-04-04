#ifndef _9e6c3d75_bc55_47f8_b528_ac620af6b5b7
#define _9e6c3d75_bc55_47f8_b528_ac620af6b5b7

// Include Standard library
#include <memory>
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
 * @brief The Logger class
 */
class LoggerBase
{
public:
    /// @brief The LoggerBase Pointer type
    typedef std::shared_ptr<LoggerBase> Pointer;

    /// @brief The LoggerBase constant Pointer type
    typedef std::shared_ptr<LoggerBase const> ConstPointer;

    /**
     * @brief Create an instance of Logger
     */
    LoggerBase();

    /**
     * @brief Destructor
     */
    virtual ~LoggerBase();

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
    /**
     * @brief Write line
     * @param message: Text to log
     * @param level: Log level
     */
    virtual void write(std::string const & message, std::string const & level) = 0;

private:

};

} // namespace common

} // namespace lib

} // namespace cams

#endif // _9e6c3d75_bc55_47f8_b528_ac620af6b5b7
