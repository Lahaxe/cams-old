#ifndef _bf3a2ec9_0a84_40aa_bc55_6f02f9c83fd8
#define _bf3a2ec9_0a84_40aa_bc55_6f02f9c83fd8

// Include Standard library files
#include <fstream>
#include <experimental/filesystem>

// Include Project files
#include "tests/code/FixtureBase.h"
#include "src/lib/common/logger/FileLogger.h"

const std::string TEST_FILE_FILELOGGER = "camscpp.log";

class FixtureFileLogger : public FixtureBase
{
public:
    FixtureFileLogger(): FixtureBase(),
        _logger(cams::lib::common::FileLogger::New())
    {
        // Nothing to do
    }

    virtual ~FixtureFileLogger()
    {
        if (std::experimental::filesystem::v1::exists(TEST_FILE_FILELOGGER))
        {
            std::experimental::filesystem::v1::remove(TEST_FILE_FILELOGGER);
        }
    }

protected:
    cams::lib::common::FileLogger::Pointer _logger;

    std::string _get_file_content() const
    {
        std::ifstream expected_file(TEST_FILE_FILELOGGER);

        std::string file_content((std::istreambuf_iterator<char>(expected_file)),
                                 (std::istreambuf_iterator<char>()));

        return  file_content;
    }

private:

};

#endif // _bf3a2ec9_0a84_40aa_bc55_6f02f9c83fd8
