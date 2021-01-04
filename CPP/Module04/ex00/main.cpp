//
// Created by Temple Tarsha on 12/15/20.
//

#include "Sorcerer.hpp"
#include "Victim.hpp"
#include "Peon.hpp"

int 	main()
{
	{
		Sorcerer robert("Robert", "the Magnificent");
		Victim jim("Jimmy");
		Peon joe("Joe");
		std::cout << robert << jim << joe;
		robert.polymorph(jim);
		robert.polymorph(joe);
	}
	{
		std::cout	<<  std::endl << "_________________________________________"
					<<  std::endl;
		Sorcerer albert("Albert", "the Magnificent");
		Peon joe("Joe");
		Peon peo(joe);
		Peon *lin = new Peon("Lin");

		std::cout << albert << peo << *lin;

		albert.polymorph(peo);
		albert.polymorph(*lin);
		delete lin;
	}

	return 0;
}
