#include "loggedInInterface.h"

loggedInInterface::loggedInInterface(Account& account)
{
	system("CLS");
	this->acct = account;
	std::cout << "Welcome, " << account.get_customer().getFirstName() << std::endl;
	preLoad();
	menuLogic();
}

void loggedInInterface::preLoad()
{
	std::vector<std::string> menu = {"Account Info", "Your Upcoming Trips", "Browse Available Trips", "Book Trip", "Account Trip History", "Bus Rental", "Log Out"};
	std::vector<std::vector<std::string>> temp = { menu };
	set_vecMen(temp);
}

int loggedInInterface::menuLogic()
{
	accountInfoView aIV;
	int choice_int = 0;
	while (choice_int != 7) {
	int max = display_menu_items(0);
	choice_int = enterChoice(max);
	bool confirm = confirm_Menu_Choice(0, choice_int - 1);
	
		if (!confirm)
		{
			menuLogic();
		}
		else
		{
			//TODO: Change to allow going back to menu
			switch (choice_int)
			{
			case 1: //acct info
				aIV = accountInfoView(acct);
				break;
			case 2: //upcoming trips the customer is scheduled to take/has ticket(s) for
				break;
			case 3:
				/*see trips that the customer can book--
				 *not sure if we want to limit this to those that
				 *can be scheduled already (remember, 2 weeks) or all of them */
				break;
			case 4:
				/*basically the same thing as before but this time,
				 *the customer can select a trip to book*/
				break;
			case 5:
				/*see history for account, including cancelled tickets and prior trips or rentals*/
				break;
			case 6:
				//bus rental
				break;
			default:
				//log out
				std::cout << "Goodbye, " << acct.get_customer().getFirstName() << std::endl;
				break;
			}
		}
	}
	return 0;
}