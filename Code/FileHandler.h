#pragma once
#include "Flight.h"
#include <string>
#include <vector>
#include <iostream>
#include "DataCollector.h"
using namespace std;

class FileHandler
{
public:
	FileHandler();
	void load();
	friend istream& operator >> (istream& in, FileHandler& fh);
	//friend ostream& operator << (ostream& in, DataCollector& dc);
	void setInputFile(string);
	void displayFlights() const;
	const vector<Flight>& getFlights() const;

private:
	string input_file;
	string output_file;
	vector<Flight> allFlights; //vektor koji sadrzi sve letove ucitane iz fajla

};


