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
#include <numeric>
#include <iomanip>
#include <string>
#include <fstream>
#include <algorithm>
#include "Bakery.h"

namespace sdds {
   Bakery::Bakery(const char* filename){
      std::ifstream fin(filename);
      std::string line;
      if (!fin) {
         throw std::invalid_argument("filename is invalid");
      }
      else {
         while (std::getline(fin, line)) {
            BakedGood bakedgood;
            //baked type
            //extracts the first 8 characters from the line string and stores them in a new string 
            //variable named bakeType
            std::string bakeType = line.substr(0, 8);
               if (bakeType[0] == 'B') {
                  removeSpace(bakeType);
                  bakedgood.m_bakeType = BakedType::BREAD;               
               }
               else if (bakeType[0] == 'P') {
                  removeSpace(bakeType);
                  bakedgood.m_bakeType = BakedType::PASTERY;                
               }  
            
            //description
            //extract the character from position 8 to 28(lenth of 20)
            std::string description = line.substr(8, 20);
            removeSpace(description);
            bakedgood.m_description = description;           

            //shelflife
            //extract the character from position 28 to 42(lenth of 14)
            std::string shelfLife = line.substr(28, 14);
            removeSpace(shelfLife);
            bakedgood.m_shelfLife = std::stoi(shelfLife);

            //stock
            //extract the character from position 42 to 50(lenth of 8)
            std::string stock = line.substr(42, 8);
            removeSpace(stock);
            bakedgood.m_noOfstock = std::stoi(stock);

            //price
            //extract the character from position 50 to 56(lenth of 6)
            std::string price = line.substr(50, 6);
            removeSpace(price);
            bakedgood.m_price = std::stod(price);

            m_goods.push_back(bakedgood);                   
         }
      }
   }

   //print the content of the collection into the parameter
   void Bakery::showGoods(std::ostream& os) const {
      std::for_each(m_goods.begin(), m_goods.end(), [&](const BakedGood& bakedgood) {
         os << bakedgood << std::endl;
         });
      //to sum up all of the stock
      int totalStock = std::accumulate(m_goods.begin(), m_goods.end(), 0, [](int curr_stock, const BakedGood& bakedgood) {
         return curr_stock + bakedgood.m_noOfstock;
         });
      //to sum up all of the price
      double totalPrice = std::accumulate(m_goods.begin(), m_goods.end(), 0.0, [](double curr_price, const BakedGood& bakedgood) {
         return curr_price + bakedgood.m_price;
         });
      os << "Total Stock: " << totalStock << std::endl;
      os << "Total Price: " << totalPrice << std::endl;
   }

   //sort bakery in different category
   void Bakery::sortBakery(std::string str){
      if (str == "Description") {
         std::sort(m_goods.begin(), m_goods.end(), [](BakedGood& good, BakedGood& anotherGood) {
            return good.m_description < anotherGood.m_description;
            });
      }
      else if (str == "Shelf"){
         std::sort(m_goods.begin(), m_goods.end(), [](BakedGood& good, BakedGood& anotherGood) {
            return good.m_shelfLife < anotherGood.m_shelfLife;
            });
      }
      else if (str == "Stock") {
         std::sort(m_goods.begin(), m_goods.end(), [](const BakedGood& good, const BakedGood& anotherGood) {
            return good.m_noOfstock < anotherGood.m_noOfstock;
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
      std::vector<BakedGood> combined;
      //Creates a copy of the std::vector m_goods from the current instance of the Bakery class, 
     //and sorts it by price using a lambda function
      std::vector<BakedGood> collection_a = m_goods;//sort collection a 
      std::sort(collection_a.begin(), collection_a.end(), [](const BakedGood& a, const BakedGood& b){
            return a.m_price < b.m_price;
         });
      std::vector<BakedGood> collection_b = other.m_goods; //sort collection b
      std::sort(collection_b.begin(), collection_b.end(), [](const BakedGood& a, const BakedGood& b)
         {
            return a.m_price < b.m_price;
         });
      //resizes the combined collection to hold the total number of elements in both collection_a and collection_b
      combined.resize(collection_a.size() + collection_b.size());
      auto res = std::merge(
         //use make_move_iterator to indicate that the elements should be moved instead of copied
         std::make_move_iterator(collection_a.begin()),
         std::make_move_iterator(collection_a.end()),
         std::make_move_iterator(collection_b.begin()),
         std::make_move_iterator(collection_b.end()),
         combined.begin(),[](const BakedGood& a, const BakedGood& b){
            return a.m_price < b.m_price;
         }
      );
      //erases any elements in combined that come after the merged range.
      combined.erase(res, combined.end());
      return combined;
   }

   bool operator==(const BakedGood& a, const BakedGood& b) {
      return a.m_description == a.m_description&& a.m_price == b.m_price;
   }
   // receives the Description of a BakedGood and a BakedType as parameters, 
   //and returns true if the collection contains Stock of that BakedGood
   bool Bakery::inStock(const std::string& description, BakedType type) const {
      return std::any_of(m_goods.begin(), m_goods.end(), [&](const BakedGood& bakedGood) {
         return bakedGood.m_description == description && bakedGood.m_bakeType == type && bakedGood.m_noOfstock > 0;
         });
   }

   //receives a BakedType as a parameter, and returns the list of all the out of stock items 
   //in the collection
   std::list<BakedGood> Bakery::outOfStock(BakedType t) const {
      std::list<BakedGood> outOfStockGoods;
      std::copy_if(m_goods.begin(), m_goods.end(), std::back_inserter(outOfStockGoods), [&](const BakedGood& good) {
         return good.m_bakeType == t && good.m_noOfstock == 0;
         });
      outOfStockGoods.sort([](const BakedGood& a, const BakedGood& b) {
         return a.m_price < b.m_price;
         });
      return outOfStockGoods;
   }

   void Bakery::removeSpace(std::string& str){
      // Remove spaces from the beginning and end of the string
      str.erase(str.begin(), std::find_if(str.begin(), str.end(), [](int ch) {
         return !std::isspace(ch);
         }));
      str.erase(std::find_if(str.rbegin(), str.rend(), [](int ch) {
         return !std::isspace(ch);
         }).base(), str.end());
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
            << "* " << std::left << std::setw(5) << b.m_noOfstock
            << " * " << std::right << std::setw(8) << std::fixed << std::setprecision(2) << b.m_price << " * ";
      return out;
   }


  





}











