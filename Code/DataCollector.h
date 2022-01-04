#pragma once
#include <vector>;
#include "Flight.h"
using namespace std;

class  DataCollector
{
public:
	DataCollector() {
		num_iterations = 0;
		num_of_comparisons = 0;
		num_of_moves = 0;
	}
	vector <vector<Flight>> flight_iterations; //current itteration
	vector <vector<Flight>> get_iteration(vector<Flight>flights); //returns current iteration
	void add_num_iteration();  //adds number of iterations
	void add_number_of_comparisons();  //adds number of comparisons
	void add_num_of_moves();  //adds number of moves
	void add_iteration(vector<Flight>flights); //adds new iteration	
	int get_num_iterations();  //returns number of iterations
	int get_num_of_comparisons();  //returns number of comparisons
	int get_num_of_moves();  //returns number of moves
	

private:
	unsigned int num_iterations;  //number of itterations
	unsigned int current_positions;  //current postion
	unsigned int num_of_comparisons;  //number of comparisons
	unsigned int num_of_moves;  //number of moves
};



