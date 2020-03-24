#ifndef _d9cb6f7b_3646_4fa3_92ec_afdc25443782
#define _d9cb6f7b_3646_4fa3_92ec_afdc25443782

// Include Standard files
#include <string>

/**
 * @brief Base class for all entity
 */
class EntityBase
{
public:
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

protected:

private:
    /// Identifier
    std::string _id;

};

#endif // _d9cb6f7b_3646_4fa3_92ec_afdc25443782
