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
#ifndef SDDS_BOOK_H_
#define SDDS_BOOK_H_
namespace sdds {

   class Book {
      std::string m_author{};
      std::string m_title{};
      std::string m_publicationCountry{};
      size_t m_publicationYear{ 0 };
      double m_price{ 0.0 };
      std::string m_description{};
   public:
      Book();
      const std::string& title() const;
      const std::string& country() const;
      const size_t& year() const;
      double& price();
      Book(const std::string& strBook);

      //Add a public templated function to your Book class:
      //his function calls the overloaded operator() on the instance spellChecker, 
      //passing to it the book description.
      template<typename T>
      void fixSpelling(T& spellChecker) {
         spellChecker(m_description);
      }

      friend std::ostream& operator<<(std::ostream& ostr, const Book& B);

   };
}

#endif // !SDDS_BOOK_H_
