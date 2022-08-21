#include<iostream>
#include<stdlib.h>
#include<fstream>
#include <string>

using namespace std;

struct customer {
	string id;
	string age;
	string sex;
	string region;
	string income;
	string married;
	string children;
	string car;
	string save_act;
	string current_act;
	string mortgage;
	int ageRisk =0 ;
	int sexRisk=0;
	int regionRisk=0;
	int incomeRisk=0;
	int marriedRisk=0;
	int childrenRisk=0;
	int carRisk=0;
	int save_actRisk=0;
	int current_actRisk=0;
	int mortgageRisk=0;
	bool isApproved=false;
	int totalRisk=0;
};
struct denied {
	int priority=0;
	struct customer cust;
	denied* next_denied = {};
};

denied* front_denied = NULL;
struct approved {
	int priority=0;
	struct customer cust;
	approved *next_approved = {};
};

approved* front_approved = NULL;


//insert into the approved linked list
void insert_approved(int priority, struct customer cust) {
	approved *tmp, *rear;
	tmp = new approved;
	tmp->cust = cust;
	tmp->priority = priority;
	if (front_approved == NULL || priority > front_approved->priority) {
		tmp->next_approved = front_approved;
		front_approved = tmp;
	}
	else {
		rear = front_approved;
		while (rear->next_approved != NULL && rear->next_approved->priority >= priority) {
			rear = rear->next_approved;
		}
		tmp->next_approved = rear->next_approved;
		rear->next_approved = tmp;
	}
}
//insert into the denied linked list
void insert_denied(int priority, struct customer cust) {
	denied* tmp, *rear;
	tmp = new denied;
	tmp->cust = cust;
	tmp->priority = priority;
	if (front_denied == NULL || priority > front_denied->priority) {
		tmp->next_denied = front_denied;
		front_denied = tmp;
	}
	else {
		rear = front_denied;
		while (rear->next_denied != NULL && rear->next_denied->priority >= priority) {
			rear = rear->next_denied;
		}
		tmp->next_denied = rear->next_denied;
		rear->next_denied = tmp;
	}
}
// display customer with highest priority
void display_high_app() {
	approved* ptr;
	ptr = front_approved;
	cout << "id: " << ptr->cust.id << "\n";
	cout << "age: " << ptr->cust.age << "\n";
	cout << "sex: " << ptr->cust.sex << "\n";
	cout << "region: " << ptr->cust.region << "\n";
	cout << "income: " << ptr->cust.income << "\n";
	cout << "married: " << ptr->cust.married << "\n";
	cout << "children: " << ptr->cust.children << "\n";
	cout << "car: " << ptr->cust.car << "\n";
	cout << "save_act: " << ptr->cust.save_act << "\n";
	cout << "current_act: " << ptr->cust.current_act << "\n";
	cout << "mortgage: " << ptr->cust.mortgage << "\n";
	cout << "totalRisk: " << ptr->cust.totalRisk << "\n";
	cout << "isApproved?: " << ptr->cust.isApproved << "\n\n";
}
// display customer with highest priority in the denied queue
void display_high_denied() {
	denied* ptr;
	ptr = front_denied;
	cout << "id: " << ptr->cust.id << "\n";
	cout << "age: " << ptr->cust.age << "\n";
	cout << "sex: " << ptr->cust.sex << "\n";
	cout << "region: " << ptr->cust.region << "\n";
	cout << "income: " << ptr->cust.income << "\n";
	cout << "married: " << ptr->cust.married << "\n";
	cout << "children: " << ptr->cust.children << "\n";
	cout << "car: " << ptr->cust.car << "\n";
	cout << "save_act: " << ptr->cust.save_act << "\n";
	cout << "current_act: " << ptr->cust.current_act << "\n";
	cout << "mortgage: " << ptr->cust.mortgage << "\n";
	cout << "totalRisk: " << ptr->cust.totalRisk << "\n";
	cout << "isApproved?: " << ptr->cust.isApproved << "\n\n";
}
// display approved customer
void display_approved() {
	approved* ptr;
	ptr = front_approved;
	if (front_approved == NULL) {
		cout << "the queue is empty\n";
	}
	else {
		cout << "the lsit of approved customer is: \n";
		while (ptr != NULL)
		{
			cout << "id: " << ptr->cust.id << "\n";
			cout << "age: " << ptr->cust.age << "\n";
			cout << "sex: " << ptr->cust.sex << "\n";
			cout << "region: " << ptr->cust.region << "\n";
			cout << "income: " << ptr->cust.income << "\n";
			cout << "married: " << ptr->cust.married << "\n";
			cout << "children: " << ptr->cust.children << "\n";
			cout << "car: " << ptr->cust.car << "\n";
			cout << "save_act: " << ptr->cust.save_act << "\n";
			cout << "current_act: " << ptr->cust.current_act << "\n";
			cout << "mortgage: " << ptr->cust.mortgage << "\n";
			cout << "totalRisk: " << ptr->cust.totalRisk << "\n";
			cout << "isApproved?: " << ptr->cust.isApproved << "\n\n";
			ptr = ptr->next_approved;

		}
	}
}
// display approved customer
void display_denied() {
	denied* ptr;
	ptr = front_denied;
	if (front_denied == NULL) {
		cout << "the queue is empty\n";
	}
	else {
		cout << "the lsit of denied customer is: \n";
		while (ptr != NULL)
		{
			cout << "id: " << ptr->cust.id << "\n";
			cout << "age: " << ptr->cust.age << "\n";
			cout << "sex: " << ptr->cust.sex << "\n";
			cout << "region: " << ptr->cust.region << "\n";
			cout << "income: " << ptr->cust.income << "\n";
			cout << "married: " << ptr->cust.married << "\n";
			cout << "children: " << ptr->cust.children << "\n";
			cout << "car: " << ptr->cust.car << "\n";
			cout << "save_act: " << ptr->cust.save_act << "\n";
			cout << "current_act: " << ptr->cust.current_act << "\n" ;
			cout << "mortgage: " << ptr->cust.mortgage << "\n";
			cout << "totalRisk: " << ptr->cust.totalRisk << "\n";
			cout << "isApproved?: " << ptr->cust.isApproved << "\n\n";
			ptr = ptr->next_denied;

		}
	}
}
// create approved csv
void create_approved(string temp)
{
	fstream fout;

	fout.open("approved.csv", ios::out );

	approved* ptr;
	ptr = front_approved;
	if (front_approved == NULL) {
		fout << "the queue is empty\n";
		fout.close();
	}
	else {
		fout << temp <<",totalRisk,isApproved \n";
		while (ptr != NULL)
		{
			fout << ptr->cust.id 
				<< "," << ptr->cust.age
				<< "," << ptr->cust.sex
				<< "," << ptr->cust.region
				<< "," << ptr->cust.income
				<< "," << ptr->cust.married
				<< "," << ptr->cust.children
				<< "," << ptr->cust.car
				<< "," << ptr->cust.save_act
				<< "," << ptr->cust.current_act
				<< "," << ptr->cust.mortgage
				<< "," << ptr->cust.totalRisk
				<< "," << ptr->cust.isApproved << "\n";
			ptr = ptr->next_approved;

		}
		fout.close();
	}
}
// create denied csv
void create_denied(string temp)
{
	fstream fout;

	fout.open("denied.csv", ios::out );

	denied* ptr;
	ptr = front_denied;
	if (front_denied == NULL) {
		fout << "the queue is empty\n";
		fout.close();
	}
	else {
		fout << temp << ",totalRisk,isApproved \n";
		while (ptr != NULL)
		{
			fout << ptr->cust.id
				<< "," << ptr->cust.age
				<< "," << ptr->cust.sex
				<< "," << ptr->cust.region
				<< "," << ptr->cust.income
				<< "," << ptr->cust.married
				<< "," << ptr->cust.children
				<< "," << ptr->cust.car
				<< "," << ptr->cust.save_act
				<< "," << ptr->cust.current_act
				<< "," << ptr->cust.mortgage
				<< "," << ptr->cust.totalRisk
				<< "," << ptr->cust.isApproved << "\n";
			ptr = ptr->next_denied;

		}
		fout.close();
	}
}
int main() {
	string id;
	string age;
	string sex;
	string region;
	string income;
	string married;
	string children;
	string car;
	string save_act;
	string current_act;
	string mortgage;
	string temp;

	int lowest = 1, highest = 10;
	int range = (highest - lowest) + 1;
	ifstream file("bank-data.csv");
	int count = 0;
	if (file.is_open()) {
		while (!file.eof()) {

			if (count == 0)
			{
				
				getline(file, temp);
				count = 1;
			}
			else {
				customer cust ;
				getline(file, id, ',');
				getline(file, age, ',');
				getline(file, sex, ',');
				getline(file, region, ',');
				getline(file, income, ',');
				getline(file, married ,',');
				getline(file, children, ',');
				getline(file, car, ',');
				getline(file, save_act, ',');
				getline(file, current_act ,',');
				getline(file, mortgage, '\n');
				
				cust.id = id;
				cust.age = age;
				cust.sex = sex;
				cust.region = region;
				cust.income = income;
				cust.married = married;
				cust.children = children;
				cust.car = car;
				cust.save_act = save_act;
				cust.current_act = current_act;
				cust.mortgage = mortgage;
				cust.ageRisk = lowest + rand() % range;
				cust.sexRisk = lowest + rand() % range;
				cust.regionRisk = lowest + rand() % range;
				cust.incomeRisk = lowest + rand() % range;
				cust.marriedRisk = lowest + rand() % range;
				cust.childrenRisk = lowest + rand() % range;
				cust.carRisk = lowest + rand() % range;
				cust.save_actRisk = lowest + rand() % range;
				cust.current_actRisk = lowest + rand() % range;
				cust.mortgageRisk = lowest + rand() % range;

				cust.totalRisk = (cust.ageRisk + cust.sexRisk + cust.regionRisk + cust.incomeRisk + 
					cust.marriedRisk + cust.childrenRisk + cust.carRisk + cust.save_actRisk + cust.current_actRisk 
					+ cust.mortgageRisk)/10;
				
				if (cust.totalRisk < 5) {
					cust.isApproved = false;
					insert_denied(cust.totalRisk, cust);
				}
				else {
					cust.isApproved = true;
					insert_approved(cust.totalRisk, cust);
				}
				}

			}
		}

	int choice;
	do {
		cout << "1. Display Approved Customers Queue\n";
		cout << "2. Display denied Customers Queue\n";
		cout << "3. save queue to csv\n";
		cout << "4. Display customer with the highest priority\n";
		cout << "5. Display customer with the highest priority in denied queue\n";
		cout << "6. Exit \n";
		cin >> choice;
		switch(choice)
		{
		case 1:
			display_approved();
			break;
		case 2:
			display_denied();
			break;
		case 3:
			create_approved(temp);
			create_denied(temp);
			cout << "Successfully saved to file \n";
		case 4:
			display_high_app();
			break;
		case 5:
			display_high_denied();
			break;
		case 6:
			break;
		default:
			cout << "wrong choice enter valid choice\n";
		}
	} while (choice != 6);
	
	}

