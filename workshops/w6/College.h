/*
*****************************************************************************
                        Workshop 6
Full Name  : Chunxue You
Student ID#: 127632214
Email      : cyou8@myseneca.ca
Section    : OOP244 NRA
Date       : 2023-03-04
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. I have done all
the coding by myself and only copied the code that my professor provided to
complete my workshops and assignments.
*****************************************************************************
*/
#ifndef SDDS_COLLEGE_H
#define SDDS_COLLEGE_H
#include <vector>
#include <list>
#include "Person.h"

namespace sdds {
   class College {
      //vector that store all the persons present at this college. 
      //All these Person objects will be dynamically allocated;
      std::vector<Person*> m_persons;
   public:
      College();
      // copy operations disabled
      College(const College&) = delete;
      College& operator=(const College&) = delete;
      College& operator +=(Person* thePerson);
      void display(std::ostream& out) const;

      template<typename T>
      // template function that iterates over the persons stored in the m_persons, 
      //and adds to the second parameter all persons for which the test is true.
      void select(const T& test, std::list<const Person*>& persons) {
         for (auto& person : m_persons) {
            if (test(person)) {
               persons.push_back(person);
            }
         }
      }
      ~College();
   };


}

#endif //!SDDS_COLLEGE_H