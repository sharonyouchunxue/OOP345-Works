#pragma once
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

#ifndef SDDS_CONFIRMORDER_H_
#define SDDS_CONFIRMORDER_H_
#include "Toy.h"
namespace sdds {
   class ConfirmOrder {
      const sdds::Toy** m_toy = nullptr;
      size_t m_noOfRecs{};
   public:
      ConfirmOrder();
      //Rule of five
      ConfirmOrder(const ConfirmOrder&);
      ConfirmOrder& operator=(const ConfirmOrder&);
      ConfirmOrder(ConfirmOrder&&)noexcept;
      ConfirmOrder& operator=(ConfirmOrder&&)noexcept;
      ~ConfirmOrder();

      ConfirmOrder& operator+=(const Toy& toy);
      ConfirmOrder& operator-=(const Toy& toy);
      friend std::ostream& operator<<(std::ostream& ostr ,const ConfirmOrder& ) ;
   };

}
#endif //!SDDS_CONFIRMORDER_H_

