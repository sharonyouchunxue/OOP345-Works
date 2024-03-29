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
#include <string>
#include <sstream>
#include "Student.h"
namespace sdds {
   //default constructor
   Student::Student() {}

   //read record
   Student::Student(std::istream& istr) {
      // get name
      getline(istr, m_name, ',');
      m_name = removeSpace(m_name);

      //get age
      getline(istr, m_age, ',');
      m_age = removeSpace(m_age);
      if (!isInteger(m_age)) {
         throw std::invalid_argument(m_name + "++Invalid record!");
      }

      // get id
      getline(istr, m_id, ',');
      m_id = removeSpace(m_id);
      // code that might throw an exception
      if (m_id.empty() || m_id[0] != 'S') {
         throw std::invalid_argument(m_name + "++Invalid record!");
      }

      //number of course
      std::string num_course, course_list;
      getline(istr, num_course, ',');
      std::stringstream ss;
      ss << num_course;
      ss >> m_count;
      if (ss.fail() || m_count < 0) {
         throw m_name + " ++Invalid record!";
      }

      // check if line has ended and remove any extra commas
      std::getline(istr, course_list);
      course_list = removeSpace(course_list);

      // allocate memory for courses array and parse course list   
      if (m_count != 0) {
         std::stringstream course_ss(course_list);
         m_courses = new std::string[m_count];
         for (size_t i = 0; i < m_count; ++i) {
            std::getline(course_ss, m_courses[i], ',');
            if (!course_list.empty()) {
               m_courses[i] = removeSpace(m_courses[i]);
            }
         }
      }
   }

   //returns the word Student
   std::string Student::status() const {
      return std::string("Student");
   }

   //return name of the student
   std::string Student::name() const {
      return m_name;
   }

   //return student age
   std::string Student::age() const {
      return m_age;
   }

   //return id
   std::string Student::id() const {
      return m_id;
   }

   //print the student record in format
   void Student::display(std::ostream& out) const {
      out << "| " << std::left << std::setw(10) << status()
         << "| " << std::left << std::setw(10) << id()
         << "| " << std::left << std::setw(20) << name()
         << " |" << std::right << std::setw(3) << age() << "  |";
      for (size_t i = 0; i < m_count; i++) {
         out << std::right << m_courses[i];
         if (i < m_count - 1) {
            out << ", ";
         }
      }
   }

   //destructor
   Student::~Student() {
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