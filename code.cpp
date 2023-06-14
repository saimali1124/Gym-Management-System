#include<iostream>
#include <string>
#include <fstream> 
using namespace std;
string mainMenu();
string customerOptions();
string trainerOptions();
string equipmentOptions();
string SubscriptionsOptions();

class Date {
public:

	string day;

	Date()
	{
		day = "---";
	}
	Date(string d)
	{
		day = d;
	}
};

class Equipment {

	string name;

public:
	int id;

	static int equipmentCount;
	Equipment()
	{
		id = 0;
		name = "---";
	}
	Equipment(int i, string n)
	{
		id = i;
		name = n;
	}
	void print()
	{
		cout << "Equipment ID: " << id << "\t" << "Equipment Name: " << name << endl;
	}
	int getEquipmentId()
	{
		return id;
	}
	void setID(int i)
	{
		id = i;
	}
	void setName(string n)
	{
		name = n;
	}
	int getID()
	{
		return id;
	}
	string getName()
	{
		return name;
	}
};
int Equipment::equipmentCount = 0;


class ExercisePlan {

public:

	Equipment* equipment;
	int id;
	int duration;

	static int exerciseCount;

	ExercisePlan(Equipment& e)
	{
		equipment = new Equipment(e);

		id = 0;
		duration = 0;
	}
	ExercisePlan()
	{
		id = 0;
		duration = 0;
	}
	void print()
	{
		cout << "Plan ID: " << id << "\t" << "Equipment ID: " << equipment->getEquipmentId() << "\t" << "Duration: " << duration << endl;
	}
	~ExercisePlan()
	{
		delete equipment;
		equipment = nullptr;
	}
};

class Customer {

public:
	int id;
	string phone;;
	string name;
	string address;
	string email;

	static int customerCount;

	Customer()
	{
		id = 0;
		phone = "---";
		name = "---";
		address = "---";
		email = "---";
	}
	Customer(int i, string p, string n, string a, string e)
	{
		id = i;
		phone = p;
		name = n;
		address = a;
		email = e;
	}
	void print()
	{
		cout << "Customer ID: " << id << "\t" << "Customer Name: " << name << "\t" << "Address: " << address << "\t" << "Phone: " << phone << "\t" << "Email: " << email << "\t" << endl;
	}
	void setId(int i)
	{
		id = i;
	}
	void setPhone(string p)
	{
		phone = p;
	}
	void setName(string n)
	{
		name = n;
	}
	void setEmail(string p)
	{
		email = p;
	}
	void setAddress(string p)
	{
		address = p;
	}
	int getID()
	{
		return id;
	}
	string getAddress()
	{
		return address;
	}
	string getPhone()
	{
		return phone;
	}
	string getName()
	{
		return name;
	}
	string getEmail()
	{
		return email;
	}
};




class Trainer {

public:

	int id;
	string name;
	ExercisePlan exe;

	int subscriptionID;
	Date date;
	Customer* customer;
	int PlanID;
	int tempid;

	static int TotalSubscriptions;

	static int trainerCount;

	Trainer()
	{
		id = 0;
		name = "---";
	}
	Trainer(Equipment& e)
	{
		exe.equipment->setID(e.getID());
		exe.equipment->setName(e.getName());
	}
	Trainer(Customer*& c)
	{
		customer = c;
	}
	void print()
	{
		cout << "Trainer ID: " << id << "\t" << "Trainer Name: " << name << endl;
	}
	void printSubs()
	{
		cout << " Subscription ID : " << subscriptionID << "  Date/Time : " << date.day << "  Customer ID : " << customer[0].id << "  Plan ID : " << PlanID << endl;
	}
	void printExercisePlans()
	{
		cout << " PlanID : " << exe.id << "  TrainerID : " << id << "  Equipment ID : " << tempid << "  Duration : " << exe.duration << endl;
	}
	int getTrainerId()
	{
		return id;
	}
	void setID(int i)
	{
		id = i;
	}
	void setName(string n)
	{
		name = n;
	}
	int getID()
	{
		return id;
	}
	string getName()
	{
		return name;
	}
};



class GYM
{
	const int equipmentLimit = 5;
	const int trainerLimit = 5;
	const int customerLimit = 10;

	int customerCount;
	int trainerCount;
	int equipmentCount;

public:
	Customer* customer;
	Trainer* trainer;
	Equipment* equipment;

	GYM()
	{
		equipment = new Equipment[equipmentLimit];
		customerCount = 0;
		equipmentCount = 0;
		trainerCount = 0;
	}
	GYM(Equipment*& Eq, Customer*& C, Trainer*& T)
	{
		equipment = new Equipment[equipmentLimit];

		for (int i = 0; i < Equipment::equipmentCount; i++)
		{

			equipment[i].setID(Eq[i].getID());
			equipment[i].setName(Eq[i].getName());
		}
		customer = C;
		trainer = T;
		equipmentCount = 0;
		trainerCount = 0;
		customerCount = 0;
	}

	~GYM()
	{
		delete[] equipment;
		equipment = nullptr;
	}

	void addCustomer()
	{
		if (Customer::customerCount < customerLimit)
		{
			string temp;
			customer[Customer::customerCount].setId(Customer::customerCount + 1);
			cout << "Enter name of the customer: ";
			cin >> temp;
			customer[Customer::customerCount].setName(temp);
			cout << "Enter phone: ";
			cin >> temp;
			customer[Customer::customerCount].setPhone(temp);
			cout << "Enter email: ";
			cin >> temp;
			customer[Customer::customerCount].setEmail(temp);
			cout << "Enter address: ";
			cin >> temp;
			customer[Customer::customerCount].setAddress(temp);
			Customer::customerCount++;
		}
		else
		{
			cout << "Hall already full !" << endl;
		}
	}
	void showCustomerList()
	{

		cout << endl << "Customer list : " << endl << endl;

		for (int i = 0; i < Customer::customerCount; i++)
		{
			customer[i].print();
		}
		cout << endl;
	}
	void removeCustomer()
	{
		int temp; int count = 0;
		cout << "Enter id of customer to remove: ";
		cin >> temp;
		Customer* array = new Customer[customerLimit];

		for (int i = 0; i < Customer::customerCount; i++)
		{
			if (customer[i].getID() != temp)
			{
				array[count].setId(customer[i].getID());
				array[count].setAddress(customer[i].getAddress());
				array[count].setEmail(customer[i].getEmail());
				array[count].setName(customer[i].getName());
				array[count].setPhone(customer[i].getPhone());
				count++;
			}
		}
		Customer::customerCount--;
		delete[] customer;
		customer = array;
		cout << "Customer Removed" << endl;

	}
	void editCustomer()
	{
		int temp = 0;
		cout << "Enter id of customer to edit: ";
		cin >> temp;
		for (int i = 0; i < Customer::customerCount; i++)
		{
			if (temp == customer[i].getID())
			{
				string s;
				cout << "Enter name of the customer: ";
				cin >> s;
				customer[i].setName(s);
				cout << "Enter phone: ";
				cin >> s;
				customer[i].setPhone(s);
				cout << "Enter email: ";
				cin >> s;
				customer[i].setEmail(s);
				cout << "Enter address: ";
				cin >> s;
				customer[i].setAddress(s);
				break;
			}
		}
	}

	void updateCustomerFile()
	{
		ofstream write;
		write.open("customer.txt", ios::trunc);
		if (write.is_open())
		{
			for (int i = 0; i < Customer::customerCount; i++)
			{
				write << customer[i].getID() << "  " << customer[i].getName() << "  " << customer[i].getAddress() << "  " << customer[i].getPhone() << "  " << customer[i].getEmail() << endl;
			}
		}
	}

	void addTrainer()
	{
		if (Trainer::trainerCount < trainerLimit)
		{
			string temp;
			trainer[Trainer::trainerCount].setID(Trainer::trainerCount+1);
			cout << "Enter name of the trainer: ";
			cin >> temp;
			trainer[Trainer::trainerCount].setName(temp);
			Trainer::trainerCount++;
			cout << endl << "Trainer has been added." << endl;
		}
		else
		{
			cout << "Hall already full !" << endl;
		}
	}
	void showTrainerList()
	{
		cout << "List of trainers : " << endl;

		for (int i = 0; i < Trainer::trainerCount; i++)
		{
			trainer[i].print();
		}
	}
	void removeTrainer()
	{
		int temp; int count = 0;
		cout << "Enter id of trainer to remove: ";
		cin >> temp;
		Trainer* array = new Trainer[trainerLimit];

		for (int i = 0; i < Trainer::trainerCount; i++)
		{
			if (trainer[i].getTrainerId() != temp)
			{
				array[count].setID(trainer[i].getID());
				array[count].setName(trainer[i].getName());
				count++;
			}
		}
		Trainer::trainerCount--;
		trainer = nullptr;
		trainer = array;
		cout << "Trainer Removed" << endl;
	}

	void editTrainer()
	{
		int temp = 0;
		cout << "Enter id of trainer to edit: ";
		cin >> temp;
		for (int i = 0; i < Trainer::trainerCount; i++)
		{
			if (temp = trainer[i].getTrainerId())
			{
				string s;
				cout << "Enter name of the trainer: ";
				cin >> s;
				trainer[i].setName(s);
				break;
			}
		}
	}

	void updateTrainerFile()
	{
		ofstream write2;
		write2.open("trainer.txt", ios::trunc);
		if (write2.is_open())
		{
			for (int i = 0; i < Trainer::trainerCount; i++)
			{
				write2 << trainer[i].getID() << "  " << trainer[i].getName() << endl;
			}
		}
	}

	void addEquipment()
	{
		if (Equipment::equipmentCount < equipmentLimit)
		{
			string temp;
			equipment[Equipment::equipmentCount].setID(Equipment::equipmentCount);
			cout << "Enter name of the equipment: ";
			cin >> temp;
			equipment[Equipment::equipmentCount].setName(temp);
			equipmentCount++;
		}
		else
		{
			cout << "Hall already full. No space for more equipments !" << endl;
		}
	}

	void showEquipmentList()
	{
		cout << endl << "List of equipments : " << endl;

		for (int i = 0; i < Equipment::equipmentCount; i++)
		{
			equipment[i].print();
		}
	}
	void removeEquipment()
	{
		int temp; int count = 0;
		cout << "Enter id of equipment to remove: ";
		cin >> temp;
		Equipment* array = new Equipment[equipmentLimit];

		for (int i = 0; i < Equipment::Equipment::equipmentCount; i++)
		{
			if (equipment[i].getEquipmentId() != temp)
			{
				array[count] = equipment[i];
				count++;
			}
		}

		Equipment::Equipment::equipmentCount--;
		delete[] equipment;
		equipment = nullptr;
		equipment = array;
		cout << "Equipment Removed" << endl;
	}

	void editEquipment()
	{
		int temp = 0;
		cout << "Enter id of equipment to edit: ";
		cin >> temp;
		for (int i = 0; i < Equipment::Equipment::equipmentCount; i++)
		{
			if (temp == equipment[i].getEquipmentId())
			{
				string s;
				cout << "Enter name of the equipment: ";
				cin >> s;
				equipment[i].setName(s);
				break;
			}
		}
	}

	void updateEquipmentFile()
	{
		ofstream write3;
		write3.open("equipment.txt", ios::trunc);
		if (write3.is_open())
		{
			for (int i = 0; i < Equipment::Equipment::equipmentCount; i++)
			{
				write3 << equipment[i].getID() << "  " << equipment[i].getName() << endl;
			}
		}
	}

	void showExercisePlansList()
	{
		cout << endl << " List of exercise plans : " << endl;

		for (int i = 0; i < ExercisePlan::exerciseCount; i++)
		{
			trainer[i].printExercisePlans();
		}
	}

	void showSubscriptionsList()
	{
		cout << endl << " List of subscriptions : " << endl;
		for (int i = 0; i < Trainer::TotalSubscriptions; i++)
		{
			trainer[i].printSubs();
		}
	}

	void addSubscriptions()
	{
		string temp;
		int i = 0;
		
		cout << " Enter Plan ID of Exercise Plan you want to choose from the following : " << endl;
		for (int i = 0; i < ExercisePlan::exerciseCount; i++)
		{
			trainer[i].printExercisePlans();
		}
		cout << " PlanID choice : ";
		cin >> i;

		int a[10] = {};
		int b = 0;
		for (int u = 0; u < Trainer::TotalSubscriptions; u++)
		{
			a[u] = trainer[u].PlanID;
			b++;
		}

		int pp = 1;
		int y = 0;
		for (int h = 0; h < b; h++)
		{
			if (i == a[h])
			{
				y++;
			}
		}
		if (y == 0)
		{
			pp = 0;
		}

		int p = 1;
		int c = 0;
		for (int j = 0; j < b ; j++)
		{
			if (a[j] == i)
			{
				c++;
			}
		}
		if (c > 2)
		{
			p = 0;
		}

		if ((p == 1) && (pp == 1))
		{
			trainer[Trainer::TotalSubscriptions].customer = new Customer[1];
			trainer[Trainer::TotalSubscriptions].PlanID = i;
			trainer[Trainer::TotalSubscriptions].subscriptionID = ((Trainer::TotalSubscriptions)+1);
            cout << "Enter the date for subscription in the format dd/mm/yyyy: ";
            cin >> temp;
            trainer[Trainer::TotalSubscriptions].date = temp;
            cout << "Enter customer ID: ";
			cin >> i;
 			trainer[Trainer::TotalSubscriptions].customer[0].id = i;
			
			Trainer::TotalSubscriptions++;
			cout << "\n **Subscription Successful** " << endl << endl;
		}
		if(p == 0)
		{
			cout << "\n **Subscription unsuccessful**\n **Trainer and equipments are not free**\n **The exercise plan has already been occupied by 3 customers**\n ";
		}
		if (pp == 0)
		{
			cout << " **Error. Invalid Plan ID** " << endl << endl;
		}
	}
};

void readEquipmentsFromFile(Equipment*& Eq);
void readCustomersFromFile(Customer*& C);
void readTrainersFromFile(Trainer*& T);
void readSubscriptionsFromFile(Trainer*& T);
void readExerciseplansFromFile(Trainer*& T);

int Trainer::trainerCount = 0;
int Customer::customerCount = 0;
int ExercisePlan::exerciseCount = 0;
int Trainer::TotalSubscriptions = 0;
int main()
{
	Customer* C;
	C = new Customer[10];
	readCustomersFromFile(C);

	Trainer* T;
	T = new Trainer[10];
	readTrainersFromFile(T);

	readExerciseplansFromFile(T);
	readSubscriptionsFromFile(T);

	Equipment* Eq;
	Eq = new Equipment[10];
	readEquipmentsFromFile(Eq);

	GYM MyGym(Eq, C, T);

	string choice = "1";
	while ((choice != "x") && (choice != "X"))
	{
		choice = mainMenu();
		if (choice == "x" || choice == "X")
		{
			return 0;
		}
		else if (choice == "1")
		{
			choice = customerOptions();
			if (choice == "1")
			{
				MyGym.showCustomerList();
			}
			else if (choice == "2")
			{
				MyGym.addCustomer();
				MyGym.updateCustomerFile();
			}
			else if (choice == "3")
			{
				MyGym.editCustomer();
				MyGym.updateCustomerFile();

			}
			else if (choice == "4")
			{
				MyGym.removeCustomer();
				MyGym.updateCustomerFile();
			}
			else if (choice == "x" || choice == "X")
			{
				return 0;
			}
			else
			{
				cout << " **Invalid Input** " << endl;
			}

		}
		else if (choice == "2")
		{
			choice = trainerOptions();
			if (choice == "1")
			{
				MyGym.showTrainerList();
			}
			else if (choice == "2")
			{
				MyGym.addTrainer();
				MyGym.updateTrainerFile();
			}
			else if (choice == "3")
			{
				MyGym.editTrainer();
				MyGym.updateTrainerFile();

			}
			else if (choice == "4")
			{
				MyGym.removeTrainer();
				MyGym.updateTrainerFile();
			}
			else if (choice == "x" || choice == "X")
			{
				return 0;
			}
			else
			{
				cout << " **Invalid Input** " << endl;
			}
		}
		else if (choice == "3")
		{
			choice = equipmentOptions();
			if (choice == "1")
			{
				MyGym.showEquipmentList();
			}
			else if (choice == "2")
			{
				MyGym.addEquipment();
				MyGym.updateEquipmentFile();
			}
			else if (choice == "3")
			{
				MyGym.editEquipment();
				MyGym.updateEquipmentFile();

			}
			else if (choice == "4")
			{
				MyGym.removeEquipment();
				MyGym.updateEquipmentFile();
			}
			else if (choice == "x" || choice == "X")
			{
				return 0;
			}
			else
			{
				cout << " **Invalid Input** " << endl;
			}
		}
		else if (choice == "4")
		{
			MyGym.showExercisePlansList();
		}
		else if (choice == "5")
		{
			choice = SubscriptionsOptions();
			if (choice == "1")
			{
				MyGym.showSubscriptionsList();
			}
			else if (choice == "2")
			{
				MyGym.addSubscriptions();
			}
			else
			{
				cout << " **Invalid Input** " << endl;
			}
		}
		else
		{
			cout << "  *Invalid input* " << endl << endl;
		}
	}

	delete[] C; 
	C = nullptr;

	delete[] T;
	T = nullptr;

	delete[] Eq;
	Eq = nullptr;
}


string mainMenu()
{
	string temp;
	cout << endl << endl;
	cout << "=============================Gym Management System===============================" << endl;
	cout << endl << " 1. Customer options" << endl;
	cout << " 2. Trainer options" << endl;
	cout << " 3. Equipment options" << endl;
	cout << " 4. Display list of Exercise Plans" << endl;
	cout << " 5. Subscriptions options" << endl;
	cout << " Press x to exit program" << endl;

	cout << "\n Pick appropriate option: ";
	cin >> temp;
	return temp;

}

string customerOptions()
{
	string temp;
	cout << endl << "---------------Customer Options------------------" << endl;
	cout << " 1. Show customer list" << endl;
	cout << " 2. Add a customer" << endl;
	cout << " 3. Edit a customer data" << endl;
	cout << " 4. Remove a customer" << endl;
	cout << " Any other key to go to main menu" << endl;
	cout << " Press x to exit program" << endl;

	cout << "\n Pick appropriate option: ";
	cin >> temp;
	cout << endl;
	return temp;

}

string trainerOptions()
{
	string temp;
	cout << endl << "---------------Trainer Options------------------" << endl;
	cout << " 1. Show trainer list" << endl;
	cout << " 2. Add a trainer" << endl;
	cout << " 3. Edit a trainer data" << endl;
	cout << " 4. Remove a trainer" << endl;
	cout << " Any other key to go to main menu" << endl;
	cout << " Press x to exit program" << endl;

	cout << "\n Pick appropriate option: ";
	cin >> temp;
	cout << endl;
	return temp;
}

string equipmentOptions()
{
	string temp;
	cout << endl << "---------------Equipment Options------------------" << endl;
	cout << " 1. Show equipment list" << endl;
	cout << " 2. Add a equipment" << endl;
	cout << " 3. Edit an equipment data" << endl;
	cout << " 4. Remove an equipment" << endl;
	cout << " Any other key to go to main menu" << endl;
	cout << " Press x to exit program" << endl;

	cout << "\n Pick appropriate option: ";
	cin >> temp;
	cout << endl;
	return temp;
}

string SubscriptionsOptions()
{
	string temp;
	cout << endl << "---------------Subscriptions Options------------------" << endl;
	cout << " 1. Show subscriptions list" << endl;
	cout << " 2. Add a subscription" << endl;
	cout << " Any other key to go to main menu" << endl;
	cout << " Press x to exit program" << endl;

	cout << "\n Pick appropriate option: ";
	cin >> temp;
	cout << endl;
	return temp;
}


void readCustomersFromFile(Customer*& C)
{
	int i; string s; int count = 0;
	ifstream read1;
	read1.open("customer.txt");
	if (read1.is_open())
	{
		while (!read1.eof())
		{

			read1 >> i;
			C[count].setId(i);
			read1 >> s;
			C[count].setName(s);
			read1 >> s;
			C[count].setAddress(s);
			read1 >> s;
			C[count].setPhone(s);
			read1 >> s;
			C[count].setEmail(s);
			count++;
			Customer::customerCount++;
		}
	}
}

void readTrainersFromFile(Trainer*& T)
{
	int i; string s; int count = 0;
	ifstream read2;
	read2.open("trainer.txt");
	if (read2.is_open())
	{
		while (!read2.eof())
		{
			read2 >> i;
			T[count].setID(i);
			read2 >> s;
			T[count].setName(s);
			count++;
			Trainer::trainerCount++;
		}
	}
}

void readSubscriptionsFromFile(Trainer*& T)
{
	int i; string s; int count = 0;
	ifstream read3;
	read3.open("subscriptions.txt");
	if (read3.is_open())
	{
		while (!read3.eof())
		{
			T[count].customer = new Customer[1];
			read3 >> i;
			T[count].subscriptionID = i;
			read3 >> s;
			T[count].date = s;
			read3 >> i;
			T[count].customer[0].id = i;
			read3 >> i;
			T[count].PlanID = i;

			count++;
			Trainer::TotalSubscriptions++;
		}
	}
}

void readExerciseplansFromFile(Trainer*& T)
{
	int i; int count = 0;
	ifstream read4;
	read4.open("exercisePlans.txt");
	if (read4.is_open())
	{
		
		while (!read4.eof())
		{
			T[count].exe.equipment = new Equipment[1];
			read4 >> i;
			T[count].exe.id = i;
			read4 >> i;
			T[count].exe.equipment[0].id = i;
			T[count].tempid = T[count].exe.equipment[0].id;
			read4 >> i;
			T[count].exe.duration = i;
			count++;
			ExercisePlan::exerciseCount++;
		}
	}
}

void readEquipmentsFromFile(Equipment*& Eq)
{
	int i; string s; int count = 0;
	ifstream read3;
	read3.open("equipment.txt");
	if (read3.is_open())
	{
		while (!read3.eof())
		{
			read3 >> i;
			Eq[count].setID(i);
			read3 >> s;
			Eq[count].setName(s);
			Equipment::equipmentCount++;
			count++;
		}
	}
}