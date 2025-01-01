#include "reservation.h"
#include <iostream>
#include "hotel.h"
#include "date.h"
#include "chambre.h"


int main() {
	
	Reservation a(31, 3, 2024, 5, "anda18", 14);
	Hotel anda("anda18", "Paradise", "Boston");
	Chambre aa(18, "presidentiel", 200);
	Chambre bb(14, "presidentiel", 200);
	Chambre cc(15, "luxieuse", 300);
	Chambre dd(16, "Normal", 100);
	anda.add_chambre(aa);
	anda.add_chambre(bb);
	anda.add_chambre(cc);
	anda.add_chambre(dd);
	std::cout << aa << std::endl;
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