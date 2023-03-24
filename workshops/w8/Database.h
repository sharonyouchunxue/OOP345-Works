/*
*****************************************************************************
                        Workshop 8
Full Name  : Chunxue You
Student ID#: 127632214
Email      : cyou8@myseneca.ca
Section    : OOP244 NRA
Date       : 2023-03-24
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. I have done all
the coding by myself and only copied the code that my professor provided to
complete my workshops and assignments.
*****************************************************************************
*/

#ifndef SDDS_DATABASE_H
#define SDDS_DATABASE_H
#include <iostream>
#include <iomanip>
#include <memory>
#include <algorithm>
#include <fstream>
namespace sdds {
   
   enum class Err_Status
   {
      Err_Success,
      Err_NotFound,
      Err_OutOfMemory,
   };

   template<typename T>
   class Database {    
      static std::shared_ptr<Database> m_instance; //class member
      size_t m_noOfEntries{ 0u };
      std::string m_keys[20]{};
      T m_values[20]{};
      //std::vector<std::string> m_keys{};
      //std::vector<T> m_values{};
      std::string m_filename;
      
      // Declare getInstance as a friend function
      Database(const std::string& filename) : m_filename(filename) {
         //Print address and prototype of the constructor
         std::cout << "[" << this << "]" << "Database(const std::string&)" << std::endl;

         //Open the file and read key/value pairs
         std::ifstream fin(filename);
         std::string key;
         T value;
         size_t i = 0;
         while (fin >> key >> value&& i < 20) {
            // Replace underscores with spaces in keys
            std::replace(key.begin(), key.end(), '_', ' ');
            //call the encryptDecrypt() function, passing the value as a parameter
            encryptDecrypt(value);
            m_keys[i] = key;
            m_values[i] = value;
            m_noOfEntries++;
            i++;
         }
      }

      //an empty body function
      void encryptDecrypt(T& value){}

   public: 

      static std::shared_ptr<Database>getInstance(const std::string& filename) {
         if (m_instance == nullptr) {
            m_instance = std::shared_ptr<Database>(new Database(filename));
         }
         return m_instance;
      }

      Err_Status GetValue(const std::string& key, T& value) {
         for (size_t i = 0; i < 20; ++i) {
            if (m_keys[i] == key) {
               value = m_values[i];
               return Err_Status::Err_Success;
            }
         }
         return Err_Status::Err_NotFound;
      }

      Err_Status SetValue(const std::string& key, const T& value) {
         // Check if there is space in the database
         if (m_noOfEntries >= (sizeof(m_keys) / sizeof(m_keys[0]))) {
            return Err_Status::Err_OutOfMemory;
         }

         // Check if the key already exists in the database
         size_t index = -1;
         for (size_t i = 0; i < m_noOfEntries; i++) {
            if (m_keys[i] == key) {
               index = i;
               break;
            }
         }

         //if (index != -1) {
         if (index != static_cast<size_t>(-1)) {
            m_values[index] = value;
            return Err_Status::Err_Success;
         }

         // Add the new key/value pair to the database
         m_keys[m_noOfEntries] = key;
         m_values[m_noOfEntries] = value;
         m_noOfEntries++;

         return Err_Status::Err_Success;
      }

      ~Database() {
         //Print address and prototype of the constructor
         std::cout << "[" << this << "]" << "~Database()" << std::endl;

         // create backup file name
         std::string backupFileName = m_filename + ".bkp.txt";

         // open backup file
         std::ofstream backupFile(backupFileName);       
  
         // iterate over the record and write it out to backup file
         //for (size_t i = 0; i < sizeof(m_keys) / sizeof(m_keys[0]); ++i) {
         for (size_t i = 0; i < m_noOfEntries; ++i) {
            // call the encryptDecrypt() function, passing the value as a parameter   
            T valueCopy = m_values[i];
            encryptDecrypt(valueCopy);
            backupFile << std::left << std::setw(25) << m_keys[i] << " -> " << valueCopy << std::endl;
         }
         // close backup file
         backupFile.close();
      }
   };

   template<typename T>
   // Definition of static member variable m_instance
   std::shared_ptr<Database<T>> Database<T>::m_instance = nullptr;

   // Specialization for std::string
   template<>
   void Database<std::string>::encryptDecrypt(std::string& value) {
      const char secret[]{ "secret encryption key" };
      std::for_each(value.begin(), value.end(), [secret](char& c) {
         std::for_each(secret, secret + sizeof(secret) - 1, [&c](const char& k) {
            c ^= k; 
            });
         });
   }

   // Specialization for long long
   template<>
   void Database<long long>::encryptDecrypt(long long& value) {
      const char secret[]{ "super secret encryption key" };
      char* byte = reinterpret_cast<char*>(&value);
      std::for_each(byte, byte + sizeof(long long), [&secret](char& b) {
         for (char k : secret) {
            b ^= k;
         }
         });
   }
}
#endif // ! SDDS_DATABASE_H
