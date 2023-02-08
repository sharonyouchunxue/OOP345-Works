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
#ifndef SDDS_TOY_H_
#define SDDS_TOY_H_
namespace sdds {

   class Toy {
      std::string m_orderID{}; //a positive number
      std::string m_toyName{};
      size_t m_noOfordered{ 0 };
      double m_price{ 0.00 };
      const double m_saleTax = 0.13;
   public:
      Toy();
      void update(int numItems);
      Toy(const std::string& toy);
      friend std::ostream& operator<<(std::ostream& ostr, const Toy&);
       ~Toy();
   };
}

#endif //!SDDS_TOY_H_

