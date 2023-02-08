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
#include <iomanip>
#include <string>
#include "Toy.h"

namespace sdds {

   //default constructor
   Toy::Toy() {}

   void Toy::update(int numItems) {
      m_noOfordered = numItems;
   }

   sdds::Toy::Toy(const std::string& toy) {
      std::string tempStr = toy;
      size_t tempIdx = 0u;

      //ID
      tempStr.erase(0, tempStr.find_first_not_of(' '));
      tempIdx = tempStr.find(':');
      m_orderID = tempStr.substr(0, tempIdx);
      m_orderID.erase(m_orderID.find_last_not_of(' ') + 1);
      tempStr.erase(0, tempIdx + 1);

      //Toy name
      tempStr.erase(0, tempStr.find_first_not_of(' '));
      tempIdx = tempStr.find(':');
      m_toyName = tempStr.substr(0, tempIdx);
      m_toyName.erase(m_toyName.find_last_not_of(' ') + 1);
      tempStr.erase(0, tempIdx + 1);

      //the number of items the number of toys of this type to be ordered
      tempStr.erase(0, tempStr.find_first_not_of(' '));
      tempIdx = tempStr.find(':');
      m_noOfordered = std::stoi(tempStr.substr(0, tempIdx));
      tempStr.erase(0, tempIdx + 1);

      //the price of this toy
      tempStr.erase(0, tempStr.find_first_not_of(' '));
      tempIdx = tempStr.find(':');
      m_price = std::stod(tempStr.substr(0, tempIdx));
      tempStr.erase(0, tempIdx + 1);
   }

   std::ostream& operator<<(std::ostream& ostr, const Toy& T) {
      ostr << "Toy" << std::setw(8) << T.m_orderID << ":"
         << std::setw(18) << std::right << T.m_toyName << std::setw(3)
         << T.m_noOfordered << " " << "items" << std::setw(8)
         << T.m_price << std::fixed << std::setprecision(2)
         << "/item  subtotal:" << std::setw(7) << std::fixed << std::setprecision(2)
         << (T.m_noOfordered) * (T.m_price) << " "
         << "tax:" << std::setw(6) << (T.m_noOfordered) * (T.m_price * T.m_saleTax) << " "
         << "total:" << std::setw(7) << (T.m_noOfordered * T.m_price) * (1 + T.m_saleTax) << std::endl;
      return ostr;
   }

   Toy::~Toy(){}


}
