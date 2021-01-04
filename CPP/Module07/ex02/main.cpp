//
// Created by Temple Tarsha on 12/27/20.
//

#include "Array.hpp"

int main()
{
	try {
		Array<int> intArray(10);
		Array<double> doubleArray(10);

		for (unsigned int count = 0; count < intArray.size(); ++count) {
			intArray[count] = count;
			doubleArray[count] = count + 0.5;
		}

		for (unsigned int count = 0; count < intArray.size(); ++count)
			std::cout << intArray[count] << "\t" << doubleArray[count] << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "__________________" << std::endl;
	try {
		Array<std::string> stringsArray(5);

		for (unsigned int count = 0; count < stringsArray.size(); ++count) {
			stringsArray[count] = "hello";
		}

		for (unsigned int count = 0; count < stringsArray.size(); ++count)
			std::cout << stringsArray[count] << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "__________________" << std::endl;
	try {
		Array<float> floatsArray(5);

		std::cout << floatsArray[6] << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "__________________" << std::endl;
	try {
		Array<int> intArray1(5);

		for (unsigned int count = 0; count < intArray1.size(); ++count) {
			intArray1[count] = count;
		}

		for (unsigned int count = 0; count < intArray1.size(); ++count)
			std::cout << intArray1[count];

		std::cout << std::endl;

		Array<int> intArray2(intArray1);
		for (unsigned int count = 0; count < intArray2.size(); ++count)
			std::cout << intArray2[count];
		std::cout << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}