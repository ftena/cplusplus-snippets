// Boost.Units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2008 Matthias Christian Schabel
// Copyright (C) 2008 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#include <iostream>

#include <boost/units/io.hpp>
#include <boost/units/pow.hpp>
#include <boost/units/systems/angle/degrees.hpp>
#include <boost/units/systems/cgs.hpp>
#include <boost/units/systems/cgs/io.hpp>
#include <boost/units/systems/si.hpp>
#include <boost/units/systems/si/io.hpp>
#include <boost/lexical_cast.hpp>

using namespace boost::units;

int main(int argc, char* argv[])
{
	if (argc < 3)
	{
		std::cout << "Usage: ./units vertical_degrees horizontal_degrees" << std::endl;
		return -1;
	}

    // test quantity_cast
    {
    // implicit value_type conversions
    //[conversion_snippet_1
    quantity<si::length>     L1 = quantity<si::length,int>(int(2.5)*si::meters);
    quantity<si::length,int> L2(quantity<si::length,double>(2.5*si::meters));
    //]
    
    //[conversion_snippet_3
    quantity<si::length,int> L3 = static_cast<quantity<si::length,int> >(L1);
    //]
    
    //[conversion_snippet_4
    quantity<cgs::length>    L4 = static_cast<quantity<cgs::length> >(L1);
    //]
    
    quantity<si::length,int> L5(4*si::meters),
                             L6(5*si::meters);
    quantity<cgs::length>    L7(L1);
    
    swap(L5,L6);
    
    std::cout << "L1 = " << L1 << std::endl
              << "L2 = " << L2 << std::endl
              << "L3 = " << L3 << std::endl
              << "L4 = " << L4 << std::endl
              << "L5 = " << L5 << std::endl
              << "L6 = " << L6 << std::endl
              << "L7 = " << L7 << std::endl
              << std::endl;
    }
    
    // test explicit unit system conversion
    {
    //[conversion_snippet_5
    quantity<si::volume>    vs(1.0*pow<3>(si::meter));      
    quantity<cgs::volume>   vc(vs);
    quantity<si::volume>    vs2(vc);
                        
    quantity<si::energy>    es(1.0*si::joule);      
    quantity<cgs::energy>   ec(es);
    quantity<si::energy>    es2(ec);
                        
    quantity<si::velocity>  v1 = 2.0*si::meters/si::second,     
                            v2(2.0*cgs::centimeters/cgs::second);
    //]
    
    std::cout << "volume (m^3)  = " << vs << std::endl
              << "volume (cm^3) = " << vc << std::endl
              << "volume (m^3)  = " << vs2 << std::endl
              << std::endl;
            
    std::cout << "energy (joules) = " << es << std::endl
              << "energy (ergs)   = " << ec << std::endl
              << "energy (joules) = " << es2 << std::endl
              << std::endl;
            
    std::cout << "velocity (2 m/s)  = " << v1 << std::endl
              << "velocity (2 cm/s) = " << v2 << std::endl
              << std::endl;
    }

	{
		// Unit
		const si::plane_angle plane_angle_unit;

		// SI System Reference
		quantity<si::plane_angle> rad(1.0*si::radians); // 1 rad as plane angle
		quantity<si::plane_angle> degree_as_plane_angle(1.0*degree::degrees); // 1 degree as plane angle

		// Trigonometry and Angle System Reference
		quantity<degree::plane_angle> degree(1.0*degree::degrees);

		std::cout << "unit = " << plane_angle_unit << std::endl; // rad
		std::cout << "1 radian = " << rad << std::endl; // 1 rad 
		std::cout << "1 degree as plane angle = " << degree_as_plane_angle << std::endl; // 0.0174533 rad
		std::cout << "1 degree using angle system reference = " << degree << std::endl; // 1 deg

		// Conversion from user input
		std::cout << boost::lexical_cast<double>(argv[1]) << " degrees: "
					<< degree_as_plane_angle*boost::lexical_cast<double>(argv[1])
					<< " "
					<< boost::lexical_cast<double>(argv[2]) << " degrees: "
					<< degree_as_plane_angle*boost::lexical_cast<double>(argv[2])
					<< std::endl;

		// Get default radians values for AP and OS cameras 
		std:: cout << "AP" << std::endl;

		std::cout << "IRTV - MFOV"
					<< " vertical: "
					<< degree_as_plane_angle*9.0
					<< " horizontal: "
					<< degree_as_plane_angle*14.0 << std::endl;
		std::cout << "IRTV - NFOV"
					<< " vertical: "
					<< degree_as_plane_angle*3.0
					<< " horizontal: "
					<< degree_as_plane_angle*5.0 << std::endl;
		std::cout << "CTV - WFOV"
					<< " vertical: "
					<< degree_as_plane_angle*17.0
					<< " horizontal: "
					<< degree_as_plane_angle*26.0 << std::endl;
		std::cout << "CTV - MFOV"
					<< " vertical: "
					<< degree_as_plane_angle*4.0
					<< " horizontal: "
					<< degree_as_plane_angle*6.0 << std::endl;
		std::cout << "CTV - NFOV"
					<< " vertical: "
					<< degree_as_plane_angle*2.0
					<< " horizontal: "
					<< degree_as_plane_angle*3.0 << std::endl;

		std::cout << "OS" << std::endl;

		std::cout << "IRTV - MFOV"
					<< " vertical: "
					<< degree_as_plane_angle*9.0
					<< " horizontal: "
					<< degree_as_plane_angle*14.0 << std::endl;
		std::cout << "IRTV - NFOV"
					<< " vertical: "
					<< degree_as_plane_angle*3.0
					<< " horizontal: "
					<< degree_as_plane_angle*5.0 << std::endl;
		std::cout << "IRTV - UNFOV"
					<< " vertical: "
					<< degree_as_plane_angle*2.0
					<< " horizontal: "
					<< degree_as_plane_angle*3.0 << std::endl;
		std::cout << "CHDTV - WFOV"
					<< " vertical: "
					<< degree_as_plane_angle*27.0
					<< " horizontal: "
					<< degree_as_plane_angle*40.0 << std::endl;
		std::cout << "CHDTV - MFOV"
					<< " vertical: "
					<< degree_as_plane_angle*10.0
					<< " horizontal: "
					<< degree_as_plane_angle*15.0 << std::endl;
		std::cout << "CHDTV - NFOV"
					<< " vertical: "
					<< degree_as_plane_angle*3.0
					<< " horizontal: "
					<< degree_as_plane_angle*5.0 << std::endl;
		std::cout << "CHDTV - UNFOV"
					<< " vertical: "
					<< degree_as_plane_angle*2.0
					<< " horizontal: "
					<< degree_as_plane_angle*3.0 << std::endl;
		std::cout << "LLLTV - WFOV"
					<< " vertical: "
					<< degree_as_plane_angle*24.0
					<< " horizontal: "
					<< degree_as_plane_angle*36.0 << std::endl;
		std::cout << "LLLTV - MFOV"
					<< " vertical: "
					<< degree_as_plane_angle*9.0
					<< " horizontal: "
					<< degree_as_plane_angle*14.0 << std::endl;
		std::cout << "LLLTV - NFOV"
					<< " vertical: "
					<< degree_as_plane_angle*3.0
					<< " horizontal: "
					<< degree_as_plane_angle*5.0 << std::endl;
	}

    return 0;
}
