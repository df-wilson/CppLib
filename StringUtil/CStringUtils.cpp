#include "CStringUtils.h"

#include <iostream>
#include <sstream>
#include <string>
#include <stack>

using std::cout;
using std::endl;
using std::stack;
using std::string;

namespace dw {
   
//-----------------------------------------------------------------------------
int atoi(const char* strIn) {
   int  stringLength = 0;
   bool isNegative   = false;
   char tempChar     = 0;
   int  result       = 0;
   int  multiplier   = 1;

   if(!strIn) {
      return 0;
   }

   if(*strIn == '-') {
      isNegative = true;
      strIn++;
   }

   stringLength = strlen (strIn);
   if(stringLength < 1) {
      return 0;
   }

   strIn += (stringLength - 1);

   for(int i = 0; i < stringLength; ++i)
   {
      tempChar = *strIn;

      result += ((tempChar - '0') * multiplier);

      multiplier *= 10;
      strIn--;
   }

   if(isNegative) {
      result = -result;
   }

   return result;
}

//-----------------------------------------------------------------------------
int itoa(char* str, int number, int radix) {
   bool isNegative = false;
   char* posPtr = str;
   char digitArray[] = "0123456789ABCDEF";

   //validate input
   if(str == nullptr) {
      return NULL_STR_INPUT_ERROR;
   }
   
   if( radix < 2 || radix > 16) {
      return INVALID_RADIX_ERROR;
   }

   // Determine sign and if zero
   if(number == 0) {
      *posPtr = '0';
      posPtr++;
   }
   else if(number < 0) {
      number = -number;
      isNegative = true;
   }
   else {
      // Positive
   }

   // Convert digints
   int digit = 0;
   while(number) {
      digit = number % radix;
      number /= radix;
      *posPtr = digitArray[digit];
      posPtr++;
   }

   if(isNegative) {
      *posPtr = '-';
      posPtr++;
   }

   *posPtr = 0;

   reverse (str);

   return 0;
}

//-----------------------------------------------------------------------------
bool isAnagram(const char* string1, const char* string2)
{
   const size_t ASCII_CHARS = 'z' - 'a';
   int temp = ' ';
   int charCount[ASCII_CHARS] = {};

   if(string1 == nullptr || string2 == nullptr) {
      return false;
   }

   while(*string1) {
      temp = toLower(*string1);
      if(temp >= 'a' && temp <= 'z') {
         temp = temp - 'a';
         charCount[temp]++;
      }
      string1++;

      temp = toLower(*string2);
      if(temp >= 'a' && temp <= 'z') {
         temp = temp - 'a';
         charCount[temp]--;
      }
      string2++;
   }

   for(size_t i = 0; i < ASCII_CHARS; ++i) {
      if(charCount[i] != 0) {
         return false;
      }
   }

   return true;
}


//-----------------------------------------------------------------------------
bool isCharOneOf(char charIn, const char* charsToMatchIn)
{
   bool isMatch = false;

   while(*charsToMatchIn != '\0' && !isMatch) {
      if(charIn == *charsToMatchIn)
      {
         isMatch = true;
      }

      charsToMatchIn++;
   }

   return isMatch;
}

//-----------------------------------------------------------------------------
void reverse(char* str) {
   int length = strlen ( str );
   char* begin = str;
   char* end = str+length-1;
   char temp = 0;

   for (int i = 0; i < length/2; ++i) {
      temp = *begin;
      *begin = *end;
      *end = temp;
      begin++;
      end--;
   }
}

void reverseWordOrder(char* strIn)
{
   const char* delimeters = " ,;.?!";
   char* currentChar = strIn;
   char* wordStart = strIn;
   char* wordEnd   = strIn;
   bool isCurrentCharInWord = false;

   // If strIn is a nullptr just return.
   if(!strIn)
   {
      return;
   }
   
   // Reverse the entire string to get the words in the correct location in the
   // string.
   reverse(strIn);

   // Now reverse each individual word in the string, since the characters in the 
   // words themselves should not be reversed. 
   while(*currentChar) {
      if(isCharOneOf(*currentChar, delimeters)) {
         if(isCurrentCharInWord) {
            // end of word found, so reverse it
         }
         isCurrentCharInWord = false;
      }
      else {
         if(isCurrentCharInWord) {
            wordEnd++;
         }
         else {
            //starting a new word.
            wordStart = currentChar;
            wordEnd = currentChar;
         }
      }

      currentChar++;
   }
}

string reverseWordOrder(const string& strIn)
{
   std::stack<string> wordStack;
   std::string word;
   const std::string delims = " ,.;!?";
   string::size_type wordStart = 0;
   string::size_type wordEnd = 0;
   std::ostringstream buffer;

   while(wordStart != std::string::npos || wordEnd != std::string::npos) {
      wordStart = strIn.find_first_not_of(delims, wordStart);
      wordEnd = strIn.find_first_of(delims, wordStart);

      if(wordStart < std::string::npos && wordEnd < std::string::npos) {
         word = strIn.substr(wordStart, wordEnd - wordStart);
         wordStack.push(word);
         cout << "Word: <" << word 
              << "> - word start: " << wordStart 
              << " word end: " << wordEnd << endl;

         wordStart = wordEnd;
      }

      wordEnd = strIn.find_first_not_of(delims, wordStart);

      if(wordStart < string::npos && wordEnd < string::npos) {
         word = strIn.substr(wordStart, wordEnd-wordStart);
         wordStack.push(word);
         cout << "Delims: <" << word << "> - word start: " 
              << wordStart << " word end: " << wordEnd << endl;
              
         wordStart = wordEnd;
      }
   }

   cout << "Word stack size: " << wordStack.size() << endl;
   string temp;
   while(wordStack.size()) {
      buffer << wordStack.top();
      temp += wordStack.top();
      wordStack.pop();
   }

   cout << "Buffer is " << buffer.str() << "Temp string is: " << temp << endl;

   return buffer.str();
}

//-----------------------------------------------------------------------------
int strlen (const char* strIn)
{
   int count = 0;

   if(strIn) {
      while(*strIn) {
         count++;
         strIn++;
      }
   }
   
   return count;
}

//-----------------------------------------------------------------------------
int strncmp(const    char* string1,
            const    char* string2,
            unsigned int   length)
{
  unsigned int lLength    = 0;
  int          lReturnVal = 0;
  
  while (0 != string1  &&
         0 != string2  &&
         lLength < length)
  {
    if (*string1 < *string2)
    {
      lReturnVal = -1;
      break;
    }
    else if(*string1 > *string2)
    {
      lReturnVal = 1;
      break;
    }
    else if ((lLength+1) == length)
    {
       /* If this is the last char to compare, don't increment the string 
       // pointers.
       */
       break;
    }
    else
    {
      // Continue to next char in the strings.
      string1++;
      string2++;
      lLength++;
    }
  }
  
  /* If the return value is 0 at this point then either string1 or string2
  // is at it's end or we've checked up to length. If the char both strings
  // are pointing to is the same then the strings are equal. If one or the
  // other but not both are pointing to 0 then find which is the shorter.
  */
  if(lReturnVal == 0)
  {
     if(*string1 != *string2)
     {
        if(*string1 == 0)
        {
           lReturnVal = -1;
        }
        else if (*string2 == 0)
        {
           lReturnVal = 1;
        }
        else
        {
           return UNKNOWN_ERROR;
        }  
     }
  }
  
   return lReturnVal;   
}

//-----------------------------------------------------------------------------
bool isPallindrome(const char* stringIn)
{
   if(!stringIn) {
      return false;
   }

   int stringLength = strlen (stringIn);
   int j = stringLength;
   for (int i = 0;i < stringLength/2;++i) {
      --j;
      if((*stringIn+i) != *(stringIn+j)) {
         return false;
      }
   }

   cout << "It is a pallindrome!!!" << endl;

   return true;
}

//-----------------------------------------------------------------------------
bool isPallindrome(int numIn)
{
   char stringVal[50];

   itoa(stringVal, numIn, 10);
   cout << numIn << endl;
   if(isPallindrome(stringVal)) {
      cout << "It is a pallindrome!!!" << endl;
   }

   return false;
}

//-----------------------------------------------------------------------------
char* dstrtok(char* str, const char* delim) {
   // Create another pointer to the start of strIn and keep it between calls
   static char* savedString;
   int i = 0;
   bool isDone = false;

   if( str == nullptr) {
      str = savedString;
   }
   else {
      savedString = str;
   }

   while(*savedString != '\0' && isDone == false) {
      i = 0;

      // Make sure to get rid of any duplicates. Always test each char against
      // all possible delimiters.
      //
      while(*( delim+i) != '\0') {
         if(*savedString == *( delim+i)) {
            *savedString = 0;
            savedString++;
            isDone = true;
         }
         else {
            // Only go to the next delimeter if the current one does not match
            i++;
         }
      }

      // If a delimiter has not been found yet, increment to the next char in the string.
      // If a delimiter has been found savedString has already been incremented during
      // the test for duplicates, so don't increment again.
      //
      if(!isDone) {
         savedString++;
      }
   }

   return str;
}

//-----------------------------------------------------------------------------
void strToLower(char* strIn)
{
   if(!strIn) {
       return;
   }

   while(*strIn) {
      *strIn = toLower(*strIn);
      ++strIn;
   }
}

//-----------------------------------------------------------------------------
void strToUpper(char* strIn)
{
   if(!strIn) {
       return;
   }

   while(*strIn) {
      *strIn = toUpper(*strIn);
      ++strIn;
   }
}

//-----------------------------------------------------------------------------
char toLower(char value)
{
   char conversionValue = 'a' - 'A';

   if(value >= 'A' && value <= 'Z') {
      value += conversionValue;
   }

   return value;
}

//-----------------------------------------------------------------------------
char toUpper(char value)
{
   char conversionValue = 'a' - 'A';

   if(value >= 'a' && value <= 'z') {
      value -= conversionValue;
   }

   return value;
}

} // end namespace dw
