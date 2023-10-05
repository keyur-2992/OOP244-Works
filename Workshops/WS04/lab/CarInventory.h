/*
*****************************************************************************
						  Workshop 4 Part 1
Full Name  : keyurkumar shankarlal patel
Student ID#: 170852214
Email      : kpatel453@myseneca.ca
Section    : Z

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/
#ifndef SDDS_CARINVENTORY_H
#define SDDS_CARINVENTORY_H

namespace sdds {

	class CarInventory {
		char* m_type;
		char* m_brand;
		char* m_model;
		int m_year;
		int m_code;
		double m_price;

		void resetInfo();

	public:
		CarInventory();
		CarInventory(const char* type, const char* brand, const char* model, int year = 2022, int code = 100, double price = 1.0);
		~CarInventory();
		CarInventory& setInfo(const char* type, const char* brand, const char* model, int year, int code, double price);
		void printInfo() const;
		bool isValid() const;
		bool isSimilarTo(const CarInventory& car) const;
	};

	int find_similar(CarInventory car[], const int num_cars);
}
#endif // !SDDS_CARINVENTORY_H
