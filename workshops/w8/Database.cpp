///*
//*****************************************************************************
//                        Workshop 8
//Full Name  : Chunxue You
//Student ID#: 127632214
//Email      : cyou8@myseneca.ca
//Section    : OOP244 NRA
//Date       : 2023-03-22
//Authenticity Declaration:
//I declare this submission is the result of my own work and has not been
//shared with any other student or 3rd party content provider. I have done all
//the coding by myself and only copied the code that my professor provided to
//complete my workshops and assignments.
//*****************************************************************************
//*/
//
//#include <iostream>
//#include <iomanip>
//#include "Database.h"
//
//namespace sdds {
//   std::shared_ptr<Database> Database::m_instance = nullptr;
//
//   std::shared_ptr<Database> Database::getInstance(const std::string& filename) {
//      if (m_instance == nullptr) {
//         m_instance = std::shared_ptr<Database>(new Database(filename));
//      }
//      return m_instance;
//   }
//
//   Err_Status Database::GetValue(const std::string& key, std::string& value) {
//      auto result = std::find(m_keys.begin(), m_keys.end(), key);
//      if (result != m_keys.end()) {
//         value = m_values[std::distance(m_keys.begin(), result)];
//         return Err_Status::Err_Success;
//      }
//      return Err_Status::Err_NotFound;
//   }
//
//   Err_Status Database::SetValue(const std::string& key, const std::string& value) {
//      // Check if there is space in the database
//      if (m_noOfEntries >= m_keys.size()) {
//         return Err_Status::Err_OutOfMemory;
//      }
//
//      // Check if the key already exists in the database
//      for (size_t i = 0; i < m_noOfEntries; i++) {
//         if (m_keys[i] == key) {
//            m_values[i] = value;
//            return Err_Status::Err_Success;
//         }
//      }
//
//      // Add the new key/value pair to the database
//      m_keys[m_noOfEntries] = key;
//      m_values[m_noOfEntries] = value;
//      m_noOfEntries++;
//
//      return Err_Status::Err_Success;
//   }
//
//   Database::~Database() {
//      //Print address and prototype of the constructor
//      std::cout << "[" << this << "]" << "~Database()" << std::endl;
//
//      // create backup file name
//      std::string backupFileName = m_filename + ".bkp.txt";
//
//      // open backup file
//      std::ofstream backupFile(backupFileName);
//
//      // iterate over the record and write it out to backup file
//         for (size_t i = 0; i < m_keys.size(); ++i) {
//            backupFile <<std::left << std::setw(25)<< m_keys[i] << " -> " << m_values[i] << std::endl;
//         }
//      // close backup file
//      backupFile.close();
//
//   }
//
//
//}





