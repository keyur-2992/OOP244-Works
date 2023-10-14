/***********************************************************************
// OOP244 Workshop #5 lab (part 1): tester program
//
// File  Flight.h
// Version 1.0
// Author   Asam Gulaid, revised by Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name keyurkumar Patel  Date 10-OCT-2023  STU ID 170852214
***********************************************************************/
#ifndef SDDS_FLIGHT_H
#define SDDS_FLIGHT_H
#include <iostream>

namespace sdds {

   const int Boen747Capacity = 388;
   const int FuelTankCapacity = 238840;

   class Flight {

      int m_passengers = 0;
      double m_fuel = 0;
      char m_title[16];
      void emptyPlane();

   public:
      Flight();
      Flight(int passengers, double fuel, const char* title);
      std::ostream& display()const;

      operator bool() const;
      operator int() const;
      operator double() const;
      operator const char* () const;
      bool operator ~() const;

      Flight& operator=(Flight& first);
      Flight& operator=(int passenger);
      Flight& operator=(double fuel);

      Flight& operator+=(double fuel);
      Flight& operator+=(int passenger);

      Flight& operator-=(double fuel);
      Flight& operator-=(int passenger);

      Flight& operator>>(Flight& right);
      Flight& operator<<(Flight& right);
   };

   int operator+ (Flight& left, Flight& right);
   int operator+=(int& left, Flight& right);

}
#endif // SDDS_FLIGHT_H