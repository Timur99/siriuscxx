#include <iostream>
using namespace std;

#include <string>
#include <fstream>
#include "location.h"


int main(int argc, char** argv)
{
	int x, y;
	if (argc != 5)
	{
		cout << "Please, give 4 arguments" << endl;
		exit(-1);
	}
	else
	{
		string filename = argv[1];
		x = atoi(argv[2]);
		y = atoi(argv[3]);
		string first_orient = argv[4];
		string res = orient_position(filename, first_orient, x, y);
		cout << res;
	}
	return 0;
}
