#ifndef GUEST_H
#define GUEST_H

#include <iostream>
#include <string>

using namespace std;

class Guest
{
public:

	Guest();
	Guest(string, int, int, int, int,float);
	int get_type();
	string get_name();
	int get_id();
	int get_nights();
	int get_room();
	float get_cost();


	void set_type(int);
	void set_name(string);
	void set_id(int);
	void set_nights(int);
	void set_room(int);
	void set_cost(float);

private:

	string name;
	int type;
	int room;
	int id;
	int nights;
	float cost;

};

#endif