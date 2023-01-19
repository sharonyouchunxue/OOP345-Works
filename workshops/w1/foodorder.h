/*
*****************************************************************************
                        Workshop 1
Full Name  : Chunxue You
Student ID#: 127632214
Email      : cyou8@myseneca.ca
Section    : OOP244 NRA
Date       : 2023-01-14
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. I have done all
the coding by myself and only copied the code that my professor provided to
complete my workshops and assignments.
*****************************************************************************
*/
#ifndef SDDS_FOODORDER_H_
#define SDDS_FOODORDER_H_

//two global variables
extern double g_taxrate;
extern double g_dailydiscount;

namespace sdds {

   class FoodOrder {
      //C-style null-terminated string
      char m_customerName[10];
      //char m_foodDescription[25];
      char* m_foodDescription{};
      double m_foodPrice;
      bool m_dailySpecial;
      void set(const char* customerName, const char* foodDescription, const double price, const char dailySpecial);
      void setEmpty();
      bool isEmpty();

   public:
      //Default constructor
      FoodOrder();
      ~FoodOrder();
      void read(std::istream& istr);
      void display();
   };

}

#endif // !SDDS_FOODORDER_H_

