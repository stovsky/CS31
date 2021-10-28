#include <iostream>
#include <string>
#include "PlaneFlight.h"
#include "FrequentFlyerAccount.h"
using namespace std;

FrequentFlyerAccount::FrequentFlyerAccount(string name) {
    mName = name;
    mBalance = 0;
}

double FrequentFlyerAccount::getBalance() {
    return mBalance;
}

string FrequentFlyerAccount::getName() {
    return mName;
}

bool FrequentFlyerAccount::addFlightToAccount(PlaneFlight flight) {
    
    // Only add flight to the account if the names match
    if (mName != flight.getName()) return false;
    
    // Balance only gets added if the flight is not free
    if (flight.getCost() > 0) mBalance += flight.getMileage();
    return true;
}

bool FrequentFlyerAccount::canEarnFreeFlight(double mileage) {
    
    // Check if the balance is greater than or equal to the mileage
    if (mBalance >= mileage) return true;
    else return false;
}

bool FrequentFlyerAccount::freeFlight(string from, string to, double mileage, PlaneFlight &flight) {
    
    // Check if the account has enough balance to redeem a free flight
    if (mBalance < mileage) return false;
    
    // Create the desired PlaneFlight with zero cost
    // Redeem the mileage by adjusting the balance
    flight = PlaneFlight(mName, from, to, 0, mileage);
    mBalance -= mileage;
    return true;
}
