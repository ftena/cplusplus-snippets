#include <iostream>
#include <string>
#include <math.h>
#include <sstream>
#include <iomanip>

//#define FUNCTION_TIME(x) gmtime(x)
#define FUNCTION_TIME(x) localtime(x)

using namespace std;

int main (int argc, char *argv[])
{
	if (argc < 2)
	{
		std::cout << "Usage app <seconds>" << std::endl;
		return -1;
	}

	int seconds = atoi(argv[1]);

	//int seconds = 90062;
	char *str;
	int len;

	len = snprintf(NULL, 0, "%01.0f:%02.0f:%02.2f", floor(seconds/3600.0), floor(fmod(seconds,3600.0)/60.0), fmod(seconds,60.0));

	std::cout << "length = " << len << std::endl;

	str = new char[len + 1];

	sprintf(str, "%01.0f:%02.0f:%02.2f", floor(seconds/3600.0), floor(fmod(seconds,3600.0)/60.0), fmod(seconds,60.0));

	std::cout << str << std::endl;

	delete str;

	std::stringstream ss;
	ss << std::setfill('0') << std::setw(2) << floor(seconds/3600.0)
	<< ":" << std::setfill('0') << std::setw(2) << floor(fmod(seconds,3600.0)/60.0);
	std::cout << "hh:mm -> " << ss.str() << std::endl;

	ss.str("");
	ss << std::setfill('0') << std::setw(2) << floor(seconds/3600.0)
	<< ":" << std::setfill('0') << std::setw(2) << floor(fmod(seconds,3600.0)/60.0)
	<< ":" << std::setfill('0') << std::setw(2) << fmod(seconds,60.0);
	std::cout << "hh:mm::ss -> " << ss.str() << std::endl;
	ss.str("");

	ss << std::setfill('0') << std::setw(2) << floor(seconds/60.0)
	<< ":" << std::setfill('0') << std::setw(2) << fmod(seconds,60.0);
	std::cout << "mm::ss -> " << ss.str() << std::endl;
	ss.str("");
}
