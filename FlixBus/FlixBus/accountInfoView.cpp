#include "accountInfoView.h"

accountInfoView::accountInfoView()
= default;

accountInfoView::accountInfoView(Account acct)
{
	std::vector<std::string> promptSet1 = {
"Username", "First Name", "Last Name", "Email", "Address", "Phone Number"
	};
	std::vector<std::string> acctInfo = {acct.get_username(), acct.get_customer().getFirstName(), acct.get_customer().getLastName(), acct.get_customer().getEmail(), acct.get_customer().getAddress(), acct.get_customer().getContactNumber()};
	std::vector<std::vector<std::string>> temp = { promptSet1, acctInfo };
	set_vecStr(temp);
	display(0);
	system("PAUSE");
}

void accountInfoView::display(int i)
{
	system("CLS");
	for (int j = 0; j < get_strs()[i].size(); j++)
	{
		//TODO: format this later
		std::cout << get_strs()[i][j] << ":     " << get_strs()[i+1][j]<< "\n";
	}
}
