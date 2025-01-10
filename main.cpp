#include "reservation.h"
#include <iostream>
#include <string.h>
#include "hotel.h"
#include "date.h"
#include "chambre.h"
#include "client.h"


std::vector<Reservation> reservations;
void display_clients(const std::vector<Client> clients) {
	std::cout << "Nos clients sont: " << std::endl;
	for (size_t i = 0; i < clients.size(); i++) {
		std::cout << clients[i] << std::endl;
	}
}

void search_clients(std::vector<Client>& clients, std::string name, std::string last_name) {
	bool search = false;
	for (size_t i = 0; i < clients.size(); i++) {
		if (clients[i].get_first_name() == name && clients[i].get_last_name() == last_name ) {
			std::cout << clients[i] << std::endl;
			search = true;
		}
	}
	if (!search) {
		Client ff(clients.size(), name, last_name);
		clients.push_back(ff);
		std::cout << "Client ajoute dans la base de donnees" << std::endl;
	}
}


void create_reservation(int id_client, std::string typer, Hotel& h, int day, int month, int year, int night_number) {
	Date date(day, month, year);
	bool correct = false;
	if (date.check() && night_number > 0) {
		correct = true;
	}
	int room = h.get_next_number_room(typer);

	if ( room != 0 && correct ) {
		Reservation r(id_client, day, month, year, night_number, h.get_id(), h.get_next_number_room(typer));
		reservations.push_back(r);
		h.change_room_state(room);
		std::cout << "La chambre " << room << " a ete reservee pour vous" << std::endl;
		int price = h.get_price_chambre(room) * night_number;
		std::cout << "Le prix total de votre reservation est de: " << price << "  dollars a raison de " << h.get_price_chambre(room) << " dollars la nuit" << std::endl;
	}
	if ( room == 0) {
		std::cout << "Il n'y a plus de chambres disponibles de ce type" << std::endl;
	}
	if (!correct) {
		std::cout << "Verifiez votre date ou le nombre de jours entre dans la reservation" << std::endl;
	}
}



	void display_reservations(const std::vector<Reservation>& r) {
		std::cout << "\n" << "\n" << "La liste des reservations faites : " << std::endl;
		for (const auto& reservation : r) {
		std::cout << reservation << std::endl;
		}
	}


int main() {
	Hotel anda("anda18", "Paradise", "Boston");
	Chambre aa(18, "presidentiel", 200);
	Chambre bb(14, "presidentiel", 200);
	Chambre cc(15, "luxieuse", 300);
	Chambre dd(16, "Normal", 100);
	Client El(1, "Elon", "Musk");
	Client Je(2, "Jeff", "Bezzos");
	Client Wa(3, "Warren", "Buffet");


	std::cout << anda.get_next_number_room("presidentiel");

	std::vector<Client> _clients = { El, Je, Wa };
	display_clients(_clients);
	search_clients(_clients, "Elon", "Musk");
	search_clients(_clients, "Michael", "Todd");

	anda.add_chambre(aa);
	anda.add_chambre(bb);
	anda.add_chambre(cc);
	anda.add_chambre(dd);

	
	/**std::cout << anda << std::endl;
	std::cout << aa << std::endl;
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
	std::cout << a.get_price_chambre_total() << std::endl; **/
	anda.display_list_chambre();

	create_reservation(1,"presidentiel", anda, 31, 3, 2024, 4);
	create_reservation(2,"presidentiel", anda, 31, 3, 2024, 5);
	create_reservation(1,"presidentiel", anda, 31, 3, 2024, 8);
	create_reservation(2,"luxieuse", anda, 31, 3, 2024, 8);
	create_reservation(3,"luxieuse", anda, 31, 3, 2025, 8);
	create_reservation(1,"Normal", anda, 32, 3, 2024, 8);


	display_reservations(reservations);


	return 0;

} 