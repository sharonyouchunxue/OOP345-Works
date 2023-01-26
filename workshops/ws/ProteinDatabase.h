#pragma once
/*
*****************************************************************************
                        Workshop 2
Full Name  : Chunxue You
Student ID#: 127632214
Email      : cyou8@myseneca.ca
Section    : OOP244 NRA
Date       : 2023-01-23
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. I have done all
the coding by myself and only copied the code that my professor provided to
complete my workshops and assignments.
*****************************************************************************
*/
#ifndef SDDS_PROTEINDATABASE_H_
#define SDDS_PROTEINDATABASE_H_

namespace sdds {
   class ProteinDatabase {
      // array of elements of type std::string
      std::string *m_string{};
      unsigned int m_noOfstrings = 0;
   public:
      //default constructor
      ProteinDatabase();
      //1-argument constructor
      ProteinDatabase(const char* filename);
      std::size_t size()const;
      std::string operator[](size_t)const;
      //rule of five
      //copy constructor
      ProteinDatabase(const ProteinDatabase& src);
      //move constructor
      ProteinDatabase(ProteinDatabase&& src)noexcept;
      //copy assignment operator
      ProteinDatabase& operator=(ProteinDatabase& src); 
      //move assignment operator
      ProteinDatabase& operator=(ProteinDatabase&& src)noexcept;
      //destructor
      ~ProteinDatabase();
   };

}

#endif // ! SDDS_PROTEINDATABASE_H_
