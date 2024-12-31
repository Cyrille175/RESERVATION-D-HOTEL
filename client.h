#ifndef CLIENT_H
#define CLIENT_H
#include <string>
#include <iostream>

class Client {
private:
	int _id;
	std::string _first_name;
	std::string _last_name;

public:
	Client(int id, std::string first_name, std::string last_name);
	int get_id() const;
	std::string get_first_name() const;
	std::string get_last_name() const;
	void set_last_name(std::string name);
};




#endif