//============================================================================
// Name        : Flight.h
// Author      :Milos Zrnic
// Date        :17.01.2017
// Copyright   :
// Description :
//============================================================================

#include "Sort.h"
#include <algorithm>

using namespace std;

void SelectionSort::sort(std::vector<Flight>& flights, DataCollector& datacollector, int choice)
{
	int minimum;
	int vect_size = flights.size();

	for (int i = 0; i < vect_size - 1; i++) {
		minimum = i; //First is minimal

		for (int j = i + 1; j < vect_size; j++) {
			datacollector.add_number_of_comparisons();
			if (flights[j].comparing_flights(flights[minimum], choice)) {  //promeniti drugi parametar u zavisnosti od kriterijuma sortiranja
				minimum = j;
				
			}
		}

		if (minimum != i) {
			swap(flights[minimum], flights[i]);
			datacollector.add_num_of_moves();
		}
		datacollector.add_num_iteration();
		//cout << "usao"<<endl;
		datacollector.add_iteration(flights);
		

	}
}

unsigned long Sort::getNumCmps()
{
	return num_cmps;
}

void Sort::resetNumCmps()
{
	num_cmps = 0;
}
int min(int x, int y) { return (x < y) ? x : y; }; //Vraca manji od dva prosledjena cela broja

void MergeSort::sort(std::vector<Flight>& flights, DataCollector& datacollector, int choice) {
	size_t i, width;

	std::vector<Flight> ret(flights.size()); //Drugi vektor za cuvanje podataka

	for (width = 1; width < flights.size(); width *= 2) { /* merge pass */
		datacollector.add_num_iteration();
		for (i = 0; i < flights.size(); i += 2 * width) { /* merge sublists */
			merge(ret, flights, i, min(i + width, flights.size()), min(i + 2 * width, flights.size()), datacollector , choice);
		}
		flights.swap(ret);    //Smesta vrednosti iz ret vektora u data vektor
	}

}
/* Spaja dva podniza */
void MergeSort::merge(std::vector<Flight> &ret, std::vector<Flight> &flights, size_t ileft, size_t iright, size_t iend, DataCollector& datacollector, int choice) {
	size_t il = ileft;
	size_t ir = iright;
	for (size_t iout = ileft; iout < iend; iout++) {
		datacollector.add_number_of_comparisons();
		datacollector.add_num_of_moves();
		if (il < iright && (ir >= iend || flights[il].comparing_flights(flights[ir],choice)))
			ret[iout] = flights[il++];
		else
			ret[iout] = flights[ir++];
	}
}