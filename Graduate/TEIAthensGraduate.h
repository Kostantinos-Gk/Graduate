#pragma once
#include "Graduate.h"
#include <iostream>
#include <string>

using namespace std;


class TEIAthensGraduate : public Graduate {
public:
	static int numOfTEIAthensGraduate;
private:
	double graduateGrade;
	double yearsOfStudies;
public:
	TEIAthensGraduate();
	TEIAthensGraduate(string,string, double, double);
	~TEIAthensGraduate();

	void SetGraduateGrade(double); 
	void SetYearsOfStudies(double);
	double GetGraduateGrade() const;
	double GetYearsOfStudies() const;

	friend ostream& operator<<(ostream&, TEIAthensGraduate &);
	void GraduateDisplay(ostream&);

	bool operator<(TEIAthensGraduate &);
	bool operator>(TEIAthensGraduate &);
	bool operator==(TEIAthensGraduate&);
};

