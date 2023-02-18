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
#include "Movie.h"
namespace sdds {

   //default constructor
   Movie::Movie(){}

   //a query that returns the title of the movie
   const std::string& Movie::title() const{
      return m_movieTitle;
   }

   //receives the movie through a reference to a string. 
   //This constructor extracts the information about the movie from the string and 
   //stores the tokens in the attributes
   Movie::Movie(const std::string& strMovie){
      std::string tempStr = strMovie;
      size_t tempIndx = 0u;

      //TITLE
      tempStr.erase(0, tempStr.find_first_not_of(' '));
      tempIndx = tempStr.find(',');
      m_movieTitle = tempStr.substr(0, tempIndx);
      m_movieTitle.erase(m_movieTitle.find_last_not_of(' ') + 1);
      tempStr.erase(0, tempIndx + 1);
      
      //YEAR
      tempStr.erase(0, tempStr.find_first_not_of(' '));
      tempIndx = tempStr.find(',');
      m_releaseYear = std::stoi(tempStr.substr(0, tempIndx));
      tempStr.erase(0, tempIndx + 1);
      
      //DESCRIPTION
      tempStr.erase(0, tempStr.find_first_not_of(' '));
      m_descrip = tempStr;

   }

   //Friend Helpers
   //overload the insertion operator to insert the content of a movie object into an ostream object
   std::ostream& operator<<(std::ostream& ostr, const Movie& M){
      ostr << std::setw(40) << std::right << M.m_movieTitle << " | ";
      ostr << std::setw(4) << std::right << M.m_releaseYear << " | ";
      ostr << M.m_descrip << std::endl;
      return ostr;
   }

}