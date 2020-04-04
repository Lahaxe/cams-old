#ifndef _d9cb6f7b_3646_4fa3_92ec_afdc25443782
#define _d9cb6f7b_3646_4fa3_92ec_afdc25443782

// Include Project files
#include "model/core/Attribute.h"

/// @brief Main namespace
namespace cams
{

/// @brief Cams library part
namespace lib
{

/// @brief Data Model
namespace model
{

/// @brief Name of the attribute 'ID'
const std::string ENTITYBASE_ID = "id";

/**
 * @brief The EntityBase class
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
     */
    EntityBase();

    /**
     * @brief Create an instance of EntityBase
     * @param id: The entity Identifier
     */
    EntityBase(std::string const & id);

    /**
     * @brief Destroy the instance of EntityBase
     */
    virtual ~EntityBase();

    /**
     * @brief Get the EntityBase identifier
     * @return Return the EntityBase identifier
     */
    std::string get_id() const;

    /**
     * @brief Set the EntityBase identifier
     * @param id: New EntityBase identifier
     */
    void set_id(std::string const & id);

    /**
     * @brief Convert a JSON object into this EntityBase
     * @param json: JSON object in which the entity is readed
     */
    virtual void from_json(QJsonObject const & json);

    /**
     * @brief Convert this EntityBase as JSON attribute
     * @param json: JSON object in which the entity is added
     */
    virtual void to_json(QJsonObject & json) const;

protected:

private:
    /// @brief The EntityBase Identifier
    Attribute<std::string>::Pointer _id;

};

} // namespace model

} // namespace lib

} // namespace cams

#endif // _d9cb6f7b_3646_4fa3_92ec_afdc25443782
