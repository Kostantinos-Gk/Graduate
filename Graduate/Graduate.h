#pragma once
#include <iostream>
#include <string>

using namespace std;

class Graduate{
private:
	string fullName;
	string studentCode;
public:
	Graduate();
	Graduate(string ,string );
	virtual ~Graduate();

	void SetFullName(string);
	string GetFullName() const;
	void SetStudentCode(string);
	string GetStudentCode()const;

	friend ostream& operator<<(ostream&, Graduate&);
	virtual void GraduateDisplay(ostream&);

	virtual double GetGraduateGrade() const = 0;
	
};
class GradeException {

};

