#include "drink.hpp"
#include <iostream>
#include <string>
#include <vector>

void admin(std::vector<Drink>* v, bool* b); // Holds admin functions
std::vector<Drink>* loadData(std::vector<Drink>* v); // Load stock from file
void saveData(std::vector<Drink>* v); // Save stock to file

int main() {
	std::vector<Drink>* vDrink = new std::vector<Drink>;
	loadData(vDrink);
	bool* bAdmin = new bool;
	*bAdmin = false;
	bool* quit = new bool;
	*quit = false;
	bool* found = new bool;
	int* selection = new int;

	while(!(*quit)) {
		std::cout << "Welcome. What drink would you like to buy?\n\n";
		for(size_t i = 0; i < (*vDrink).size(); i++) {
			// Get a list of drinks which are in stock
			if((*vDrink)[i].stock > 0) {
				std::cout << (*vDrink)[i].name << " - " << (*vDrink)[i].price;
				std::cout << " (selection: " << (*vDrink)[i].id << ")\n";
			}
		}
		std::cout << "\nAdmin (selection: -1)\n";
		std::cout << "Quit (selection: 0)\n\n";
		std::cin >> *selection;
		std::cin.ignore();

		switch(*selection) {
			case 0:
				*quit = true;
				break;
			case -1:
				*bAdmin = true;
				admin(vDrink, bAdmin);
				break;
		}

		*found = false;
		for(size_t i = 0; i < (*vDrink).size(); i++) {
			if((*vDrink)[i].id == *selection) {
				*found = true;
				if((*vDrink)[i].stock > 0) {
					std::cout << (*vDrink)[i].name << " dispensed. Enjoy your drink.\n\n";
				}
				(*vDrink)[i].removeStock(); // This process handles out of stock
				break;
			}
		}
		if(!(*found) && !(*quit)) {
			// Drink ID doesn't exist
			std::cout << "Invalid selection.\n";
		}
		std::cout << '\n';
	}

	saveData(vDrink); // Save changes to stock

	delete bAdmin;
	delete found;
	delete selection;
	delete quit;
	delete vDrink;
	return 0;
}
