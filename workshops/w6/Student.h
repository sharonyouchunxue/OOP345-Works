/*
*****************************************************************************
                        Workshop 6
Full Name  : Chunxue You
Student ID#: 127632214
Email      : cyou8@myseneca.ca
Section    : OOP244 NRA
Date       : 2023-03-04
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. I have done all
the coding by myself and only copied the code that my professor provided to
complete my workshops and assignments.
*****************************************************************************
*/
#ifndef SDDS_STUDENT_H
#define SDDS_STUDENT_H
#include "Person.h"
namespace sdds {
   // inherits the abstract class Person
   class Student : public Person{
      std::string m_name{};
      std::string m_age{};
      std::string m_id{};
      std::string* m_courses{};//dynamically allocated array of strings
      size_t m_count{};//number of courses in the array
   public:
      Student();
      //read student record
      Student(std::istream& istr);
      std::string status() const;
      std::string name() const;
      std::string age() const;
      std::string id()const;
      void display(std::ostream& out) const;
      bool isInteger(std::string& str)const;
      std::string removeSpace(const std::string& str);
      ~Student();

      // Disable copy operations
      Student(const Student&) = delete;
      Student& operator=(const Student&) = delete;
   };








}
#endif // !SDDS_STUDENT_H
