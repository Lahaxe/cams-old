#ifndef _42a7bd3f_7a58_41ad_8d5f_a8044c1b6ec7
#define _42a7bd3f_7a58_41ad_8d5f_a8044c1b6ec7

// Include Standard library files
#include <fstream>
#include <experimental/filesystem>

// Include Project files
#include "tests/code/FixtureBase.h"
#include "src/lib/common/json/JsonTools.h"

const std::string TEST_FILE_JSONTOOLS_READ = "test_file_jsontools_read.json";
const std::string TEST_FILE_JSONTOOLS_WRITE = "test_file_jsontools_write.json";

class FixtureJsonTools : public FixtureBase
{
public:
    FixtureJsonTools(): FixtureBase()
    {
        std::stringstream file_content;
        file_content << "{\n";
        file_content << "    \"field\": \"value\"\n";
        file_content << "}\n";

        std::ofstream test_file(TEST_FILE_JSONTOOLS_READ);
        test_file << file_content.str().c_str();
        test_file.close();
    }

    virtual ~FixtureJsonTools()
    {
        if (std::experimental::filesystem::v1::exists(TEST_FILE_JSONTOOLS_READ))
        {
            std::experimental::filesystem::v1::remove(TEST_FILE_JSONTOOLS_READ);
        }
        if (std::experimental::filesystem::v1::exists(TEST_FILE_JSONTOOLS_WRITE))
        {
            std::experimental::filesystem::v1::remove(TEST_FILE_JSONTOOLS_WRITE);
        }
    }

protected:

private:

};

#endif // _42a7bd3f_7a58_41ad_8d5f_a8044c1b6ec7
