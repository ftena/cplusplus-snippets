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
				cout << "Exception in myclass. Se lanza de nuevo la excepción" << endl;
				throw;
				cout << "Aquí no se llega" << endl;
			}		

			
		}
 
};

#endif

