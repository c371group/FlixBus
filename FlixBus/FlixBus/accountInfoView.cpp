#include "accountInfoView.h"

accountInfoView::accountInfoView()
= default;

accountInfoView::accountInfoView(account acct)
{
	std::vector<std::string> infoSet1 = {
"Username", "First Name", "Last Name", "Email", "Address", "Phone Number"
	};
	std::vector<std::string> acctInfo = {acct.get_username(), acct.get_customer().get_first_name(), acct.get_customer().get_last_name(), acct.get_customer().get_email(), acct.get_customer().get_address(), acct.get_customer().get_contact_number()};
	std::vector<std::vector<std::string>> temp = {infoSet1, acctInfo};
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
		std::cout << std::left << std::setw(14) << get_strs()[i][j] << std::setw(14) << get_strs()[i+1][j]<< "\n";
	}
}
