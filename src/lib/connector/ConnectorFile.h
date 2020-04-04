#ifndef _ca947e3d_ec65_42f8_8ceb_a2d673b76e6c
#define _ca947e3d_ec65_42f8_8ceb_a2d673b76e6c

//Include Project files
#include "connector/ConnectorBase.h"

/// @brief Main namespace
namespace cams
{

namespace lib
{

namespace connector
{

/**
 * @brief The ConnectorFile class
 */
class ConnectorFile : public ConnectorBase
{
public:
    /// @brief The ConnectorFile Pointer type
    typedef std::shared_ptr<ConnectorFile> Pointer;

    /// @brief The ConnectorFile constante Pointer type
    typedef std::shared_ptr<ConnectorFile const> ConstPointer;

    /**
     * @brief Create pointer to a new instance of ConnectorFile
     * @return Return Pointer to new instance of ConnectorFile
     */
    static Pointer New();

    /**
     * @brief Destructor
     */
    virtual ~ConnectorFile();

    /**
     * @brief Return the name of this class
     * @return Return name of this class
     */
    static std::string class_name();

    virtual model::Token::Pointer authenticate();

    virtual std::vector<model::User::Pointer> get_users();

    virtual model::User::Pointer get_user_by_id(std::string const & id);

    virtual void post_user(model::User::Pointer user);

    virtual void put_user(model::User::Pointer user);

    virtual void patch_user(model::User::Pointer user);

    virtual model::User::Pointer delete_user_by_id(std::string const & id);

protected:

private:
    /**
     * @brief Create an instance of ConnectorFile
     */
    ConnectorFile();

    /**
     * @brief Copy constructor: purposely not implemented
     * @param other: Object to copy
     */
    ConnectorFile(ConnectorFile const & other);

    /**
     * @brief operator =: purposely not implemented
     * @param other: Object to copy
     */
    ConnectorFile& operator=(ConnectorFile const & other);

    std::string _generate_token(std::string const & userid) const;

    bool _is_good_token(std::string const & token) const;

};

} // namespace connector

} // namespace lib

} // namespace cams

#endif // _ca947e3d_ec65_42f8_8ceb_a2d673b76e6c
