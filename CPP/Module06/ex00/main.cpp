//
// Created by Temple Tarsha on 12/23/20.
//

#include "main.hpp"

void	ConvertToChar(std::string str) {
	char c;
	try {
		if (str.length() == 1 && !isdigit(str[0])) {
			int a = static_cast<int>(str[0]);
			c = static_cast<char>(a);
		} else {
			std::string::size_type sz;
			int b = std::stoi(str, &sz);
			c = static_cast<char>(b);
		}
		if (c < 0 || c > 127) {
			std::cout << "char: impossible" << std::endl;
			return ;
		}
		if (isprint(c))
			std::cout << "char: \'" << c << "\'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}
	catch (const std::invalid_argument &ia) {
		std::cout << "char: impossible" << std::endl;
	}
	catch (const std::out_of_range &oor) {
		std::cout << "char: impossible" << std::endl;
	}
}

void 	ConvertToInt(std::string str) {
	try {
		int a = stoi(str);
		a = static_cast<int>(a);
		std::cout << "int: " << a << std::endl;
	}
	catch (const std::invalid_argument &ia) {
		std::cout << "int: impossible" << std::endl;
	}
	catch (const std::out_of_range &oor) {
		std::cout << "int: impossible" << std::endl;
	}
}

void 	ConvertToFloat(std::string str) {
	try {
		std::string::size_type sz;
		float a = stof(str, &sz);
		a = static_cast<float>(a);
		if (std::fmod(a, 1.0) == 0.0) {
			std::cout << "float: " << a << ".0f" << std::endl;
		} else {
			std::cout << "float: " << a << "f" << std::endl;
		}
	}
	catch (const std::invalid_argument &ia) {
		std::cout << "float: impossible" << std::endl;
	}
	catch (const std::out_of_range &oor) {
		std::cout << "float: impossible" << std::endl;
	}
}

void 	ConvertToDouble(std::string str) {
	try {
		std::string::size_type sz;
		double a = stof(str, &sz);
		a = static_cast<double>(a);
		if (std::fmod(a, 1.0) == 0.0) {
			std::cout << "double: " << a << ".0" << std::endl;
		} else {
			std::cout << "double: " << a << std::endl;
		}
	}
	catch (const std::invalid_argument &ia) {
		std::cout << "double: impossible" << std::endl;
	}
	catch (const std::out_of_range &oor) {
		std::cout << "double: impossible" << std::endl;
	}
}

int 	main(int ac, char **av) {
	if (ac != 2) {
		std::cout << "Bad arguments." << std::endl;
		return 1;
	}
	std::string str = av[1];
	ConvertToChar(str);
	ConvertToInt(str);
	ConvertToFloat(str);
	ConvertToDouble(str);
	return 0;
}