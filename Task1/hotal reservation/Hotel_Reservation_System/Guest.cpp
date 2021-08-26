#include "Guest.h"


Guest::Guest()
{
	room = 0;
	name = ' ';
	id = 0;
	type = 0;
	nights = 0;
	cost = 0.0;
}

Guest::Guest(string na, int ty, int ag, int ni, int i,float c):name(na),type(ty),room(ag),nights(ni),id(i),cost(c)
{
}


int Guest::get_type()
{
	return type;
}

string Guest::get_name()
{
	return name;
}

int Guest::get_id()
{
	return id;
}


int Guest::get_nights()
{
	return nights;
}

int Guest::get_room()
{
	return room;
}


float Guest::get_cost()
{
	return cost;
}

void Guest::set_type(int t)
{
	type = t;
}

void Guest::set_name(string n)
{
	name = n;
}

void Guest::set_id(int i)
{
	id = i;
}

void Guest::set_nights(int n)
{
	nights = n;
}

void Guest::set_room(int a)
{
	room = a;
}

void Guest::set_cost(float c)
{
	cost = c;
}
