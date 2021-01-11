
/*
Fahrenheit to Centigrade conversion

Prompts the user to enter a temperature and type of conversion, and then displays 
the answer.

Implementation notes:
 - User input should be validated.
 - Temperature input needs to be converted from a string to a number.
 - Precision should be considered (data types, rounding etc.).
 - Numbers used in conversion calculations should be given names to improve readability.
 - Conversion formulae should be written as utility functions to improve readability.
*/
#define C_TO_F_MULTIPLIER 9
#define C_TO_F_DIVISOR 5
#define C_TO_F_INCREMENT 32
#include <iostream>

using namespace std;

/** Returns the result of converting the input temperature from Fahrenheit to Centigrade. */
double fToC(double tempInF) {
  return (tempInF - C_TO_F_INCREMENT) * C_TO_F_DIVISOR / C_TO_F_MULTIPLIER;
}

/** Returns the result of converting the input temperature from Centigrade to Fahrenheit. */
double cToF(double tempInC) {
  return (tempInC * C_TO_F_MULTIPLIER / C_TO_F_DIVISOR) + C_TO_F_INCREMENT;
}

/** Returns whether or not the input string is a valid number. */
bool isValidNumber(string s) {
  bool foundDecimal = false;
  
  if (s[0] != '-' && s[0] != '.' && !isdigit(s[0])) {
    return false;
  }
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == '.') {
      if (foundDecimal) {
        return false;
      } else {
        foundDecimal = true;
      }
    } else if (!isdigit(s[i])) {
      return false;
    }
  }
  return true;
}

/** Returns the result of rounding the input double to 2 decimal places. */
double roundTo2Dp(double d) {
  return (int)(d * 100.0)/100.0;
}

int main() {
  // initialise variables to store user input
  string inputTemp = "";
  string conversionType = "";
  double startingTemp;
  bool isValidTemp = false;
  bool isValidConversionType = false;
  
  while (!isValidTemp) {
    // prompt the user to enter a temperature, and store the input in variable 'inputTemp'
    cout << "Please enter the starting temperature:" << endl; 
    getline(cin, inputTemp);

    // check the input is a number, and convert from string to double
    isValidTemp = isValidNumber(inputTemp);
    if (isValidTemp) {
      startingTemp = stod(inputTemp);
    } else {
      cout << inputTemp << " is not a valid number." << endl;
    }
  }

  while (!isValidConversionType) {
    // prompt the user to enter the conversion type, and store the input in variable 'conversionType'
    cout << "\nPress ‘C’ to convert from Fahrenheit to Centigrade." << endl;
    cout << "Press ‘F’ to convert from Centigrade to Fahrenheit." << endl;
    getline(cin, conversionType);

    // check the input is equal to either 'F' or 'C'
    isValidConversionType = conversionType.length() == 1 && (conversionType[0] == 'F' || conversionType[0] == 'C');
    if (!isValidConversionType)  {
      cout << conversionType << " does not match 'F' or 'C'." << endl;
    }
  }
  // once valid, output the answer to the console
  cout << "\nYour choice: " << conversionType << endl;
  if (conversionType[0] == 'C') {
    cout << inputTemp << " degrees Fahrenheit is " << roundTo2Dp(fToC(startingTemp)) << " degrees Centigrade." << endl;
  } else if (conversionType[0] == 'F') {
    cout << inputTemp << " degrees Centigrade is " << roundTo2Dp(cToF(startingTemp)) << " degrees Fahrenheit." << endl;
  }
}
