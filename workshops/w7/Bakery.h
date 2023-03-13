/*
*****************************************************************************
                        Workshop 7
Full Name  : Chunxue You
Student ID#: 127632214
Email      : cyou8@myseneca.ca
Section    : OOP244 NRA
Date       : 2023-03-12
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. I have done all
the coding by myself and only copied the code that my professor provided to
complete my workshops and assignments.
*****************************************************************************
*/
#ifndef SDDS_BAKERY_H
#define SDDS_BAKERY_H
#include <vector>
#include <list>
namespace sdds {

   enum class BakedType {
      BREAD, PASTERY
   };

   struct BakedGood {
      BakedType m_bakeType{};
      std::string m_description{};
      std::string m_shelfLife{};//in days
      int m_noOfstock{};
      double m_price{};
   };

   class Bakery {
      std::vector<BakedGood> m_goods;
   public:
      Bakery(const char* filename);
      void showGoods(std::ostream& os) const;
      void sortBakery(std::string str);
      std::vector<BakedGood> combine(const Bakery& other) const;
      bool inStock(const std::string& description, BakedType type) const;
      std::list<BakedGood> outOfStock(BakedType t) const;
      std::string removeSpace(std::string& str);
   };
   std::ostream& operator<<(std::ostream& out, const BakedGood& b);
   

}
#endif // !SDDS_BAKERY_H
