#include "hotel.h"

Hotel::Hotel(std::string id, std::string name, std::string city) : _id(id), _name(name), _city(city) {

}

std::string Hotel::get_id() const {
	return _id;
}

std::string Hotel::get_name() const {
	return _name;
}

std::string Hotel::get_city() const {
	return _city;
}

void Hotel::add_chambre(const Chambre& chambre) {
	_chambres.push_back(chambre);
}

void Hotel::delete_chambre(const Chambre& chambre_delete) {
	auto it = std::find(_chambres.begin(), _chambres.end(), chambre_delete);
	
	if (it != _chambres.end()) {
			_chambres.erase(it);
			std::cout << "Votre chambre a bel et bien ete effacee" << std::endl;
		}
	else {
		std::cout << "Veuillez verifier les infos de votre chambre, elle ne se retrouve pas notre base de donnees" << std::endl;
	}
}

int Hotel::get_price_chambre(int number) const {
	auto it = std::find_if(_chambres.begin(), _chambres.end(), [&number](const Chambre& chambre) {
		return chambre.get_number() == number;
		});
	return it->get_price();
}

void Hotel::display_list_chambre() const {
	for (auto chambre : _chambres) {
		std::cout << chambre.get_number() << "   " << chambre.get_type() << "    " << chambre.get_price() << " dollars" << std::endl;
	}
}

std::ostream& operator<<(std::ostream& os, const Hotel& h) {
	std::string info = "Les chambres dans cet hôtel sont:\n";
	for (const auto& chambre : h._chambres) {
		info += std::to_string(chambre.get_number()) + "   " + chambre.get_type() + "    " + std::to_string(chambre.get_price()) + " dollars\n";
	}

	os << std::endl << "Les informations sur l'hotel sont: " << "\n" << "Nom de l'hotel: " << h._id << "\n" << "Nom de l'hotel: " << h._name << "\n" << "Ville: " << h._city << "\n" << "Il y'a " << h._chambres.size() << " chambres dans cet hotel" << info << std::endl;
	return os;
}


// donnes le numero de chambre a reserver 
int Hotel::get_next_number_room(std::string type) const {
	int number = 0;
	int room_number_to_reserve;
	for (const auto& chambre : _chambres) {
		if ( !(chambre.get_state()) && (chambre.get_type() == type) ) {
			number = number + 1;
			room_number_to_reserve = chambre.get_number();
		}
	}
	if (number == 0) {
		room_number_to_reserve = 0;
	}
	return room_number_to_reserve;
}

void Hotel::change_room_state(int number) {
	for (auto& chambre : _chambres) {
		if (chambre.get_number() == number) {
			chambre.change_state();
		}
	}
}

/**
int main() {
	Hotel anda("anda18", "Paradise", "Boston");
	Chambre a(18, "presidentiel", 150);
	Chambre b(14, "presidentiel", 1500);
	Chambre c(15, "luxieuse", 1600);
	Chambre d(16, "Normal", 1700);

	anda.get_next_number_room("presidentiel");
	anda.get_next_number_room("luxieuse");

	std::cout << anda.get_id() << std::endl;
	std::cout << anda.get_name() << std::endl;
	std::cout << anda.get_city() << std::endl;
	anda.add_chambre(b);
	anda.add_chambre(c);
	anda.add_chambre(d);
	anda.display_list_chambre();
	anda.delete_chambre(b);
	anda.delete_chambre(a);
	anda.display_list_chambre();
	
	return 0; 
} **/