/*
*****************************************************************************
                        Milestone 3
Full Name  : Chunxue You
Student ID#: 127632214
Email      : cyou8@myseneca.ca
Section    : OOP244 NRA
Date       : 2023-03-21
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. I have done all
the coding by myself and only copied the code that my professor provided to
complete my workshops and assignments.
*****************************************************************************
*/

#include <iostream>
#include "Workstation.h"
namespace sdds {
   ////1 argument constructor-> passes Station base class
   Workstation::Workstation(const std::string& str) : Station(str) {
      m_pNextStation = nullptr;
   }
   //fills the order at the front of the queue if there are 
   //CustomerOrders in the queue; otherwise, does nothing.
   void Workstation::fill(std::ostream& os) {
      if (m_orders.empty())
         m_orders.front().fillItem(*this, os);
   }


   bool Workstation::attemptToMoveOrder() {
      bool moved = false;
      if (!m_orders.empty() && m_pNextStation) {
         if (m_orders.front().isItemFilled(this->getItemName())) {
            *m_pNextStation += std::move(m_orders.front());
         }
         else if (!m_orders.front().isOrderFilled()) {
            g_incomplete.push_back(std::move(m_orders.front()));
         }
         else {
            g_completed.push_back(std::move(m_orders.front()));
            m_orders.pop_front();
            moved = true;
         }
      }
      else {
         if (m_pNextStation)
            *m_pNextStation += std::move(m_orders.front());
         else
            g_incomplete.push_back(std::move(m_orders.front()));

         moved = true;
         m_orders.pop_front();
      }
      return moved;
   }

   //stores the address of the referenced Workstation object in the pointer to the m_pNextStation.
   //Parameter defaults to nullptr.
   void Workstation::setNextStation(Workstation* station) {
      station = m_pNextStation;
   }

   // returns the address of next Workstation
   Workstation* Workstation::getNextStation() const {
      return m_pNextStation;
   }

   //inserts the name of the Item for which the current object is responsible into stream os following the forma
   void Workstation::display(std::ostream& os) const {
      if (m_pNextStation)
         os << getItemName() << " --> " << m_pNextStation->getItemName() << std::endl;
      else
         os << getItemName() << " --> " << "End of Line" << std::endl;
   }

   //moves the CustomerOrder referenced in parameter newOrder to the back of the queue.
   Workstation& Workstation::operator+=(CustomerOrder&& newOrder){
      m_orders.push_back(std::move(newOrder));
      return *this;
   }

}