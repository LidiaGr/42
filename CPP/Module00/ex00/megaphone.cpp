/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarsha <ttarsha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 13:14:47 by ttarsha           #+#    #+#             */
/*   Updated: 2020/12/03 13:14:47 by ttarsha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void	to_upper(char *str)
{
	int i = -1;

	while(str[++i] != '\0')
		if(str[i] >= 'a' && str[i] <= 'z')
			str[i] = str[i] - 32;
}

int		main(int ac, char **av) {

	int i = 1;

	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		while(av[i])
			to_upper(av[i++]);
		i = 1;
		while(av[i])
			std::cout << av[i++];
		std::cout << std::endl;
	}
	return 0;
}
