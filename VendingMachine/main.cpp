#include "drink.hpp"
#include <iostream>
#include <string>
#include <vector>

void addDrink(std::vector<Drink>* v); // Handle adding drinks manually
void loadStock(); // Load stock from file

int main() {
	std::vector<Drink>* vDrink = new std::vector<Drink>;
	Drink coke("Coke", 1.35, 10, vDrink);
	(*vDrink).push_back(coke);
	Drink sprite("Sprite", 1.05, 0, vDrink);
	(*vDrink).push_back(sprite);
	Drink fanta("Fanta", 1.25, 10, vDrink);
	(*vDrink).push_back(fanta);

	std::cout << "Welcome. What drink would you like to buy?\n\n";
	for(int i = 0; i < (*vDrink).size(); i++) {
		// Get a list of drinks which are in stock
		if((*vDrink)[i].stock > 0) {
			std::cout << (*vDrink)[i].name << " - " << (*vDrink)[i].price;
			std::cout << " (selection: " << (*vDrink)[i].id << ")\n";
		}
	}
	std::cout << '\n';

	bool* found = new bool;
	int* selection = new int;
	std::cin >> *selection;
	*found = false;

	for(int i = 0; i < (*vDrink).size(); i++) {
		if((*vDrink)[i].id == *selection) {
			*found = true;
			(*vDrink)[i].removeStock(); // This process handles out of stock
			break;
		}
	}
	if(!(*found)) {
		// Drink ID doesn't exist
		std::cout << "Invalid selection.\n";
	}

	delete found;
	delete selection;
	delete vDrink;

	system("PAUSE");
	return 0;
}
