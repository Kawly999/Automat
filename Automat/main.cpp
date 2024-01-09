#include <iostream>
#include <string>
#include <cstdlib>
#include "ManagingSystem.h"
#include "Product.h"
#include "DatabaseHandler.h"
#include "PaymentSystem.h"
using std::string;

void clientCode() {
	string filename = "produkty_automat.txt";
	string bankAccountNumber = "1234 3567 1241 6877";
	Product prod;
	PaymentSystem ps(bankAccountNumber);
	ManagingSystem ms(prod, filename, ps);
	ms.collectNumber();
	ms.findProduct();
	if (ms.createTransaction()) {
		cout << "Wyrzucono produkt: " << ms.getProduct().getName() << std::endl;
	}
	else cout << "Awaria systemu." << std::endl;
}


int main(void) {
	setlocale(LC_ALL, "Polish");
	clientCode();

	system("pause");
	return 0;
}