#ifndef _730ac144_2efe_44ba_a248_2e48b183a75a
#define _730ac144_2efe_44ba_a248_2e48b183a75a

// Include Standard library
#include <string>

namespace libcams
{

class Logger
{
public:
    static Logger& instance();

    static void delete_instance();

    virtual ~Logger();

    void debug(std::string const & message);

    void info(std::string const & message);

    void warning(std::string const & message);

    void error(std::string const & message);

    void fatal(std::string const & message);

protected:

private:
    Logger();

    static Logger* _instance;

    void write(std::string const & message, std::string const & level);

};

} // namespace libcams

#endif // _730ac144_2efe_44ba_a248_2e48b183a75a
