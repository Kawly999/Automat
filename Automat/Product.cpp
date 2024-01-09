#include "Product.h"

Product& Product::operator=(const Product& pr) {
	if (this != &pr) {
		name = pr.name;
		price = pr.price;
	}
	return *this;
}
