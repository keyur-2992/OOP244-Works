/***********************************************************************
// OOP244 Workshop #5 DIY (part 2): tester program
//
// File  Portfolio.h
// Version 1.0
// Author   Asam Gulaid, revised by Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name                 Date            Reason
***********************************************************************/
#ifndef SDDS_Portfolio_H_
#define SDDS_Portfolio_H_
#include <iostream>
#include <cstring>

namespace sdds {

   class Portfolio {
      double m_value = 0;
      char m_stock[16];
      char m_type;

   public:
       Portfolio();
       Portfolio(double value, const char* stock, char type);
       void emptyPortfolio();
       void dispPortfolio() const;
       bool isVaild() const;
       std::ostream& display() const;

       operator bool() const;
       operator const char* () const;
       operator char() const;
       operator double() const;

       Portfolio& operator+=(double value);
       Portfolio& operator-=(double value);
       bool operator~() const;

       Portfolio& operator<<(Portfolio& right);
       Portfolio& operator>>(Portfolio& right);
   };
   double operator+(Portfolio& left, Portfolio& right);
   double operator+=(double& left, Portfolio& right);
}
#endif // SDDS_Portfolio_H_