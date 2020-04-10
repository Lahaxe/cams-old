#ifndef _314d338a_29c1_4858_9898_a94e63ecba66
#define _314d338a_29c1_4858_9898_a94e63ecba66

// Include Standard library
#include <exception>
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
 * @brief The CamsException class
 */
class CamsException : public std::exception
{
public:
    /**
     * @brief Message string constructor
     * @param message: Details of the exception
     * @param code: Code of the exception
     */
    CamsException(std::string const & message = "", unsigned int code = 500);

    /**
     * @brief Destroy the instance of CamsException
     */
    virtual ~CamsException() noexcept;

    /**
     * @brief Return the reason for the exception
     * @return Return Details of the exception
     */
    virtual const char* what() const noexcept;

    /**
     * @brief Converts this exception as a JSON string
     * @return Returns this exception as a JSON string
     */
    std::string to_json() const noexcept;

protected:
    /// @brief Message of the exception
    std::string _message;

    /// @brief Code of the exception
    unsigned int _code;

private:

};

} // namespace common

} // namespace lib

} // namespace cams

#endif // _314d338a_29c1_4858_9898_a94e63ecba66
