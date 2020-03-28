#ifndef _0b2f6564_a4c4_4714_a50b_3e3968ae9300
#define _0b2f6564_a4c4_4714_a50b_3e3968ae9300

// Include Project files
#include "common/factory/BaseFactory.h"

namespace libcams
{

namespace common
{

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

} // namespace common

} // namespace libcams

#endif // _0b2f6564_a4c4_4714_a50b_3e3968ae9300
