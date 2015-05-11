#include "drink.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

std::vector<Drink>* loadData(std::vector<Drink>* v) {
	std::ifstream drinkFile("drinks.txt");
	std::string* name = new std::string;
	double* price = new double;
	int* stock = new int;

	if(drinkFile.is_open()) {
		while(drinkFile >> *name >> *price >> *stock) {
			Drink drink(*name, *price, *stock, v);
			(*v).push_back(drink);
		}
	}
	delete name;
	delete price;
	delete stock;

	return v;
}

void saveData(std::vector<Drink>* v) {
	std::ofstream drinkFile("drinks.txt");
	if(drinkFile.is_open()) {
		for(int i = 0; i < (*v).size(); i++) {
			drinkFile << (*v)[i].name << " " << (*v)[i].price << " " << (*v)[i].stock << '\n';
		}
		drinkFile.close();
	}
	else {
		std::cout << "Unable to open file\n";
	}
}
