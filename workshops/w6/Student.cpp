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
#include <iomanip>
#include <stdexcept>
#include <string>
#include <sstream>
#include "Student.h"
namespace sdds {
   Student::Student(){}

   Student::Student(std::istream& istr){
      // get name
      getline(istr, m_name, ',');
      m_name = removeSpace(m_name);

      //get age
      try {
         getline(istr, m_age, ',');
         m_age = removeSpace(m_age);
         if (!isInteger(m_age)) {
            throw std::invalid_argument(m_name + "++Invalid record!");
         }
      }
      catch (const std::invalid_argument& e) {
         // handle the exception here
         std::cerr << "Exception caught: " << e.what() << std::endl;
      }

      // get id
      try {
         getline(istr, m_id, ',');
         m_id = removeSpace(m_id);
         // code that might throw an exception
         if (m_id.empty() || m_id[0] != 'S') {
            throw std::invalid_argument(m_name + "++Invalid record!");
         }
      }
      catch (const std::invalid_argument& e) {
         // handle the exception here
         std::cerr << "Exception caught: " << e.what() << std::endl;
      }

      //number of course
      std::string num_course, course_list;
      getline(istr, num_course, ',');
      std::stringstream ss;
      ss << m_age << ' ' << num_course;
   
      ss >> m_count;
      if (ss.fail() || m_count < 0) {
         throw m_name + " ++Invalid record!";
      }

      // allocate memory for courses array and parse course list
      m_courses = new std::string[m_count];
      std::stringstream course_ss(course_list);
      for (int i = 0; i < m_count; ++i) {         
         std::getline(istr, m_courses[i]);
         m_courses[i] = removeSpace( m_courses[i]);
      }
 
   }

   //returns the word Student
   std::string Student::status() const{
      return std::string("Student");
   }

   //return name of the student
   std::string Student::name() const{
      return m_name;
   }

   //return student age
   std::string Student::age() const{
      return m_age;
   }

   //return id
   std::string Student::id() const{
      return m_id;
   }

   //print the student record in format
   void Student::display(std::ostream& out) const{     
      out << "| " << std::left << std::setw(10) << status()
         << " | " << std::left << std::setw(10) << id()
         << " | " << std::left << std::setw(20) << name()
         << " | " << std::right << std::setw(3) << age() << " | ";
      for (int i = 0; i < m_count; i++) {
         out << std::right << m_courses[i];
      }     
   }

   //destructor
   Student::~Student(){
      delete[] m_courses;
   }

   //check if it is integer
   bool Student::isInteger(std::string& str) const {
      bool res = true;
      for (size_t i = 0u; i < str.size() && res; i++) {
         if (!isdigit(str[i])) {
            res = false;
         }
      }
      return res;
   }

   //remove all the leading spaces
   std::string Student::removeSpace(const std::string& str) {
      size_t first = str.find_first_not_of(' ');
      if (std::string::npos == first) {
         return str;
      }
      size_t last = str.find_last_not_of(' ');
      return str.substr(first, (last - first + 1));
   }

}