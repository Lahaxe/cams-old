#ifndef _a45a4540_1a7a_44f8_b997_5b0311e5dabb
#define _a45a4540_1a7a_44f8_b997_5b0311e5dabb

// Include Standard library
#include <memory>

// Include Project files
#include "connector/ConnectorBase.h"
#include "controller/Identity.h"

namespace libcams
{

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
     * @brief Get identity member
     * @return Return value of identity
     */
    Identity::Pointer get_identity() const;

    /**
     * @brief Set identity member
     * @param password: New value of identity
     */
    void set_identity(Identity::Pointer identity);

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
    std::string execute(std::string const & action);

protected:
    /// @brief The identity data
    Identity::Pointer _identity;

    connector::ConnectorBase::Pointer _connector;

    /**
     * @brief Execute the GET action
     */
    virtual std::string execute_get();

    /**
     * @brief Execute the POST action
     */
    virtual std::string execute_post();

    /**
     * @brief Execute the PUT action
     */
    virtual std::string execute_put();

    /**
     * @brief Execute the PATCH action
     */
    virtual std::string execute_patch();

    /**
     * @brief Execute the DELETE action
     */
    virtual std::string execute_delete();

    /**
     * @brief Execute the OPTIONS action
     */
    virtual std::string execute_options();

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

}

}

#endif // _a45a4540_1a7a_44f8_b997_5b0311e5dabb
