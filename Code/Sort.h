//============================================================================
// Name        : Flight.h
// Author      :Milos Zrnic
// Date        :17.01.2017
// Copyright   :
// Description : Sort interface class and various sorting algorithms in C++
//============================================================================
#pragma once

#include "Flight.h"
#include "DataCollector.h"
#include <vector>


// Sort class
class Sort
{
protected:
	// number of comparisons performed in sort function
	unsigned long num_cmps;
public:
	// main entry point
	virtual void sort(std::vector<Flight>& data, DataCollector& datacollector, int choice) = 0;
	// returns number of comparisons
	unsigned long getNumCmps();
	// resets the number of comparisons
	void resetNumCmps();
};

// SelectionSort class
class SelectionSort : public Sort
{
public:
	// main entry point
	void sort(std::vector<Flight>& flights, DataCollector& datacollector,  int choice);
};

class MergeSort : public Sort
{
public:
	void sort(std::vector<Flight>& flights, DataCollector& datacollector, int choice);
	void merge(std::vector<Flight> &ret, std::vector<Flight> &data, size_t ileft, size_t iright, size_t iend, DataCollector& datacollector, int choice);
	
};


