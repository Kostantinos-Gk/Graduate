#pragma once
#include "Graduate.h"
#include <iostream>
#include <string>

using namespace std;


class TEIPeireusGraduate : public Graduate{
public:
	static int numOfTEIPeireusGraduate;
private:
	double graduateGrade;
	double yearsOfStudies;
public:
	TEIPeireusGraduate();
	TEIPeireusGraduate(string, string, double, double);
	~TEIPeireusGraduate();

	void SetGraduateGrade(double);
	void SetYearsOfStudies(double);
	double GetGraduateGrade() const;
	double GetYearsOfStudies() const;

	friend ostream& operator<<(ostream&, TEIPeireusGraduate&);
	void GraduateDisplay(ostream&);

	bool operator<(TEIPeireusGraduate &);
	bool operator>(TEIPeireusGraduate &);
	bool operator==(TEIPeireusGraduate&);
};

