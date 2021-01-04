/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarsha <ttarsha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 22:22:05 by ttarsha           #+#    #+#             */
/*   Updated: 2020/12/07 22:22:05 by ttarsha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

void	to_upper(char *str)
{
	int i = -1;

	while(str[++i] != '\0')
		if(str[i] >= 'a' && str[i] <= 'z')
			str[i] = str[i] - 32;
}

int 	main(int ac, char **av) {
	std::ifstream	inputF;
	std::ofstream	outputF;
	std::string		fName;
	std::string		tmp;
	std::string		s1;
	size_t			nb = 0;

	if (ac != 4) {
		std::cout << "Bad arguments number." << std::endl;
		return 1;
	}
	inputF.open(av[1], std::ifstream::in);
	if (inputF.is_open()) {
		to_upper(av[1]);
		fName = av[1];
		fName += ".replace";
		outputF.open(fName, std::ofstream::out);
		do {
			std::getline(inputF, tmp);
			if ((nb = tmp.find(av[2])) != std::string::npos) {
				s1 = av[2];
				tmp.erase(nb, s1.length());
				tmp.insert(nb, av[3]);
			}
			outputF << tmp;
			if (!inputF.eof())
				outputF << '\n';
		} while (!inputF.eof());
	} else {
		std::cout << "File \"" << av[1] << "\" cannot be opened." << std::endl;
		return 1;
	}
	inputF.close();
	outputF.close();
	return 0;
}
