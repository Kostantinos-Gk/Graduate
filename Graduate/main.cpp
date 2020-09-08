/*
	Project_1 'Graduate' - Subject July / 2020 - Object Oriented Programing - C++

	Konstantinos Gousaris - University Of West Attica
*/
#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include "Graduate.h"
#include "TEIAthensGraduate.h"
#include "TEIPeireusGraduate.h"

using namespace std;

void DisplayList(list <Graduate*> , list <Graduate*>::iterator );
void FindStudentByID(list <Graduate*> , list <Graduate*>::iterator);
double AverageGrade‘EIPeireus(list <Graduate*>, list <Graduate*>::iterator);
double AverageGrade‘EIAthens(list <Graduate*>, list <Graduate*>::iterator);
void mysortTEIPeireus(list <Graduate*>, list <Graduate*>::iterator);

//TODO 3 and 4.

int main() {
	/*
	Graduate *Maria = new TEIPeireusGraduate("Maria Oikonomidi", "000001", 5.5, 7.0);
	Graduate *Apo = new TEIPeireusGraduate("Apostolis Gakis", "234523", 8.2, 6.7);
	Graduate* Giannis = new TEIAthensGraduate("Giannis Alifantis", "000003", 8.0, 6.6);

	cout << (Giannis > Apo) << endl;
	*/
	list <Graduate *> graduateList;  //list of graduate, maube later i will need pointers
	list <Graduate *>::iterator it;
	double averageGradeTeiPeireus = 0.0;
	double averageGradeTeiAthens = 0.0;

	try {
		graduateList.push_back(new TEIPeireusGraduate("Maria Oikonomidi", "000001", 5.5, 7.0));
		graduateList.push_back(new TEIAthensGraduate("Nikos Spirou", "000002", 5.0, 7.0));
		graduateList.push_back(new TEIAthensGraduate("Giannis Alifantis", "000003", 8.0, 6.6));
		graduateList.push_back(new TEIAthensGraduate("Kyriakos Swthriou", "000004", 7.9, 5.3));
		graduateList.push_back(new TEIAthensGraduate("Dionisis Gakis", "000008", 9.8, 6.4));
		graduateList.push_back(new TEIPeireusGraduate("Apostolis Gakis", "234523", 8.2, 6.7));
		graduateList.push_back(new TEIPeireusGraduate("Marina Gazaiou", "123456", 9.0, 7.2));
		graduateList.push_back(new TEIPeireusGraduate("Trifonas Samaras", "234673", 5.5, 5.2));
		graduateList.push_back(new TEIPeireusGraduate("Sakis Rouvas", "123654", 5.5, 5.8));
	}
	catch(const GradeException &ex){
		cerr << "Error Grade Input" << endl;
	}
	

	DisplayList(graduateList,it);
	//FindStudentByID(graduateList, it);
	graduateList.sort();
	cout << "-------------------------------------------------------------------------------------------------" << endl;
	DisplayList(graduateList, it);
	averageGradeTeiAthens = AverageGrade‘EIAthens(graduateList, it);
	averageGradeTeiPeireus = AverageGrade‘EIPeireus(graduateList, it);
	cout << "-------------------------------------------------------------------------------------------------" << endl;
	cout << "Average Grade 'TEI Athens': " << averageGradeTeiAthens << endl;
	cout << "Average Grade 'TEI Peireus': " << averageGradeTeiPeireus << endl;
	cout << ((averageGradeTeiAthens > averageGradeTeiPeireus) ? "TEI ATHENS has biggest average grade" : "TEI Peireus has biggest average grade") << endl;
	cout << "\nNumber of Entries: " << graduateList.size() << endl;
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
double AverageGrade‘EIPeireus(list <Graduate*> l, list <Graduate*>::iterator it)
{ 
	double averageGrade = 0;
	double sum = 0;
	for (it = l.begin(); it != l.end(); it++)
	{
		if ((*it)->GetGraduateGrade() && dynamic_cast<TEIPeireusGraduate*>(*it))
		sum = sum + (*it)->GetGraduateGrade();
	}

	averageGrade = sum / TEIPeireusGraduate::numOfTEIPeireusGraduate;
	return averageGrade;
}
double AverageGrade‘EIAthens(list <Graduate*> l, list <Graduate*>::iterator it)
{
	double averageGrade = 0;
	double sum = 0;
	for (it = l.begin(); it != l.end(); it++)
	{
		if((*it)->GetGraduateGrade() && dynamic_cast<TEIAthensGraduate*>(*it))
			sum = sum + (*it)->GetGraduateGrade();
	}

	averageGrade = sum / TEIAthensGraduate::numOfTEIAthensGraduate;
	return averageGrade;
}
void mysortTEIPeireus(list <Graduate*> l, list <Graduate*>::iterator it) 
{


}