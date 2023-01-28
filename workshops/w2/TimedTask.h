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

#ifndef SDDS_TIMEDTASK_H_
#define SDDS_TIMEDTASK_H_
#include <chrono>

namespace sdds {
   struct Task {
      std::string m_taskName{};
      std::string m_unitsOftime{};
      //the duration of the task, and object type
      std::chrono::duration<double, std::nano> m_duration;
   };

   class TimedTask {
      //class predefines the maximum number of event objects at 10
      struct Task m_task[10]{};
      int m_noOfRecs{0};
      //the start time for the current task (an object of type std::chrono::steady_clock::time_point
      std::chrono::time_point<std::chrono::steady_clock> start;
      //the end time for the current task (an object of type std::chrono::steady_clock::time_point). 
      std::chrono::time_point<std::chrono::steady_clock> end;
   public:
      //default constructor
      TimedTask();
      void startClock();
      void stopClock();
      void addTask(const char* taskName);
      friend std::ostream& operator<<(std::ostream& ostr, const TimedTask& object);
   };
}

#endif // !SDDS_TIMETASK_H_
