#ifndef MYCLASS_H
#define MYCLASS_H

#include <exception>
#include <iostream>
#include "myexception.h"

class myclass
{

	public:

		myclass() 
		{
		}

		void f()
		{
			try {
				throw myexception();
			} catch (myexception& m) {
				cout << "Exception in myclass. The exception is thrown again!" << endl;
				throw;
				cout << "Never here!" << endl;
			}		
		}
};

#endif

