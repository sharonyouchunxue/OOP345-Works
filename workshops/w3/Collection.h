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
*/
#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H
#include <iostream>
#include "Pair.h"
#include <string>
namespace sdds {
   //class template collection, it takes two parameters
   //T: the type of any element in the collection
   //CAPACITY: the capacity of the collection (a non-type parameter; an integer without sign). 
   template<typename T, int CAPACITY>
   class Collection {
   protected:
      T arr[CAPACITY]; 
      int m_noOfElements{ 0 };
      //dummy object T
      T dummy{};
   public:
      //default constructor
      Collection() {};
      //destructor
      virtual ~Collection() {}
      //a query that returns the current number of elements in the collection
      int size() const {
         return m_noOfElements;
      }
      //query that receives as the parameter an output stream (with default value std::cout) 
      //and inserts into the stream all items from the collection
      void display(std::ostream& ostr = std::cout)const {
         ostr << "----------------------" << std::endl;
         ostr << "|" << " Collection Content " << "|" << std::endl;
         ostr << "----------------------" << std::endl;
         for (int i = 0; i < m_noOfElements; i++) {
            ostr << arr[i] << std::endl;
         }
         ostr << "----------------------" << std::endl;
      }

      virtual bool add(const T& item) {
         bool res = false;
         //check if there still is capacity.
         if (m_noOfElements < CAPACITY) {
            //adds a copy of the parameter to the collection
            arr[m_noOfElements] = item;
            m_noOfElements++;
            // If the item has been added, this function return true
            res = true;
         }
         //false otherwise.
         return res;
      }
      //a query that receives an index as parameter and returns a copy of the element stored in 
      //the collection at the specified index. 
      //If the index is not valid (outside the boundaries of the collection), this query returns the dummy object.
      T& operator[](int i) {
         return i < m_noOfElements ? arr[i] : dummy;
      }
   };

      //Specialize the dummy object when type T = Pair and CAPACITY = 100 so the key is "No Key" and the value is "No Value"
      template<>
      Collection<Pair, 100>::Collection() {
         Pair P("No Key", "No Value");
         dummy = P;
   };
}
#endif // !
