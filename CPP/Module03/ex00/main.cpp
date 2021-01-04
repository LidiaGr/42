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

int 	main(void) {
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

	return 0;
}