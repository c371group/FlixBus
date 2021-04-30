#include <iostream>
#include <string>

#include "Account.h"
#include "registration.h"
#include "Fleet.h"
#include "Customer.h"
#include "DateTime.h"
#include "Trip.h"
#include "tripRepo.h"
#include "customerInterface.h"
#include "fullTripListView.h"
#include "interfaceView.h"
#include "userTypeMenuView.h"
using namespace std;

int test_basic()
{
    ////////////////////////////
    // TESTING CLASS RELATION //
    ///////////////////////////

    Customer testCustomer("Jon", "Doe", "123 Road St", "JD@uwgb.edu", "(435) 534-2345");
    Account acct(testCustomer);
    fleet testFleet;
    // Adding test ticket.
    ticket testTicket;
    route testRout("Green Bay", "Madison", 1356, &testFleet);
    testTicket.set_route(&testRout);
    //testTicket.set_cost(5500); // TODO: This will have to be calculated based on type of bus chosen for ticket;

    // Adding second ticket
    ticket testTicket2;
    route testRout2("Green Bay", "Oshkosh", 504, &testFleet);
    testTicket2.set_route(&testRout2);
    testTicket2.set_cost(2500); //25 dollars, or 2500 pennies

    acct.addTicket(testTicket);
    acct.addTicket(testTicket2);

    //testCustomer.datesOfTravel.push_back("1/1/2021 12:00:00PM"); // FIXME: Maybe we should put datetime object here?
    //i'm gonna be honest, I have no idea what you were trying to do here?

    //testCustomer.getTickets().at(1).set_travel_date("1/1/2021 12:00:00PM");

    cout << "Customer: " << acct.get_customer().getFirstName() << " " << acct.get_customer().getLastName() << endl;
    for (ticket item : acct.getTickets())
    {
        cout << "Ticket: From " << item.get_route()->get_source() << " To " << item.get_route()->get_destination() <<
            endl;
        cout << "Total of " << item.get_route()->get_distance() << " miles." << endl;
        cout << "Price: $" << item.get_cost() << endl;
    }
    DateTime ticketDate(2021, 1, 1, 12, 0, 0);
    acct.getTickets()[1].set_travel_date(ticketDate);

    cout << "Customer: " << acct.get_customer().getFirstName() << " " << acct.get_customer().getLastName() << endl;
    for (ticket item : acct.getTickets())
    {
        cout << "Ticket: From " << item.get_route()->get_source() << " To " << item.get_route()->get_destination() <<
            endl;
        cout << "Total of " << item.get_route()->get_distance() << " miles." << endl;
        cout << "Price: $" << item.get_cost() << endl;
    }

    return 0;
}

void busSeatTesting()
{
    /*
    ////////////////////////
    // TESTING BUS SEATS //
    /////////////////////// */
    // Testing luxury bus seats
    cout << "\nTesting luxury bus seats" << endl;
    luxuryBus testLuxBus;
    testLuxBus.displaySeats();
    testLuxBus.reserveSeat(1, 'B');
    testLuxBus.reserveSeat(11, 'B');
    testLuxBus.reserveSeat(33, 'B');
    testLuxBus.displayFreeSeats();
    testLuxBus.cancelSeat(11, 'B');
    testLuxBus.displayFreeSeats();

    // Testing small bus seats
    cout << "\nTesting mini bus seats" << endl;
    miniBus testMiniBus;
    testMiniBus.displaySeats();
    testMiniBus.reserveSeat(1, 'A');
    testMiniBus.reserveSeat(11, 'A');
    testMiniBus.reserveSeat(42, 'A');
    testMiniBus.displayFreeSeats();
    testMiniBus.cancelSeat(1, 'A');
    testMiniBus.displayFreeSeats();

    // Testing mini bus seats
    cout << "\nTesting minivan seats" << endl;
    miniVan testMiniVan;
    testMiniVan.displaySeats();
    testMiniVan.reserveSeat(1, 'C');
    testMiniVan.reserveSeat(3, 'C');
    testMiniVan.reserveSeat(12, 'B');
    testMiniVan.displayFreeSeats();
    testMiniVan.cancelSeat(1, 'C');
    testMiniVan.displayFreeSeats();
}

void fleetTesting()
{
    /*
    ////////////////////////
    //     TEST FLEET    //
    /////////////////////// */

    fleet busFleet;
    luxuryBus luxBus;
    miniVan miniVan;
    luxuryBus luxBus1;
    miniBus miniBus;
    cout << "\nTesting fleet class." << endl;
    busFleet.displayLuxaryBusFleet();
    busFleet.displayMiniBusFleet();
    busFleet.displayMiniVanFleet();

    cout << "\nAdding Luxury buss" << endl;
    busFleet.addLuxaryBus(&luxBus);
    cout << "Adding Luxury buss" << endl;
    busFleet.addLuxaryBus(&luxBus1);
    cout << "Adding Minivan" << endl;
    busFleet.addMiniVan(&miniVan);
    cout << "Adding Mini bus" << endl;
    busFleet.addMiniBus(&miniBus);

    busFleet.displayLuxaryBusFleet();
    busFleet.displayMiniBusFleet();
    busFleet.displayMiniVanFleet();

    vehicle* testSeats = busFleet.getLuxaryBus(0);
    cout << "\nTesting accessing seats from the fleet class:" << endl;
    testSeats->displaySeats();
    cout << "\nTesting reserving a seat from the fleet class:" << endl;
    testSeats->reserveSeat(1, 'A');
    testSeats->reserveSeat(1, 'B');
    testSeats->displayFreeSeats();
}

void dateTesting() {
    DateTime currentDate;
    DateTime testTicketDate(2021, 6, 20, 12, 0, 0);
    std::cout << "Current date: " << std::endl;
    currentDate.displayDate();
    std::cout << "\nTicket date: " << std::endl;
    testTicketDate.displayDate();
    std::cout << "\nDifference in days: " << std::endl;
    std::cout << currentDate.differenceDays(testTicketDate) << std::endl;

    // Needs sleep if we want the 2 times to be different.
    std::cout << "Get updated current date: " << std::endl;
    currentDate.getCurrentTime();
}

int customer_menu(Account account, tripRepo trip_repo)
{
    int customer_choice = 0;
    Customer current_customer = account.get_customer();
    int index;

    //Creating the choice options for reservation and scheduling.
    cout << "*******************" << endl;
    cout << "*  Customer Menu  *" << endl;
    cout << "*******************" << endl;
    cout << "1. Customer Information\n2. Manage trips\n3. Book a trip\n4. Bus hire\n0. Exit\n";
    cout << "Enter your choice: ";
    cin >> customer_choice;
    switch (customer_choice) {
    case 1:
        //customer info
        cout << "\n##########################" << endl;
        cout << "## Customer Information ##" << endl;
        cout << "##########################" << endl;
        cout << "# Name: " << current_customer.getFirstName() << " " << current_customer.getLastName() << endl;
        cout << "# Address: " << current_customer.getAddress() << endl;
        cout << "# Contact Number: " << current_customer.getContactNumber() << endl;
        cout << "# Email Address: " << current_customer.getEmail() << endl;
        system("pause");
        customer_menu(account, trip_repo);
        break;
    case 2:
        //manage trips
        cout << "Manage trips" << endl;
        customer_menu(account, trip_repo);
        break;
    case 3:
        //available trips that the customer can book
        cout << "AVAILABLE TRIPS: " << endl;

        cout << "DEPARTURE\t\t" << "ARRIVAL\t\t\t" << "SOURCE\t\t" << "DESTINATION" << endl;
        index = 1;
        for (auto item : trip_repo.getAllTrips())
        {
            cout << index << ". ";
            item.getDepartureDT().displayDate();
            cout << "\t";
            item.getEstArrivalDT().displayDate();
            cout << "\t";
            cout << item.getRoute()->get_source() << "\t" << item.getRoute()->get_destination() << "\t" << endl;
            index++;
        }
        customer_menu(account, trip_repo);
        break;

    case 4:
        //bus hire
        cout << "Bus hire" << endl;
        customer_menu(account, trip_repo);
        break;
    case 0:
        break;
    default:
        cout << "Please enter a valid option. \n";
        customer_menu(account, trip_repo);
    }

    return 0;
}

int admin_menu(Account account)
{
    int adminPrivlages = 0;
    int sentinel = -1;
    int orderReservation = 0;
    fleet busFleet;
    luxuryBus luxBus;
    miniVan miniVan;
    luxuryBus luxBus1;
    miniBus miniBus;

    while (adminPrivlages != sentinel) {
        //Showing the code for ordering each item possible. All 3 possible busses. 
        cout << "1. Add a vehicle \n2. View reservations \n3. Edit passenger information \n4. Change reservation charges \n5. View income \n0. Exit\n";
        cout << "Enter your choice: ";

        cin >> orderReservation;
        string nameEdit;
        Customer customer;
        switch (orderReservation) {

            //Add a vehicle case 1
        case 1:
            cout << "Add a vehicle to the fleet:\n";
            while (adminPrivlages != sentinel) {
                cout << "1. Luxary Bus \n2. Mini Bus \n3. Minivan\n-1. Exit\n";
                cout << "Enter your choice: ";

                cin >> adminPrivlages;
                switch (adminPrivlages) {

                case 1:
                    busFleet.addLuxaryBus(&luxBus);
                    cout << "Bus added successfully.\n";
                    break;
                case 2:
                    busFleet.addMiniBus(&miniBus);
                    cout << "Bus added successfully.\n";
                    break;
                case 3:
                    busFleet.addMiniVan(&miniVan);
                    cout << "Bus added successfully.\n";
                    break;
                }
            }
            cout << "Current busses\n";
            busFleet.displayLuxaryBusFleet();
            busFleet.displayMiniBusFleet();
            busFleet.displayMiniVanFleet();
            break;

        case 2:
            cout << "View reservation by bus and date:\n";
            //****Insert Code Here****//
            break;

            //Edit Passenger Information****//
        case 3:
            cout << "Edit passenger's name and charges:\n";
            customer = account.get_customer();
            cout << "Change first name.\n";
            cin >> nameEdit;
            customer.setFirstName(nameEdit);
            cout << "Change last name.\n";
            cin >> nameEdit;
            customer.setLastName(nameEdit);
            account.set_customer(customer);
            //****Add Charges****//
            break;

        case 4:
            cout << "Change reservation charges:\n";
            //****Insert Code Here****//
            break;

        case 5:
            cout << "View income:\n";
            //****Insert Code Here****//
            break;
        case 0:
            sentinel = 0;
            break;
        default:
            cout << "Please enter a valid option. \n";
        }
    }
    return 0;
}

int mainMenu()
{

    //Setting variables for choice, order, and sentinel. 
    int main_menu = 0;
    int sentinel = -1;
    ///////////////
    // TEST DATA //
    //////////////
    Customer test_customer("Jon", "Doe", "JD@uwgb.edu", "123 Road St", "(435) 534-2345");
    Account test_account(test_customer);

    // Creating test bus fleet. This should come from a file.
    fleet bus_fleet;
    luxuryBus lux_bus_1(201);
    luxuryBus lux_bus_2(202);
    luxuryBus lux_bus_3(203);
    miniVan mini_van_1(401);
    miniVan mini_van_2(402);
    miniVan mini_van_3(403);
    miniVan mini_van_4(404);
    miniBus mini_bus_1(301);
    miniBus mini_bus_2(302);
    miniBus mini_bus_3(303);
    miniBus mini_bus_4(304);

    // Add them in a loop.
    bus_fleet.addLuxaryBus(&lux_bus_1);
    bus_fleet.addLuxaryBus(&lux_bus_2);
    bus_fleet.addLuxaryBus(&lux_bus_3);

    bus_fleet.addMiniVan(&mini_van_1);
    bus_fleet.addMiniVan(&mini_van_2);
    bus_fleet.addMiniVan(&mini_van_3);
    bus_fleet.addMiniVan(&mini_van_4);

    bus_fleet.addMiniBus(&mini_bus_1);
    bus_fleet.addMiniBus(&mini_bus_2);
    bus_fleet.addMiniBus(&mini_bus_3);
    bus_fleet.addMiniBus(&mini_bus_4);

    // Adding routes
    route GreenBayMadison("Green Bay", "Madison", 135.6, &bus_fleet);
    route GreenBayMilwaukee("Green Bay", "Milwaukee", 118.7, &bus_fleet);
    route GreenBayWhitewater("Green Bay", "Whitewater", 142.2, &bus_fleet);
    route GreenBayOshkosh("Green Bay", "Oshkosh", 50.4, &bus_fleet);
    route GreenBayEauClaire("Green Bay", "Eau Claire", 194.4, &bus_fleet);

    // Adding trips
    Trip GBToMadisonTrip_1(&GreenBayMadison, DateTime(2021, 5, 1, 12, 00, 00), DateTime(2021, 5, 1, 15, 00, 00));
    Trip GBToMadisonTrip_2(&GreenBayMadison, DateTime(2021, 5, 2, 12, 00, 00), DateTime(2021, 5, 2, 15, 00, 00));
    Trip GBToMadisonTrip_3(&GreenBayMadison, DateTime(2021, 5, 3, 12, 00, 00), DateTime(2021, 5, 3, 15, 00, 00));
    Trip GBToMadisonTrip_4(&GreenBayMadison, DateTime(2021, 5, 4, 12, 00, 00), DateTime(2021, 5, 4, 15, 00, 00));

    Trip GBToMilwaukeeTrip_1(&GreenBayMilwaukee, DateTime(2021, 5, 1, 18, 30, 00), DateTime(2021, 5, 1, 22, 00, 00));
    Trip GBToMilwaukeeTrip_2(&GreenBayMilwaukee, DateTime(2021, 5, 4, 18, 30, 00), DateTime(2021, 5, 4, 22, 00, 00));
    Trip GBToMilwaukeeTrip_3(&GreenBayMilwaukee, DateTime(2021, 5, 7, 18, 30, 00), DateTime(2021, 5, 7, 22, 00, 00));

    Trip GBToWhitewaterTrip_1(&GreenBayWhitewater, DateTime(2021, 5, 1, 10, 45, 00), DateTime(2021, 5, 1, 12, 45, 00));
    Trip GBToWhitewaterTrip_2(&GreenBayWhitewater, DateTime(2021, 5, 2, 10, 45, 00), DateTime(2021, 5, 2, 12, 45, 00));

    Trip GBToOshkoshTrip_1(&GreenBayOshkosh, DateTime(2021, 5, 1, 9, 00, 00), DateTime(2021, 5, 1, 9, 45, 00));
    Trip GBToOshkoshTrip_2(&GreenBayOshkosh, DateTime(2021, 5, 1, 12, 00, 00), DateTime(2021, 5, 1, 12, 45, 00));
    Trip GBToOshkoshTrip_3(&GreenBayOshkosh, DateTime(2021, 5, 1, 15, 00, 00), DateTime(2021, 5, 1, 15, 45, 00));
    Trip GBToOshkoshTrip_4(&GreenBayOshkosh, DateTime(2021, 5, 1, 18, 00, 00), DateTime(2021, 5, 1, 18, 45, 00));

    Trip GBToEauClairTrip_1(&GreenBayEauClaire, DateTime(2021, 5, 1, 10, 00, 00), DateTime(2021, 5, 1, 13, 00, 00));
    Trip GBToEauClairTrip_2(&GreenBayEauClaire, DateTime(2021, 5, 1, 20, 00, 00), DateTime(2021, 5, 1, 23, 00, 00));

    tripRepo trip_repo;
    trip_repo.add_trip(GBToMadisonTrip_1);
    trip_repo.add_trip(GBToMadisonTrip_2);
    trip_repo.add_trip(GBToMadisonTrip_3);
    trip_repo.add_trip(GBToMadisonTrip_4);

    trip_repo.add_trip(GBToMilwaukeeTrip_1);
    trip_repo.add_trip(GBToMilwaukeeTrip_2);
    trip_repo.add_trip(GBToMilwaukeeTrip_3);

    trip_repo.add_trip(GBToWhitewaterTrip_1);
    trip_repo.add_trip(GBToWhitewaterTrip_2);

    trip_repo.add_trip(GBToOshkoshTrip_1);
    trip_repo.add_trip(GBToOshkoshTrip_2);
    trip_repo.add_trip(GBToOshkoshTrip_3);
    trip_repo.add_trip(GBToOshkoshTrip_4);

    trip_repo.add_trip(GBToEauClairTrip_1);
    trip_repo.add_trip(GBToEauClairTrip_2);
    //////////////////////
    // END OF TEST DATA //
    /////////////////////

    while (main_menu != sentinel) {
        //Creating the choice options of Order, Pay, Exit.
        cout << "1. Customer\n2. Admin\n0. Exit\n" << endl;
        cout << "Enter your choice: ";
        cin >> main_menu;
        switch (main_menu) {

            //Menu for Customer 
        case 1:
            customer_menu(test_account, trip_repo);
            break;
            //Menu for Admin 
        case 2:
            admin_menu(test_account);
            break;
        case 0:
            sentinel = 0;
            break;
        default:
            cout << "Please enter a valid option. \n";
            mainMenu();
        }
        //system("PAUSE");
    }
    return 0;
}

void functionalityTesting() {

    std::cout << "Creating buses" << std::endl;
    luxuryBus luxBus(201);
    luxuryBus luxBus1(203);
    miniVan miniVan_(202);
    miniBus miniBus(204);
    std::cout << "Creating fleet object" << std::endl;
    fleet GBMadisonFleet;
    std::cout << "Adding buses to fleet object" << std::endl;
    GBMadisonFleet.addLuxaryBus(&luxBus);
    GBMadisonFleet.addLuxaryBus(&luxBus1);
    GBMadisonFleet.addMiniVan(&miniVan_);
    GBMadisonFleet.addMiniBus(&miniBus);
    std::cout << "Creating route object" << std::endl;
    route GreenBayMadison("Green Bay", "Madison", 135.6, &GBMadisonFleet);
    std::cout << "Creating customer." << std::endl;
    Customer testCustomer("Jon", "Doe", "123 Road St", "JD@uwgb.edu", "(435) 534-2345");
    luxuryBus* testBussPtr = GBMadisonFleet.getLuxaryBus(203);
    ticket customerTicket(&GreenBayMadison, testBussPtr);
    DateTime ticketDate(2021, 5, 5, 12, 0, 0);
    customerTicket.set_travel_date(ticketDate);
    customerTicket.set_active(true);
    customerTicket.add_seat(1, 'A');
    testCustomer.setTicket(&customerTicket);
    std::cout << "Customer: " << std::endl;
    std::cout << "\tName: " << testCustomer.getFirstName() << " " << testCustomer.getLastName() << std::endl;
    std::cout << "\tContact number: " << testCustomer.getContactNumber() << std::endl;
    std::cout << "\tRoute: " << testCustomer.get_ticket()->get_route()->get_source() << " - " << testCustomer.get_ticket()->get_route()->get_destination() << std::endl;
    std::cout << "\tBus type: " << testCustomer.get_ticket()->get_bus()->get_type() << std::endl;
    std::cout << "\tSeat number: " << testCustomer.get_ticket()->get_seat_number() << std::endl;
    std::cout << "\tTicket cost: " << testCustomer.get_ticket()->get_cost() << std::endl;
    std::cout << "All seats count on the bus: " << testCustomer.get_ticket()->get_bus()->get_all_seats_count() << std::endl;
    std::cout << "All free seats count on the bus: " << testCustomer.get_ticket()->get_bus()->get_free_seats_count() << std::endl;


    std::cout << "\nTesting 2nd Customer" << std::endl;
    route GreenBayMilwaukee("Green Bay", "Milwaukee", 118.7, &GBMadisonFleet);
    Customer testCustomer2("Poo", "Moo", "852 Road St", "PM@uwgb.edu", "(920) 123-4567");
    miniVan* testMinivanPtr = GBMadisonFleet.getMiniVan(202);
    ticket customerTicket2(&GreenBayMilwaukee, testMinivanPtr);
    DateTime newTicketDate(2021, 5, 1, 17, 45, 0);
    customerTicket2.set_travel_date(ticketDate);
    customerTicket2.set_active(true);
    customerTicket2.add_seat(4, 'B');
    testCustomer2.setTicket(&customerTicket2);
    std::cout << "Customer: " << std::endl;
    std::cout << "\tName: " << testCustomer2.getFirstName() << " " << testCustomer2.getLastName() << std::endl;
    std::cout << "\tContact number: " << testCustomer2.getContactNumber() << std::endl;
    std::cout << "\tRoute: " << customerTicket2.get_route()->get_source() << " - " << customerTicket2.get_route()->get_destination() << std::endl;
    std::cout << "\tBus type: " << customerTicket2.get_bus()->get_type() << std::endl;
    std::cout << "\tSeat number: " << customerTicket2.get_seat_number() << std::endl;
    std::cout << "\tTicket cost: " << customerTicket2.get_cost() << std::endl;
    std::cout << "All seats count on the bus: " << testCustomer2.get_ticket()->get_bus()->get_all_seats_count() << std::endl;
    std::cout << "All free seats count on the bus: " << testCustomer2.get_ticket()->get_bus()->get_free_seats_count() << std::endl;

}

void busHireTesting()
{
    cout << "\nTesting luxury bus hire:" << endl;
    cout << "Creating luxury bus object and reserving seats." << endl;
    luxuryBus lux_bus;
    lux_bus.reserveSeat(1, 'A');
    lux_bus.reserveSeat(2, 'A');
    lux_bus.reserveSeat(3, 'A');
    lux_bus.reserveSeat(4, 'A');
    lux_bus.reserveSeat(5, 'A');
    lux_bus.reserveSeat(6, 'A');
    cout << "Check bus seats:" << endl;
    lux_bus.displayFreeSeats();
    cout << "\nTrying to hire bus." << endl;
    std::cout << std::boolalpha;
    cout << "Bus hire status: " << lux_bus.can_hire() << endl;
    cout << "Hire the bus." << endl;
    lux_bus.reserveAllSeats();
    lux_bus.displayFreeSeats();
    cout << "\nFlat fee for " << lux_bus.get_type() << " hire is: " << lux_bus.getBusHireRate() << endl;
    cout << "Additionally there is a fee of " << lux_bus.getBusHireRatePerMile() << " per mile." << endl;

    cout << "\nTesting minivan hire:" << endl;
    miniVan mini_van;
    mini_van.reserveSeat(1, 'A');
    mini_van.reserveSeat(2, 'A');
    mini_van.reserveSeat(3, 'A');
    mini_van.reserveSeat(4, 'A');
    mini_van.reserveSeat(1, 'B');
    mini_van.reserveSeat(2, 'B');
    mini_van.reserveSeat(3, 'B');
    mini_van.reserveSeat(4, 'B');
    cout << "Check bus seats:" << endl;
    mini_van.displayFreeSeats();
    cout << "\nTrying to hire minivan." << endl;
    std::cout << std::boolalpha;
    cout << "Minivan hire status: " << mini_van.can_hire() << endl;
}

int main()
{
    //TODO: sticking this here before we have capabilities to read from permanent file
    accountRepo acctRepo = accountRepo();
    //busSeatTesting();
    //fleetTesting();
    //dateTesting();
    //functionalityTesting();
    //busHireTesting();
    mainMenu();

    /*try
    {
        userTypeMenuView usertypemenuview = userTypeMenuView(acctRepo);
    }
    catch (std::exception e)
    {
        std::cout << "ERROR: COULD NOT LOAD PROGRAM." << std::endl;
    }*/
}