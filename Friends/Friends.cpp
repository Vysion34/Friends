// Friends.cpp : Defines the entry point for the console application.

/*
Dean Hartfield

11-4-2015

Module 05 Assignment - Demonstrate the Use of Friend Functions

Your programming assignment is to:

1. Create an application that declares a class, and in it two friend functions.
2. Declare and implement one friend function in such way that, you shouldn't be able to modify, 
   but only read the class attributes.
3. Declare and implement the other friend function in such way that, you should be able to both 
   read and modify the class attributes.
4. In the main() function, create an object of the class. Call your two friend functions using 
   that object as an argument to demonstrate the use of the friend functions.
5. Add plenty of narrative comments.
6. Your program must be compilable and executable.
*/


#include "stdafx.h"
#include <iostream>
#include <string>


// Person class
class Person {
	std::string name;
	int age;
public:
	void setName(std::string inName);
	void setAge(int inAge);
	friend void printPersonDetails(Person person);
	friend void modifyPersonDetails(Person person, std::string name, int age);
};


// Set name member setter
void Person::setName(std::string inName) {
	name = inName;
}


// Set age member setter
void Person::setAge(int inAge) {
	age = inAge;
}


// Friend function to print the details of the Person object
void printPersonDetails(Person person) {
	std::cout << "Name: " << person.name << std::endl << "Age: " << person.age << std::endl;
}


// Friend function to modify and then print the details of the Person object
void modifyPersonDetails(Person person, std::string name, int age) {
	person.name = name;
	person.age = age;

	std::cout << "Modified Name: " << person.name << std::endl << "Modified Age: " << person.age << std::endl;
}


int main()
{
	// Create new person and assign name and age
	Person person;
	person.setName("Dean");
	person.setAge(34);

	// Print the person details
	printPersonDetails(person);

	std::cout << std::endl;

	// Modify the person object and print the modified details
	modifyPersonDetails(person, "Bob", 50);

	std::cout << std::endl;
	system("pause");
	return 0;
}
