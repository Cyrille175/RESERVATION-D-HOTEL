#include "reservation.h"

Reservation::Reservation(int day, int month, int year, int number_of_nights, std::string id_hotel, int number_chambre) : _date_begin(day, month, year), _number_of_nights(number_of_nights), _id_hotel(id_hotel), _number_chambre(number_chambre) {

}

Date Reservation::get_date() const {
	return _date_begin;
}

int Reservation::get_night_number() const {
	return _number_of_nights;
}

std::string Reservation::get_id_hotel() const {
	return _id_hotel;
}

int Reservation::get_number_chambre() const {
	return _number_chambre;
}

void Reservation::add_hotel(const Hotel& hotel) {
	_hotels.push_back(hotel);
}

int Reservation::get_price_chambre_total()const {
	auto at = std::find_if(_hotels.begin(), _hotels.end(), [this](const Hotel& hotel) {
		return hotel.get_id() == this->_id_hotel;
		});
	return (( at->get_price_chambre(_number_chambre) ) * (_number_of_nights) );
}

void Reservation::modify_stay(const Date& date, int night_number) {
	_date_begin.edit_date(date.get_day(), date.get_month(), date.get_year());
	if (night_number > 0) {
		_number_of_nights = night_number;
		std::cout << "votre sejour a ete modifie pour " << _number_of_nights << " nuits" << std::endl;
	}
	else std::cout << "Verifier votre nombre de nuits" << std::endl;
}

int main() {
	Reservation a(31, 3, 2024, 5, "anda18", 14);
	Hotel anda("anda18", "Paradise", "Boston");
	Chambre aa(18, "presidentiel", 150);
	Chambre bb(14, "presidentiel", 1500);
	Chambre cc(15, "luxieuse", 1600);
	Chambre dd(16, "Normal", 1700);
	anda.add_chambre(aa);
	anda.add_chambre(bb);
	anda.add_chambre(cc);
	anda.add_chambre(dd);
	a.add_hotel(anda);
	std::cout << a.get_date().display_date() << std::endl;
	std::cout << a.get_night_number() << std::endl;
	std::cout << a.get_id_hotel() << std::endl;
	std::cout << a.get_number_chambre() << std::endl;
	std::cout << a.get_price_chambre_total() << std::endl;

	Date date(3, 8, 2024);
	a.modify_stay(date, 6);

	std::cout << a.get_date().display_date() << std::endl;
	std::cout << a.get_night_number() << std::endl;
	std::cout << a.get_id_hotel() << std::endl;
	std::cout << a.get_number_chambre() << std::endl;
	std::cout << a.get_price_chambre_total() << std::endl;

	return 0;

}