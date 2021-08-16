//
//  Student.h
//  Qwirkle
//
//  Created by Philip Beeby on 18/7/21.
//

#ifndef Student_h
#define Student_h

#include <stdio.h>
#include <string>
class Student
{
public:
    //default constructor
    Student();
    //constructor
    Student(std::string name, std::string studentID,std::string email);
    //destructor
    ~Student();
    //copy constructor
    Student(Student& other);
    // setters
    void setName(std::string name);
    void setstudentID(std::string studentID);
    void setEmail(std::string email);
 
    // getters
    std::string getName();
    std::string getstudentID();
    std::string getEmail();
    //other
    void printStudentDetails();

private:
    // these have to be pointers so we can create class attributes on the heap
    std::string* name;
    std::string* studentID;
    std::string* email;
};

#endif /* Student_h */