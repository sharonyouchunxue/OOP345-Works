/*
*****************************************************************************
                        Workshop 5
Full Name  : Chunxue You
Student ID#: 127632214
Email      : cyou8@myseneca.ca
Section    : OOP244 NRA
Date       : 2023-02-19
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. I have done all
the coding by myself and only copied the code that my professor provided to
complete my workshops and assignments.
*****************************************************************************
*/

#ifndef SDDS_COLLECTION_H_
#define SDDS_COLLECTION_H_
#include <iostream>
#include <string>

namespace sdds {

   template <typename T>
   class Collection {
      //the name of the collection;
      std::string m_name{};
      //a dynamically allocated array of items T
      T* m_items{ nullptr };
      //the size of the array
      size_t m_numOfitems{ 0 };
      //a pointer to a function that returns void and receives two parameters of type const 
      //Collection<T>& and const T& in that order.
      void (*addObserver)(const Collection<T>&, const T&) { nullptr };
   public:
      //sets the name of the collection to the string referred to by the parameter 
      //and sets all other attributes to their default value
      Collection(const std::string& name):m_name(name){}
      //this class doesn't support any copy operations; delete all of them.
      Collection(const Collection&) = delete;
      Collection& operator=(const Collection&) = delete;
      //a destructor
      ~Collection(){
         delete[] m_items;
         m_items = nullptr;
      }
      //a query that returns the name of the collection.
      const std::string& name() const {
         return m_name;
      }
      //a query that returns the number of items in the collection.
      size_t size() const {
         return m_numOfitems;
      }
      //stores the address of the callback function (observer) into an attribute. 
      //This parameter is a pointer to a function that returns void and accepts two parameters: 
      //a collection and an item that has just been added to the collection. 
      //This function is called when an item is added to the collection.
      void setObserver(void (*observer)(const Collection<T>&, const T&)) {
         addObserver = observer;
      }

      //dds a copy of item to the collection, only if the collection doesn't contain an 
      //item with the same title.
      Collection<T>& operator+=(const T& item) {
         bool found = false;
         for (size_t i = 0; i < m_numOfitems; ++i) {
            if (m_items[i].title() == item.title()) {
               found = true;
            }
         }
         if (!found) {
            T* temp = new T[m_numOfitems + 1];
            for (size_t i = 0; i < m_numOfitems; ++i) {
               temp[i] = m_items[i];
            }
            temp[m_numOfitems] = item;

            delete[] m_items;
            m_items = temp;
            m_numOfitems++;

            if (addObserver != nullptr) {
               addObserver(*this, m_items[m_numOfitems - 1]);
            }
         }
         return *this;
      }

      //returns the item at index idx.
      T& operator[](size_t idx) const {
         //if the index is out of range, this operator throws an exception of type
         //std::out_of_range with the message Bad index [IDX]. Collection has [SIZE] items.. 
         //Use operator + to concatenate strings
         if (idx >= size()) {
            std::string err = "Bad index [" + std::to_string(idx) + "]. Collection has [" + std::to_string(m_numOfitems) + "] items.";
            throw std::out_of_range(err);                                         
         }
         return m_items[idx];
      }

      //returns the address of the item with the title title (type T has a member function called
      //title() that returns the title of the item). 
      //If no such item exists, this function returns nullptr
      T* operator[](const std::string& title) const {
         T* itemAddress = nullptr;
         for (size_t i = 0; i < m_numOfitems; ++i) {
            if (m_items[i].title() == title) {
               itemAddress = &m_items[i];
            }
         }
         return itemAddress;
      }
   };

   //FREE Helpers
   //overload the insertion operator to insert the content of a Collection object into an 
   //ostream object. Iterate over all elements in the collection and insert each one into 
   //the ostream object (do not add newlines).
   template <typename T>
   std::ostream& operator<<(std::ostream& ostr, Collection<T>& C) {
      for (size_t i = 0; i < C.size(); ++i) {
         ostr << C[i];
      }
      return ostr;
   }
}

#endif // !SDDS_COLLECTION_H_
