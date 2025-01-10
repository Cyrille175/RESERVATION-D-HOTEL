#ifndef CHAMBRE_H
#define CHAMBRE_H
#include <string>
#include <iostream>


class Chambre {
private:
	int _number;
	std::string _type;
	int _price;
	bool _state; // ceci est vrai quand la chambre est reserv�e et faux quand ce n'est pas le cas 
public:
	Chambre(int number, std::string type, int price);
	int get_number() const;
	std::string get_type() const;
	int get_price() const;
	bool get_state() const;
	void set_number(int number) ;
	void set_type(std::string type);
	void set_price(int price);
	void change_state();
	bool operator==(const Chambre& chambre) ;
	friend std::ostream& operator<<(std::ostream& os, const Chambre& chambre);
};






#endif