///*
//*****************************************************************************
//                        Milestone 3
//Full Name  : Chunxue You
//Student ID#: 127632214
//Email      : cyou8@myseneca.ca
//Section    : OOP244 NRA
//Date       : 2023-03-28
//Authenticity Declaration:
//I declare this submission is the result of my own work and has not been
//shared with any other student or 3rd party content provider. I have done all
//the coding by myself and only copied the code that my professor provided to
//complete my workshops and assignments.
//*****************************************************************************
//*/

#include "Workstation.h"

namespace sdds {
   
   std::deque<CustomerOrder> g_pending;
   std::deque<CustomerOrder> g_completed;
   std::deque<CustomerOrder> g_incomplete;

   //check customerorders if not empty, fills the order at the front of the queue
   void Workstation::fill(std::ostream& os) {
      if (!m_orders.empty())
         m_orders.front().fillItem(*this, os);
   }

   bool Workstation::attemptToMoveOrder() {
      bool res = false;
      if (!m_orders.empty()) {
         //get customeroder front of the queue
         CustomerOrder& order = m_orders.front();
         //check the item is filed
         if (order.isItemFilled(getItemName())) {
            if (m_pNextStation) {
               //move order to the next station
               size_t nextStationSize = m_pNextStation->getQueueSize();
               *m_pNextStation += std::move(order);
               //if the order has been moved to next, set result to true
               if (nextStationSize < m_pNextStation->getQueueSize()) {
                  res = true;
                  //remove the order from front
                  m_orders.pop_front();
               }
            }
            // If the order cannot be filled completely and there is no next station, 
            //move it to incomplete orders
            else if (!order.isOrderFilled()) {
               g_incomplete.push_back(std::move(order));
               res = true;
               m_orders.pop_front();
            }
            //else move to complete orders
            else {
               g_completed.push_back(std::move(order));
               res = true;
               m_orders.pop_front();
            }
         }
         else if (this->getQuantity() <= 0) {
            if (m_pNextStation) {
               //move order to the next station
               size_t nextStationSize = m_pNextStation->getQueueSize();
               *m_pNextStation += std::move(order);
               //If the order has been moved to the next station, 
               //set result to true and remove the order from this station
               if (nextStationSize < m_pNextStation->getQueueSize()) {
                  res = true;
                  m_orders.pop_front();
               }
            }
            else {
               //If the order cannot be filled completely and there is no next station, 
               //move it to incomplete orders
               g_incomplete.push_back(std::move(order));
               g_incomplete.push_back(std::move(order));
               res = true;
               m_orders.pop_front();
            }
         }
      }
      return res;
   }


   //stores the address of the referenced Workstation object in the pointer to the m_pNextStation.
   void Workstation::setNextStation(Workstation* station) {
      m_pNextStation = station;
   }

   // returns the address of next Workstation
   Workstation* Workstation::getNextStation() const {
      return m_pNextStation;
   }

   //inserts the name of the Item for which the current object is responsible into stream os in format
   void Workstation::display(std::ostream& os) const {
      if (m_pNextStation)
         os << getItemName() << " --> " << m_pNextStation->getItemName() << std::endl;    
      else
         //if the current object is the last Workstation in the assembly line this query inserts: 
         os << getItemName() << " --> " << "End of Line" << std::endl;
   }

   //moves the CustomerOrder referenced in parameter newOrder to the back of the queue.
   Workstation& Workstation::operator+=(CustomerOrder&& newOrder) {
      m_orders.push_back(std::move(newOrder));
      return *this;
   }

   //get custmerorder size
   size_t Workstation::getQueueSize() const {
      return m_orders.size();
   }
}