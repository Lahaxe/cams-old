#ifndef _d3ed60ca_8ce4_4dce_a886_8f98ed87cb61
#define _d3ed60ca_8ce4_4dce_a886_8f98ed87cb61

//Include Project files
#include "controller/ControllerBase.h"

namespace libcams
{

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
     * @brief Destructor
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
     */
    virtual std::string execute_post();

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

}

}

#endif // _d3ed60ca_8ce4_4dce_a886_8f98ed87cb61
