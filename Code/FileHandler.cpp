#include "FileHandler.h"
#include <string>
#include <fstream>
//using namespace std;

istream& operator >> (istream& in, FileHandler& fh)
{
	Flight f;
	string s, destination, departure, gateNo, flightNo;

	while (getline(in, s))
	{
		getline(in, destination, ';');
		getline(in, departure, ';');
		getline(in, flightNo, ';');
		getline(in, gateNo, ';');

		f.setDestination(destination);
		f.setDeparture(departure);
		f.setFlightNum(flightNo);
		f.setGateNum(gateNo);

		fh.allFlights.push_back(f);
	}
	return in;
}

FileHandler::FileHandler()
{
}

void FileHandler::load()
{
	ifstream ifs;
	ifs.open(input_file);

	if (ifs.fail())
		cerr << "File loading fail!" << endl;	//neuspesno citanje

	ifs >> *this;
	ifs.close();
}

void FileHandler::setInputFile(string file_name)
{
	input_file = file_name;
}

void FileHandler::displayFlights() const
{
	int n = allFlights.size();

	for (int i = 0; i < n; i++)
	{
		cout << allFlights[i].getDestination() << "|" << allFlights[i].getDeparture() << "|"
			<< allFlights[i].getFlightNum() << "|" << allFlights[i].getGateNum() << endl;
	}
}

const vector<Flight>& FileHandler::getFlights() const
{
	return allFlights;
}
