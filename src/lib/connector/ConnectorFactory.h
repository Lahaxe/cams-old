#ifndef _257e0f34_882a_4fcb_ac78_dd82bbf79dc9
#define _257e0f34_882a_4fcb_ac78_dd82bbf79dc9

// Include Porject files
#include "common/factory/BaseFactory.h"
#include "connector/ConnectorBase.h"

namespace cams
{

namespace lib
{

namespace connector
{

/**
 * @brief The ConnectorFactory class
 */
class ConnectorFactory : public common::BaseFactory<ConnectorBase>
{
public:
    /**
     * @brief Create an unique instance of ConnectorFactory
     * @return Return the instance of ConnectorFactory
     */
    static ConnectorFactory & instance();

    /**
     * @brief Destory the instance of ConnectorFactory
     */
    static void delete_instance();

    /**
     * @brief Destroy the instance of this factory
     */
    virtual ~ConnectorFactory();

protected:

private:
    /// @brief Create an instance of this factory
    ConnectorFactory();

    /// @brief Unique instance of this factory
    static ConnectorFactory* _instance;

    /**
     * @brief Copy constructor: purposely not implemented
     * @param other: Object to copy
     */
    ConnectorFactory(ConnectorFactory const & other);

    /**
     * @brief operator =: purposely not implemented
     * @param other: Object to copy
     */
    void operator=(ConnectorFactory const & other);

};

}

}

}

#endif // _257e0f34_882a_4fcb_ac78_dd82bbf79dc9
