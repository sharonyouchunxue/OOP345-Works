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
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include "LineManager.h"
#include "Utilities.h"

using namespace std;

namespace sdds {

   LineManager::LineManager(const std::string& file, const std::vector<Workstation*>& stations) {
      // Create an instance of the Utilities class
      Utilities util;
      // Declare variables to store a line of text and a file stream object
      std::string line;
      std::ifstream fin(file);
      // If the file cannot be opened, throw an exception with an error message
      if (!fin) {
         throw std::string("\n***Failed to open file ") + file + std::string(" ***\n");
      }
      // Read each line of the file
      while (std::getline(fin, line)) {
         // If the line is empty, skip it
         if (line.empty()) {
            continue;
         }
         // Extract the names of the current and next workstations from the line
         std::string cur_ws, next_ws;
         size_t pos = 0;
         bool more = false;
         cur_ws = util.extractToken(line, pos, more);
         next_ws = more ? util.extractToken(line, pos, more) : "";
         // Find the current workstation in the list of all workstations
         auto cur_ws_it = std::find_if(stations.begin(), stations.end(), [&](const Workstation* ws) {
            return ws->getItemName() == cur_ws;
            });
         // If the current workstation is not found, throw an exception with an error message
         if (cur_ws_it == stations.end()) {
            throw std::string("\n\n***Invalid***\n\n");
         }
         // Get a pointer to the current workstation
         Workstation* cur_ws_ptr = *cur_ws_it;
         // If the next workstation is not empty, find it in the list of all workstations
         if (!next_ws.empty()) {
            auto next_ws_it = std::find_if(stations.begin(), stations.end(), [&](const Workstation* ws) {
               return ws->getItemName() == next_ws;
               });
            // If the next workstation is not found, throw an exception with an error message
            if (next_ws_it == stations.end()) {
               throw std::string("\n\n***Next Workstation is not found***\n\n");
            }
            // If the current workstation is the same as the next workstation, throw an exception with an error message
            if (cur_ws == next_ws) {
               throw std::string("\n\n***Next Workstation is not found***\n\n");
            }
            // Set the next workstation for the current workstation
            cur_ws_ptr->setNextStation(*next_ws_it);
         }
         // Add the current workstation to the list of active workstations
         m_activeLine.push_back(cur_ws_ptr);
      }
      // Close the file
      fin.close();
      // Find the first workstation in the assembly line by looking for a workstation with no previous workstation
      for (Workstation* ws : m_activeLine) {
         auto prev_ws = std::find_if(stations.begin(), stations.end(), [&](const Workstation* prev) {
            return prev->getNextStation() == ws;
            });
         // If the previous workstation is not found, set the first workstation to the current workstation and break out of the loop
         if (prev_ws == stations.end()) {
            m_firstStation = ws;
            break;
         }
      }
      // Set the number of customer orders to the size of the global pending orders list
      m_cntCustomerOrder = g_pending.size();
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
      // Counter to keep track of the number of times this function has been called
      static size_t count = 0u;

      // Output the iteration number
      os << "Line Manager Iteration: " << ++count << endl;

      // If there are pending orders, move the first one to the front of the active line
      if (!g_pending.empty()) {
         *m_activeLine.front() += move(g_pending.front());
         g_pending.pop_front();
      }

      // Fill orders for each station in the active line
      for (size_t i = 0; i < m_activeLine.size(); i++) {
         m_activeLine[i]->fill(os);
      }

      // Attempt to move orders along the assembly line for each station in the active line
      for (size_t i = 0; i < m_activeLine.size(); i++) {
         m_activeLine[i]->attemptToMoveOrder();
      }

      // Return true if all customer orders have been completed or marked incomplete
      return m_cntCustomerOrder == g_completed.size() + g_incomplete.size();
   }

   //displays all active stations on the assembly line in their current order
   void LineManager::display(std::ostream& os) const {
      for_each(m_activeLine.begin(), m_activeLine.end(), [&](Workstation* src) {
         src->display(os);
         });
   }
}