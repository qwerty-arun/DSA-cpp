#include <iostream>
#include <string>

using namespace std;


class Student
{
public:
	string name;
	double* cgpaPtr;

	Student(string name, double cgpa)
	{
		this->name = name;
		cgpaPtr = new double;
		*cgpaPtr = cgpa;
	}

	void getInfo()
	{
		cout<<"Name: "<<name<<endl;
		cout<<"Cgpa: "<<*cgpaPtr<<endl;
	}
};
int main()
{
	Student s1("Rahul",7.9);

	Student s2(s1);
	s2.getInfo();
	return 0;
}
