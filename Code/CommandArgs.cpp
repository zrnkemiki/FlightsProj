#include "CommandArgs.h"


void CommandArgs::setArguments(int args, char* argv[])
{
	if (args == 5) {
		char* arg1 = argv[1];
		char* arg2 = argv[2];
		char* arg3 = argv[3];
		char* arg4 = argv[4];

		inputfile = arg1;
		outputfile = arg2;
		string s = arg3;
		sortType = atoi(s.c_str());
		s = arg4;
		sortCrit = atoi(s.c_str());
	}
}
