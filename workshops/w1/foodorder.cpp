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
using namespace std;

double g_taxrate = 0.0;
double g_dailydiscount = 0.0;

namespace sdds {
	//set all values
	void FoodOrder::set(const char* customerName, const char* foodDescription, const double price, const char dailySpecial) {
		strcpy(m_customerName, customerName);
		m_foodDescription = new char[strlen(foodDescription) + 1];
		strcpy(m_foodDescription, foodDescription);
		m_foodPrice = price;
		if (dailySpecial == 'Y') {
			m_dailySpecial = true;
		}
		else {
			m_dailySpecial = false;
		}
	}

	//set safety empty state
	void FoodOrder::setEmpty() {
		m_foodDescription = nullptr;
		m_customerName[0] = '\0';
		m_foodPrice = -1;
		m_dailySpecial = false;
	}

	bool FoodOrder::isEmpty(){
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
		setEmpty();
			char tempcustName[10];
			//read customer name up to comma
			istr.get(tempcustName, 10, ',');
			istr.ignore();
			//read food description up to comma
			std::string tempDescription;
			getline(istr, tempDescription, ',');
			//read food price
			double tempFoodPrice = -1;
			istr >> tempFoodPrice;
			istr.ignore();
			//read  special status
			char tempSpecialStatus;
			istr >> tempSpecialStatus;
			//check if cin is in good state, if cin not fail, call set 
			//function to set all the value
			if (!istr.fail()) {
			   this->set(tempcustName, tempDescription.c_str(), tempFoodPrice, tempSpecialStatus);
			}
	}

	//display function to print the formated value
	void FoodOrder::display() {
		static int counter = 0;
		if (!isEmpty())
		{
			double afterTaxPrice= m_foodPrice * (1 + g_taxrate);
			double specialPrice = afterTaxPrice - g_dailydiscount;

			cout << left << setw(2) << ++counter 
				<< ". "
				<< left << setw(10) << m_customerName
				<< "|"
				<< left << setw(25) << m_foodDescription
				<< "|"
				<< left << setw(12) << fixed << setprecision(2) << afterTaxPrice
				<< "|";
			if (m_dailySpecial)
				cout << right << setw(13) << specialPrice;
			   cout << endl;
		}
		else {
			cout << left << setw(2) << ++counter
				<< ". "
				<< "No Order"
				<< endl;

		}
	}
}




