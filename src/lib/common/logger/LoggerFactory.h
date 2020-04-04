#ifndef _7de528e2_5530_489e_b91e_a197ff6687ab
#define _7de528e2_5530_489e_b91e_a197ff6687ab

// Include Porject files
#include "common/factory/BaseFactory.h"
#include "common/logger/LoggerBase.h"

/// @brief Main namespace
namespace cams
{

/// @brief Cams library part
namespace lib
{

/// @brief Common part
namespace common
{

/**
 * @brief The ConnectorFactory class
 */
class LoggerFactory : public common::BaseFactory<LoggerBase>
{
public:
    /**
     * @brief Create an unique instance of LoggerFactory
     * @return Return the instance of LoggerFactory
     */
    static LoggerFactory & instance();

    /**
     * @brief Destory the instance of LoggerFactory
     */
    static void delete_instance();

    /**
     * @brief Destroy the instance of this factory
     */
    virtual ~LoggerFactory();

protected:

private:
    /// @brief Create an instance of this factory
    LoggerFactory();

    /// @brief Unique instance of this factory
    static LoggerFactory* _instance;

    /**
     * @brief Copy constructor: purposely not implemented
     * @param other: Object to copy
     */
    LoggerFactory(LoggerFactory const & other);

    /**
     * @brief operator =: purposely not implemented
     * @param other: Object to copy
     */
    void operator=(LoggerFactory const & other);

};

} // namespace common

} // namespace lib

} // namespace cams

#endif // _7de528e2_5530_489e_b91e_a197ff6687ab
