#include <iostream>

#define COKE 1
#define SPRITE 2
#define TANGO 3
#define WATER 4

void availableDrinks(); // Get a list of drinks which are in stock
void dispense(int drink); // Dispend a selected drink
void restock(int drink, int amount);

double calculate(); // total cost of purchase

int main() {std::cout << "Welcome. What drink would you like to buy?\n\n";
	availableDrinks();

	int selection;
	std::cin >> selection;

	switch(selection) {
		case COKE:
			dispense(COKE);
			break;
		case SPRITE:
			dispense(SPRITE);
			break;
		case TANGO:
			dispense(TANGO);
			break;
		case WATER:
			dispense(WATER);
			break;
		default:
			std::cout << "Invalid selection, choose again\n\n";
	}

	return 0;
}
