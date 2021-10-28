#include <iostream>
#include <cassert>
#include <string>
using namespace std;

int locateMaximum(const string array[], int n);
bool hasNoCapitals(const string array[], int n);
bool identicalValuesTogether(const string array[], int n);
bool hasTwoOrMoreDuplicates(const string array[], int n);
int shiftLeft(string array[], int n, int amount, string placeholder);
int replaceFirstAndLastOccurrences(string array[], int n, char charToFind, char charToReplace);
int countFloatingPointValues(const string array[], int  n);
bool findDuplicates(const string array[], int n);

int main() {
    string array[6] = {"0.123", "0.123", "HellO", "tyler", "HellO", "0.123"};
    
    assert(locateMaximum(array, 6) == 3);
    assert(!hasNoCapitals(array, 6));
    assert(!identicalValuesTogether(array, 6));
    assert(hasTwoOrMoreDuplicates(array, 6));
    assert(replaceFirstAndLastOccurrences(array, 6, 'e', '$') == 3);
    assert(countFloatingPointValues(array, 6) == 3);
    assert(shiftLeft(array, 6, 4, "cs31") == 4);
    
    return 0;
}

bool findDuplicates(const string array[], int n) {
    
    if (n <= 0) return false;
    
    // Determine if there are any duplicates in the array
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (j != i) {
                if (array[i] == array[j]) {
                    return true;
                }
            }
        }
    }
    return false;
}

int locateMaximum(const string array[], int n) {

    if (n <= 0) return -1;
    
    string max = array[0];
    int result = 0;
    
    // Loop through the array to find the max value
    for (int i = 1; i < n; i++) {
        if (array[i] > max) max = array[i];
    }
    
    // Reloop through the array to find the index of the max value
    for (int i = 0; i < n; i++) {
        if (array[i] == max) {result = i; break;}
    }
    return result;
}

bool hasNoCapitals(const string array[], int n) {
    
    if (n <= 0) return true;
    
    // Loop through each character in the array to check if it is a capital letter
    for (int i = 0; i < n; i++) {
        for (size_t j = 0; j < array[i].size(); j++) {
            if (array[i][j] >= 'A' && array[i][j] <= 'Z') return false;
        }
    }
    return true;
}

bool hasTwoOrMoreDuplicates(const string array[], int n) {

    if (n <= 0) return false;
    
    // Loop through the array to count every time a duplicate is found
    int counter = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (j != i) {
                if (array[i] == array[j]) {
                    counter++;
                }
            }
        }
    }

    return counter > 1;
}

bool identicalValuesTogether(const string array[], int n) {
    
    if (n <= 0) return false;
    // Check if there are any duplicates at all in the array
    if (!findDuplicates(array, n)) return true;
    
    // Loop through the array to check if each duplicate is 1 index apart from each other
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (j != i) {
                if (array[i] == array[j]) {
                    if (j - i == 1) break;
                    else return false;
                }
            }
        }
    }
    return true;
}

int shiftLeft(string array[], int n, int amount, string placeholder) {
    
    if (n <= 0 || amount < 0) return -1;
    
    // Shift the array to the left by 1, loop this amount times
    // After shifting, replace the last element with the placeholder string
    for (int i = 0; i < amount; i++) {
        for (int j = 0; j < n - 1; j++) {
            array[j] = array[j + 1];
        }
        array[n - 1] = placeholder;
    }
    
    if (amount > n) return n;
    else return amount;
}

int replaceFirstAndLastOccurrences(string array[], int n, char charToFind, char charToReplace) {
    
    if (n <= 0) return -1;
    
    int counter = 0, firstOccurrence = -1, secondOccurrence = -1, counterReset = 0;
    
    // Loop through each character in the array
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < array[i].size(); j++) {
            
            // Find the first occurrence of the character
            // Update the second occurrence when a larger index is discovered
            if (array[i][j] == charToFind) {
                counter++;
                counterReset++;
                if (counter == 1) {
                    firstOccurrence = j;
                    secondOccurrence = j;
                }
                else {
                    secondOccurrence = j;
                }
            }
        }
        
        // Only replace if charToFind is discovered at all in the string
        if (counterReset > 0) {
        array[i][firstOccurrence] = charToReplace;
        array[i][secondOccurrence] = charToReplace;
        }
        counterReset = 0;
    }
    
    return counter;
    
}

int countFloatingPointValues(const string array[ ], int  n) {
    
    if (n <= 0) return -1;
    
    bool foundDecimal = false;
    int decimalCounter = 0;
    bool validString = false;
    int counter = 0;
    
    // Loop through each character in the array
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < array[i].size(); j++) {
            
            // Check if the character is a digit
            if (isdigit(array[i][j])) validString = true;
            else if (array[i][j] == '.') {foundDecimal = true;}
            else {validString = false; break;}
            
            // Check if a decimal is the last character in the string
            // Check if there is more than one decimal in the string
            if (foundDecimal && array[i][j] == '.') {
                if (j + 1 == array[i].size()) {counter++; break;}
                decimalCounter++;
                if (decimalCounter > 1) break;
            }
            
            // If the string passes all the tests, a valid value has been found
            if (j == array[i].size() - 1) {
                if (validString) {
                    counter++;
                }
                else break;
            }
        }
        foundDecimal = false;
        validString = false;
        decimalCounter = 0;
    }
    return counter;
}
