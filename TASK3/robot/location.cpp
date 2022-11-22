
#include <iostream>
#include <string>
#include <fstream>

using namespace std;
string orient_position(string filename, string first_orient, int x, int y)
{
	enum Orient {
		up,
		down,
		right,
		left
	};
	Orient orient;
	if (first_orient == "up")
	{
		orient = up;
	}
	else if (first_orient == "right")
	{
		orient = right;
	}
	else if (first_orient == "left")
	{
		orient = left;
	}
	else if (first_orient == "down")
	{
		orient = down;
	}
	else 
	{
		return "Uncorrect value";
	}
	char station;
	ifstream f(filename);
	while (f>>station)
	{
		if (f.good())
		{
			//f >> station;
			cout << "station " << station << endl;
			switch (orient)
			{
			case up:
				switch (station)
				{
				case 'f':
					y++;
					break;
				case 'b':
					--y;
					break;
				case 'l':
					orient = left;
					break;
				case 'r':
					orient = right;
					break;
				default:
					return "Unknown command";
					break;
				}
				break;
			case down:
				switch (station)
				{
				case 'f':
					--y;
					break;
				case 'b':
					++y;
					break;
				case 'l':
					orient = left;
					break;
				case 'r':
					orient = right;
					break;
				default:
					return "Unknown command";
					break;
				}
				break;
			case left:
				switch (station)
				{
				case 'f':
					--x;
					break;
				case 'b':
					++x;
					break;
				case 'l':
					orient = down;
					break;
				case 'r':
					orient = up;
					break;
				default:
					return "Unknown command";
					break;
				}
				break;
			case right:
				switch (station)
				{
				case 'f':
					++x;
					break;
				case 'b':
					--x;
					break;
				case 'l':
					orient = up;
					break;
				case 'r':
					orient = down;
					break;
				default:
					return "Unknown command";
					break;
				}
				break;
			}

		}
		else
		{
			return "Error while opening file";
		}

	}
	string output;
	switch (orient)
	{
	case up:
		output = "up";
		break;
	case down:
		output = "down";
		break;
	case right:
		output = "right";
		break;
	case left:
		output = "left";
		break;
	}
	return "Final position : (" + to_string(x) + ", " + to_string(y) + ")"  + "\n"  + "Final orientation : " + output;
}
