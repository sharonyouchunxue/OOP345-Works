/*
*****************************************************************************
                        Workshop 6
Full Name  : Chunxue You
Student ID#: 127632214
Email      : cyou8@myseneca.ca
Section    : OOP244 NRA
Date       : 2023-03-01
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. I have done all
the coding by myself and only copied the code that my professor provided to
complete my workshops and assignments.
*****************************************************************************
*/
#include <sstream>
#include "Utilities.h"
#include "Employee.h"
#include "Professor.h"
#include "Student.h"

namespace sdds {

   Person* sdds::buildInstance(std::istream& in) {
      Person* ps = nullptr;

      std::string str = "";
      char tag = ' ';
      std::getline(in, str);
      std::stringstream ss(str);

      ss >> tag;
      ss.ignore(1000, ',');
      if (ss) {
         switch (tag) {
         case 'e':
         case 'E':
            return new Employee(ss);
            break;

         case 'p':
         case 'P':
            return new Professor(ss);
            break;
   
         case 's':
         case 'S':
            return new Student(ss);
            break;  
         }
      }
      return ps;
   }
}