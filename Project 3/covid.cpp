#include <iostream>
#include <string>
#include <cctype>
#include <cassert>
using namespace std;

int extractNumber( string commands, size_t& index, bool& isValid );
bool isValidResultString(string results);
int positiveTests(string results);
int negativeTests(string results);
int totalTests(string results);
int batches(string results);

int main() {
    
    assert( isValidResultString("") == false );
    assert( isValidResultString("    ") == false );
    assert( positiveTests( "    " ) == -1 );
    assert( negativeTests( "      " ) == -1 );
    assert( totalTests( "      " ) == -1 );
    assert( batches( "      " ) == -1 );
    assert( isValidResultString( "R2+1-1" ) == true );
    assert( positiveTests( "R2+1-1" ) == 1 );
    assert( negativeTests( "R2+1-1" ) == 1 );
    assert( totalTests( "R2+1-1" ) == 2 );
    assert( batches( "R2+1-1" ) == 1 );

    return 0;
}

int extractNumber( string commands, size_t& index, bool& isValid )
{
 // track the integer value found
 int quantity( 0 );
 // the number can't start with a zero!
 if (commands.at(index) >= '1' && commands.at(index) <= '9')
 {
 // the number should be made up of digits
 while( index < commands.length() &&
 (commands.at(index) >= '0' && commands.at(index) <= '9') )
 {
 // extract one digit and add it to the cumulative value
 // held in quantity "123" ---> 123
 int digit = commands.at( index ) - '0';
 quantity = quantity * 10 + digit;
 index = index + 1;
 }
 }
 // once we run out of digits to consume, the cumulative quantity
 // must not still be zero
 isValid = (quantity != 0);
 return( quantity );
}

bool isValidResultString(string results) {
    
    if (results == "") return false;
    
    bool b = false;
    int totalCases = 0;
    int firstCase = 0;
    int secondCase = 0;
    size_t i = 0;
    
    
    while (i < results.length()) {
        
        // Checks if first letter is 'R'
        // Out of bounds check
        if (results.at(i) != 'R') return false;
        if (results.at(i) == 'R' ) {
            if (i+1 == results.length()) return false;
            i++;
        }

        // Extracts if next character is a nonzero digit
        if (results.at(i) == '0' || !isdigit(results.at(i))) return false;
        totalCases = extractNumber(results, i, b);
        
        // Ensures no out of bounds error if the string is too short
        if (i == results.length()) return false;
        
        // Checks if the next character is '+' or '-'
        // Stores it
        if (results.at(i) != '+' && results.at(i) != '-') return false;
        char sign = results.at(i);
        i++;
        
        if (i == results.length()) return false;
        
        // Checks if next character is a digit
        if (!isdigit(results.at(i))) {
            return false;
        }
        
        // Check for a leading zero, nonleading zero, or digit
        if (results.at(i) == '0' ) {
            if (i+1 != results.length() && isdigit(results.at(i+1))) return false;
            firstCase = extractNumber(results, i, b);
            i++;
        }
        else firstCase = extractNumber(results, i, b);
        
        // Checks if next character is '+' or '-'
        // Checks it's opposite the previous
        if (i == results.length()) return false;
        if (results.at(i) != '+' && results.at(i) != '-') return false;
        if (results.at(i) == sign) return false;
        i++;
        
        // Checks if next character is a digit
        if (i == results.length()) return false;
        if (!isdigit(results.at(i))) {
            return false;
        }
        
        // Check for a leading zero, nonleading zero, or digit
        if (results.at(i) == '0' ) {
            if (i+1 != results.length() && isdigit(results.at(i+1))) return false;
            secondCase = extractNumber(results, i, b);
            i++;
        }
        else secondCase = extractNumber(results, i, b);
        
        // Checks that the second two numbers add up to the first number
        if (firstCase + secondCase != totalCases) return false;
    }
    
    return true;
    
}

int positiveTests(string results) {
    
    // Checks that string is valid
    if (!isValidResultString(results)) return -1;
    
    bool b = false;
    int sum = 0;
    size_t i = 0;
    
    // Sums up the numbers directly after a '+'
    while (i < results.length()) {
        if (results.at(i) == '+') {
            i++;
            sum += extractNumber(results, i, b);
        }
        i++;
    }
    return sum;
    
}


int negativeTests(string results) {
    
    // Checks that string is valid
    if (!isValidResultString(results)) return -1;
    
    bool b = false;
    int sum = 0;
    size_t i = 0;
    
    // Sums up the numbers directly after a '-'
    while (i < results.length()) {
        if (results.at(i) == '-') {
            i++;
            sum += extractNumber(results, i, b);
        }
        i++;
    }
    return sum;
    
}

int totalTests(string results) {
    
    // Checks that string is valid
    if (!isValidResultString(results)) return -1;
    
    bool b = false;
    int sum = 0;
    size_t i = 0;
    
    // Sums up the numbers directly after an 'R'
    while (i < results.length()) {
        if (results.at(i) == 'R') {
            i++;
            sum += extractNumber(results, i, b);
        }
        i++;
    }
    return sum;
}

int batches(string results) {
    
    // Checks that string is valid
    if (!isValidResultString(results)) return -1;
    
    int counter = 0;
    size_t i = 0;
    
    // Counts the number of time 'R' appears in the string
    while (i < results.length()) {
        if (results.at(i) == 'R') {
            counter++;
        }
        i++;
    }
    return counter;
}
