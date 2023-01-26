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
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include "TimedTask.h"

namespace sdds {
   TimedTask::TimedTask(){
      m_noOfRecs = 0;
   }
   //starts the timer for an event
   void TimedTask::startClock(){
      start = std::chrono::steady_clock::now();
   }
   //stops the timer for an event
   void TimedTask::stopClock(){
      end = std::chrono::steady_clock::now();
   }

   //receives the address of a C-style null-terminated string that holds the name of the task
   void TimedTask::addTask(const char* taskName){
      if (m_noOfRecs < 10) {
         //stores into the name attribute the C-style string received as parameter
         m_task[m_noOfRecs].m_taskName = taskName;
         //stores "nanoseconds" as the units of time
         m_task[m_noOfRecs].m_unitsOftime = "nanoseconds";
         //calculates and stores the duration of the event
         m_task[m_noOfRecs].m_duration = end - start;
         //number of record increment
         m_noOfRecs++;
      }
   }

   //friend insertion operator that receives a reference to an std::ostream object and a TimedTaskobject.
   std::ostream& operator<<(std::ostream& ostr, const TimedTask& object){
      ostr << "--------------------------" << std::endl;
      ostr << "Execution Times:" << std::endl;
      ostr << "--------------------------" << std::endl;
      for (int i = 0; i < object.m_noOfRecs; i++) {
         //display the task name
         ostr << std::left << std::setw(21) << object.m_task[i].m_taskName << " ";
         //display the duration
         ostr << std::right << std::fixed << std::setprecision(0) << std::setw(13) << object.m_task[i].m_duration.count() << " ";
         //display the unit of time
         ostr << object.m_task[i].m_unitsOftime << std::endl;
      }
      ostr << "--------------------------" << std::endl;
      return ostr;
   }

}