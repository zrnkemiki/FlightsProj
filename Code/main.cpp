//============================================================================
// Name        : main.cpp
// Author      :
// Date        :
// Copyright   :
// Description :
//============================================================================
#include "FileHandler.h"
#include "Sort.h"
#include "Flight.h"
#include "DataCollector.h"
#include <string>
#include <iostream>
#include "MyWindow.h"
#include "Window.h"
using namespace std;

int main(int args, char* argv[])
{
	FileHandler filehandler;
	SelectionSort selectionsort;
	MergeSort mergesort;
	DataCollector dc;
	CommandArgs commandargs;
	commandargs.setArguments(args, argv);
	MyWindow win(Point(100, 100), 400, 300, "Input arguments");
	win.setArguments(commandargs);
	

	//filehandler.setInputFile("C://Users/zrnke/Desktop/inputFileExample.txt");
	//filehandler.load();

	//filehandler.displayFlights();

	//vector<Flight> allFlights;
	//
	//allFlights = filehandler.getFlights();
	////selectionsort.sort(allFlights, dc, 1);
	//mergesort.sort(allFlights, dc, 1);


	//cout << "Broj poredjenja" << dc.get_num_of_comparisons() << endl;
	//cout << "Broj pomeranja" << dc.get_num_of_moves() << endl;
	//cout << "Broj iteracija" << dc.get_num_iterations() << endl;



	//cout << "\nSortirano: " << endl;

	//for (int i = 0; i < allFlights.size(); i++)
	//{
	//	cout << allFlights[i].getDestination() << "|" << allFlights[i].getDeparture() << "|"
	//		<< allFlights[i].getFlightNum() << "|" << allFlights[i].getGateNum() << endl;
	//}
	return gui_main();

}








