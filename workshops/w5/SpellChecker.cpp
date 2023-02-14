/*
*****************************************************************************
                        Workshop 5
Full Name  : Chunxue You
Student ID#: 127632214
Email      : cyou8@myseneca.ca
Section    : OOP244 NRA
Date       : 2023-02-19
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
#include "SpellChecker.h"

namespace sdds {

   //default constructor
   SpellChecker::SpellChecker(){}

   //receives the address of a C-style null-terminated string that holds the name of the file 
   //that contains the misspelled words. If the file exists, this constructor loads its contents. 
   //If the file is missing, this constructor throws an exception of type const char*, with the 
   //message Bad file name!. Each line in the file has the format BAD_WORD  GOOD_WORD; 
   //the two fields can be separated by any number of spaces.
   SpellChecker::SpellChecker(const char* filename){
      std::ifstream file(filename);
      if (!file.is_open()) {
         throw "Bad file name!";
      }
         for (size_t i = 0; i < MAX_STR_SIZE; ++i) {
            file >> m_badWords[i];
            file >> m_goodWords[i];
         }
   }

   //this operator searches text and replaces any misspelled word with the correct version. 
   //It should also count how many times each misspelled word has been replaced.
   void SpellChecker::operator()(std::string& text){
      for (size_t i = 0; i < MAX_STR_SIZE; ++i) {
         while (text.find(m_badWords[i]) != std::string::npos) {
            text.replace(text.find(m_badWords[i]), m_badWords[i].size(),m_goodWords[i]);
            ++m_replace[i];

         }
      }
   }

   //inserts into the parameter how many times each misspelled word has been replaced by the 
   //correct word using the current instance. The format of the output is:
   //where BAD_WORD is to be printed on a field of size 15, aligned to the right.
   void SpellChecker::showStatistics(std::ostream& out) const{
      out << "Spellchecker Statistics" << std::endl;
      for (size_t i = 0; i < MAX_STR_SIZE; ++i) {
         out << std::setw(15) << std::right << m_badWords[i] << ": " << m_replace[i] << " replacements" << std::left << std::endl;
      }
   }
}