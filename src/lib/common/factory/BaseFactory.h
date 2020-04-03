#ifndef _aa1c930a_a05a_45d4_85ce_952c1bd78b37
#define _aa1c930a_a05a_45d4_85ce_952c1bd78b37

// Include Standard library
#include <functional>
#include <map>
#include <memory>
#include <string>

namespace cams
{

namespace lib
{

namespace common
{

/**
 * @brief The factory base class
 */
template<class T>
class BaseFactory
{
public:
    /**
     * @brief Constructor
     */
    BaseFactory();

    /**
     * @brief Destructor
     */
    virtual ~BaseFactory();

    /**
     * @brief Register class in this factory
     */
    template<typename TClass>
    void register_();

    /**
     * @brief Check if a class given by name could be created
     * @param name: Name of the given class
     * @return True if the class is registered
     */
    bool can_create(std::string const & name) const;

    /**
     * @brief Create an instance of the given class by name
     * @param name: Name of the given class
     * @return Return an instance of the given class
     */
    std::shared_ptr<T> create(std::string const & name) const;

protected:

private:
    /// @brief The creator type
    typedef std::function<std::shared_ptr<T>()> Creator;

    /// @brief The map creator type
    typedef std::map<std::string, Creator> CreatorMap;

    /// @brief Creators map
    CreatorMap _creators;

};

} // namespace common

} // namespace lib

} // namespace cams

// Include template implementation
#include "common/factory/BaseFactory.txx"

#endif // _aa1c930a_a05a_45d4_85ce_952c1bd78b37
