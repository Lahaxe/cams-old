#ifndef _2042560f_85db_421b_87f7_edb1a566b5b3
#define _2042560f_85db_421b_87f7_edb1a566b5b3

// Include Standard library
#include <memory>
#include <vector>

#include "model/users/Identity.h"
#include "model/users/Token.h"
#include "model/users/User.h"

namespace cams
{

namespace lib
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

    /**
     * @brief Get identity member
     * @return Return value of identity
     */
    model::Identity::Pointer get_identity() const;

    /**
     * @brief Set identity member
     * @param password: New value of identity
     */
    void set_identity(model::Identity::Pointer identity);

    virtual model::Token::Pointer authenticate();

    virtual std::vector<model::User::Pointer> get_users() = 0;

    virtual model::User::Pointer get_user_by_id(std::string const & id) = 0;

    virtual void post_user(model::User::Pointer user) = 0;

    virtual void put_user(model::User::Pointer user) = 0;

    virtual void patch_user(model::User::Pointer user) = 0;

    virtual model::User::Pointer delete_user_by_id(std::string const & id) = 0;

protected:

private:
    /// @brief The identity data
    model::Identity::Pointer _identity;

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

} // namespace lib

} // namespace cams

#endif // _2042560f_85db_421b_87f7_edb1a566b5b3
