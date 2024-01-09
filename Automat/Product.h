#pragma once
#include <string>
using std::string;

class Product {
public:
	string getName() { return name; }
	double getPrice() { return price; }
	Product(string _name = "produkt0", double _price = 0.0) : name(_name), price(_price) {}
	Product& operator=(const Product& pr);
private:
	string name;
	double price;
};
