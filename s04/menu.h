//menu.h
//Specification file for a Menu class.
//Specification file corresponding to menu.cpp.

#ifndef MENU_H
#define MENU_H

#include <string>
using namespace std;

/**
Contains a Student::Menu class and namespace Student serves to isolate
and distinguish it from the Scobey::Menu class.
*/
namespace Student
{

    class Menu
    /**<
    For displaying menus and getting user menu choices in console
    applications. The <tt>%Menu</tt> class provides a convenient
    way for simple text-based console programs to display for the
    user a menu of choices. A menu has a title and options which
    are separated from the title by a blank line when the menu is
    displayed. A menu object can also get a menu choice from a user.
    */
    {
    public:
        Menu();
        /**<
        Default constructor; creates a "blank" menu.
        @pre None
        @post A "blank" menu has been constructed which has
        the (default) title <tt>"Empty Menu"</tt> and no options.
        */

        ~Menu();
        /**<
        Destructor. Restores storage allocated for this object to the
        free store.
        @pre This object has been initialized.
        @post All memory allocated to this object during construction
        has been returned to the free store.
        */

        void setTitle
        (
            const string& menuTitle //in
        );
        /**<
        Sets (or resets) the menu title. There is no error checking
        on the length of the title.
        @return void
        @param menuTitle Contains the text of the title for the menu.
        @pre <b>menuTitle</b> has been initialized.
        @post The text in <b>menuTitle</b> has been assigned as the
        title of the menu. The number of menu options is unchanged.
        */

        void addOption
        (
            const string& option //in
        );
        /**<
        Adds a new option to the menu and assigns it the next available
        option number. There is no error checking on the number of options
        or the length of any particular option.
        @return void
        @param option The text of the next option to be added to the menu.
        @pre <b>option</b> has been initialized.
        @post The number of menu options has been incremented by 1 and the
        text in <b>option</b> has become the option with the new option
        number.
        */

        void display() const;
        /**<
        Displays a menu on the screen, with its title and each option
        starting at the left margin. The menu display is "centered"
        vertically.
        @return void
        @pre The menu has been initialized.
        @post The menu has been displayed on the screen, more or less
        centered top-to-bottom, but with a slight bias toward the top.
        Note, however, that a blank menu, or a menu with just a title,
        is displayed with its title left-justified (and the bias toward
        the top). Such a title is followed by a blank line and the
        following 1-line message, which also starts at the left margin:
        <pre>
        This menu currently has no options ...
        </pre>
        */

        int getChoice() const;
        /**<
        Gets a menu choice from the user, without any error checking,
        except if the menu has no options from which to choose.
        @return The user's menu choice, or -1 if an attempt is made to
        get a choice from a menu with no options.
        @pre Typically, a menu has been initialized, and presumably
        displayed, though in fact this is not technically a necessary
        pre-condition for this function.
        @post The default prompt
        <pre>
        Enter the number of your menu choice here and press Enter:
        </pre>
        has been displayed, starting at the left margin.
        - Case 1 (typical): A valid menu choice for the menu has been
        entered by the user and returned.
        - Case 2 (error): If a choice was sought from a blank menu, the
        message
        <pre>
        ===== Error: The menu has no options from which to choose.
        Press Enter to continue ...
        </pre>
        has been displayed, the user has pressed <tt>Enter</tt>,
        and -1 has been returned.
        */

    private:
        int numberOfOptions;
        //Number of options currently on the menu.

        char* titlePtr;
        struct OptionNode
        {
            char* optionTextPtr;
            OptionNode* link;
        };
        OptionNode* firstNodePtr;
        OptionNode* lastNodePtr;

        //The two function prototypes below essentially deactivate
        //the copy constructor and the overloaded assignment operator
        //for this class. You do not have to implement these functions.
        //Menu::Menu(const Menu& original /* in */);
        //Menu& Menu::operator=(const Menu& rhs /* in */);
    };

}//end of namespace Student

#endif

