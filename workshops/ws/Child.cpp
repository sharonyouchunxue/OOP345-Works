/*
*****************************************************************************
                        Workshop 4
Full Name  : Chunxue You
Student ID#: 127632214
Email      : cyou8@myseneca.ca
Section    : OOP244 NRA
Date       : 2023-02-6
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. I have done all
the coding by myself and only copied the code that my professor provided to
complete my workshops and assignments.
*****************************************************************************
*/
#include <iostream>
#include "Child.h"

namespace sdds {
   //default constructor
   Child::Child() {
   }

   //four argument constructor to copy the value from class
   Child::Child(std::string name, int age, const Toy* toys[], size_t count){    
         m_toy = new const Toy*[count]; 
         for (size_t i = 0; i < count; i++) { 
            m_toy[i] = new Toy(*(toys[i])); 
         }
      //copy all other varibale to be stored
      m_name = name;
      m_age = age;
      m_noOfToys = count;
   }

   //Rule of five
   //1.copy constructor
   Child::Child(const Child& C) {
      operator = (C);
   }

   //2. copy assignment operator
   Child& Child::operator=(const Child& C) {
      if (this != &C)
      {
         for (size_t i = 0; i < m_noOfToys; ++i) {
            delete m_toy[i];
         }
            
         delete[] m_toy;
         m_noOfToys = C.m_noOfToys;

         m_age = C.m_age;
         m_name = C.m_name;

         m_toy = new const Toy * [m_noOfToys];
         for (size_t i = 0; i < m_noOfToys; i++) {
            m_toy[i] = new Toy(*(C.m_toy[i]));
         }
        }
      return *this;
   }

   //3. move copy constructor
   Child::Child(Child&& C)noexcept {
      operator=(std::move(C));
   }

   //4. move copy aasignemnt operator
   Child& Child::operator=(Child&& C)noexcept{
      if (this != &C) {
         delete[] m_toy;
         m_toy = C.m_toy;
         C.m_toy = nullptr;
         m_name = C.m_name;
         m_age = C.m_age;
         m_noOfToys = C.m_noOfToys;
         if (C.m_name != "") C.m_name = "";
         C.m_age = 0;
         C.m_noOfToys = 0;
      }
      return *this;
   }

   //5. destructor
   Child::~Child() { 
      for (size_t i = 0; i < m_noOfToys; ++i)
         delete m_toy[i];
      delete[] m_toy;
      m_toy = nullptr;
   }

   //a query that returns the number of toys stored in the array attribute.
   size_t Child::size() const {
      return m_noOfToys;

   }

   //Helpers
   //overload the insertion operator to insert the content of a Child object into an ostream object.
   std::ostream& operator<<(std::ostream& ostr, const Child& C) {
      //This operator should use a local to function variable to count how many times 
      //this operator has been called
      static size_t counter = 1;
      ostr << "--------------------------" << std::endl;
      ostr << "Child" << " "<< counter++ << ": " << C.m_name << " "
         << C.m_age << " " << "years old:" << std::endl;
      ostr << "--------------------------" << std::endl;
      if (C.m_noOfToys == 0) {
         ostr << "This child has no toys!" << std::endl;
      }
      else {
         for (size_t i = 0; i < C.m_noOfToys; i++) {
             ostr << *(C.m_toy[i]);
         }
      }
      ostr << "--------------------------" << std::endl;
      return ostr;
      counter++;
   }

}

