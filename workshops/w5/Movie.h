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

#ifndef  SDDS_MOVIE_H_
#define SDDS_MOVIE_H_
namespace sdds {
   class Movie {
      std::string m_movieTitle{};
      size_t m_releaseYear{ 0 };
      std::string m_descrip{};
   public:
      Movie();
      const std::string& title() const;
      Movie(const std::string& strMovie);

      //This function calls the overloaded operator() on instance spellChecker, 
      //passing to it the movie title and description.
      template<typename T>
      void fixSpelling(T& spellChecker) {
         spellChecker(m_movieTitle);
         spellChecker(m_descrip);
      }

      friend std::ostream& operator<<(std::ostream& ostr, const Movie& M);
   };


}
#endif // ! SDDS_MOVIE_H_
