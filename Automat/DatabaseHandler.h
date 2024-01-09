#pragma once
#include <unordered_map>
#include "Product.h"
#include <string>
using std::unordered_map;
typedef unordered_map<int, Product> umIP_t;
extern int amountOfProducts;

class DatabaseHandler {
public:
	void loadProducts();
	DatabaseHandler(string& fname) : filename(fname) {};
	Product& getProduct(int num) { return products[num]; }
private:
	string filename;
	umIP_t products;
};

