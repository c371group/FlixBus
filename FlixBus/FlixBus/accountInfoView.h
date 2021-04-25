#pragma once
#include "interfaceView.h"
#include <iomanip>
class accountInfoView :
    public interfaceView
{
public:
	accountInfoView();
	accountInfoView(Account);
	void display(int);
};

