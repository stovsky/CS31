#include <iostream>
#include <string>
using namespace std;

int main()
{
    
    // User Inputs
    
    string month;
    cout << "Provide a month: ";
    getline(cin, month);
    
    if ((month != "January") && (month != "February") && (month != "March") && (month != "April") && (month != "May") && (month != "June") && (month != "July") && (month != "August") && (month != "September") && (month != "October") && (month != "November") && (month != "December"))
    {
        cout << "Invalid month!" << endl;
        return(-1);
    }
    
    int day;
    cout << "Provide a day: ";
    cin >> day;
    if (day < 1 || day > 31) {
        cout << "Invalid day!" << endl;
        return(-1);
    }
     
    int year;
    cout << "Provide a year: ";
    cin >> year;
    if (year < 1 || year > 3000) {
        cout << "Invalid year!" << endl;
        return(-1);
    }
    
    // Month Code
    
    int monthCode = -1;
    
    if (month == "July" || month == "April") monthCode = 0;
    if (month == "January" || month == "October") monthCode = 1;
    if (month == "May") monthCode = 2;
    if (month == "August") monthCode = 3;
    if (month == "February" || month == "March" || month == "November") monthCode = 4;
    if (month == "June") monthCode = 5;
    if (month == "September" || month == "December") monthCode = 6;
    
    
    // Leap Year Offset
    
    if (month == "January" || month == "February") {
        if (year % 4 == 0) {
            if (year % 100 == 0) {
                if (year % 400 == 0)
                    monthCode = monthCode - 1;
                else
                    monthCode = monthCode;
               }
            else
                monthCode = monthCode - 1;
           }
        else
            monthCode = monthCode;
    }
    
    // Century Code
    
    int centuryCode = 0;
    int centuryValue = (year / 100) % 4;
    if (centuryValue == 0) centuryCode = -2;
    if (centuryValue == 1) centuryCode = 3;
    if (centuryValue == 2) centuryCode = 1;
    if (centuryValue == 3) centuryCode = -1;
    
    // Year Code
    
    int yearCode = (year % 100) / 4 + (year % 100);
    
    // Day Code
    
    int dayCode = (centuryCode + day + yearCode + monthCode) % 7;
    
    // Final Day Calculation
    
    string finalDay = "";
    if (dayCode == 0) finalDay = "Sunday";
    if (dayCode == 1 || dayCode == -6) finalDay = "Monday";
    if (dayCode == 2 || dayCode == -5) finalDay = "Tuesday";
    if (dayCode == 3 || dayCode == -4) finalDay = "Wednesday";
    if (dayCode == 4 || dayCode == -3) finalDay = "Thursday";
    if (dayCode == 5 || dayCode == -2) finalDay = "Friday";
    if (dayCode == 6 || dayCode == -1) finalDay = "Saturday";
    
    // End Result
    
    cout << month << " " << day << ", " << year << " was a " << finalDay << "!" << endl;
    return(0);

}
