#include "std_lib_facilities.h"
using namespace std;

class CommandArgs
{
public:
	//CommandArgs();
	void setArguments(int args, char* argv[]);
	string inputfile;
	string outputfile;
	int sortType;
	int sortCrit;
};

