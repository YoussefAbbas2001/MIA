/*
Start : 25/8/2021
End :  -
Author : youssef abbas

Tranilvanian Hotal
*/
#include <iostream>
#include <string>
#include "Hotal.h"


using namespace std;
int main()
{

	int type_service;
	int ackn;
	Hotal day1;

	while (1)
	{
		cout << "\nTYPE OF SERVICE YOU NEED?\n" << endl;
		cout << "1) New Reservation.\n2) Extend Reservation.\n3) Additional Services.\n4) Cancel Reservation.\n5) Acknowledment.\n6) End." << endl;
		cout << "\n>>";
		cin >> type_service;
		if (type_service == 1)
		{
			day1.reservation();
		}
		else if (type_service == 2)
		{
			day1.extend();
		}
		else if (type_service == 3)
		{
			day1.service();
		}
		else if (type_service == 4)
		{

		}
		else if(type_service == 5)
		{
			day1.acknowledment();

		}
		else if(type_service == 6)
		{
			cout << "\nThank you for using this program.\n\n" << endl;
			exit(0);
		}
	}

	return 0;
}
