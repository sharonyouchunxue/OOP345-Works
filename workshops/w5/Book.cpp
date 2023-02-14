#include <iostream>
#include <iomanip>
#include <string>
#include "Book.h"

namespace sdds {
   //default constructor
   Book::Book() {}

   //a query that returns the title of the book
   const std::string& Book::title() const {
      return m_title;
   }

   // query that returns the publication country
   const std::string& Book::country() const {
      return m_publicationCountry;
   }

   //a query that returns the publication year
   const size_t& Book::year() const {
      return m_publicationYear;
   }
   //a function that returns the price by reference, 
   //allowing the client code to update the price
   double& Book::price() {
      return m_price;
   }

   //a constructor that receives a reference to an unmodifiable string that 
   //contains information about the book; 
   Book::Book(const std::string& strBook) {
      //extracts the information about the book from the string 
      //by parsing it and stores the tokens in the object's attributes
      std::string tempStr = strBook;
      size_t tempIndx = 0u;

      //remove all spaces from the beginning and end of any token in the string.
      //AUTHOR  
      tempStr.erase(0, tempStr.find_first_not_of(' '));
      tempIndx = tempStr.find(',');
      m_author = tempStr.substr(0, tempIndx);
      m_author.erase(m_author.find_last_not_of(' ') + 1);
      tempStr.erase(0, tempIndx + 1);

      //TITLE
      tempStr.erase(0, tempStr.find_first_not_of(' '));
      tempIndx = tempStr.find(',');
      m_title = tempStr.substr(0, tempIndx);
      m_title.erase(m_title.find_last_not_of(' ') + 1);
      tempStr.erase(0, tempIndx + 1);

      //COUNTRY
      tempStr.erase(0, tempStr.find_first_not_of(' '));
      tempIndx = tempStr.find(',');
      m_publicationCountry = tempStr.substr(0, tempIndx);
      m_publicationCountry.erase(m_publicationCountry.find_last_not_of(' ') + 1);
      tempStr.erase(0, tempIndx + 1);

      //PRICE
      tempStr.erase(0, tempStr.find_first_not_of(' '));
      tempIndx = tempStr.find(',');
      m_price = std::stod(tempStr.substr(0, tempIndx));
      tempStr.erase(0, tempIndx + 1);

      //YEAR
      tempStr.erase(0, tempStr.find_first_not_of(' '));
      tempIndx = tempStr.find(',');
      m_publicationYear = std::stoi(tempStr.substr(0, tempIndx));
      tempStr.erase(0, tempIndx + 1);

      //DESCRIPTION
      tempStr.erase(0, tempStr.find_first_not_of(' '));
      m_description = tempStr;
      //tempIndx = tempStr.find(',');
      //m_description = tempStr.substr(0, tempIndx);
      //m_description.erase(m_description.find_last_not_of(' ') + 1);
      //tempStr.erase(0, tempIndx + 1);

   }

   //Friend Helpers
   //verload the insertion operator to insert the content of a book object into an ostream object
   std::ostream& operator<<(std::ostream& ostr, const Book& B) {
      ostr << std::setw(20) << std::right << B.m_author << " | ";
      ostr << std::setw(22) << std::right << B.m_title << " | ";
      ostr << std::setw(5) << std::right << B.m_publicationCountry << " | ";
      ostr << std::setw(4) << std::right << B.m_publicationYear << " | ";
      ostr << std::setw(6) << std::right << std::fixed << std::setprecision(2) << B.m_price << " | ";
      ostr << std::left<< B.m_description << std::endl;
      return ostr;
   }

}