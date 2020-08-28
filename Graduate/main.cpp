/*
	Project_1 'Graduate' - Subject July / 2020 - Object Oriented Programing - C++

	Konstantinos Gousaris - University Of West Attica
*/
#include <iostream>
#include <string>
#include <list>
#include "Graduate.h"
#include "TEIAthensGraduate.h"
#include "TEIPeireusGraduate.h"

using namespace std;

void DisplayList(list <Graduate*> , list <Graduate*>::iterator );
void FindStudentByID(list <Graduate*> , list <Graduate*>::iterator);
double AverageGrade(list <Graduate*>, list <Graduate*>::iterator);



int main() {
	/*
	Graduate *Maria = new TEIPeireusGraduate("Maria Oikonomidi", "000001", 5.5, 7.0);
	Graduate *Apo = new TEIPeireusGraduate("Apostolis Gakis", "234523", 8.2, 6.7);
	Graduate* Giannis = new TEIAthensGraduate("Giannis Alifantis", "000003", 8.0, 6.6);

	cout << (Giannis > Apo) << endl;
	*/
	list <Graduate *> graduateList;  //list of graduate, maube later i will need pointers
	list <Graduate *>::iterator it;
	try {
		graduateList.push_back(new TEIPeireusGraduate("Maria Oikonomidi", "000001", 5.5, 7.0));
		graduateList.push_back(new TEIAthensGraduate("Nikos Spirou", "000002", 4.0, 11.0));
		graduateList.push_back(new TEIAthensGraduate("Giannis Alifantis", "000003", 8.0, 6.6));
		graduateList.push_back(new TEIAthensGraduate("Kyriakos Swthriou", "000004", 7.9, 5.3));
		graduateList.push_back(new TEIAthensGraduate("Dionisis Gakis", "000008", 9.8, 6.4));
		graduateList.push_back(new TEIPeireusGraduate("Apostolis Gakis", "234523", 8.2, 6.7));
		graduateList.push_back(new TEIPeireusGraduate("Marina Gazi", "123456", 9.0, 7.2));
		graduateList.push_back(new TEIPeireusGraduate("Trifonas Samaras", "234673", 5.5, 5.2));
		graduateList.push_back(new TEIPeireusGraduate("Sakis Rouvas", "123654", 5.5, 5.8));
	}
	catch(const GradeException &ex){
		cerr << "Error Grade Input" << endl;
	}
	
	cout << "\nNumber of Entries: " << graduateList.size() << endl;
	DisplayList(graduateList,it);
	//FindStudentByID(graduateList, it);
	//graduateList.sort();
	//DisplayList(graduateList, it);
	cout << "Bye" << endl;

	//delete Maria;
	//delete Apo;
	//delete Giannis;
	return 0;
}

void DisplayList(list<Graduate*> l, list <Graduate*>::iterator it){
	it = l.begin();

	while (it != l.end()) {
		(*it)->GraduateDisplay(cout);
		it++;
	}
}
void FindStudentByID(list <Graduate*> l, list <Graduate*>::iterator it)
{	
	bool found = false;
	char choice;
	do {
		string id;
		cout << "Enter Student ID : ";
		cin >> id;
		for (it = l.begin(); it != l.end(); it++) {
			if (id == (*it)->GetStudentCode()) {
				found = true;
				(*it)->GraduateDisplay(cout);
			}
		}
		if (!found)
		{
			cout << "There is no person with that ID" << endl;
		}
		cout << "Exit(Y/y) :";
		cin >> choice; 
	} while (choice != 'Y' && choice != 'y');

}
double AverageGrade(list <Graduate*> l, list <Graduate*>::iterator it)
{ 
	double averageGrade = 0;
	double sum = 0;
	for (it = l.begin(); it != l.end(); it++)
	{
		sum = sum + (*it)->GetGraduateGrade();
	}

}