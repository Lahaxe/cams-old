#ifndef _d9cb6f7b_3646_4fa3_92ec_afdc25443782
#define _d9cb6f7b_3646_4fa3_92ec_afdc25443782

// Include Standard files
#include <string>

class EntityBase
{
public:
    EntityBase(std::string const & id = "");

    virtual ~EntityBase();

    std::string get_id() const;

    void set_id(std::string const & id);

protected:

private:
    std::string _id;

};

#endif // _d9cb6f7b_3646_4fa3_92ec_afdc25443782
