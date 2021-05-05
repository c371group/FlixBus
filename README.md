## Flix Bus

A local bus company “FlixBus” wants to hire you to automate their processes. These include the ticketing, reservation, routing, customer service, resource management and administration. The bus company has three different type [vehicles](https://github.com/c371group/FlixBus/blob/main/FlixBus/FlixBus/Vehicle.h): (1) luxury bus (2) mini bus, and (3) minivan. There are 3 luxury buses, 4 small buses and 4 minivans. The luxury bus has 52 seats (2x11 seats and 3x10 seats), the small bus has 36 seats (1x12 and 2x12) and the minivan has 12 seats (3x4). This means in case of the minivan, there are 3 seats in each of the 4 rows, in case of the small bus, there is a column of 1 seat and a column of two seats in 12 rows, and finally, in case of the luxury bus, there are 10 rows with 2 columns of seat. One column has 2 seats and the other column has 3 seats. The rows in the buses are alphabetically numbered. Thus, the A and C mark the window seats in all kinds of vehicles. However, the B and E are the aisle seats in the luxury bus, B and D are the aisle seats marked in the minibus whereas in the minivan, there is no aisle seat. The buses haul passengers to and from Green Bay from/to the following [routes](https://github.com/c371group/FlixBus/blob/main/FlixBus/FlixBus/Route.h). The buses are identified by unique identifier and have their registration details stored including a list of drivers who drive them. A single driver can drive multiple buses.

| Source        | Destination   | Distance  |
| ------------- |:-------------:| -----:|
| Green Bay     | Madison    | 135.6 miles |
| Green Bay    | Milwaukee   |   118.7 miles |
| Green Bay | Whitewater     |    142.2 miles |
| Green Bay | Oshkosh        |    50.4 miles |
| Green Bay | Eau Claire     |    194.4 miles |

## Reservation:

[Passengers](https://github.com/c371group/FlixBus/blob/main/FlixBus/FlixBus/Customer.h) can reserve seats 2 weeks in advance. Reservation requires passenger’s biographical information including name, address, contact number, email address, date of travel and how many tickets. Passengers can cancel reservation one week before the travel however any cancellation shorter than a week will require 30% penalty. If a passenger wants to cancel reservation one day before the trave including one minute before the travel will forfeit the entire cost of the ticket. If the travel is cancelled by the company, passengers will get full refund. The company reserves the rights to cancel any travel with prior notice at 2 days ahead of the journey. The company can reject any travel at its discretion. All kinds of reservation need to store in permanent file(s) so that they can retrieve later for administration tasks.

## Scheduling:

To any destination, the company intends to operate at least 3 services a week to and from any destination. However, depending on the demand, the company can operate extra service providing that there is a bus available. The demand should meet at least 50% of particular bus type. When you
schedule one bus for a particular destination, make sure you have an available bus at that depot. You have 11 buses and 6 destinations. Therefore, depending on the passengers’ reservation, there must be one bus available to complete the travel. You may consider keeping an inventory of vehicles located in different depots.

## Bus Hire:

The inventory of buses is available for hire for recreational purpose. Once a customer requests for a bus hire, your responsibility is to check the inventory of the buses available from the location on the particular date requested. Remember, bus hire is always profitable since you can charge for the all seats available in the bus. So if the number of reservations for that bus is not half full on that particular date, it is always better to allow for bus hire. The reserving customer hiring the bus should enter the same biographical information as for normal ticket reservation. All kinds of information regarding the hire needs to store permanently in file(s) so that they can retrieve later for administration tasks.

## Rates:

In luxury bus, the aisle and window seat costs $0.95 per mile, and the other seat costs $0.75 per mile. In small bus, both the aisle seat and window seat costs 0.65. In case of the minivan, each seat cost $0.50 per mile. In case of bus hire, the luxury bus cost $1500 as rent with additional $0.25 for each mile of travel. The small bus costs $1300 as rent with additional $0.20 per mile whereas the minivan costs $1000 as rent with additional $0.15 per mile. The security deposit for luxury bus is $5000, for the small bus $3000 and for the minivan it is $1500 which will be reimbursed upon returning the vehicle. For each ticket and bus hire is subject to government tax of 10% which can change periodically. The company wants to profit 25% on all ticket sales and hire. Remember that the security deposit is not taxable. Passengers’ refunds are also taxable. All sales need to store permanently in file(s) so that they can retrieve later for administration tasks.

## Administration:

Administrator is engaged in different administration tasks such as add a bus to the [fleet](https://github.com/c371group/FlixBus/blob/main/FlixBus/FlixBus/Fleet.h), view weekly sales, manage reservations including view/edit and cancel reservation by day and by vehicle. Some of the administrator’s tasks are listed below:

* Add vehicle to the fleet
* View reservation by bus by date (current day or future days)
* Edit reservation (change passenger’s name, modify charge)
* Change reservation charge, hire charge
* View income by date and by vehicle

# UML Pseudo

![FlixBusUML](https://user-images.githubusercontent.com/5628399/117210626-8d8a3000-adbd-11eb-89e3-4638651f5afa.png)


