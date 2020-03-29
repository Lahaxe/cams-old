#ifndef _a45a4540_1a7a_44f8_b997_5b0311e5dabb
#define _a45a4540_1a7a_44f8_b997_5b0311e5dabb

// Include Standard library
#include <memory>

// Include Project files
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
    ControllerBase(Identity::Pointer identity = nullptr);

    /**
     * @brief Destructor
     */
    virtual ~ControllerBase();

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
    void execute(std::string const & action);

protected:
    Identity::Pointer _identity;

    /**
     * @brief Execute the GET action
     */
    virtual void execute_get();

    /**
     * @brief Execute the POST action
     */
    virtual void execute_post();

    /**
     * @brief Execute the PUT action
     */
    virtual void execute_put();

    /**
     * @brief Execute the PATCH action
     */
    virtual void execute_patch();

    /**
     * @brief Execute the DELETE action
     */
    virtual void execute_delete();

    /**
     * @brief Execute the OPTIONS action
     */
    virtual void execute_options();

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
