#pragma once
/*
*****************************************************************************
                        Workshop 3
Full Name  : Chunxue You
Student ID#: 127632214
Email      : cyou8@myseneca.ca
Section    : OOP244 NRA
Date       : 2023-01-30
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. I have done all
the coding by myself and only copied the code that my professor provided to
complete my workshops and assignments.
*****************************************************************************
//*/

#ifndef SDDS_SET_H
#define SDDS_SET_H
#include <iostream>
#include <cmath>
#include <string>
#include "Pair.h"
#include "Collection.h"

namespace sdds {
   //Derive the Set class template from Collection<T, 100>
   //(the Set will always have a capacity of 100 items). 
   //The Set will have only one template parameter T.
   template<class T>
   class Set : public Collection<T,100> {
      const int CAPACITY = 100;
   public:
      //default constructor
      Set() { ; }
      //override the inherited function add to prevent adding an item if it already exists in the Set
      bool add(const T& item) {
         //bool res = true;
         for (int i = 0; i < this->m_noOfElements; i++) {
            if (item == this->arr[i]) {
               return false;
            }
         }
         return Collection<T, 100>::add(item);
      }
   };

   //specialization
   //for T = double, the function add() should consider that two numbers are the same 
   //if their difference in the absolute value is smaller or equal to 0.01.
      template<>
      bool Set<double>::add(const double& item) {
         //bool res = true;
         for (int i = 0; i < this->m_noOfElements; i++) {
            if (std::fabs(item - this->arr[i]) <= 0.01) {
               return false;
            }
         }
         return Collection<double, 100>::add(item);
   };
}
#endif // !
