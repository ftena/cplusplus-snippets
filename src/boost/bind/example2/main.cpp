#include <iostream>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <vector>
#include "mystatus.h"

int main(int argc, char** argv)
{

	std::vector<boost::shared_ptr<MyStatus> > s_MyStatuses;

	s_MyStatuses.push_back(
			boost::shared_ptr<MyStatus>(new MyStatus("status 1")));
	s_MyStatuses.push_back(
			boost::shared_ptr<MyStatus>(new MyStatus("status 2")));
	s_MyStatuses.push_back(
			boost::shared_ptr<MyStatus>(new MyStatus("status 3")));
	s_MyStatuses.push_back(
			boost::shared_ptr<MyStatus>(new MyStatus("status 4")));

	s_MyStatuses[1]->break_it();
	s_MyStatuses[2]->break_it();

	std::for_each(
		s_MyStatuses.begin(),
		s_MyStatuses.end(),
		boost::bind(&MyStatus::report,_1)
	);

	return 0;
}
