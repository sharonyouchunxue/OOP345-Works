#pragma once
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
#ifndef SDDS_SPELLCHECKER_H_
#define SDDS_SPELLCHECKER_H_
namespace sdds {
   const int MAX_STR_SIZE = 6;
   class SpellChecker {
      std::string m_badWords[MAX_STR_SIZE]{};
      std::string m_goodWords[MAX_STR_SIZE]{};
      size_t m_replace[MAX_STR_SIZE]{};
   public:
      SpellChecker();
      SpellChecker(const char* filename);
      void operator()(std::string& text);
      void showStatistics(std::ostream& out) const;

   };

}
#endif // !SDDS_SPELLCHECKER_H_

