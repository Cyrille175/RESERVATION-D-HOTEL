#ifndef HOTEL_H
#define HOTEL_H
#include "chambre.h"
#include <vector>
#include <algorithm>

class Hotel {
private:
	std::string _id, _name, _city;
	std::vector<Chambre> _chambres;
public:
	Hotel(std::string id, std::string name, std::string city);
	std::string get_id() const;
	std::string get_name() const;
	std::string get_city() const;
	void add_chambre(const Chambre& chambre);
	int get_price_chambre(int number)const; //trouver le prix d'une chambre connaissant son numero
	void delete_chambre(const Chambre& chambre);
	void display_list_chambre() const;
};


	


#endif