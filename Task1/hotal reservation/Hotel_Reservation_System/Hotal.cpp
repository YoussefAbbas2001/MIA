#include "Hotal.h"

//Prototype of Composite function
class Guest;

//Initialize static varible
int Hotal::total = 0;
int Hotal::monster = 0;
int Hotal::human = 0;

Hotal::Hotal()
{
	/*
	About : Constuctor 
	get   : Display wellcome label 
	*/
	cout << "________________________________________" << endl;
	cout << "WELCOME TO TRANSILVANIA HOTEL" << endl;
	cout << "________________________________________\n\n" << endl;
}

void Hotal::reservation()
{
	/*
	About : reservation section for comming user into Hotal either new or already existed
	*/
	string name;
	string answer;
	int user_id;
	int index;
	int nights;
	int room;
	int type;

	cout << "\nHello Sir,\nIs this first time to you here.\n(yes/no) : ";
	cin >> answer;

	if (answer == "yes")
	{
		cout << "\n\nPlase, Enter this Registeration " << endl;
		cout << "---------------------------------- " << endl;
		cout << "\t\tClass (1:monster / 0:human) : ";
		cin >> type;
		cout << "\t\tHow many rooms : ";
		cin >> room;
		if (check_vacant(type,room))
		{
			guest[total-1].set_type(type);
			cout << "\t\tName : ";
			cin >> name;
			guest[total-1].set_name(name);

			guest[total-1].set_room(room);

			cout << "\t\tNumber of nights : ";
			cin >> nights;
			guest[total-1].set_nights(nights);

			guest[total-1].set_id(gen_id());
			cout << "\n\n\t\tYour ID : " << guest[total-1].get_id()<<endl;

			//Put Registeration Costs
			if (type == 0)
				add_cost(guest[total - 1].get_id(), 500 * nights * room *1.0);
			else
				add_cost(guest[total - 1].get_id(), 200 * nights * room *1.0);

			cout << "\t\tCosts   : " << guest[total-1].get_cost()<<endl;
			cout << "\t\tThank You for visiting us " << endl;
			cout << "----------------------------------\n\n" << endl;
		}
		else
		{
			cout << "Sorry sir, All rooms are busy right now. " << endl;
		}
	}
	else if (answer == "no")
	{
		cout << "Could I know your Id : ";
		cin >> user_id;
		if ((index = check_id(user_id)))
		{
			index--;
			cout << "\nOK thank you " << guest[index].get_name() << endl;
		}
		else
		{
			cout << "\nSorry but your Id not in Database." << endl;
		}
	}

}

void Hotal::extend()
{
	/*
	About : Extension Section in Hotal
	*/
	int extnd;
	int index ;
	int user_id;
	int user_index;
	float costs;


	cout << "\n\n__________________Extend Section_________________" << endl;
	cout << "Hello sir." << endl;
	cout << "Please, Could I know Your ID : ";
	cin >> user_id;
	cout << "How many nights do you want to append : ";
	cin >> extnd;

	costs = extend_nights(user_id, extnd);
	cout << "\nNow you  extended "<<extnd<<"night with total costs " << costs << "$" << endl;
	cout << "_______________________________________________________" << endl;
}

void Hotal::service()
{
	/*
	About : Service Section in Hotal, Show costs spended by user
	*/
	int serv;
	int serv_id;
	int serv_index;
	cout << "\n\n__________________Service Center_________________" << endl;
	cout << "Welcome To Service Section sir." << endl;
	cout << "Please, Could I know Your ID : ";
	cin >> serv_id;
	cout << " How could I help you..\n1) Dry Cleaning.\t\t2) Spa.\n>>";
	cin >> serv;
	if (serv == 1)
	{
		add_cost(serv_id, 30);
		cout << "Cost of your service : " << 30 << endl;
	}
	else if (serv == 2)
	{
		add_cost(serv_id, 50);
		cout << "Cost of your service : " << 50 << endl;
	}
	else
	{
		cout << "\nI don't understand what do you need..\n" << endl;
	}
	cout << "_______________________________________________________" << endl;
}

void Hotal::acknowledment()
{
	int ackn; 

	cout << "###############################################" << endl;
	cout << "\nAcknowledgment:\n";
	cout << "\t1) Information about guests\n\t2) Number of Guestes\n\t3) Number of busy Human rooms.\n\t4) Number of busy Monster Rooms.";
	cout << "\n\t5) Total income." << endl;
	cout << ">>";
	cin >> ackn;

	if (ackn == 1)
	{
		this->info();
	}
	else if (ackn == 2)
	{
		cout << "Number of Total guests : " << this->get_total() << endl;
	}
	else if (ackn == 3)
	{
		cout << "Number of Human room busy : " << this->get_human() << endl;
	}
	else if (ackn == 4)
	{
		cout << "Number of monster room busy : " << this->get_monster() << endl;
	}
	else if (ackn == 5)
	{
		cout << "Total income to Hotal : " << this->get_income() << endl;
	}
	else
	{
		cout << "Cannot Understand your choice" << endl;
	}
	cout << "###############################################" << endl;
}

int Hotal::get_monster()
{
	/*
	About : get total Number of monster existing right now
	*/
	return monster;
}

int Hotal::get_human()
{
	/*
	About : get total Number of Human existing right now
	*/
	return human;
}

int Hotal::get_total()
{
	/*
	About : get total Number of Guest existing right now
	*/
	return total;
}

float Hotal::get_income()
{
	/*
	About : get the total income from all guests
	*/
	float tot_income=0;
	for (int i = 0; i < total; i++)
	{
		tot_income += guest[i].get_cost();
	}
	return tot_income;
}

void Hotal::info()
{
	/*
	About : get us some information about the guests
	*/
	cout << "\n-----------------------------------HOTAL GUESTS---------------------------------------" << endl;
	for (int i = 0; i < total; i++)
	{
		cout << "Name : " << guest[i].get_name() <<" \tClass : "<<cls[guest[i].get_type()] <<" \trooms : "<<guest[i].get_room() << "\tId : " << guest[i].get_id() << "\tCost : " << guest[i].get_cost() << endl;
	}
	cout << "---------------------------------------------------------------------------------------" << endl;
}

int Hotal::check_vacant(int cls_type,int num_room)
{	
	/*
	About: Check if there are places in hotel according to the capacity of hotal 
	Note : there are different rooms for moster and human
	*/
	if (cls_type == 1)
	{
	    if (monster+num_room <= m_room)
		{
			total++;
			monster += num_room;
			return 1;
		}
	}
	else
	{
		if (human+num_room <= h_room)
		{
			total++;
			human += num_room;
			return 1;
		}
	}
	return 0;
}

int Hotal::gen_id()
{
	/*
	about  :  generating by check with existing ones
	return :  random id
	*/
	int rand_id;
	srand(time(NULL));
	
	while (1)
	{
		rand_id = rand() % 9999 + 10;
		for (int i = 0; i <= total; i++)
		{
			if (rand_id != guest[i].get_id())
			{
				return rand_id;
			}
			else
			{
				continue;
			}
		}
	}
	return 0;
}

int Hotal::check_id(int user_id)
{
	/*
	about : Chech if this id is exists
	retur : idex of this guest to could access it like guest[ index ] 
	*/
	for (int i = 0; i < total; i++)
	{
		if (guest[i].get_id() == user_id)
		{
			return i+1;
		}
	}
	return 0;
}

float Hotal::extend_nights(int user_id, int add_night)
{
	/*
	About     : extend Nights 
	parameter : take id and the number of night to extend reservation
	return    : costs of total reservation
	*/
	int index;
	int old_nights;
	int total_nights;
	float costs= 0;

	if ((index =check_id(user_id)))
	{
		index--;
		old_nights = guest[index].get_nights();
		total_nights = add_night + old_nights;
		guest[index].set_nights(total_nights);
		costs = (guest[index].get_type()) ? (total_nights*200) :(total_nights*500);	
	}
	else
	{
		cout << "\nSorry sir your ID isn't in Database" << endl;
	}
	return costs;
}

void Hotal::add_cost(int user_id , float new_cost)
{
	/*
	get cumulative money spended by the user that pass his id	
	*/
	int i;
	float old_cost;
	float total_cost;
	i = check_id(user_id) - 1;
	old_cost = guest[i].get_cost();
	total_cost = old_cost + new_cost;
	guest[i].set_cost(total_cost);

}

