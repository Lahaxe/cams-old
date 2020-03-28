#ifndef _0b2f6564_a4c4_4714_a50b_3e3968ae9300
#define _0b2f6564_a4c4_4714_a50b_3e3968ae9300

// Include Project files
#include "common/factory/BaseFactory.h"

namespace libcams
{

namespace common
{

template<class T>
BaseFactory<T>
::BaseFactory():
    _creators(CreatorMap())
{
    // Nothing to do
}

template<class T>
BaseFactory<T>
::~BaseFactory()
{
    // Nothing to do
}

template<class T> template<typename TClass>
void BaseFactory<T>::register_()
{
    // If class not already registered
    if (this->_creators.find(TClass::class_name()) == this->_creators.end())
    {
        // Register
        this->_creators.insert(std::make_pair(TClass::class_name(),
                                              []() { return TClass::New(); }));
    }
}

template<class T>
bool
BaseFactory<T>
::can_create(std::string const & name) const
{
    typename CreatorMap::const_iterator const creators_it = this->_creators.find(name);
    return (creators_it != this->_creators.end());
}

template<class T>
std::shared_ptr<T>
BaseFactory<T>
::create(std::string const & name) const
{
    typename CreatorMap::const_iterator const creators_it = this->_creators.find(name);
    if (creators_it != this->_creators.end())
    {
        return creators_it->second();
    }
    return nullptr;
}

} // namespace common

} // namespace libcams

#endif // _0b2f6564_a4c4_4714_a50b_3e3968ae9300
