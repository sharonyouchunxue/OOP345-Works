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
#include <iomanip>
#include <stdexcept>
#include <sstream>
#include <string>
#include "Employee.h"
namespace sdds {
   //default constructor
   Employee::Employee() {}

   //one argument constructor to read sigle record
   Employee::Employee(std::istream& istr) {
      // read name
      getline(istr, m_name, ',');
      m_name = removeSpace(m_name);

      //read age
<<<<<<< HEAD
         getline(istr, m_age, ',');
         m_age = removeSpace(m_age);
         //check if it is integer, if not throw message
         if (!isInteger(m_age)) {
            throw std::invalid_argument(m_name + "++Invalid record!");
         }
     
      // read Employee id  
=======
      getline(istr, m_age, ',');
      m_age = removeSpace(m_age);
      //check if it is integer, if not throw message
      if (!isInteger(m_age)) {
         throw std::invalid_argument(m_name + "++Invalid record!");
      }

      // read Employee id
>>>>>>> d554acd97bb1b4d248ad347749844cdd1207b7f1
         getline(istr, m_id, ',');
         m_id = removeSpace(m_id);
         //check validation with letter E 
         if (m_id.empty() || m_id[0]!= 'E') {
            throw std::invalid_argument(m_name + "++Invalid record!");
      }
<<<<<<< HEAD
=======
     
>>>>>>> d554acd97bb1b4d248ad347749844cdd1207b7f1
}

   //returns the string Employee
   std::string Employee::status() const{
      return std::string("Employee");
   }

   //returns the name of the employee
   std::string Employee::name() const{
      return m_name;
   }

   //returns the id of the employee
   std::string Employee::id() const{
      return m_id;
   }

   //returns the age of the employee
   std::string Employee::age() const{
      return m_age;
   }

   //print Employee recod in format
   void Employee::display(std::ostream& out) const{
      out << "| " << std::left << std::setw(10) << Employee::status()
<<<<<<< HEAD
         << "| " << std::left << std::setw(10) << id()
         << "| " << std::left << std::setw(20) << name()
         << " | " << std::left << std::setw(3) << age() << " |";
=======
         << " | " << std::left << std::setw(10) << id()
         << " | " << std::left << std::setw(20) << name()
         << " | " << std::right << std::setw(3) << age() << " |";
>>>>>>> d554acd97bb1b4d248ad347749844cdd1207b7f1
   }

   //check if id is integer
   bool Employee::isInteger(std::string& str) const{
      bool res = true;
      for (size_t i = 0u; i < str.size() && res; i++) {
         if (!isdigit(str[i])) {
            res = false;
         }
      }
      return res;
   }

   //remove all leading space 
   std::string Employee::removeSpace(const std::string& str){
      size_t first = str.find_first_not_of(' ');
      if (std::string::npos == first) {
         return str;
      }
      size_t last = str.find_last_not_of(' ');
      return str.substr(first, (last - first + 1));
   }

}
