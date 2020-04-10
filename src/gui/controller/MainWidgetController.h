#ifndef _920a7d49_582a_420b_bfba_2e76a57d8092
#define _920a7d49_582a_420b_bfba_2e76a57d8092

/*
/// @brief Main namespace
namespace cams
{

/// @brief Cams User Interface part
namespace gui
{

/// @brief User Interface controller part
namespace controller
{
*/

/**
 * @brief The MainWidgetController class
 */
class MainWidgetController
{
public:
    /**
     * @brief Create an unique instance of MainWidgetController
     * @return Return the instance of MainWidgetController
     */
    static MainWidgetController * instance();

    /**
     * @brief Destroy the instance of MainWidgetController
     */
    static void delete_instance();

    /**
     * @brief Destroy the instance of MainWidgetController
     */
    virtual ~MainWidgetController();

private:
    /// @brief Create an instance of MainWidgetController
    MainWidgetController();

    /// @brief Unique instance of MainWidgetController
    static MainWidgetController* _instance;

    /**
     * @brief Copy constructor: purposely not implemented
     * @param other: Object to copy
     */
    MainWidgetController(MainWidgetController const & other);

    /**
     * @brief operator =: purposely not implemented
     * @param other: Object to copy
     */
    void operator=(MainWidgetController const & other);

};
/*
} // namespace controller

} // namespace gui

} // namespace cams
*/
#endif // _920a7d49_582a_420b_bfba_2e76a57d8092
