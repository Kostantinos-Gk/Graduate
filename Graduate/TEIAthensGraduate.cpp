#include "TEIAthensGraduate.h"

int TEIAthensGraduate:: numOfTEIAthensGraduate = 0;

TEIAthensGraduate::TEIAthensGraduate():Graduate(){
	graduateGrade = 0.0;
	yearsOfStudies = 0.0;
	numOfTEIAthensGraduate++;
}

TEIAthensGraduate::TEIAthensGraduate(string fullName,string studentCode,double graduateGrade, double yearsOfStudies):Graduate(fullName,studentCode)
{
	this->graduateGrade = graduateGrade;
	if (graduateGrade < 5 || graduateGrade > 10)
		throw GradeException();
	this->yearsOfStudies = yearsOfStudies;
	numOfTEIAthensGraduate++;
}

TEIAthensGraduate::~TEIAthensGraduate()
{
	numOfTEIAthensGraduate--;
}

void TEIAthensGraduate::SetGraduateGrade(double graduateGrade)
{
	this->graduateGrade = graduateGrade;
	if (graduateGrade < 5 || graduateGrade > 10)
		throw GradeException();
}

void TEIAthensGraduate::SetYearsOfStudies(double yearsOfStudies)
{
	this->yearsOfStudies = yearsOfStudies;
}

double TEIAthensGraduate::GetGraduateGrade() const
{
	return graduateGrade;
}

double TEIAthensGraduate::GetYearsOfStudies() const
{
	return yearsOfStudies;
}

void TEIAthensGraduate::GraduateDisplay(ostream& left)
{
	left << "TEI ATHENS - Graduate Card \n---------------------" << endl <<
			"FullName : " << GetFullName() << endl <<
			"Student ID : " << GetStudentCode() << endl <<
			"Years Of Studies : " << GetYearsOfStudies() << endl <<
			"Grade : " << GetGraduateGrade() << endl;
}

bool TEIAthensGraduate::operator<(TEIAthensGraduate& right)
{
	return (GetGraduateGrade() < right.GetGraduateGrade());
}

bool TEIAthensGraduate::operator>(TEIAthensGraduate& right)
{
	return (GetGraduateGrade() > right.GetGraduateGrade());
}

bool TEIAthensGraduate::operator==(TEIAthensGraduate& right)
{
	return (GetGraduateGrade() == right.GetGraduateGrade());
}

ostream& operator<<(ostream& left, TEIAthensGraduate& right)
{
	right.GraduateDisplay(left);
	return left;
}
