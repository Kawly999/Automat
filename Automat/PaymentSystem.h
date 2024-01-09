#pragma once
#include <iostream>
#include <string>
using std::string;
using std::cout;

class PaymentSystem {
public:
	void displayCost(double price);
	bool sendMoneyToBank(double money) { return true; };
	PaymentSystem(string accNum) : accountNumber(accNum) {}
private:
	string accountNumber;
};

