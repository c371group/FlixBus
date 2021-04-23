#include "routeRepo.h"

routeRepo::routeRepo()
{
	//TODO: change this to permanent file storage
	route gbtomke = route("Green Bay", "Milwaukee");
	route mketogb = route("Milwaukee", "Green Bay");
	route gbtoec = route("Green Bay", "Eau Claire");
	route ectogb = route("Eau Claire", "Green Bay");
	route gbtoww = route("Green Bay", "Whitewater");
	route wwtogb = route("Whitewater", "Green Bay");
	route gbtomad = route("Green Bay", "Madison");
	route madtogb = route("Madison", "Green Bay");
	route gbtoosh = route("Green Bay", "Oshkosh");
	route oshtogb = route("Oshkosh", "Green Bay");
	
	std::vector<route> routeList = { gbtomke, mketogb, gbtoec, ectogb,gbtoww,wwtogb,gbtomad,madtogb,
	gbtoosh,oshtogb,gbtomke,mketogb,gbtoec,ectogb,gbtoww,wwtogb,gbtomad,madtogb,gbtoosh,oshtogb,};
	
	for (auto &route : routeList)
	{
		add_route(route);
	}
}

std::vector<route> routeRepo::getRoutes()
{
		return this->routes;
	}

void routeRepo::add_route(route rt)
	{
		routes.push_back(rt);
	}