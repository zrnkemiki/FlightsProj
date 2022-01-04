#include "DataCollector.h"

void DataCollector::add_iteration(vector<Flight> flights)
{
	this->flight_iterations.push_back(flights);
}

vector <vector<Flight>> DataCollector::get_iteration(vector<Flight> flights)
{
	return flight_iterations;
}

void DataCollector::add_num_iteration()
{
	num_iterations = num_iterations + 1;
}

void DataCollector::add_number_of_comparisons()
{
	num_of_comparisons = num_of_comparisons + 1;
}

void DataCollector::add_num_of_moves()
{
	num_of_moves = num_of_moves + 1;
}

int DataCollector::get_num_iterations()
{
	return num_iterations;
}


int DataCollector::get_num_of_comparisons()
{
	return num_of_comparisons;
}

int DataCollector::get_num_of_moves()
{
	return num_of_moves;
}