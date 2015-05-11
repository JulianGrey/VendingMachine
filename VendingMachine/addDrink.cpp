#include "drink.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

void addDrink(std::vector<Drink>* v) {
	std::string* sInput = new std::string;
	double* nInput = new double;
	int* qInput = new int;
	bool* found = new bool;

	*found = false;
	std::cout << "Enter the name of the new drink: ";
	std::getline(std::cin, *sInput);

	for(int i = 0; i < (*v).size(); i++) {
		if((*v)[i].name == *sInput) {
			*found = true;
			break;
		}
	}

	if(*found) {
		std::cout << "\nThis product has already been added\n\n";
	}
	else {
		std::cout << "Enter the price of the new drink: ";
		std::cin >> *nInput;
		std::cout << "Enter the quantity of this drink being added: ";
		std::cin >> *qInput;

		Drink drink(*sInput, *nInput, *qInput, v);
		(*v).push_back(drink);
	}

	delete sInput;
	delete nInput;
}
