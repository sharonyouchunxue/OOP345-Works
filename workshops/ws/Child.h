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
#ifndef SDDS_CHILD_H_
#define SDDS_CHILD_H_
#include "Toy.h"
namespace sdds {
   class Child {
      std::string m_name{};
      size_t m_age{};
      const Toy** m_toy{};
      size_t m_noOfToys{};
   public:
      Child();
      Child(std::string name, int age, const Toy* toys[], size_t count);
      //rule of five
      Child(const Child& C);
      Child(Child&& C)noexcept;
      Child& operator=(const Child& C);
      Child& operator=(Child&& C)noexcept;
      virtual ~Child();

      size_t size() const;
      std::ostream& display(std::ostream& ostr = std::cout)const;
   };
   std::ostream& operator<<(std::ostream& ostr, const Child&);
}

#endif //!SDDS_CHILD_H_
