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
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include "LineManager.h"
#include "Utilities.h"

using namespace std;

namespace sdds {

   LineManager::LineManager(const std::string& file, const std::vector<Workstation*>& stations) {
      vector<string> v_cur, v_next;
      Utilities temp_util;
      string    eachLine = "", cur_Wstation = "", next_Wstation = "";
      size_t    pos = 0u;
      bool      more = false;
      ifstream  read_file(file);

      if (!read_file)
         throw string("\n***Failed to open file ") + string(file) + string(" ***\n");

      else {
         while (std::getline(read_file, eachLine)) {
            if (!eachLine.empty()) {
               cur_Wstation = temp_util.extractToken(eachLine, pos, more);
               v_cur.push_back(cur_Wstation);

               next_Wstation = !more ? "" : temp_util.extractToken(eachLine, pos, more);
               v_next.push_back(next_Wstation);

               auto cur_err_check = any_of(stations.begin(), stations.end(), [=](Workstation* first_src) {
                  if (first_src->getItemName() == cur_Wstation) {
                     if (!next_Wstation.empty()) {
                        auto next_err_check = any_of(stations.begin(), stations.end(), [=](Workstation* sec_src) {
                           if (sec_src->getItemName() == next_Wstation) {
                              first_src->setNextStation(sec_src);
                              return true;
                           }
                           else
                              return false;
                           });

                        if (!next_err_check) throw string("\n\n***Next Workstation is not found***\n\n");
                        else if (cur_Wstation == next_Wstation) throw string("\n\n***Next Workstation is not found***\n\n");
                     }
                     m_activeLine.push_back(first_src);
                     return true;
                  }

                  else
                     return false;
                  });

               if (!cur_err_check)
                  throw string("\n\n***Invalid***\n\n");
            }
         }
         read_file.close();

         for_each(m_activeLine.begin(), m_activeLine.end(), [=](Workstation* first_src) {
            auto start = any_of(stations.begin(), stations.end(), [=](Workstation* sec_src) {
               if (sec_src->getNextStation() == first_src)
               return true;
               else
                  return false;
               });

         if (!start)
            m_firstStation = first_src;
            });

         m_cntCustomerOrder = g_pending.size();
      }
   }

   void LineManager::reorderStations() {
      std::vector<Workstation*> reorderedStations;
      Workstation* nextStation = m_firstStation;

      // Loop through the line and add each station to the reordered collection
      while (nextStation) {
         reorderedStations.push_back(nextStation);
         nextStation = nextStation->getNextStation();
      }
      // Rearrange the reordered collection to start at the first station
      auto firstStation = std::find(reorderedStations.begin(), reorderedStations.end(), m_firstStation);
      std::rotate(reorderedStations.begin(), firstStation, reorderedStations.end());
      // Update the active line with the reordered collection
      m_activeLine = reorderedStations;
   }

   bool LineManager::run(std::ostream& os) {
      static size_t count = 0u;
      os << "Line Manager Iteration: " << ++count << endl;
      // Move orders from the pending queue to the first station in the active line
      if (!g_pending.empty()) {
         *m_activeLine.front() += std::move(g_pending.front());
         g_pending.pop_front();
      }
      // Fill and attempt to move orders at each station in the active line
      std::for_each(m_activeLine.begin(), m_activeLine.end(),[&os](Workstation* station) {
            station->fill(os);
            station->attemptToMoveOrder();
         });
      // Check if all customer orders have been completed or not
      bool allOrdersCompleted = m_cntCustomerOrder == g_completed.size() + g_incomplete.size();

      return allOrdersCompleted;
   }

   //displays all active stations on the assembly line in their current order
   void LineManager::display(std::ostream& os) const {
      for_each(m_activeLine.begin(), m_activeLine.end(), [&](Workstation* src) {
         src->display(os);
         });
   }
}