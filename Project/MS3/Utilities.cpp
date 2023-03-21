/*
*****************************************************************************
                        Milestone 3
Full Name  : Chunxue You
Student ID#: 127632214
Email      : cyou8@myseneca.ca
Section    : OOP244 NRA
Date       : 2023-03-21
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. I have done all
the coding by myself and only copied the code that my professor provided to
complete my workshops and assignments.
*****************************************************************************
*/
#include <iostream>
#include "Utilities.h"
namespace sdds {

   char Utilities::m_delimiter = ' ';

   //sets the field width of the current object to the value of parameter newWidth
   void Utilities::setFieldWidth(size_t newWidth){
      m_widthField = newWidth;
   }

   //returns the field width of the current object
   size_t Utilities::getFieldWidth() const{
      return m_widthField;
   }

   std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more){
      std::string token = "";
      size_t first_pos = next_pos;
      next_pos = str.find(m_delimiter, first_pos);
      if (next_pos < str.length()) {
         token = str.substr(first_pos, next_pos - first_pos);
         removeSpace(token);
         more = true;
      }
      else {
         if (next_pos == std::string::npos) {
            token = str.substr(first_pos);
            removeSpace(token);
            more = false;
         }
      }
      m_widthField = m_widthField > token.length() ? m_widthField : token.length();
      next_pos++;
      return token;    
   }

   //remove all leading spaces
   void Utilities::removeSpace(std::string& str){
      if (!str.empty()) {
         str.erase(0, str.find_first_not_of(" "));
         str.erase(str.find_last_not_of(" ") + 1);
      }
   }

   //sets the delimiter for this class to the character received
   void Utilities::setDelimiter(char newDelimiter){
      m_delimiter = newDelimiter;
   }

   //returns the delimiter for this class.
   char Utilities::getDelimiter(){
      return m_delimiter;
   }

}

