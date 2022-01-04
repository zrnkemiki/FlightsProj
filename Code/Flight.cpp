//============================================================================
// Name        : Flight.cpp
// Author      : 
// Date        :
// Copyright   : 
// Description : Implementation of the Flight class
//============================================================================

#include "Flight.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

Flight::Flight()
{
}

Flight::Flight(string dest, string depart, string gatnum, string fnum)
{
	destination = dest;
	departure = depart;
	gate_num = gatnum;
	flight_num = fnum;
}

Flight::~Flight() {}

void Flight::setDestination(string dest)
{
	destination = dest;
}

void Flight::setDeparture(string depart)
{
	departure = depart;
}

void Flight::setGateNum(string gatnum)
{
	gate_num = gatnum;
}

void Flight::setFlightNum(string fnum)
{
	flight_num = fnum;
}

string Flight::getDestination() const
{
	return destination;
}

string Flight::getDeparture() const
{
	return departure;
}

string Flight::getGateNum() const
{
	return gate_num;
}

string Flight::getFlightNum() const
{
	return flight_num;
}

bool Flight::comparing_flights(Flight & flight, int choice)  // po rastucem redosledu
{
	if (choice == 1) {
		return (this->destination <= flight.getDestination());
	}
	else if (choice == 2) {
		return (this->departure <= flight.getDeparture());
	}
	else if (choice == 3) {
		return (this->flight_num <= flight.getFlightNum());
	}
	else if (choice == 4) {
		return (this->gate_num <= flight.getGateNum());
	}
	else {
		return (this->destination <= flight.getDestination());
	}
}
