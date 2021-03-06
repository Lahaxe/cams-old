#ifndef _1d4da5e6_5f16_4e41_bea7_da787d780f32
#define _1d4da5e6_5f16_4e41_bea7_da787d780f32

// Include Project files
#include "tests/code/FixtureBase.h"
#include "src/lib/common/logger/Logger.h"

class TestLoggerBase : public cams::lib::common::LoggerBase
{
public:
    TestLoggerBase() : cams::lib::common::LoggerBase()
    {
        // Nothing to do
    }

    virtual ~TestLoggerBase()
    {
        // Nothing to do
    }

    virtual void write(std::string const & __attribute__((unused))message,
                       std::string const & __attribute__((unused))level)
    {
        // Nothing to do
    }
};

class FixtureLogger : public FixtureBase
{
public:
    FixtureLogger(): FixtureBase()
    {
        cams::lib::common::Logger::instance();
        cams::lib::common::Logger::instance().set_logger_writer(
                    cams::lib::common::LoggerBase::Pointer(new TestLoggerBase()));
    }

    virtual ~FixtureLogger()
    {
        cams::lib::common::Logger::delete_instance();
    }

protected:

private:

};

#endif // _1d4da5e6_5f16_4e41_bea7_da787d780f32
