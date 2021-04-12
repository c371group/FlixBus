#include <iostream>
#include <cctype>
#include <cstdlib>
#include <iomanip>


using namespace std;


int main()
{

    //Setting variables for choice, order, and sentinel. 
    int mainMenu = 0;
    int customerMenu = 0;
    int orderReservation = 0;
    int luxarySeating = 0;
    int miniBusSeating = 0;
    int miniVanSeating = 0;
    int adminPrivlages = 0;
    int sentinel = -1;

    while (mainMenu != sentinel) {
        //Creating the choice options of Order, Pay, Exit.
        cout << "1. Are you a customer? \n2. Are you an admin? \n3. Would you like to exit? \n";

        cin >> mainMenu;
        switch (mainMenu) {

            //Menu for Customer 
        case 1:

            while (customerMenu != sentinel) {
                //Creating the choice options for reservation and scheduling. 
                cout << "1. Would you like to make a reservation? \n2. Would you like to schedule? \n";

                cin >> customerMenu;
                switch (customerMenu) {

                case 1:

                    while (orderReservation != sentinel) {
                        //Showing the code for ordering each item possible. All 3 possible busses. 
                        cout << "Reserve your seats from the list of options:\n";
                        cout << "1. Luxary Bus \n2. Mini Bus \n3. Minivan \n";

                        cin >> orderReservation;
                        switch (orderReservation) {

                        case 1:

                            while (luxarySeating != sentinel) {
                                //Showing the code for ordering each item possible. All 3 possible seats. 
                                cout << "Seats for Luxary Bus Include: \n1. Aisle Seats \n2. Window Seats \n3. Other Seats \n";

                                cin >> luxarySeating;
                                switch (luxarySeating) {

                                case 1:
                                    cout << "How many Aisle seats would you like to order?\n";
                                    //****Insert Code Here****//
                                    break;

                                case 2:
                                    cout << "How many Window seats would you like to order?\n";
                                    //****Insert Code Here****//
                                    break;

                                case 3:
                                    cout << "How many Other seats would you like to order?\n";
                                    //****Insert Code Here****//
                                    break;

                                default:
                                    cout << "Please enter a valid option. \n";
                                    return orderReservation;
                                }
                            }

                        case 2:

                            while (miniBusSeating != sentinel) {
                                //Showing the code for ordering each item possible.
                                cout << "Seats for Mini Bus Include: \n1. Aisle Seats \n2. Window Seats \n";

                                cin >> miniBusSeating;
                                switch (miniBusSeating) {

                                case 1:
                                    cout << "How many Aisle seats would you like to order?\n";
                                    //****Insert Code Here****//
                                    break;

                                case 2:
                                    cout << "How many Window seats would you like to order?\n";
                                    //****Insert Code Here****//
                                    break;

                                default:
                                    cout << "Please enter a valid option. \n";
                                    return orderReservation;
                                }
                            }

                        case 3:

                            while (miniVanSeating != sentinel) {
                                //Showing the code for ordering each item possible.
                                cout << "The Minivan is a set Rent Value.\n";

                                cin >> miniVanSeating;
                                switch (miniVanSeating) {


                                case 1:
                                    cout << "Please order the amount of Minivans you desire.\n";
                                    //****Insert Code Here****//
                                    break;

                                default:
                                    cout << "Please enter a valid option. \n";
                                    return orderReservation;
                                }
                            }

                        default:
                            cout << "Please enter a valid option. \n";
                            return orderReservation;
                        }
                    }

                case 2:

                    //What do we need to do for scheduling?
                default:
                    cout << "Please enter a valid option. \n";
                    return orderReservation;
                }
            }

            //Menu for Admin 
        case 2: 
 
            while (adminPrivlages != sentinel) {
                //Showing the code for ordering each item possible. All 3 possible busses. 
                cout << "1. Add a vehicle \n2. View reservations \n3. Edit passenger information \n4. Change reservation charges \n5. View income \n";
                
                cin >> orderReservation;
                switch (orderReservation) {

                case 1:
                    cout << "Add a vehicle to the fleet:\n";
                    //****Insert Code Here****//
                    break;

                case 2:
                    cout << "View reservation by bus and date:\n";
                    //****Insert Code Here****//
                    break;

                case 3:
                    cout << "Edit passenger's name and charges:\n";
                    //****Insert Code Here****//
                    break;

                case 4:
                    cout << "Change reservation charges:\n";
                    //****Insert Code Here****//
                    break;

                case 5:
                    cout << "View income:\n";
                    //****Insert Code Here****//
                    break;
                }
            }
        case 3: 
            exit;
        }
        system("PAUSE");
        return 0;
    }
}
