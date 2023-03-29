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

#ifndef SDDS_WORKSTATION_H
#define SDDS_WORKSTATION_H

#include <iostream>
#include <deque>
#include "CustomerOrder.h"
#include "Station.h"

namespace sdds {
   //// Define global variables for the queues
   extern std::deque<CustomerOrder> g_pending;
   extern std::deque<CustomerOrder> g_completed;
   extern std::deque<CustomerOrder> g_incomplete;

   //Each Workstation is-a-kind-of Station(inherit from station)
   class Workstation : public Station {
      //a double-ended-queue with CustomerOrders entering the back and exiting the front
      std::deque<CustomerOrder> m_orders;   
      //a pointer to the next Workstation on the assembly line.
      Workstation* m_pNextStation{ nullptr }; 

   public:
      //one argument constructor -- receives a reference to an unmodifiable reference 
      //to std::string and passes it to the Station base class.
      Workstation(const std::string& src) : Station(src) {};
      size_t getQueueSize() const;

      //object cannot be copied or moved
      Workstation(const Workstation&) = delete;
      Workstation(Workstation&&) = delete;
      Workstation& operator=(const Workstation&) = delete;
      Workstation& operator=(Workstation&&) = delete;

      void fill(std::ostream& os);    
      bool attemptToMoveOrder();   
      void setNextStation(Workstation* station);
      Workstation* getNextStation() const;
      void display(std::ostream& os) const;
      Workstation& operator+=(CustomerOrder&& newOrder);
   };
}
#endif // !SDDS_WORKSTATION_H