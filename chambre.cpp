#include "chambre.h"

Chambre::Chambre(int number, std::string type, int price) : _number(number), _type(type), _price(price) {

}

int Chambre::get_number() const {
	return _number;
}

std::string Chambre::get_type() const {
	return _type;
}

bool Chambre::operator==(const Chambre& chambre) {
	return ((this->_number == chambre.get_number()) && (this->_type == chambre.get_type()) && (this->_price == chambre.get_price()) );
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

std::ostream& operator<<(std::ostream& os, const Chambre& chambre) {
	os << std::endl << "Numero de chamnbre: " << chambre.get_number() << std::endl << "Type de la chambre: " << chambre.get_type() << std::endl << "Prix de la chambre: " << chambre.get_price() << std::endl;
	return os;
}


 /** int main() {
	Chambre b(14, "presidentiel", 1500);
	std::cout << b.get_number() << std::endl;
	std::cout << b.get_type() << std::endl;
	std::cout << b.get_price() << std::endl;
	std::cout << b << std::endl;
	b.set_number(16);
	b.set_type("luxe");
	b.set_price(1600);
	std::cout << b.get_number() << std::endl;
	std::cout << b.get_type() << std::endl;
	std::cout << b.get_price() << std::endl;
} **/