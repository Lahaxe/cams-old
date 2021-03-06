#ifndef _2bfc219c_9f95_4178_8c00_0ca7c6499d2a
#define _2bfc219c_9f95_4178_8c00_0ca7c6499d2a

//Include Project files
#include "controller/ControllerBase.h"

/// @brief Main namespace
namespace cams
{

/// @brief Cams library part
namespace lib
{

/// @brief Controller part
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
     * @brief Destroy the instance of ControllerUsers
     */
    virtual ~ControllerUsers();

    /**
     * @brief Return the name of this class
     * @return Return name of this class
     */
    static std::string class_name();

protected:
    /**
     * @brief Execute the GET action
     * @param ressource: Path of the ressource
     * @param document: Input JSON document
     * @return Returns the result of the given action as JSON
     */
    virtual QJsonDocument execute_get(std::string const & ressource = "", QJsonDocument const & document = QJsonDocument());

    /**
     * @brief Execute the POST action
     * @param ressource: Path of the ressource
     * @param document: Input JSON document
     * @return Returns the result of the given action as JSON
     */
    virtual QJsonDocument execute_post(std::string const & ressource = "", QJsonDocument const & document = QJsonDocument());

    /**
     * @brief Execute the PUT action
     * @param ressource: Path of the ressource
     * @param document: Input JSON document
     * @return Returns the result of the given action as JSON
     */
    virtual QJsonDocument execute_put(std::string const & ressource = "", QJsonDocument const & document = QJsonDocument());

    /**
     * @brief Execute the PATCH action
     * @param ressource: Path of the ressource
     * @param document: Input JSON document
     * @return Returns the result of the given action as JSON
     */
    virtual QJsonDocument execute_patch(std::string const & ressource = "", QJsonDocument const & document = QJsonDocument());

    /**
     * @brief Execute the DELETE action
     * @param ressource: Path of the ressource
     * @param document: Input JSON document
     * @return Returns the result of the given action as JSON
     */
    virtual QJsonDocument execute_delete(std::string const & ressource = "", QJsonDocument const & document = QJsonDocument());

    /**
     * @brief Execute the OPTIONS action
     * @param ressource: Path of the ressource
     * @param document: Input JSON document
     * @return Returns the result of the given action as JSON
     */
    virtual QJsonDocument execute_options(std::string const & ressource = "", QJsonDocument const & document = QJsonDocument());

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

} // namespace controller

} // namespace lib

} // namespace cams

#endif // _2bfc219c_9f95_4178_8c00_0ca7c6499d2a
