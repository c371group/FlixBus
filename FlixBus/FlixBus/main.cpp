#include <iostream>
#include <string>
#include "Trip.h"
#include "Account.h"
#include "registration.h"
#include "Fleet.h"
#include "Customer.h"
#include "DateTime.h"
#include "customerInterface.h"
#include "fullTripListView.h"
#include "interfaceView.h"
#include "userTypeMenuView.h"
#include "routeRepo.h"
#include <chrono>
#include <random>
using namespace std;


// Builds data structure
void add_vehicle_to_trip(trip_repo* trip_repo_, fleet* bus_fleet_)
{
    vector<trip>* all_trips = trip_repo_->get_all_trips();
    int trip_index = 0;
	for(auto &trip: *all_trips)
	{
		// If trip bus id is found in our fleet we add reference from the bus to the trip.
		if(bus_fleet_->get_luxury_bus(trip.get_bus_id())!= nullptr)
		{
            trip.set_bus(bus_fleet_->get_luxury_bus(trip.get_bus_id()));
		}
        else if (bus_fleet_->get_mini_bus(trip.get_bus_id()) != nullptr)
        {
            trip.set_bus(bus_fleet_->get_mini_bus(trip.get_bus_id()));
        }
        else if (bus_fleet_->get_mini_van(trip.get_bus_id()) != nullptr)
        {
            trip.set_bus(bus_fleet_->get_mini_van(trip.get_bus_id()));
        }
        trip_index++;
	}
}

// Splits string with a given delimiter and returns a vector of string elements;
std::vector<std::string> split(const std::string& s, char delim) {
    std::vector<std::string> result;
    std::stringstream ss(s);
    std::string item;

    while (getline(ss, item, delim)) {
        result.push_back(item);
    }

    return result;
}

// Adds trip repo reference and fleet reference to a route object.
void add_reference_to_route_repo(route_repo* route_repo_, vector<trip_repo>* trip_repo_vect, fleet* fleet)
{

	for(auto &route: *route_repo_->get_routes())
	{
		for(auto & trip_repo: *trip_repo_vect)
		{
			if(route.get_source() == trip_repo.get_all_trips()->at(0).get_source() && route.get_destination() == trip_repo.get_all_trips()->at(0).get_destination())
			{
                route.set_trip_repo(&trip_repo);
                route.set_fleet(fleet);
			}
		}
	}
}

// Loads ticket from csv and adds them to their accounts.
void load_tickets(account_repo* acct_repo, vector<trip_repo>* trip_repo_vect, route_repo* route_repo_)
{
    std::ifstream input_from_file("tickets.csv");
    std::string line;
    int lineno = 0;
    while (getline(input_from_file, line)) {
        lineno++;
        line += ",";

        std::stringstream ss(line);
        std::string word;
        std::vector<std::string> line_;

        while (getline(ss, word, ','))
            line_.push_back(word);
        int account_id = std::stoi(line_[0]);
        std::string ticket_id = line_[1];
        int seat_row = std::stoi(line_[2]);
    	char seat_column = line_[3][0];
        std::string route_source = line_[4];
        std::string route_dest = line_[5];
        std::string departure_time = line_[6];
        std::string arrival_time = line_[7];
        double cost = std::atof(line_[8].c_str());
        std::string dep_time = split(line_[6], ' ')[0];
        std::string dep_date = split(line_[6], ' ')[1];
        int dep_hour = std::stoi(split(dep_time, static_cast<char>(58))[0]);
        int dep_min = std::stoi(split(dep_time, static_cast<char>(58))[1]);
        int dep_sec = std::stoi(split(dep_time, static_cast<char>(58))[2]);
        int dep_year = std::stoi(split(dep_date, '/')[2]);
        int dep_month = std::stoi(split(dep_date, '/')[1]);
        int dep_day = std::stoi(split(dep_date, '/')[0]);
        std::string arr_time = split(line_[7], ' ')[0];
        std::string arr_date = split(line_[7], ' ')[1];
        int arr_hour = std::stoi(split(arr_time, static_cast<char>(58))[0]);
        int arr_min = std::stoi(split(arr_time, static_cast<char>(58))[1]);
        int arr_sec = std::stoi(split(arr_time, static_cast<char>(58))[2]);
        int arr_year = std::stoi(split(arr_date, '/')[2]);
        int arr_month = std::stoi(split(arr_date, '/')[1]);
        int arr_day = std::stoi(split(arr_date, '/')[0]);
        
       
        date_time departure(dep_year, dep_month, dep_day, dep_hour, dep_min, dep_sec);
        date_time arrival(arr_year, arr_month, arr_day, arr_hour, arr_min, arr_sec);
    	
      //TODO: pass reference  
    	for(auto & acc: acct_repo->get_accts())
    	{
            ticket new_ticket;
    		if(acc.get_acct_id().id == account_id)
    		{
                for(auto & route: *route_repo_->get_routes())
                {
	                if(route.get_destination() == route_dest && route.get_source() == route_source)
	                {
		                for(auto & trip_repo: *trip_repo_vect)
		                {
		                	for(auto & trip: *trip_repo.get_all_trips())
		                	{
                                if (trip.get_departure_dt().compare_to_date(departure) && trip.get_est_arrival_dt().compare_to_date(arrival))
                                {
                                    account* selected_acc = acct_repo->get_acc_by_id(account_id);
                                    new_ticket.set_ticket_id(ticket_id);
                                    new_ticket.set_active(true);
                                    new_ticket.set_trip(&trip);
                                    new_ticket.set_route(&route);
                                    new_ticket.reserve_seat(seat_row, seat_column);
                                    new_ticket.set_cost(cost);
                                    new_ticket.set_travel_date(departure);
                                    selected_acc->add_ticket(new_ticket);
                                }
		                	}
		                }
	                }
                }
    			
    		}
    	}
    }
    system("cls");
}


int main()
{
    revenue revenue_;
	account_repo acctRepo = account_repo();
    
    vector<trip_repo> trip_repos_;

    fleet bus_fleet;
    //Green Bay, Madison, 135.6
    trip_repo gb_m("Green Bay", "Madison");
    add_vehicle_to_trip(&gb_m, &bus_fleet);
    trip_repos_.push_back(gb_m);
    //Green Bay, Whitewater, 142.2
    trip_repo gb_w("Green Bay", "Whitewater");
    add_vehicle_to_trip(&gb_w, &bus_fleet);
    trip_repos_.push_back(gb_w);
    //Green Bay, Eau Claire, 194.4
    trip_repo gb_e("Green Bay", "Eau Claire");
    add_vehicle_to_trip(&gb_e, &bus_fleet);
    trip_repos_.push_back(gb_e);
    //Green Bay, Oshkosh, 50.4
    trip_repo gb_o("Green Bay", "Oshkosh");
    add_vehicle_to_trip(&gb_o, &bus_fleet);
    trip_repos_.push_back(gb_o);
    //Green Bay, Milwaukee, 118.7
    trip_repo gb_mil("Green Bay", "Milwaukee");
    add_vehicle_to_trip(&gb_mil, &bus_fleet);
    trip_repos_.push_back(gb_mil);
    //Madison, Green Bay, 135.6
    trip_repo m_gb("Madison", "Green Bay");
    add_vehicle_to_trip(&m_gb, &bus_fleet);
    trip_repos_.push_back(m_gb);
    //Whitewater, Green Bay, 142.2
    trip_repo w_gb("Whitewater", "Green Bay");
    add_vehicle_to_trip(&w_gb, &bus_fleet);
    trip_repos_.push_back(w_gb);
    //Eau Claire, Green Bay, 194.4
    trip_repo e_gb("Eau Claire", "Green Bay");
    add_vehicle_to_trip(&e_gb, &bus_fleet);
    trip_repos_.push_back(e_gb);
    //Oshkosh, Green Bay, 50.4
    trip_repo o_gb("Oshkosh", "Green Bay");
    add_vehicle_to_trip(&o_gb, &bus_fleet);
    trip_repos_.push_back(o_gb);
    //Milwaukee, Green Bay, 118.7
    trip_repo mil_gb("Milwaukee", "Green Bay");
    add_vehicle_to_trip(&mil_gb, &bus_fleet);
    trip_repos_.push_back(mil_gb);
	
    route_repo rteRepo;
    add_reference_to_route_repo(&rteRepo, &trip_repos_, &bus_fleet);
	
    load_tickets(&acctRepo, &trip_repos_, &rteRepo);
	
    try
	{
		userTypeMenuView usertypemenuview = userTypeMenuView(&acctRepo, &rteRepo, &revenue_);
	}
	catch (std::exception e)
	{
		std::cout << "ERROR: COULD NOT LOAD PROGRAM." << std::endl;
        exit(0);
	}
}