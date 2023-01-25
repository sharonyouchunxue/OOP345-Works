///*
//*****************************************************************************
//                        Workshop 2
//Full Name  : Chunxue You
//Student ID#: 127632214
//Email      : cyou8@myseneca.ca
//Section    : OOP244 NRA
//Date       : 2023-01-23
//Authenticity Declaration:
//I declare this submission is the result of my own work and has not been
//shared with any other student or 3rd party content provider. I have done all
//the coding by myself and only copied the code that my professor provided to
//complete my workshops and assignments.
//*****************************************************************************
//*/
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include "ProteinDatabase.h"
using namespace std;

namespace sdds {

   //default constructor
   ProteinDatabase::ProteinDatabase(){
   }
   //one argument constructor
   ProteinDatabase::ProteinDatabase(const char* filename) {
       unsigned int counter = 0;
      if (filename) {
         //create instance ifstream
         ifstream fin(filename);
         string temp;
         if (fin.is_open()) {
            while (getline(fin, temp))
               if (temp[0] == '>')
                  counter++;
         }
         fin.close();
         //Each line (except the last one) will contain exactly 60 characters.
         m_noOfstrings = counter;
         //allocates memory for that number of protein sequences in the array
         m_string = new string[m_noOfstrings + 1];
         //re-reads the file and loads the protein sequences (i.e., string of characters 
         //not sequence names) into the array.
         unsigned int i = 0;
         fin.open(filename);
         if (fin.is_open()) {
            while (getline(fin, temp) && i < m_noOfstrings)
            {
               if (temp[0] != '>') {
                  m_string[i] += temp;
               }
               if (temp[0] == '>' && !m_string[i].empty()) {
                  i++;
               }
            }
            fin.close();
         }
       }
      }

      //a query that returns the number of protein sequences stored in the current object
      std::size_t ProteinDatabase::size() {
         return m_noOfstrings;
      }

      //a query that returns a copy of the protein sequence at the index received 
      //as the function parameter. 
      std::string ProteinDatabase::operator[](size_t src) {
         string copy = "";
         //check if the index is invalid, this function, return an empty string.
         if (src > m_noOfstrings - 1 || src < 0 || m_noOfstrings == 0) {
            //copy = m_string[src];
            return copy;
         }
         else {
            return m_string[src];
         }
   }


   //copy constructor
	ProteinDatabase::ProteinDatabase(const ProteinDatabase& src) {
		if (src.m_string != nullptr) {
			this->m_string = new string[src.m_noOfstrings];
			unsigned int i;
			for (i = 0; i < src.m_noOfstrings; i++) {
				this->m_string[i] = src.m_string[i];
			}
			this->m_noOfstrings = src.m_noOfstrings;
	  }
   }

   //copy assignment operator
   ProteinDatabase& ProteinDatabase::operator=(ProteinDatabase& src) {
		if (this != &src) {
			this->m_string = new string[src.m_noOfstrings];
			unsigned int i;
			for (i = 0; i < src.m_noOfstrings; i++) {
				this->m_string[i] = src.m_string[i];
			}
			this->m_noOfstrings = src.m_noOfstrings;
		}
		return (*this);
   }
   //move copy constructor
   ProteinDatabase::ProteinDatabase(ProteinDatabase&& src) noexcept {
       *this = std::move(src);
   }

   //move assignment operator
   ProteinDatabase& ProteinDatabase::operator=(ProteinDatabase&& src) noexcept{
		if (this != &src) {
			delete[] m_string;
			this->m_string = src.m_string;
			src.m_string = nullptr;
			this->m_noOfstrings = src.m_noOfstrings;
			src.m_noOfstrings = 0u;
		}
		return (*this);
   }

   //destructor
   ProteinDatabase::~ProteinDatabase(){
      delete[] m_string;
   }

}





