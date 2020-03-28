#ifndef _a45a4540_1a7a_44f8_b997_5b0311e5dabb
#define _a45a4540_1a7a_44f8_b997_5b0311e5dabb

// Include Standard library
#include <memory>

namespace libcams
{

namespace controller
{

class ControllerBase
{
public:
    typedef std::shared_ptr<ControllerBase> Pointer;

    typedef std::shared_ptr<ControllerBase const> ConstPointer;

    ControllerBase();

    virtual ~ControllerBase();

    bool exists_action(std::string const & action) const;

    void execute(std::string const & action);

protected:
    virtual void execute_get();
    virtual void execute_post();
    virtual void execute_put();
    virtual void execute_patch();
    virtual void execute_delete();
    virtual void execute_options();

private:
    ControllerBase(ControllerBase const & other);

    ControllerBase& operator=(ControllerBase const & other);

};

}

}

#endif // _a45a4540_1a7a_44f8_b997_5b0311e5dabb
