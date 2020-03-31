#ifndef _2042560f_85db_421b_87f7_edb1a566b5b3
#define _2042560f_85db_421b_87f7_edb1a566b5b3

// Include Standard library
#include <memory>

#include <QJsonDocument>

#include "model/users/Identity.h"

namespace libcams
{

namespace connector
{

/**
 * @brief The ConnectorBase class
 */
class ConnectorBase
{
public:
    /// @brief The ConnectorBase Pointer type
    typedef std::shared_ptr<ConnectorBase> Pointer;

    /// @brief The ConnectorBase constant Pointer type
    typedef std::shared_ptr<ConnectorBase const> ConstPointer;

    /**
     * @brief Create an instance of ConnectorBase
     */
    ConnectorBase();

    /**
     * @brief Destructor
     */
    virtual ~ConnectorBase();

    virtual QJsonDocument authenticate(model::Identity::Pointer identity);

protected:

private:
    /**
     * @brief Copy constructor (Purposely not implemented)
     * @param other: Object to copy
     */
    ConnectorBase(ConnectorBase const & other);

    /**
     * @brief operator = (Purposely not implemented)
     * @param other: Object to copy
     * @return Return a copy of a given ControllerBase
     */
    ConnectorBase& operator=(ConnectorBase const & other);

};

} // namespace connector

} // namespace libcams

#endif // _2042560f_85db_421b_87f7_edb1a566b5b3
