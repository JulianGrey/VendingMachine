#ifndef __DRINK_HPP_INCLUDED__
#define __DRINK_HPP_INCLUDED__
#include <iostream>
#include <string>
#include <vector>

class Drink {
  public:
	std::string name;
	double price;
	int id;
	int stock;

	void setId(std::vector<Drink>* v) {
		this->id = (*v).size() + 1;
	}
	
	Drink(std::string n, double p, int s, std::vector<Drink>* v) {
		name = n;
		price = p;
		stock = s;
		setId(v);
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
				std::cout << "Drink is out of stock\n\n";
			}
			else {
				std::cout << "Insufficient stock (stock remaining: " << stock << ")\n\n";
			}
		}
	}
};

#endif
