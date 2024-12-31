#include "client.h"

Client::Client(int id, std::string first_name, std::string last_name): _id(id), _first_name(first_name), _last_name(last_name) {

}
int Client::get_id() const {
	return _id;
}

std::string Client::get_first_name() const {
	return _first_name;
}

std::string Client::get_last_name() const {
	return _last_name;
}

void Client::set_last_name(std::string name) {
	_last_name = name;
}



/** int main() {
	Client a(2, "Maeva", "Mamitite");
	std::cout << a.get_id();
	std::cout << a.get_first_name();
	std::cout << a.get_last_name();
	a.set_last_name("Anda");

}