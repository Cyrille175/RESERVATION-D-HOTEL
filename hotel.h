#ifndef HOTEL_H
#define HOTEL_H
#include "chambre.h"
#include <vector>
#include <algorithm>
#include <sstream>

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
	int get_next_number_room(std::string type) const ;// Cette fonction retourne un numero de chambre d'un type s'il y'a encore des chambres de ce type, mais dans le cas ou ce type n'est plus disponible il renvoie 0
	void display_list_chambre() const;
	friend std::ostream& operator<<(std::ostream& os, const Hotel& h);
	void change_room_state(int number);
};


	


#endif