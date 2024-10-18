
/**
 * @file Menu.h
 * @brief Definition of the Menu class, which manages user interaction and system menus.
 */
#ifndef PROJETO2_AED_MENU_H
#define PROJETO2_AED_MENU_H
using namespace std;
/**
 * @classMenu
 * @brief Class that represents the system menu.
 */
class Menu {
public:
    /**
    * @brief Constructor for the Menu class.
    */
    Menu();
    /**
     * @brief Displays the initial menu and starts user interaction.
     */
    void firstMenu();
private:

    /**
     * @brief Displays the global statistics menu and interacts with the user to execute the chosen option.
     */
    void   globalStatisticsMenu();
    /**
     * @brief Displays the airport information menu and interacts with the user to execute the chosen option.
     */
    void airportInformationMenu() const;
    /**
     * @brief Displays the menu to find the best flight option.
     */
    void findBestFlightOptionMenu();

};


#endif //PROJETO2_AED_MENU_H
