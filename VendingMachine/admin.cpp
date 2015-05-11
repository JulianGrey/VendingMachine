#include "drink.hpp"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

void addDrink(std::vector<Drink>* v);
void addStock(std::vector<Drink>* v);

void admin(std::vector<Drink>* v, bool* b) {
	int* selection = new int;
	while(*b) {
		std::cout << "What operation do you need?\n\n";
		std::cout << "Add new drink (selection: 1)\n";
		std::cout << "Add stock to existing drink (selection: 2)\n";
		std::cout << "List current stock (selection: 3)\n";
		std::cout << "Back to frontend (selection: 0)\n\n";
		std::cin >> *selection;
		std::cin.ignore();

		switch(*selection) {
			case 1:
				addDrink(v);
				break;
			case 2:
				addStock(v);
				break;
			case 3:
				for(size_t i = 0; i < (*v).size(); i++) {
					std::cout << (*v)[i].name << " (stock: " << (*v)[i].stock << ")\n";
				}
				break;
			case 0:
				*b= false;
				continue;
			default:
				std::cout << "Invalid selection\n\n";
		}
		std::cout << '\n';
	}
	delete selection;
}

void addDrink(std::vector<Drink>* v) {
	std::string* sInput = new std::string;
	double* pInput = new double;
	int* qInput = new int;
	bool* found = new bool;

	*found = false;
	std::cout << "Enter the name of the new drink: ";
	std::getline(std::cin, *sInput);

	for(size_t i = 0; i < (*v).size(); i++) {
		if((*v)[i].name == *sInput) {
			*found = true;
			break;
		}
	}

	if(*found) {
		std::cout << "\nThis product has already been added\n";
	}
	else {
		std::cout << "Enter the price of the new drink: ";
		std::cin >> *pInput;
		std::cout << "Enter the quantity of this drink being added: ";
		std::cin >> *qInput;

		if(*qInput < 0) {
			std::cout << "Cannot add a negative number of stock!\n";
		}
		else if(*pInput < 0.00) {
			std::cout << "Cannot have a negative price!\n";
		}
		else {
			Drink drink(*sInput, *pInput, *qInput, v);
			(*v).push_back(drink);
		}
	}
	std::cout << '\n';

	delete found;
	delete pInput;
	delete qInput;
	delete sInput;
}

void addStock(std::vector<Drink>* v) {
	std::cout << "Which drink do you want to restock?\n\n";
	
	for(size_t i = 0; i < (*v).size(); i++) {
		std::cout << (*v)[i].name << " (selection: " << (*v)[i].id;
		std::cout << ", current stock: " << (*v)[i].stock << ")\n";
	}
	std::cout << "Back to admin (selection: 0)\n\n";

	bool* itemCheck = new bool;
	int* selection = new int;
	int* quantity = new int;
	*itemCheck = false;
	std::cin >> *selection;
	std::cin.ignore();
	if(*selection != 0) {
		std::cout << '\n';
		std::cout << "How many items do you want to add? ";
		std::cin >> *quantity;
		std::cin.ignore();
		if(*quantity < 1) {
			std::cout << "Cannot add a negative or 0 number of stock!\n";
		}
		else {
			for(size_t i = 0; i < (*v).size(); i++) {
				if((*v)[i].id == *selection) {
					*itemCheck = true;
					(*v)[i].addStock(*quantity);
					std::cout << *quantity << " items have been added to drink " << (*v)[i].name;
					std::cout << "\n";
					break;
				}
			}
			if(!(*itemCheck)) {
				std::cout << "Item ID does not exist.\n";
			}
		}
	}
	std::cout << '\n';

	delete itemCheck;
	delete quantity;
	delete selection;
}
