//
// Created by Temple Tarsha on 12/17/20.
//

#include "ISpaceMarine.hpp"
#include "ISquad.hpp"
#include "Squad.hpp"
#include "AssaultTerminator.hpp"
#include "TacticalMarine.hpp"

int main() {
	{
		ISpaceMarine *bob = new TacticalMarine;
		ISpaceMarine *jim = new AssaultTerminator;

		ISquad *vlc = new Squad;
        
		vlc->push(bob);
		vlc->push(jim);
		for (int i = 0; i < vlc->getCount(); ++i) {
			ISpaceMarine *cur = vlc->getUnit(i);
			cur->battleCry();
			cur->rangedAttack();
			cur->meleeAttack();
		}
		delete vlc;
	}
	{
		std::cout	<<  std::endl << "_________________________________________"
					<<  std::endl;
		ISpaceMarine *jim = new AssaultTerminator;
		ISpaceMarine *bob = jim->clone();
        ISpaceMarine *jey = new AssaultTerminator;
		ISquad *vlc = new Squad;
        
        test->push(jey);
		vlc->push(jim);
		vlc->push(bob);
		for (int i = 0; i < vlc->getCount(); ++i) {
			std::cout << "Nb of units: " << vlc->getCount() << std::endl;
			ISpaceMarine *cur = vlc->getUnit(i);
			cur->battleCry();
			cur->rangedAttack();
			cur->meleeAttack();
		}
		delete vlc;
	}
	return 0;
}
