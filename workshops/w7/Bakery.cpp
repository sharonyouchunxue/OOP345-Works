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
#include <iomanip>
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
            bakedgood.m_bakeType = (bakeType == "BREAD") ? BakedType::BREAD : BakedType::PASTERY;
            removeSpace(bakeType);

            //description
            std::string description = line.substr(8, 20);
            bakedgood.m_description = description;
            removeSpace(description);

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
            bakedgood.m_price = std::stod(price);

            m_goods.push_back(bakedgood);

         }
      }    
   }

   //print the content of the collection into the parameter
   void Bakery::showGoods(std::ostream& os) const {
      int totalStock = 0;
      double totalPrice = 0.0;
      for (const auto& bakegood : m_goods) {
         os << bakegood << std::endl; 
         totalStock += bakegood.m_noOfstock;
         totalPrice += bakegood.m_price;
      }
      os << "Total Stock: " << totalStock <<std::endl;
      os << "Total Price: " << totalPrice << std::endl;
   }

   void Bakery::sortBakery(std::string str){
      if (str == "Description") {
         std::sort(m_goods.begin(), m_goods.end(), [](BakedGood& good, BakedGood& anotherGood) {
            return good.m_description < anotherGood.m_description;
            });
      }
      else if (str == "Stock") {
         std::sort(m_goods.begin(), m_goods.end(), [](const BakedGood& a, const BakedGood& b) {
            return a.m_noOfstock < b.m_noOfstock;
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

   //receives a parameter of another Bakery object reference and combines the collection 
   //of BakedGoods from the current object and the parameter and returns the combined collection. 
   //The combined collection should be ordered by price.
   std::vector<BakedGood> Bakery::combine(const Bakery& other) const {
      std::vector<BakedGood> combined = m_goods;
      combined.insert(combined.end(), other.m_goods.begin(), other.m_goods.end());
      std::sort(combined.begin(), combined.end(), [](const BakedGood& a, const BakedGood& b) {
         return a.m_price < b.m_price;
         });
      return combined;
   }

   // receives the Description of a BakedGood and a BakedType as parameters, 
   //and returns true if the collection contains Stock of that BakedGood
   bool Bakery::inStock(const std::string& description, BakedType type) const {
      return std::any_of(m_goods.begin(), m_goods.end(), [&](const BakedGood& bakedGood) {
         return bakedGood.m_description == description;
         });
   }

   //receives a BakedType as a parameter, and returns the list of all the out of stock items 
   //in the collection
   std::list<BakedGood> Bakery::outOfStock(BakedType t) const {
      std::list<BakedGood> outOfStockGoods;
      std::copy_if(m_goods.begin(), m_goods.end(), std::back_inserter(outOfStockGoods), [&](const BakedGood& good) {
         return good.m_bakeType == t && good.m_noOfstock == 0;
         });
      return outOfStockGoods;
   }

   std::string Bakery::removeSpace(std::string& str){
      size_t first = str.find_first_not_of(' ');
      if (std::string::npos == first) {
         return str;
      }
      size_t last = str.find_last_not_of(' ');
      return str.substr(first, (last - first + 1));
   }

   //inserts one BakedGood into the first parameter in formating
   std::ostream& operator<<(std::ostream& out, const BakedGood& b) {
      std::string bakeType;
      if (b.m_bakeType == BakedType::BREAD) {
         bakeType = "Bread";
      }
      else {
         bakeType = "Pastry";
      }
      out << "* " << std::left << std::setw(10) << bakeType
         << " * " << std::left << std::setw(20) << b.m_description
         << " * " << std::left << std::setw(6) << b.m_shelfLife
         << " * " << std::left << std::setw(5) << b.m_noOfstock
         << " * " << std::setw(8) << std::fixed << std::setprecision(2) << b.m_price << " *";
      return out;
   }

}