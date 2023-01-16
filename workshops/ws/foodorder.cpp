/*
*****************************************************************************
						Workshop 1
Full Name  : Chunxue You
Student ID#: 127632214
Email      : cyou8@myseneca.ca
Section    : OOP244 NRA
Date       : 2023-01-14
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
#include <fstream>
#include <cstring>
#include <string>
#include "foodorder.h"

double g_taxrate = 0.0;
double g_dailydiscount = 0.0;

namespace sdds {

	void FoodOrder::set(const char* customerName, const char* foodDescription, const double price, const char dailySpecial) {
		strcpy(m_customerName, customerName);

		m_foodDescription = new char[strlen(foodDescription) + 1];
		strcpy(m_foodDescription, foodDescription);

		m_foodPrice = price;
		m_dailySpecial = dailySpecial == 'Y' ? true : false;
	}

	void FoodOrder::setEmpty() {
		m_foodDescription = nullptr;
		m_customerName[0] = '\0';
		m_foodPrice = -1;
		m_dailySpecial = false;
	}

	bool FoodOrder::isEmpty() {
		return m_customerName[0] == '\0';
	}
	FoodOrder::FoodOrder() {
		setEmpty();
	}

	//destructor
	FoodOrder::~FoodOrder() {
		if (m_foodDescription != nullptr)
			delete[] m_foodDescription;
	}

	//read(): a modifier that receives an istream reference.
	void FoodOrder::read(std::istream& istr) {
		char tempName[10];
		istr.get(tempName, 10, ',');
		istr.ignore();

		std::string Desc;
		getline(istr, Desc, ',');

		double foodPrice = -1;
		istr >> foodPrice;
		istr.ignore();

		char specialStatus;
		istr >> specialStatus;

		if (!istr.fail()) {
			this->set(tempName, Desc.c_str(), foodPrice, specialStatus);
		}
	}

	void FoodOrder::display() {
		static int counter = 0;
		if (!isEmpty()) {
			std::cout.width(2);
			std::cout.setf(std::ios::left);
			std::cout << ++counter << ". ";
			std::cout.unsetf(std::ios::left);
			std::cout << "No Order" << std::endl;
		}
		else {
			double priceWithTax = m_foodPrice * (1 + g_taxrate);
			double specialPrice = priceWithTax - g_dailydiscount;
			std::cout.width(2);
			std::cout.setf(std::ios::left);
			std::cout << ++counter << ". ";
			std::cout.unsetf(std::ios::left);
			std::cout.width(10);
			std::cout.setf(std::ios::left);
			std::cout << m_customerName;
			std::cout.unsetf(std::ios::left);
			std::cout << "|";
			std::cout.width(25);
			std::cout.setf(std::ios::left);
			std::cout << m_foodDescription;
			std::cout.unsetf(std::ios::left);
			std::cout << "|";
			std::cout.width(12);
			std::cout.setf(std::ios::fixed);
			std::cout.precision(2);
			std::cout.setf(std::ios::left);
			std::cout << priceWithTax;
			std::cout.unsetf(std::ios::left);
			std::cout << "|";

			if (m_dailySpecial) {
				std::cout.width(13);
				std::cout.setf(std::ios::right);
				std::cout << specialPrice;
				std::cout.unsetf(std::ios::right);
				std::cout << std::endl;
			}
		}
	}
}




