/*
Quote a quote

Prompts the user to enter a quote and an author, and then displays them 
in the following format:

  <Author> says: "<Quote>"

Implementation notes:
 - Quotation marks need to be properly escaped when specifying the output string. 
 - If the input string contains double quotes then the output would look
   better if these were replaced with single quotes.
*/

#include <iostream>
#include <algorithm>

using namespace std;

/** Returns a copy of the input string in which double quotes have been replaced by single quotes. */
string doubleQuotesToSingles(string s) {
  string newString = s;
  replace(newString.begin(), newString.end(), '"', '\'');
  return newString;
}

int main() {
  // initialise variables to store user input
  string quote = "";
  string author = "";
  
  // prompt the user to enter a quote, and store the input in variable 'quote'
  cout << "What is the quote?" << endl; 
  getline(cin, quote);

  // prompt the user to enter the author, and store the input in variable 'author'
  cout << "Who said it?" << endl;
  getline(cin, author);

  // replace any double quotes with single quotes
  quote = doubleQuotesToSingles(quote);
  author = doubleQuotesToSingles(author);

  // output the formatted quote to the console
  cout << "\n" << author << " says: \"" << quote << "\"" << endl;
}
