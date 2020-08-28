#include "Graduate.h"

Graduate::Graduate(){
	fullName = "Unknown";
	studentCode = "000000";
}

Graduate::Graduate(string fullName, string studentCode){
	this->fullName = fullName;
	this->studentCode = studentCode;
}

Graduate::~Graduate()
{
}

void Graduate::SetFullName(string fullName) {
	this->fullName = fullName;
}
		
string Graduate::GetFullName() const{
		return string(fullName);
}

void Graduate::SetStudentCode(string studentCode){
	this-> studentCode = studentCode;
}

string Graduate::GetStudentCode() const
{
	return string(studentCode);
}

void Graduate::GraduateDisplay(ostream& left){
	left << "Graduate Card \n_______________" << endl <<
		"FullName : " << GetFullName() << endl <<
		"Student ID : " << GetStudentCode() << endl;
}

ostream& operator<<(ostream& left, Graduate& right){
	right.GraduateDisplay(left);
	return left;
}
