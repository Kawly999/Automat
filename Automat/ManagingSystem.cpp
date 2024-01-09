#include "ManagingSystem.h"

using std::cin;
using std::cout;
using std::endl;

bool areEqual(double a, double b, double epsilon = 1e-9) {
	return std::abs(a - b) < epsilon;
}

void ManagingSystem::collectNumber() {
	int number = 0;
	for (int i = 0; i < 5; i++) {
		cout << "Podaj numer produktu: " << endl;
		cin >> number;
		if (number >= 0 && number <= amountOfProducts) {
			collectedNumber = number;
			return;
		}
		if (i == 4) {
			cout << "Koniec zabawy!";
			exit(EXIT_FAILURE);
		}
		std::cout << "Podano b³êdny numer, wpsz numer ponownie." << endl;
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
}

void ManagingSystem::findProduct() {
	dbH->loadProducts();
	product = dbH->getProduct(collectedNumber);
}

bool ManagingSystem::createTransaction() {
	double money;
	double price = product.getPrice();
	ps.displayCost(price);
	cin >> money;
	if (!areEqual(money, price)) {
		cout << "Koniec zabawy!";
		exit(EXIT_FAILURE);
	}
	return ps.sendMoneyToBank(money);
}
