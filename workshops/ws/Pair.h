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

#ifndef SDDS_PAIR_H
#define SDDS_PAIR_H
#include <iostream>
#include <string>
namespace sdds {
   class Pair {
      std::string m_key{};
      std::string m_value{};
   public:
      const std::string& getKey() const {
         return m_key;
      }
      const std::string& getValue() const {
         return m_value;
      }
      Pair(const std::string& key, const std::string& value) : m_key{ key }, m_value{ value } {};
      // TODO: Add here the missing prototypes for the member
      static bool isSameKey(const Pair&, const Pair&);
      Pair(){};
      virtual std::ostream& display(std::ostream& ostr = std::cout) const;
      bool operator==(const Pair& pair)const {
         return m_key == pair.getKey();
      }
   };
   std::ostream& operator<<(std::ostream& ostr, const Pair& );
}
#endif // !SDDS_PAIR_H
