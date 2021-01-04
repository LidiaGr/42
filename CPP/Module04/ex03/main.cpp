//
// Created by Temple Tarsha on 12/18/20.
//

#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "ICharacter.hpp"


int main() {
	{
		IMateriaSource *src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		ICharacter *me = new Character("me");
		AMateria *tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		ICharacter *bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);
		delete bob;
		delete me;
		delete src;
	}
	{
		std::cout	<<  std::endl << "_________________________________________"
					<<  std::endl;
		IMateriaSource *src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		ICharacter *me = new Character("me");
		AMateria *tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);

		std::cout << "Trying to add invalid type" << std::endl;
		tmp = src->createMateria("fire");
		me->equip(tmp);

		ICharacter *bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);

		std::cout << "Trying to use empty/invalid slots" << std::endl;
		me->use(2, *bob);
		me->use(6, *bob);

		std::cout << "Trying to equip more slots" << std::endl;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		tmp = src->createMateria("ice");
		me->equip(tmp);

		std::cout << "Trying to use more slots" << std::endl;
		me->use(0, *bob);
		me->use(1, *bob);
		me->use(2, *bob);
		me->use(3, *bob);
		me->use(4, *bob);
		me->use(5, *bob);

		std::cout << "Unequip slots" << std::endl;
		me->unequip(2);
		me->unequip(8);

		std::cout << "Trying to use unequiped slots" << std::endl;
		me->use(2, *bob);

		std::cout << "Trying to learn empty material" << std::endl;
		src->learnMateria(nullptr);

		delete bob;
		delete me;
		delete src;
	}
	return 0;
}
