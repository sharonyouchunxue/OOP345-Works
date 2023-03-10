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
#ifndef SDDS_PROFESSOR_H
#define SDDS_PROFESSOR_H
#include "Employee.h"

namespace sdds {
   //inherit Employee
   class Professor : public Employee {
      // the department the professor works at
      std::string m_department{};
   public:
      //read professor information
      Professor(std::istream& in);
      void display(std::ostream& out) const;
      std::string status() const;
      std::string department() const;
   };

}
#endif // !SDDS_PROFESSOR_H
