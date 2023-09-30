/*
*****************************************************************************
						  Workshop 3 part 1
Full Name  : keyurkumar shankarlal patel
Student ID#: 170852214
Email      : kpatel453@myseneca.ca
Section    : ZAA

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/
#ifndef SDDS_TRAIN_H
#define SDDS_TRAIN_H

namespace sdds {

	class Train {
		char* m_trainName;
		int m_noPeople;
		int m_departureTime;

		const int MIN_TIME = 700;
		const int MAX_TIME = 2300;
		const int MAX_NO_OF_PASSENGERS = 1000;

	public:

		Train();
		Train(const char* name, int noOfPassengers, int departure);
		~Train();

		void initialize();
		bool validTime(int value)const;
		bool validNoOfPassengers(int value)const;
		void set(const char* name);
		void set(int noOfPassengers, int departure);
		void set(const char* name, int noOfPassengers, int departure);
		void finalize();
		bool isInvalid()const;
		int noOfPassengers() const;
		const char* getName() const;
		int getDepartureTime() const;
		void display() const;

	};
}

#endif // SDDS_TRAIN_H



