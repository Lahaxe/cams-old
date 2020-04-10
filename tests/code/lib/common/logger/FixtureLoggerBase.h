#ifndef _ddf16a32_f421_485b_b4ca_40550145922f
#define _ddf16a32_f421_485b_b4ca_40550145922f

// Include Project files
#include "tests/code/FixtureBase.h"
#include "src/lib/common/logger/LoggerBase.h"

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

class FixtureLoggerBase : public FixtureBase
{
public:
    FixtureLoggerBase(): FixtureBase(), _logger(new TestLoggerBase())
    {
        // Nothing to do
    }

    virtual ~FixtureLoggerBase()
    {
        if (this->_logger != nullptr)
        {
            delete this->_logger;
        }
    }

protected:
    TestLoggerBase* _logger;

private:

};

#endif // _ddf16a32_f421_485b_b4ca_40550145922f
