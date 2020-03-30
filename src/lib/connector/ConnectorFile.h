#ifndef _ca947e3d_ec65_42f8_8ceb_a2d673b76e6c
#define _ca947e3d_ec65_42f8_8ceb_a2d673b76e6c

//Include Project files
#include "connector/ConnectorBase.h"

namespace libcams
{

namespace connector
{

/**
 * @brief The ConnectorFile class
 */
class ConnectorFile : public ConnectorBase
{
public:
    /// @brief The ConnectorFile Pointer type
    typedef std::shared_ptr<ConnectorFile> Pointer;

    /// @brief The ConnectorFile constante Pointer type
    typedef std::shared_ptr<ConnectorFile const> ConstPointer;

    /**
     * @brief Create pointer to a new instance of ConnectorFile
     * @return Return Pointer to new instance of ConnectorFile
     */
    static Pointer New();

    /**
     * @brief Destructor
     */
    virtual ~ConnectorFile();

    /**
     * @brief Return the name of this class
     * @return Return name of this class
     */
    static std::string class_name();

protected:

private:
    /**
     * @brief Create an instance of ConnectorFile
     */
    ConnectorFile();

    /**
     * @brief Copy constructor: purposely not implemented
     * @param other: Object to copy
     */
    ConnectorFile(ConnectorFile const & other);

    /**
     * @brief operator =: purposely not implemented
     * @param other: Object to copy
     */
    ConnectorFile& operator=(ConnectorFile const & other);

};

}

}

#endif // _ca947e3d_ec65_42f8_8ceb_a2d673b76e6c
