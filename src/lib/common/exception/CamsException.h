#ifndef _aea06ea4_e689_4029_bf14_ab86d3f59139
#define _aea06ea4_e689_4029_bf14_ab86d3f59139

// Include Standard library
#include <exception>
#include <string>

/**
 * @brief The CamsException class
 */
class CamsException : public std::exception
{
public:
    /**
     * @brief Message string constructor
     * @param message: Details of the exception
     */
    CamsException(std::string const & message = "");

    /**
     * @brief Destructor
     */
    virtual ~CamsException() noexcept;

    /**
     * @brief Return the reason for the exception
     * @return Return Details of the exception
     */
    virtual const char* what() const noexcept;

protected:
    /// @brief Message of the exception
    std::string _message;

private:
};

#endif // _aea06ea4_e689_4029_bf14_ab86d3f59139
