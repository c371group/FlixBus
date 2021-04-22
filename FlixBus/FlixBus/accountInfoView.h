#pragma once
#include "interfaceView.h"
class accountInfoView :
    public interfaceView
{
public:
	accountInfoView();
	accountInfoView(Account);
	void display(int);
};

