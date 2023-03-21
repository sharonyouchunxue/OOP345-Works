/*
*****************************************************************************
                        Milestone 2
Full Name  : Chunxue You
Student ID#: 127632214
Email      : cyou8@myseneca.ca
Section    : OOP244 NRA
Date       : 2023-03-15
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. I have done all
the coding by myself and only copied the code that my professor provided to
complete my workshops and assignments.
*****************************************************************************
*/
#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H
namespace sdds {
   class Utilities {
      // length of the token extracted;
      size_t m_widthField{ 1 };
      //separates the tokens in any given std::string object
      static char m_delimiter;
   public:
      void setFieldWidth(size_t newWidth);
      size_t getFieldWidth() const;
      std::string extractToken(const std::string& str, size_t& next_pos, bool& more);
      void removeSpace(std::string& str);

      //Class Functions
      static void setDelimiter(char newDelimiter);
      static char getDelimiter();
   };
}
#endif // !SDDS_UTILITIES_H

