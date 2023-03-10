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
#include <iostream>
#include <string>
#include "Professor.h"

namespace sdds {
   // calls the constructor from Employee to build the sub-object, 
   //and then it extracts the last field from the stream containing the department
   Professor::Professor(std::istream& in):Employee(in){
      getline(in, m_department, ',');
   }

   void Professor::display(std::ostream& out)const {
      //calls Employee::display() to print the information about the Employee
      Employee::display(out);
      out << m_department << "| Professor";
   }

   // returns word Professor
   std::string Professor::status() const{
      return std::string("Professor");
   }

   //returns the department
   std::string Professor::department() const{
      return m_department;
   }
}