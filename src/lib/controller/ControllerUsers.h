#ifndef _2bfc219c_9f95_4178_8c00_0ca7c6499d2a
#define _2bfc219c_9f95_4178_8c00_0ca7c6499d2a

//Include Project files
#include "controller/ControllerBase.h"

namespace libcams
{

namespace controller
{

/**
 * @brief The ControllerUsers class
 */
class ControllerUsers : public ControllerBase
{
public:
    /// @brief The ControllerUsers Pointer type
    typedef std::shared_ptr<ControllerUsers> Pointer;

    /// @brief The ControllerUsers constante Pointer type
    typedef std::shared_ptr<ControllerUsers const> ConstPointer;

    /**
     * @brief Create pointer to a new instance of ControllerUsers
     * @return Return Pointer to new instance of ControllerUsers
     */
    static Pointer New();

    /**
     * @brief Destructor
     */
    virtual ~ControllerUsers();

    /**
     * @brief Return the name of this class
     * @return Return name of this class
     */
    static std::string class_name();

protected:
    /**
     * @brief Execute the POST action
     */
    virtual QJsonDocument execute_get(std::string const & ressource = "");

private:
    /**
     * @brief Create an instance of ControllerUsers
     */
    ControllerUsers();

    /**
     * @brief Copy constructor: purposely not implemented
     * @param other: Object to copy
     */
    ControllerUsers(ControllerUsers const & other);

    /**
     * @brief operator =: purposely not implemented
     * @param other: Object to copy
     */
    ControllerUsers& operator=(ControllerUsers const & other);

};

}

}

#endif // _2bfc219c_9f95_4178_8c00_0ca7c6499d2a
