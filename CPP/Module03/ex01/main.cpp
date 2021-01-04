/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarsha <ttarsha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 20:24:55 by ttarsha           #+#    #+#             */
/*   Updated: 2020/12/11 20:24:55 by ttarsha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int 	main(void) {
	{
		FragTrap Default;
		FragTrap NoImg = FragTrap("NO-IMAGINATION");
		FragTrap assign = NoImg;
		FragTrap copy(NoImg);

		std::cout << std::endl;
		assign.rangedAttack("BE-BE-BE");
		copy.rangedAttack("BE-BE-BE");
		std::cout << std::endl;

		NoImg.meleeAttack("BE-BE-BE");
		NoImg.vaulthunter_dot_exe("BE-BE-BE");
		NoImg.rangedAttack("BE-BE-BE");
		NoImg.vaulthunter_dot_exe("BE-BE-BE");
		NoImg.meleeAttack("BE-BE-BE");
		NoImg.vaulthunter_dot_exe("BE-BE-BE");
		std::cout << std::endl;
		NoImg.beRepaired(30);
		std::cout << std::endl;
		NoImg.takeDamage(65);
		NoImg.takeDamage(46);
		NoImg.meleeAttack("BE-BE-BE");
		std::cout << std::endl;
	}
	{
		std::cout << "__________________________________________________________________" << std::endl;
		std::cout << std::endl << std::endl;
		ScavTrap Challenger;

		std::cout << std::endl;
		Challenger.meleeAttack("BE-BE-BE");
		Challenger.challengeNewcomer("BE-BE-BE");
		Challenger.meleeAttack("BE-BE-BE");
		Challenger.challengeNewcomer("BE-BE-BE");
		Challenger.rangedAttack("BE-BE-BE");
		Challenger.beRepaired(30);
		Challenger.rangedAttack("BE-BE-BE");
		std::cout << std::endl;
	}
	return 0;
}