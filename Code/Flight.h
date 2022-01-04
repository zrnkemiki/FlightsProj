//============================================================================
// Name        : Flight.h
// Author      :Milos Zrnic
// Date        :17.01.2017
// Copyright   :
// Description :
//============================================================================
#pragma once
#include <string>
#include <iostream>
using namespace std;

class Flight
{
public:
	Flight();
	Flight(string, string, string, string);

	~Flight();

	void setDestination(string);
	void setDeparture(string);
	void setGateNum(string);
	void setFlightNum(string);

	string getDestination() const;
	string getDeparture() const;
	string getGateNum() const;
	string getFlightNum() const;

	bool comparing_flights(Flight& , int);

private:
	string destination;
	string departure;
	string gate_num;
	string flight_num;

};



