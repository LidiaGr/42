//
// Created by Temple Tarsha on 12/16/20.
//

#include "AWeapon.hpp"
#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"
#include "Enemy.hpp"
#include "RadScorpion.hpp"
#include "SuperMutant.hpp"
#include "Character.hpp"

int main() {
	{
		Character* me = new Character("me");

		std::cout << *me;

		Enemy* b = new RadScorpion();

		AWeapon* pr = new PlasmaRifle();
		AWeapon* pf = new PowerFist();

		me->equip(pr);
		std::cout << *me;
		me->equip(pf);

		me->attack(b);
		std::cout << *me;
		me->equip(pr);
		std::cout << *me;
		me->attack(b);
		std::cout << *me;
		me->attack(b);
		std::cout << *me;
	}
	{
		std::cout	<<  std::endl << "_________________________________________"
					 <<  std::endl;
		Character *peer = new Character("peer");
		Enemy *cheater = new SuperMutant;
		AWeapon *eval = new PowerFist;

		std::cout << *peer;
		peer->attack(cheater);

		peer->equip(eval);
		std::cout << *peer;
		peer->attack(cheater);
		std::cout << *peer;
		peer->attack(cheater);
		std::cout << *peer;
		peer->attack(cheater);
		std::cout << *peer;
		peer->attack(cheater);
	}

	return 0;
}
