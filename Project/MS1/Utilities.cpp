/*
*****************************************************************************
                        Milestone 1
Full Name  : Chunxue You
Student ID#: 127632214
Email      : cyou8@myseneca.ca
Section    : OOP244 NRA
Date       : 2023-03-13
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
      if (str[next_pos] == getDelimiter())
      {
         more = false;
         throw std::invalid_argument("No token!"); //throw an exception if a delimiter is found in the next position
      }
      size_t foundPos = 0;
      foundPos = str.find(getDelimiter(), next_pos);
      std::string tempString{};
      if (foundPos < str.length())                   //extracts all the tokens except the last one
      {
         tempString = str.substr(next_pos, foundPos - next_pos);
         removeSpaces(tempString);
         next_pos = foundPos + 1;
      }
      else                                         //extracts the last token
      {
         tempString = str.substr(next_pos);
         removeSpaces(tempString);
         more = false;
      }
      if (m_widthField < tempString.length())
      {
         m_widthField = tempString.length();
      }
      return tempString;    
   }

   void Utilities::removeSpaces(std::string& word)
   {
      bool spacesRemoved = false;
      while (!spacesRemoved)
      {
         if (word[0] == ' ')
         {
            word = word.substr(1, word.length());
         }
         if (word[word.length() - 1] == ' ')
         {
            word = word.substr(0, (word.length() - 1));
         }
         if (word[0] != ' ' && word[word.length() - 1] != ' ')
         {
            spacesRemoved = true;
         }
      }
   }

   void Utilities::setDelimiter(char newDelimiter){
      m_delimiter = newDelimiter;
   }

   //returns the delimiter for this class.
   char Utilities::getDelimiter(){
      return m_delimiter;
   }

}
