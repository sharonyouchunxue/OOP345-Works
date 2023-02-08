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
#include "ConfirmOrder.h"

namespace sdds {
   //default constructor
   ConfirmOrder::ConfirmOrder() {}

   //Rule of Five
   //1. copy constructor
   ConfirmOrder::ConfirmOrder(const ConfirmOrder& confirm) {
      operator = (confirm);
   }

   //2. copy assignment operator
   ConfirmOrder& ConfirmOrder::operator=(const ConfirmOrder& confirm) {
      if (this != &confirm) {
         delete[] m_toy;
         m_toy = new const Toy*[confirm.m_noOfRecs];
         for (size_t i = 0; i < confirm.m_noOfRecs; i++) {
            m_toy[i] = confirm.m_toy[i];
         }
         m_noOfRecs = confirm.m_noOfRecs;
      }
      return *this;
   }

   //3. move constructor
   ConfirmOrder::ConfirmOrder(ConfirmOrder&& confirm)noexcept {
      *this = std::move(confirm);
   }

   //4. move assignment operator
   ConfirmOrder& ConfirmOrder::operator=(ConfirmOrder&& confirm)noexcept {
      if (this != &confirm) {
         delete[] m_toy;
         m_toy = confirm.m_toy;
         confirm.m_toy = nullptr;
         m_noOfRecs = confirm.m_noOfRecs;
         confirm.m_noOfRecs = 0;
      }
      return *this;
   }

   //5. destructor
   ConfirmOrder::~ConfirmOrder() {
      delete[] m_toy;
      m_toy = nullptr;
   }

   ConfirmOrder& ConfirmOrder::operator+=(const Toy& toy) {
      bool found = false;
      for (size_t i = 0; i < m_noOfRecs && !found; ++i) {
         if (m_toy[i] == &toy) {
            found = true;
         }
      }
      if (!found) {
         const Toy** temp = new const Toy * [m_noOfRecs + 1];
         for (size_t i = 0; i < m_noOfRecs; ++i) {
            temp[i] = m_toy[i];
         }
         delete[] m_toy;
         m_toy = temp;
         temp[m_noOfRecs] = &toy;
         ++m_noOfRecs;
      }
      return *this;
   }
   ConfirmOrder& ConfirmOrder::operator-=(const Toy& toy) { 
      size_t count = 0;
      for (size_t i = 0; i < m_noOfRecs; ++i) {
         if (m_toy[i] == &toy) {
            m_toy[i] = nullptr;
            count++;
         }
      }
      if (count > 0) {
         const Toy** temp = new const Toy*[m_noOfRecs - count];

         for (size_t i = 0, j = 0; i < m_noOfRecs; ++i) {
            if (m_toy[i])
               temp[j++] = m_toy[i];
         }
         if (m_noOfRecs) {
            delete[] m_toy;
            m_toy = nullptr;
         }

         m_noOfRecs -= count;
         m_toy = temp;
      }
      return *this;
   }

   std::ostream& operator<<(std::ostream& ostr, const ConfirmOrder& C) {
      ostr << "--------------------------" << std::endl;
      ostr << "Confirmations to Send" << std::endl;
      ostr << "--------------------------" << std::endl;
      if (C.m_noOfRecs == 0) {
         ostr << "There are no confirmations to send!" << std::endl;
         ostr << "--------------------------" << std::endl;
      }
      else {
         for (size_t i = 0; i < C.m_noOfRecs; ++i) {
            ostr << *(C.m_toy[i]);
         }
         ostr << "--------------------------" << std::endl;
      }
      return ostr;
   }
}

