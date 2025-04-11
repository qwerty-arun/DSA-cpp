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
	}
	void hello()
	{
		cout<<"Hello from parent\n";
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
	}
	void hello()
	{
		cout<<"Hello from child\n";
	}
};
int main()
{
	Person s1("rahul",21);
	s1.hello();
	return 0;
}
