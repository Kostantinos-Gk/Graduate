#include "TEIPeireusGraduate.h"
TEIPeireusGraduate::TEIPeireusGraduate(){
	graduateGrade = 0.0;
	yearsOfStudies = 0.0;
}

TEIPeireusGraduate::TEIPeireusGraduate(string fullName, string studentCode, double graduateGrade, double yearsOfStudies):Graduate(fullName,studentCode)
{
	this->graduateGrade = graduateGrade;
	if (graduateGrade < 5 || graduateGrade > 10)
		throw GradeException();
	this->yearsOfStudies = yearsOfStudies;
}

TEIPeireusGraduate::~TEIPeireusGraduate()
{
}

void TEIPeireusGraduate::SetGraduateGrade(double graduateGrade)
{
	this->graduateGrade = graduateGrade;
	if (graduateGrade < 5 || graduateGrade > 10)
		throw GradeException();
}

void TEIPeireusGraduate::SetYearsOfStudies(double yearsOfStudies)
{
	this->yearsOfStudies = yearsOfStudies;
}

double TEIPeireusGraduate::GetGraduateGrade() const
{
	return graduateGrade;
}

double TEIPeireusGraduate::GetYearsOfStudies() const
{
	return yearsOfStudies;
}

void TEIPeireusGraduate::GraduateDisplay(ostream& left)
{
	left << "TEI PEIREUS - Graduate Card \n---------------------" << endl <<
			"FullName : " << GetFullName() << endl <<
			"Student ID : " << GetStudentCode() << endl <<
			"Years Of Studies : " << GetYearsOfStudies() << endl <<
			"Grade : " << GetGraduateGrade() << endl;
}

bool TEIPeireusGraduate::operator<(TEIPeireusGraduate& right)
{
	return (GetGraduateGrade() < right.GetGraduateGrade());
}

bool TEIPeireusGraduate::operator>(TEIPeireusGraduate& right)
{
	return (GetGraduateGrade() > right.GetGraduateGrade());
}
ostream& operator<<(ostream& left, TEIPeireusGraduate& right)
{
	right.GraduateDisplay(left);
	return left;
}
