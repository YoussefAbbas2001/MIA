#ifndef HOTAL_H
#define HOTAL_H

/*
Guest Class of Monster Hotal
*/
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "Guest.h"

using namespace std;


class Hotal
{
public :
	Hotal();  //Constructor of Hotal 
	//Getting function
	int get_monster();   //return number of monster in Hotal
	int get_human();     //return number of human in Hotal
	int get_total();	 //return number of total guests in Hotal 
	float get_income();  //return total costs earned

	void reservation();  //Reservation Prompt 
	void extend();       //Extend reservation
	void service();      //Service prompot
	void acknowledment();//Acknowledment about Hotal
	void info();         //get inforamtoin abour guests
	


private:
	//m : monster   , h : human
	const int m_room = 15;                           //max number of monster rooms
	const int h_room = 5;                            //max number of human rooms
	const string cls[2] = { "Human  ","Monster" };   //to convert type from (int) to (string)
	static int total;                                //Number of guests exist in hotal
	static int monster;                              //number of monster guests in the hotal
	static int human;                                //number of human guests in the hotal
	Guest guest[20];                                 //Array of guests object 
	
	//Utilty Functions
	int check_vacant(int,int);    //function to check if there is place in Hotal
	int gen_id();                 //generate id
	int check_id(int);            //Check id and return index
	float extend_nights(int, int);//Extend Nights to spend
	void add_cost(int,float);     //cumulative costs

};


//end of preprossor wapper
#endif