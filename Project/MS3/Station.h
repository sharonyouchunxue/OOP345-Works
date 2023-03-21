/*
*****************************************************************************
                        Milestone 3
Full Name  : Chunxue You
Student ID#: 127632214
Email      : cyou8@myseneca.ca
Section    : OOP244 NRA
Date       : 2023-03-21
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. I have done all
the coding by myself and only copied the code that my professor provided to
complete my workshops and assignments.
*****************************************************************************
*/

#ifndef SDDS_STATION_H
#define SDDS_STATION_H

#include <ostream>
#include "Utilities.h"

namespace sdds {
   class Station {
      //Instance Variables
      int m_id{ 0 };
      std::string m_name{};
      std::string m_description{};
      size_t m_nextSerialNumber{ 0u };//the next serial number to be assigned to an item at this station 
      size_t m_noOfCurr{ 0 };//the number of items currently in stock

      //Class Variables
      static size_t m_widthField;
      static size_t id_generator;
   public:
      Station(const std::string& src);
      const std::string& getItemName() const;
      size_t getNextSerialNumber();
      size_t getQuantity() const;
      void updateQuantity();
      void display(std::ostream& os, bool full) const;
   };
}
#endif // !SDDS_STATION_H



