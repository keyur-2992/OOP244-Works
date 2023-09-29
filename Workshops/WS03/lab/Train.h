#ifndef SDDS_TRAIN_H
#define SDDS_TRAIN_H

namespace sdds {

	class Train {
		char* m_trainName;
		int m_noPeople;
		int m_departureTime;

	public:
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



