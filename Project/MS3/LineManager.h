/*
*****************************************************************************
                        Milestone 3
Full Name  : Chunxue You
Student ID#: 127632214
Email      : cyou8@myseneca.ca
Section    : OOP244 NRA
Date       : 2023-04-03
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. I have done all
the coding by myself and only copied the code that my professor provided to
complete my workshops and assignments.
*****************************************************************************
*/
#ifndef SDDS_LINEMANAGER_H
#define SDDS_LINEMANAGER_H
#include <vector>
#include "Workstation.h"

namespace sdds {
   class LineManager{
      // the collection of workstations for the current assembly line.
      std::vector<Workstation*> m_activeLine;
      //the total number of CustomerOrder objects
      size_t m_cntCustomerOrder{ 0u }; 
      //points to the first active station on the current line
      Workstation* m_firstStation; 
                   
   public:
      LineManager(const std::string& file, const std::vector<Workstation*>& stations);
      void reorderStations();
      bool run(std::ostream& os);
      void display(std::ostream& os) const;
   };

}
#endif // !SDDS_LINEMANAGER_H

