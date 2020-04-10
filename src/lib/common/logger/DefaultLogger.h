#ifndef _365e5589_7aa8_448f_8bfd_ceae68ac3a10
#define _365e5589_7aa8_448f_8bfd_ceae68ac3a10

// Include Project files
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
 * @brief The DefaultLogger class
 */
class DefaultLogger : public LoggerBase
{
public:
    /// @brief The DefaultLogger Pointer type
    typedef std::shared_ptr<DefaultLogger> Pointer;

    /// @brief The DefaultLogger constante Pointer type
    typedef std::shared_ptr<DefaultLogger const> ConstPointer;

    /**
     * @brief Create pointer to a new instance of DefaultLogger
     * @return Return Pointer to new instance of DefaultLogger
     */
    static Pointer New();

    /**
     * @brief Destroy the instance of DefaultLogger
     */
    virtual ~DefaultLogger();

    /**
     * @brief Return the name of this class
     * @return Return name of this class
     */
    static std::string class_name();

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

} // namespace lib

} // namespace cams

#endif // _365e5589_7aa8_448f_8bfd_ceae68ac3a10
