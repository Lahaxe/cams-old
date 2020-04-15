#ifndef _d95b22e0_911a_4f38_904b_a8bc697cbf5b
#define _d95b22e0_911a_4f38_904b_a8bc697cbf5b

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
 * @brief The ControllerStamps class
 */
class ControllerStamps : public ControllerBase
{
public:
    /// @brief The ControllerStamps Pointer type
    typedef std::shared_ptr<ControllerStamps> Pointer;

    /// @brief The ControllerStamps constante Pointer type
    typedef std::shared_ptr<ControllerStamps const> ConstPointer;

    /**
     * @brief Create pointer to a new instance of ControllerUsers
     * @return Return Pointer to new instance of ControllerUsers
     */
    static Pointer New();

    /**
     * @brief Destroy the instance of ControllerUsers
     */
    virtual ~ControllerStamps();

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
     * @brief Create an instance of ControllerStamps
     */
    ControllerStamps();

    /**
     * @brief Copy constructor: purposely not implemented
     * @param other: Object to copy
     */
    ControllerStamps(ControllerStamps const & other);

    /**
     * @brief operator =: purposely not implemented
     * @param other: Object to copy
     */
    ControllerStamps& operator=(ControllerStamps const & other);

};

} // namespace controller

} // namespace lib

} // namespace cams

#endif // _d95b22e0_911a_4f38_904b_a8bc697cbf5b
