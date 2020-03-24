#ifndef _785f3a4a_bd4b_4116_a2f2_5bbd9c2fb9fc
#define _785f3a4a_bd4b_4116_a2f2_5bbd9c2fb9fc

#include "model/core/EntityBase.h"

class User : public EntityBase
{
public:
    User(std::string const & id = "", std::string const & name = "");

    virtual ~User();

    std::string get_name() const;

    void set_name(std::string const & name);

protected:

private:
    std::string _name;

};

#endif // _785f3a4a_bd4b_4116_a2f2_5bbd9c2fb9fc
