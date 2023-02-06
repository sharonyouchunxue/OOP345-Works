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
#include <iomanip>
#include "Pair.h"
using namespace std;
namespace sdds {
   //Two objects of type Pair are considered to be equal if they have the same key.
   bool Pair::isSameKey(const Pair& L, const Pair& R) {
      return (L.m_key == R.m_key);
   }
   
   std::ostream& Pair::display(std::ostream& ostr) const {
      ostr << std::right << std::setw(20) << getKey();
      ostr << std::left << ": " << getValue();
      return ostr;
   }

   bool Pair::operator==(const Pair& pair) const{
      return m_key == pair.getKey();
   }

   std::ostream& operator<<(std::ostream& ostr, const Pair& pair) {
      return pair.display(ostr);
   }
}