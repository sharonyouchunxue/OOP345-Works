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
#ifndef SDDS_CUSTOMERORDER_H
#define SDDS_CUSTOMERORDER_H
#include "Station.h"
namespace sdds{

	struct Item
	{
		std::string m_itemName;
		size_t m_serialNumber{ 0 };
		bool m_isFilled{ false };

		Item(const std::string& src) : m_itemName(src) {};
	};

	class CustomerOrder {
		//Instance Variables
		std::string m_name{ "" };
		std::string m_product{""};
		size_t m_cntItem{0u};
		//dynamically allocated array of pointers
		Item** m_lstItem{ nullptr };
		//Class Variable
		static size_t m_widthField;

	public:
		CustomerOrder();
		CustomerOrder(const std::string& str);
		CustomerOrder(const CustomerOrder& src);
		CustomerOrder& operator=(const CustomerOrder& src) = delete;
		CustomerOrder(CustomerOrder&& src)noexcept;
		CustomerOrder& operator=(CustomerOrder&& src)noexcept;
		~CustomerOrder();
		bool isOrderFilled() const;
		bool isItemFilled(const std::string& itemName) const;
		void fillItem(Station& station, std::ostream& os);
		void display(std::ostream& os) const;
	};
}

#endif // ! SDDS_CUSTOMERORDER_H


