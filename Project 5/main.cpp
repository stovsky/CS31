#include <iostream>
#include <string>
#include <cassert>
#include "PlaneFlight.h"
#include "FrequentFlyerAccount.h"
using namespace std;

int main()
{
    PlaneFlight test( "Tyler", "CLE", "LAX", 100.00, 2350 );
    FrequentFlyerAccount account("Tyler");

    assert(test.getFromCity( ) == "CLE");
    assert(test.getToCity( ) == "LAX");
    assert(test.getName( ) == "Tyler");
    assert(to_string(test.getCost()) == "100.000000");
    assert(to_string(test.getMileage()) == "2350.000000");

    assert(to_string(account.getBalance()) == "0.000000");
    assert(account.getName() == "Tyler");
    assert(account.canEarnFreeFlight(1000.00) == false);

    assert(account.addFlightToAccount(test) == true);
    assert(to_string(account.getBalance()) == "2350.000000");

    if (account.canEarnFreeFlight(1000)) {
        assert(account.freeFlight("DEN", "ORD", 1000, test) == true);
        assert(test.getName() == "Tyler");
        assert(to_string(test.getCost()) == "0.000000");
        assert(test.getFromCity() == "DEN");
        assert(test.getToCity() == "ORD");
        assert(to_string(test.getMileage()) == "1000.000000");
        assert(to_string(account.getBalance()) == "1350.000000");
    }
    else {
        assert(false);
    }

    return 0;
    }

