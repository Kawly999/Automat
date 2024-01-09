#pragma once
#include <iostream>
#include <string>
#include "Product.h"
#include "DatabaseHandler.h"
#include "PaymentSystem.h"

static int amountOfProducts = 10;
using std::string;

class ManagingSystem {
public:
	void collectNumber(); // takes number from user
	int getNumber() { return collectedNumber; }
	void findProduct(); 
	bool createTransaction();
	Product getProduct() { return product; }
	ManagingSystem() = delete;
	ManagingSystem(Product& prod, string filename, PaymentSystem& payS) : product(prod), dbH(new DatabaseHandler(filename)), ps(payS) {};
	~ManagingSystem() { delete dbH; }
private:
	int collectedNumber = 0;
	DatabaseHandler* dbH;
	Product product;
	PaymentSystem ps;
};

