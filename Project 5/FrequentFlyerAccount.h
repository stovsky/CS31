#ifndef FrequentFlyerAccount_h
#define FrequentFlyerAccount_h

#include <iostream>
#include <string>
#include "PlaneFlight.h"
using namespace std;

class FrequentFlyerAccount {
private:
    string mName;
    double mBalance;
public:
    FrequentFlyerAccount(string name);
    
    double getBalance();
    string getName();
    
    bool addFlightToAccount(PlaneFlight flight);
    bool canEarnFreeFlight(double mileage);
    bool freeFlight(string from, string to, double mileage, PlaneFlight & flight);

};


#endif
