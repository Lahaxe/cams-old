#ifndef _febfcff8_c201_4700_a75e_9dc63974986f
#define _febfcff8_c201_4700_a75e_9dc63974986f

// Include Standard library files
#include <fstream>
#include <experimental/filesystem>

// Include Project files
#include "tests/code/FixtureBase.h"
#include "src/lib/common/configuration/Configuration.h"

const std::string TEST_FILE_CONFIGURATION = "cams.conf";

class FixtureConfiguration : public FixtureBase
{
public:
    FixtureConfiguration(): FixtureBase()
    {
        std::stringstream file_content;
        file_content << "[general]\n"
                     << "connector_type=file\n"
                     << "[logger]\n"
                     << "logger_type=file\n"
                     << "[connector_file]\n"
                     << "root_path=./data\n";

        std::ofstream test_file(TEST_FILE_CONFIGURATION);
        test_file << file_content.str().c_str();
        test_file.close();
    }

    virtual ~FixtureConfiguration()
    {
        if (std::experimental::filesystem::v1::exists(TEST_FILE_CONFIGURATION))
        {
            std::experimental::filesystem::v1::remove(TEST_FILE_CONFIGURATION);
        }
    }

protected:

private:

};

#endif // _febfcff8_c201_4700_a75e_9dc63974986f
