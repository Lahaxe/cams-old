#ifndef _a7b81810_6d49_46c2_bdf2_6dbdf1126a72
#define _a7b81810_6d49_46c2_bdf2_6dbdf1126a72

// Include Standard library files
#include <fstream>
#include <experimental/filesystem>

// Include Project files
#include "tests/code/FixtureBase.h"
#include "src/lib/common/configuration/INIFileParser.h"

const std::string TEST_FILE_INIFILEPARSER = "test_file_inifileparser.ini";
const std::string TEST_FILE_INIFILEPARSER_WRITE = "test_file_inifileparser_write.ini";

class FixtureINIFileParser : public FixtureBase
{
public:
    FixtureINIFileParser(): FixtureBase(), _fileparser(nullptr)
    {
        std::stringstream file_content;
        file_content << "[section]\n";
        file_content << "field=value\n";

        std::ofstream test_file(TEST_FILE_INIFILEPARSER);
        test_file << file_content.str().c_str();
        test_file.close();

        this->_fileparser = cams::lib::common::INIFileParser::New(TEST_FILE_INIFILEPARSER);
    }

    virtual ~FixtureINIFileParser()
    {
        if (std::experimental::filesystem::v1::exists(TEST_FILE_INIFILEPARSER))
        {
            std::experimental::filesystem::v1::remove(TEST_FILE_INIFILEPARSER);
        }
        if (std::experimental::filesystem::v1::exists(TEST_FILE_INIFILEPARSER_WRITE))
        {
            std::experimental::filesystem::v1::remove(TEST_FILE_INIFILEPARSER_WRITE);
        }
    }

protected:
    cams::lib::common::INIFileParser::Pointer _fileparser;

private:

};

#endif // _a7b81810_6d49_46c2_bdf2_6dbdf1126a72
