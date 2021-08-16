//
//  Student.cpp
//  Qwirkle
//
//  Created by Philip Beeby on 18/7/21.
//

#include"Student.h"
#include <iostream>
#include <string>

Student::Student(){
    // default contructor
    this->name = new std::string("default_name");
    this->studentID = new std::string("default_StdID");
    this->email = new std::string("default_email");

}

Student::Student(std::string name, std::string studentID,std::string email){
    // constructor
    std::cout << "Creating a new Student Object: " << std::endl;
    this->name = new std::string(name);
    this->studentID = new std::string(studentID);
    this->email = new std::string(email);

}
Student::~Student(){
    // destructor
    std::cout << "Deleting Student Object and Attributes: " << std::endl;
    delete name;
    delete studentID;
    delete email;

}
void Student::setName(std::string name){
    // update the student name (prolly won't need this)
    *(this->name) = name;
    
}
void Student::setstudentID(std::string studentID){
    // update the studentID (prolly won't need this)
    *(this->studentID) = studentID;
    
}
void Student::setEmail(std::string email){
    // update the student email (prolly won't need this)
    *(this->email) = email;
    
}
std::string Student::getName(){
    return *name;
    
}
std::string Student::getstudentID(){
    return *studentID;
    
}
std::string Student::getEmail(){
    return *email;
    
}

void Student::printStudentDetails(){
    // print out all of the attributes of a student
    std::cout << "Name: " << getName() << std::endl;
    std::cout << "Student ID: " << getstudentID() << std::endl;
    std::cout << "Email: " << getEmail() << std::endl;
    
}