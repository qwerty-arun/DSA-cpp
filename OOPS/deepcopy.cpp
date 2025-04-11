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

	Student(Student &obj) //Deep Copy constructor
	{
		this->name = obj.name;
		cgpaPtr = new double;
		*cgpaPtr = *(obj.cgpaPtr);
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
	s1.getInfo();

	*(s2.cgpaPtr) = 9.2;
	s2.name = "Neha";
	s2.getInfo();
	return 0;
}
