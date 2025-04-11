#include <iostream>
#include <string>

using namespace std;


class Person
{
public:
	string name;
	int age;

	Person(string name, int age)
	{
		this->name = name;
		this->age = age;
	}
	~Person()
	{
		cout<<"parent deleted\n";
	}
};

class Student : public Person
{
public:
	Student(string name, int age,int rollno):Person(name, age) //Person() gets called before the Student constructor, this is used when Person() is parameterized constructor (not automatically invoked)
	{
		this->rollno = rollno;
	}
	int rollno;

	void getInfo()
	{
		cout<<"name: "<<name<<endl;
		cout<<"age: "<<age<<endl;
		cout<<"rollno: "<<rollno<<endl;
	}
	~Student()
	{
		cout<<"child deleted\n";
	}
};
int main()
{
	Student s1("rahul",21,24);
	s1.getInfo();
	return 0;
}
