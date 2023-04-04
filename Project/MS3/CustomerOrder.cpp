/*
*****************************************************************************
                        Milestone 3
Full Name  : Chunxue You
Student ID#: 127632214
Email      : cyou8@myseneca.ca
Section    : OOP244 NRA
Date       : 2023-04-03
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. I have done all
the coding by myself and only copied the code that my professor provided to
complete my workshops and assignments.
*****************************************************************************
*/
#include <iostream>
#include <iomanip>
#include <vector>
#include "CustomerOrder.h"
#include "Utilities.h"
#include <unordered_set>

namespace sdds {

   size_t CustomerOrder::m_widthField = 0u;

   //default constructor
   CustomerOrder::CustomerOrder() {}

   //one argument constructor uses a local Utilities object to extract the tokens from the string and 
   //populate the current instance. 
   CustomerOrder::CustomerOrder(const std::string& str) {
      std::vector<Item*> items;
      Utilities util;
      size_t position = 0u;
      bool more = false;
      if (!str.empty()) {
         m_name = util.extractToken(str, position, more);
         m_product = util.extractToken(str, position, more);

         while (more) {
            std::string item = util.extractToken(str, position, more);
            items.push_back(new Item(item));
         }
         m_cntItem = items.size();
         m_lstItem = new Item * [m_cntItem];
         for (size_t i = 0u; i < m_cntItem; ++i) {
            m_lstItem[i] = std::move(items[i]);
         }
         m_widthField = m_widthField > util.getFieldWidth() ? m_widthField : util.getFieldWidth();
      }
   }

   //copy constructor should throw an exception if called and the copy operator= should be deleted.
   CustomerOrder::CustomerOrder(const CustomerOrder& src) {
      throw "invalid call copy constructor";
   }

   //move constrcutor
   //should "promise" that it doesn't throw exceptions
   CustomerOrder::CustomerOrder(CustomerOrder&& src) noexcept {
      *this = std::move(src);
   }

   //move assignment operator
   //should "promise" that it doesn't throw exceptions
   CustomerOrder& CustomerOrder::operator=(CustomerOrder&& src) noexcept {
      if (this != &src) {
         for (size_t i = 0u; i < m_cntItem; ++i) {
            delete m_lstItem[i];
            m_lstItem[i] = nullptr;
         }
         delete[] m_lstItem;
         m_lstItem = nullptr;

         m_name = src.m_name;
         m_product = src.m_product;
         m_cntItem = src.m_cntItem;
         m_lstItem = src.m_lstItem;

         src.m_name = "";
         src.m_product = "";
         src.m_cntItem = 0u;
         src.m_lstItem = nullptr;
      }
      return *this;
   }

   //destructor to deallocate the memory
   CustomerOrder::~CustomerOrder() {
      for (size_t i = 0u; i < m_cntItem; ++i) {
         delete m_lstItem[i];
         m_lstItem[i] = nullptr;
      }
      delete[] m_lstItem;
      m_lstItem = nullptr;
   }

   //returns true if all the items in the order have been filled; false otherwise
   bool CustomerOrder::isOrderFilled() const {
      bool res = true;
      // Traverse all the elements in the current order
      for (size_t i = 0u; i < m_cntItem; ++i) {
         // If any item is not filled, return false
         if (!m_lstItem[i]->m_isFilled) {
            res = false;
         }
      }
      // All items are filled
      return res;
   }

   //returns true if all items specified by itemName have been filled. 
   //If the item doesn't exist in the order, this query returns true.
   bool CustomerOrder::isItemFilled(const std::string& itemName) const {
      bool res = true;
      // Traverse all the elements in the current order
      for (size_t i = 0u; i < m_cntItem; ++i) {
         // Check if the current order item matches the itemName
         if (m_lstItem[i]->m_itemName == itemName) {
            // If the item is not filled, return false
            if (!m_lstItem[i]->m_isFilled) {
               res =  false;
            }
         }
      }
      // All items are either filled or the specified item doesn't exist in the order
      return res;
   }

   // fills one item in the current order that the Station specified in the first parameter handles.
   void CustomerOrder::fillItem(Station& station, std::ostream& os) {
      bool stop = false;
      // Traverse all the elements in the current order
      for (size_t i = 0; i < m_cntItem && !stop; ++i) {
         // Check if the current order item is unfilled and matches the item handled by the station
         if (!m_lstItem[i]->m_isFilled && m_lstItem[i]->m_itemName == station.getItemName()) {
            // Check if the station's inventory contains at least one item
            if (station.getQuantity() > 0) {
               // Update the order item and station's inventory
               station.updateQuantity();
               m_lstItem[i]->m_isFilled = true;
               m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
               // Print the filled message
               os << "    Filled " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << std::endl;
               stop = true;
            }
            else {
               // Print the unfilled message
               os << "    Unable to fill " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << std::endl;
            }
         }
      }
   }
 
   //print record to console
   void CustomerOrder::display(std::ostream& os) const {
         os << m_name << " - " << m_product << std::endl;
         for (size_t i = 0u; i < m_cntItem; ++i) {
            os << "[" << std::right << std::setw(6) << std::setfill('0') << m_lstItem[i]->m_serialNumber << "]";
            os << " "<< std::left << std::setw(CustomerOrder::m_widthField) << std::setfill(' ') << m_lstItem[i]->m_itemName;
            os << "  " << " -" << (m_lstItem[i]->m_isFilled ? " FILLED" : " TO BE FILLED") << std::endl;
         }
      }
}





