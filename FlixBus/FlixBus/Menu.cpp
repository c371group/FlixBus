#include <iostream>
#include <cctype>
#include <cstdlib>
#include <iomanip>


using namespace std;


int main() {

    //Setting variables for choice, order, and sentinel. 
    int choice = 0;
    int order = 1;
    int sentinel = -1;

    while (choice != sentinel) {


        //Creating the choice options of Order, Pay, Exit.
        cout << "1. Customer \n2. Admin \n";

        cin >> choice;
        switch (choice) {

            //Menu for Customer 
        case 1:
            cout << "1. Reservation \n2. Scheduling \n";

            //Showing the code for ordering each item possible. All 3 possible busses. 
            while (order != sentinel) {

                cout << "Reserve your seats from the list of options:\n";
                cout << "1. Luxary Bus \n2. Mini Bus \n3. Minivan \n";
                cin >> order;
                switch (order) {

                case 0:

                    cout << "Seats for Luxary Bus Include: \n1. Aisle Seat \n2. Window Seat \n3. Other Seats";

                    //Showing the code for ordering each item possible. All 3 possible seats. 
                    while (order != sentinel) {

                        cin >> order;
                        switch (order) {

                        case 0:
                            cout << "How many Aisle seats would you like to order:\n";

                            //****Insert Code Here****//
                            break;

                        case 1:
                            cout << "How many Window seats would you like to order:\n";

                            //****Insert Code Here****//
                            break;

                        case 2:
                            cout << "How many Other seats would you like to order:\n";

                            //****Insert Code Here****//
                            break;
                        }
                    }

                case 1:
                    cout << "Seats for Mini Bus Include: \n1. Aisle Seat \n2. Window Seat \n";

                    //Showing the code for ordering each item possible. All 3 possible seats. 
                    while (order != sentinel) {

                        cin >> order;
                        switch (order) {

                        case 0:
                            cout << "How many Aisle seats would you like to order:\n";

                            //****Insert Code Here****//
                            break;

                        case 1:
                            cout << "How many Window seats would you like to order:\n";

                            //****Insert Code Here****//
                            break;
                        }
                    }

                case 2:
                    cout << "The Minivan is a set Rent Value:\n";

                    //****Insert Code Here****//
                    break;
                }
            }

        case 2:
            //Menu for Admin 
            cout << "Options for Administration: \n1. Add Vehicle \n2. View Reservation \n3. Edit Reservation \n4. Change Charges \n5. View Income";

            //Showing the code for ordering each item possible. All 3 possible seats. 
            while (order != sentinel) {

                cin >> order;
                switch (order) {

                case 0:
                    cout << "Add a vehicle to the fleet:\n";

                    //****Insert Code Here****//
                    break;

                case 1:
                    cout << "View reservation by bus and date:\n";

                    //****Insert Code Here****//
                    break;

                case 2:
                    cout << "Edit passenger's name and charges:\n";

                    //****Insert Code Here****//
                    break;

                case 3:
                    cout << "Change reservation charges:\n";

                    //****Insert Code Here****//
                    break;

                case 4:
                    cout << "View income:\n";

                    //****Insert Code Here****//
                    break;
                }
            }
        }
        system("PAUSE");
        return 0;
    }
}
