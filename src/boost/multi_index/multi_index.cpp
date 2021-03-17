#include <iostream>
#include <boost/multi_index_container.hpp>
#include <boost/multi_index/ordered_index.hpp>
#include <boost/multi_index/identity.hpp>
#include <boost/multi_index/member.hpp>
#include <boost/multi_index/composite_key.hpp>
#include <boost/multi_index/mem_fun.hpp>

/* 
* A simple struct with id, name and time
*/

struct MyStruct
{
	int id;
	std::string name;
	int time;

	MyStruct(int id,const std::string& name,int time):
		id(id),name(name),time(time){}

	int getId() const {return id;}

	bool operator<(const MyStruct& e)const{return id<e.id;}
};

/*
* Tags for the container.
*/
struct NumberThenTime {};
struct Time {};

/*
* Key extractor for multi_index_container storing the MyStruct messages.
*/
struct PacketTime
{
    // result_type typedef required by Key Extractor concept
    typedef long result_type;

    result_type operator()(MyStruct* r) const
    {
        return r->time;
    }
};

/*
* Multi index.
*/
typedef boost::multi_index_container<
    MyStruct*,
    boost::multi_index::indexed_by<
        // Order by id then time. Unique: one time for each id.
        boost::multi_index::ordered_unique<
            boost::multi_index::tag<NumberThenTime>,
            boost::multi_index::composite_key<
                MyStruct*,
                boost::multi_index::const_mem_fun<MyStruct, int, &MyStruct::getId>,
                PacketTime
            >,
            boost::multi_index::composite_key_compare<
                std::less<int>,
                std::greater<long>
            >
        >,
        // Order all by time from newest to oldest.
        boost::multi_index::ordered_non_unique<
            boost::multi_index::tag<Time>,
            PacketTime,
            std::greater<long>
        >
    >
> multi_index_data;

int main(int argc, char** argv)
{
	multi_index_data my_index_data;

	for(int i = 0; i < 5; i++)
	{
		my_index_data.insert(new MyStruct(i, "Peter", i-100));		
		my_index_data.insert(new MyStruct(i+1, "Teddy", i-100));		
	}

	// Now look for one with the exact time.
	multi_index_data::iterator foundIter;

	for(foundIter = my_index_data.begin(); foundIter != my_index_data.end(); ++foundIter)
	{
		std::cout << (*foundIter)->getId() << std::endl;
	}

	multi_index_data::index_iterator<NumberThenTime>::type index_iterator_by_number;
 
	std::cout << "Ordering by number" << std::endl;

	for (index_iterator_by_number = my_index_data.get<NumberThenTime>().begin();
			index_iterator_by_number != my_index_data.get<NumberThenTime>().end();
			++index_iterator_by_number)
	{
		std::cout << "Id: " << (*index_iterator_by_number)->id
					<< " Name: " << (*index_iterator_by_number)->name
					<< " Time: " << (*index_iterator_by_number)->time
					<< std::endl;
	}

	multi_index_data::index_iterator<Time>::type index_iterator_by_time;

	std::cout << "Ordering by datatime" << std::endl;

	for (index_iterator_by_time = my_index_data.get<Time>().begin();
         index_iterator_by_time != my_index_data.get<Time>().end();
         ++index_iterator_by_time)
   {
      std::cout << "Id: " << (*index_iterator_by_time)->id
               << " Name: " << (*index_iterator_by_time)->name
               << " Time: " << (*index_iterator_by_time)->time
               << std::endl;
   }

	std::cout << "Number of ocurrences" << std::endl;

	// get a view to index tagged with NumberThenTime
	multi_index_data::index<NumberThenTime>::type& index_by_number = my_index_data.get<NumberThenTime>();
	// get a view to index tagged with Time
	multi_index_data::index<Time>::type& index_by_time = my_index_data.get<Time>();

	std::cout << "   Track = 1: " << index_by_time.count(-100) << std::endl;
	std::cout << "   Time = -100: " << index_by_number.count(1) << std::endl;

	return 0;
}
