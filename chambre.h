#ifndef CHAMBRE_H
#define CHAMBRE_H
#include <string>
#include <iostream>

class Chambre {
private:
	int _number;
	std::string _type;
	int _price;
public:
	Chambre(int number, std::string type, int price);
	int get_number() const;
	std::string get_type() const;
	int get_price() const;
	void set_number(int number) ;
	void set_type(std::string type);
	void set_price(int price);
	bool operator==(const Chambre& chambre) ;
};






#endif