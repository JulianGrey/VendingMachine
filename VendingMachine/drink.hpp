#include <iostream>
#include <string>

class Drink {
  public:
	std::string name;
	double price;
	int id;
	int stock;

	Drink(std::string n, double p) {
		name = n;
		price = p;

		// The drink also needs to be added to a list
	}

	void addStock(int q) {
		stock += q;
	}

	void removeStock(int q = 1) {
		if(q <= stock) {
			stock -= q;
		}
		else {
			std::cout << "Operation cannot be performed: ";
			if(stock == 0) {
				std::cout << "Drink is out of stock\n";
			}
			else {
				std::cout << "Insufficient stock (stock remaining: " << stock << ")\n\n";
			}
		}
	}
};
