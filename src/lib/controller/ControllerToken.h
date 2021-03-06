#ifndef _d3ed60ca_8ce4_4dce_a886_8f98ed87cb61
#define _d3ed60ca_8ce4_4dce_a886_8f98ed87cb61

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
 * @brief The ControllerToken class
 */
class ControllerToken : public ControllerBase
{
public:
    /// @brief The ControllerToken Pointer type
    typedef std::shared_ptr<ControllerToken> Pointer;

    /// @brief The ControllerToken constante Pointer type
    typedef std::shared_ptr<ControllerToken const> ConstPointer;

    /**
     * @brief Create pointer to a new instance of ControllerToken
     * @return Return Pointer to new instance of ControllerToken
     */
    static Pointer New();

    /**
     * @brief Destroy the instance of ControllerToken
     */
    virtual ~ControllerToken();

    /**
     * @brief Return the name of this class
     * @return Return name of this class
     */
    static std::string class_name();

protected:
    /**
     * @brief Execute the POST action
     * @param ressource: Path of the ressource
     * @param document: Input JSON document
     * @return Returns the result of the given action as JSON
     */
    virtual QJsonDocument execute_post(std::string const & ressource = "", QJsonDocument const & document = QJsonDocument());

private:
    /**
     * @brief Create an instance of ControllerToken
     */
    ControllerToken();

    /**
     * @brief Copy constructor: purposely not implemented
     * @param other: Object to copy
     */
    ControllerToken(ControllerToken const & other);

    /**
     * @brief operator =: purposely not implemented
     * @param other: Object to copy
     */
    ControllerToken& operator=(ControllerToken const & other);

};

} // namespace controller

} // namespace lib

} // namespace cams

#endif // _d3ed60ca_8ce4_4dce_a886_8f98ed87cb61
