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
#include <iostream>
//#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include "Bakery.h"

namespace sdds {

   Bakery::Bakery(const char* filename){
      std::ifstream fin(filename);
      BakedGood bakedgood;
      std::string line;
      if (!fin) {
         throw std::invalid_argument("filename is invalid");
      }
      else {
         //baked type
         while (std::getline(fin, line)) {
            std::string bakeType = line.substr(0, 8);
            if (bakeType == "BREAD ") {
               bakedgood.m_bakeType = BakedType::BREAD;
            }
            else if (bakeType == "PASTRAY ") {
               bakedgood.m_bakeType = BakedType::PASTERY;
            } 

            //shelflife
            std::string shelfLife = line.substr(28, 14);
            removeSpace(shelfLife);
            bakedgood.m_shelfLife = std::stoi(shelfLife);

            //stock
            std::string stock = line.substr(42, 8);
            removeSpace(stock);
            bakedgood.m_noOfstock = std::stoi(stock);

            //price
            std::string price = line.substr(50, 6);
            removeSpace(price);
            bakedgood.m_price = std::stoi(price);

            m_goods.push_back(bakedgood);

         }
      }    
   }

   void Bakery::showGoods(std::ostream& os) const {

   }

   void Bakery::sortBakery(std::string str){
      if (str == "Description") {
         std::sort(m_goods.begin(), m_goods.end(), [](BakedGood& good, BakedGood& anotherGood) {
            return good.m_description < anotherGood.m_description;
            });
      }
      else if (str == "Shelf") {
         std::sort(m_goods.begin(), m_goods.end(), [](BakedGood& good, BakedGood& anotherGood) {
            return good.m_shelfLife < anotherGood.m_shelfLife;
            });
      }
      else if (str == "Price") {
         std::sort(m_goods.begin(), m_goods.end(), [](BakedGood& good, BakedGood& anotherGood) {
            return good.m_price < anotherGood.m_price;
            });
      }
      else {
         throw std::invalid_argument(" invalid str");
      }

   }

   std::vector<BakedGood> Bakery::combine(const Bakery& other) const {
      return std::vector<BakedGood>();
   }

   bool Bakery::inStock(const std::string& description, BakedType type) const {
      return std::any_of(m_goods.begin(), m_goods.end(), [&](const BakedGood& bakedGood) {
         return bakedGood.m_description == description;
         });
   }

   std::list<BakedGood> Bakery::outOfStock(BakedType t) const {
      std::list<BakedGood> outOfstock;
      std::copy_if(m_goods.begin(), m_goods.end(), std::back_inserter(outOfstock),
         [&](const BakedGood& g) {
            return g.m_bakeType == t && g.m_noOfstock == 0;
         });
      return outOfstock;
   }



   std::string Bakery::removeSpace(std::string& str){
      size_t first = str.find_first_not_of(' ');
      if (std::string::npos == first) {
         return str;
      }
      size_t last = str.find_last_not_of(' ');
      return str.substr(first, (last - first + 1));
   }

}