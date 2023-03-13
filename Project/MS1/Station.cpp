/*
*****************************************************************************
                        Milestone 1
Full Name  : Chunxue You
Student ID#: 127632214
Email      : cyou8@myseneca.ca
Section    : OOP244 NRA
Date       : 2023-03-13
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. I have done all
the coding by myself and only copied the code that my professor provided to
complete my workshops and assignments.
*****************************************************************************
*/
#include <iostream>
#include <iomanip>
#include <string>
#include "Station.h"


namespace sdds {
   size_t Station::m_widthField = 0u;
   size_t Station::id_generator = 0u;

   Station::Station(const std::string& src){
      size_t next_pos = 0u;
      bool more = true;
      Utilities util;
      m_id = ++Station::id_generator;
      // extract name
      m_name = util.extractToken(src, next_pos, more);
      //extract starting serial number 
      m_nextSerialNumber = std::stoi(util.extractToken(src, next_pos, more));
      //extract quantity 
      m_noOfCurr = std::stoi(util.extractToken(src, next_pos, more));
      // extract description 
      m_description = util.extractToken(src, next_pos, more);
      //update m_widthField
      m_widthField = std::max(m_widthField, util.getFieldWidth());
   }

   //returns the name of the current Station object
   const std::string& Station::getItemName() const {
      return m_name;
   }

   //returns the next serial number to be used on the assembly line and increments m_serialNumber
   size_t Station::getNextSerialNumber() {
      ++m_nextSerialNumber;
      return m_nextSerialNumber - 1;
   }

   // returns the remaining quantity of items in the Station object
   size_t Station::getQuantity() const {
      return m_noOfCurr;
   }

   //subtracts 1 from the available quantity; should not drop below 0.
   void Station::updateQuantity() {
      if (m_noOfCurr > 0) {
         --m_noOfCurr;
      }
   }

   void Station::display(std::ostream& os, bool full) const {
      os << std::right << std::setw(3) << std::setfill('0') << m_id << " | ";
      os << std::left << std::setw(Station::m_widthField) << std::setfill(' ') << m_name
         << " | " << std::right << std::setw(6) << std::setfill('0') << m_nextSerialNumber << " |";

      if (full) {
         os << std::right << std::setw(4) << std::setfill(' ') << m_noOfCurr << " | ";
         os << std::left  << m_description << std::endl;
      }
      else
         os << std::endl;
   }

}

