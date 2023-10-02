/*
*****************************************************************************
						  Workshop 3 part 2
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

	extern const int MIN_TIME;
	extern const int MAX_TIME;
	extern const int MAX_NO_OF_PASSENGERS;

	class Train {
		char* m_trainName;
		int m_noPeople;
		int m_departureTime;

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

		// for part 2
		bool load(int& unboardedPassengers);
		bool updateDepartureTime();
		bool transfer(const Train& otherTrain);


	};
}

#endif // SDDS_TRAIN_H



