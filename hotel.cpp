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

void Hotel::display_list_chambre() const {
	for (auto chambre : _chambres) {
		std::cout << chambre.get_number() << "   " << chambre.get_type() << "    " << chambre.get_price() << " dollars" << std::endl;
	}
}


/**int main() {
	Hotel anda("anda18", "Paradise", "Boston");
	Chambre a(18, "presidentiel", 150);
	Chambre b(14, "presidentiel", 1500);
	Chambre c(15, "luxieuse", 1600);
	Chambre d(16, "Normal", 1700);

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
} **/