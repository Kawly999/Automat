#include "DatabaseHandler.h"
#include <fstream>
#include <sstream>
#include <exception>

void DatabaseHandler::loadProducts() {
	std::ifstream ifs(filename, std::ios::in);
	if (!ifs.is_open()) throw std::runtime_error("B³¹d otwarcia pliku.");
	string tmp_name = "";
	double tmp_price = 0.0;
	string line;
	for (int i = 0; std::getline(ifs, line); i++) {
		std::istringstream iss(line);
		if (iss >> tmp_name >> tmp_price) products[i] = Product(tmp_name, tmp_price);
		else throw ("B³ad odczytu z linii.");
	}
}