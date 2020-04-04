#ifndef _a45a4540_1a7a_44f8_b997_5b0311e5dabb
#define _a45a4540_1a7a_44f8_b997_5b0311e5dabb

// Include Standard library
#include <memory>

#include <QJsonDocument>

// Include Project files
#include "connector/ConnectorBase.h"
#include "model/users/Identity.h"

/// @brief Main namespace
namespace cams
{

/// @brief Cams library part
namespace lib
{

/// @brief Controller part
namespace controller
{

const std::string ACTION_GET = "GET";
const std::string ACTION_POST = "POST";
const std::string ACTION_PUT = "PUT";
const std::string ACTION_PATCH = "PATCH";
const std::string ACTION_DELETE = "DELETE";
const std::string ACTION_OPTIONS = "OPTIONS";

/**
 * @brief The ControllerBase class
 */
class ControllerBase
{
public:
    /// @brief The ControllerBase Pointer type
    typedef std::shared_ptr<ControllerBase> Pointer;

    /// @brief The ControllerBase constant Pointer type
    typedef std::shared_ptr<ControllerBase const> ConstPointer;

    /**
     * @brief Create an instance of ControllerBase
     */
    ControllerBase();

    /**
     * @brief Destructor
     */
    virtual ~ControllerBase();

    /**
     * @brief Get connector member
     * @return Return value of connector
     */
    connector::ConnectorBase::Pointer get_connector() const;

    /**
     * @brief Set connector member
     * @param password: New value of connector
     */
    void set_connector(connector::ConnectorBase::Pointer connector);

    /**
     * @brief Indicate if a given action exists
     * @param action: The given action name
     * @return Return true if the given action exists
     */
    bool exists_action(std::string const & action) const;

    /**
     * @brief Execute the given action
     * @param action: The given action name
     */
    QJsonDocument execute(std::string const & action, std::string const & ressource = "", QJsonDocument const & document = QJsonDocument());

protected:
    connector::ConnectorBase::Pointer _connector;

    /**
     * @brief Execute the GET action
     */
    virtual QJsonDocument execute_get(std::string const & ressource = "", QJsonDocument const & document = QJsonDocument());

    /**
     * @brief Execute the POST action
     */
    virtual QJsonDocument execute_post(std::string const & ressource = "", QJsonDocument const & document = QJsonDocument());

    /**
     * @brief Execute the PUT action
     */
    virtual QJsonDocument execute_put(std::string const & ressource = "", QJsonDocument const & document = QJsonDocument());

    /**
     * @brief Execute the PATCH action
     */
    virtual QJsonDocument execute_patch(std::string const & ressource = "", QJsonDocument const & document = QJsonDocument());

    /**
     * @brief Execute the DELETE action
     */
    virtual QJsonDocument execute_delete(std::string const & ressource = "", QJsonDocument const & document = QJsonDocument());

    /**
     * @brief Execute the OPTIONS action
     */
    virtual QJsonDocument execute_options(std::string const & ressource = "", QJsonDocument const & document = QJsonDocument());

private:
    /**
     * @brief Copy constructor (Purposely not implemented)
     * @param other: Object to copy
     */
    ControllerBase(ControllerBase const & other);

    /**
     * @brief operator = (Purposely not implemented)
     * @param other: Object to copy
     * @return Return a copy of a given ControllerBase
     */
    ControllerBase& operator=(ControllerBase const & other);

};

} // namespace controller

} // namespace lib

} // namespace cams

#endif // _a45a4540_1a7a_44f8_b997_5b0311e5dabb
