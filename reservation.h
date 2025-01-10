#ifndef RESERVATION_H
#define RESERVATION_H
#include "date.h"
#include "hotel.h"
#include <sstream>

class Reservation {
private:
	int _id_client; 
	Date _date_begin;
	int _number_of_nights;
	std::string _id_hotel;
	int _number_chambre;
	int _price;
	std::vector<Hotel> _hotels;
public:
	Reservation(int id_client, int day, int month, int year, int number_of_nights, std::string id_hotel, int number_chambre);
	Date get_date() const;
	int get_night_number() const;
	std::string get_id_hotel() const;
	int get_number_chambre() const;
	void add_hotel(const Hotel& hotel);
	int get_price_chambre_total() const; //trouver le prix d'une chambre connaissant son numero
	void modify_stay(const Date& new_date, int night_number);
	friend std::ostream& operator<<(std::ostream& os, const Reservation& r);
	//int get_total_price() ;
};


#endif