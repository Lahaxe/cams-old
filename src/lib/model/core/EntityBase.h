#ifndef _d9cb6f7b_3646_4fa3_92ec_afdc25443782
#define _d9cb6f7b_3646_4fa3_92ec_afdc25443782

// Include Standard files
#include <memory>
#include <string>

// Include Qt files
#include <QJsonObject>

namespace libcams
{

namespace model
{

/**
 * @brief Base class for all entity
 */
class EntityBase
{
public:
    /// @brief The EntityBase Pointer type
    typedef std::shared_ptr<EntityBase> Pointer;

    /// @brief The EntityBase constant Pointer type
    typedef std::shared_ptr<EntityBase const> ConstPointer;

    /**
     * @brief Create an instance of EntityBase
     * @param id: The entity Identifier
     */
    EntityBase(std::string const & id = "");

    /**
     * @brief Destructor
     */
    virtual ~EntityBase();

    /**
     * @brief Get the Entity identifier
     * @return Return the entity identifier
     */
    std::string get_id() const;

    /**
     * @brief Set the Entity identifier
     * @param id: The entity identifier
     */
    void set_id(std::string const & id);

    virtual void from_json(QJsonObject const & json);

    virtual void to_json(QJsonObject & json) const;

protected:

private:
    /// Identifier
    std::string _id;

};

} // namespace model

} // namespace libcams

#endif // _d9cb6f7b_3646_4fa3_92ec_afdc25443782
