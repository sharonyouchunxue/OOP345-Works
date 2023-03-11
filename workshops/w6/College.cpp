/*
*****************************************************************************
                        Workshop 6
Full Name  : Chunxue You
Student ID#: 127632214
Email      : cyou8@myseneca.ca
Section    : OOP244 NRA
Date       : 2023-03-11
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. I have done all
the coding by myself and only copied the code that my professor provided to
complete my workshops and assignments.
*****************************************************************************
*/
#include <iostream>
#include <vector>
#include <iomanip>
#include "College.h"
namespace sdds {
   //default constructor
   College::College(){}

   //adds the address of the person object received as parameter into the m_persons vector.
   College& sdds::College::operator+=(Person* thePerson) {
      m_persons.push_back(thePerson);
      return *this;
   }

   void sdds::College::display(std::ostream& out) const{
      out << "------------------------------------------------------------------------------------------------------------------------" << std::endl;
      out << "|                                        Test #1 Persons in the college!                                               |" << std::endl;
      out << "------------------------------------------------------------------------------------------------------------------------" << std::endl;
      //Person::display() for the first test
      for (size_t i = 0u; i < m_persons.size(); i++) {
         m_persons[i]->display(out);
         out << std::endl;
      }
      out << "------------------------------------------------------------------------------------------------------------------------" << std::endl;
      out << "|                                        Test #2 Persons in the college!                                               |" << std::endl;
      out << "------------------------------------------------------------------------------------------------------------------------" << std::endl;
      //other public functions for the second test
      for (const auto& person : m_persons) {
         out << "| " << std::left << std::setw(10) << person->status()
            << "| " << std::left << std::setw(10) << person->id()
            << "| " << std::left << std::setw(20) << person->name()
            << " | " << std::left << std::setw(3) << person->age() << " |" << std::endl;
      }
      out << "------------------------------------------------------------------------------------------------------------------------" << std::endl;
   }

   //destructor
   sdds::College::~College(){
      for (size_t i = 0u; i < m_persons.size(); i++) {
         delete m_persons[i];
         m_persons[i] = nullptr;
      }
   }

}
