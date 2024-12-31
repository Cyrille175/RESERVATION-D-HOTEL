#include "chambre.h"

Chambre::Chambre(int number, std::string type, int price) : _number(number), _type(type), _price(price) {

}

int Chambre::get_number() const {
	return _number;
}

std::string Chambre::get_type() const {
	return _type;
}

int Chambre::get_price() const {
	return _price;
}

void Chambre::set_number(int number) {
	_number = number;
}

void Chambre::set_type(std::string type) {
	_type = type;
}
void Chambre::set_price(int price) {
	_price = price;
}

/** int main() {
	Chambre b(14, "presidentiel", 1500);
	std::cout << b.get_number() << std::endl ;
	std::cout << b.get_type() << std::endl;
	std::cout << b.get_price() << std::endl;
	b.set_number(16);
	b.set_type("luxe");
	b.set_price(1600);
	std::cout << b.get_number() << std::endl;
	std::cout << b.get_type() << std::endl;
	std::cout << b.get_price() << std::endl;
}