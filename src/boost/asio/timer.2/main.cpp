//
// timer.cpp
// ~~~~~~~~~
//
// Copyright (c) 2003-2014 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#include <iostream>
#include <boost/asio.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

/*

For each call to async_wait(), the supplied handler will be called exactly once.
The handler will be called when:

    + The timer has expired.
    + The timer was cancelled, in which case the handler is passed the error
	 code boost::asio::error::operation_aborted.

*/

void print(const boost::system::error_code& /*e*/)
{
	std::cout << "Hello, world!\n";
}

int main()
{
	boost::asio::io_service io;

	boost::asio::deadline_timer t(io, boost::posix_time::seconds(5));

	std::cout << "before t.async_wait(&print)" << std::endl;
	/*
	* We call the deadline_timer::async_wait() function to
	* perform an asynchronous wait.
	*/
	t.async_wait(&print);

	std::cout << "before io.run()" << std::endl;
	io.run();

	std::cout << "after io.run()" << std::endl;
	return 0;
}
