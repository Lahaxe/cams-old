#ifndef _0f58ba5f_4de8_4b21_8ebb_2ca689c4b7f7
#define _0f58ba5f_4de8_4b21_8ebb_2ca689c4b7f7

// Include Porject files
#include "common/factory/BaseFactory.h"
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
 * @brief The ControllerFactory class
 */
class ControllerFactory : public common::BaseFactory<ControllerBase>
{
public:
    /**
     * @brief Create an unique instance of ControllerFactory
     * @return Return the instance of ControllerFactory
     */
    static ControllerFactory & instance();

    /**
     * @brief Destroy the instance of ControllerFactory
     */
    static void delete_instance();

    /**
     * @brief Destroy the instance of ControllerFactory
     */
    virtual ~ControllerFactory();

protected:

private:
    /// @brief Create an instance of ControllerFactory
    ControllerFactory();

    /// @brief Unique instance of ControllerFactory
    static ControllerFactory* _instance;

    /**
     * @brief Copy constructor: purposely not implemented
     * @param other: Object to copy
     */
    ControllerFactory(ControllerFactory const & other);

    /**
     * @brief operator =: purposely not implemented
     * @param other: Object to copy
     */
    void operator=(ControllerFactory const & other);

};

} // namespace controller

} // namespace lib

} // namespace cams

#endif // _0f58ba5f_4de8_4b21_8ebb_2ca689c4b7f7
