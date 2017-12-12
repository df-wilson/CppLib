#ifndef CSTRING_UTILS_H
#define CSTRING_UTILS_H

#include <memory>
#include <string>

namespace dw {
   
// Error codes
const int NULL_STR_INPUT_ERROR = -1;
const int INVALID_RADIX_ERROR  = -2;
const int UNKNOWN_ERROR        = 3;

/**
 * @brief Convert a string to an integer value
 *
 * @param strIn The string to convert
 * @return The integer equivalent of the string
 */
int atoi(char* strIn);

/**
 * @brief Convert an integer to its string representation. The integer can be either
 * positive or negative. By default the base is 10, but the integer may also be represented
 * as any base from binary to hexadecimal.
 *
 * Possible error codes are NULL_STR_INPUT_ERROR and INVALID_RADIX_ERROR.
 *
 * @param str    [in/out]The string representation of the integer.
 * @param number [in]    The number to convert to a string.
 * @param radix  [in]    Default is base 10. Valid values from 2 to 16.
 * @return 0 if successful or an error code otherwise.
 */
int itoa(char* str, int number, int radix);

bool isCharOneOf(char charIn, const char* charsToMatch);

/**
 * @brief Check to see if a string is an anagram.of another
 *
 * @param string1 The first string to compare
 * @param string2 The second string to compare
 * @return true if one string is an anagram of the other.
 */
bool isAnagram(const char* string1, const char* string2);

/**
 * @brief Determine if a string is a pallindrome.
 *
 * @param string The string to test.
 * @return true if the string is a pallindrome, otherwise false.
 */
bool isPallindrome(const char* string);

/**
 * @brief Determine if an integer is a pallindrome.
 *
 * @param numIn The number to test.
 * @return true if the number is a pallindrome, otherwise false.
 */
bool isPallindrome(int numIn);

/**
 * @brief Split a string based on a delimeter or set of delimeters. For the first
 * token pass in the string to split. To obtain the rest of the tokens, call dstrtok
 * with NULL for strIn until NULL is returned.
 *
 * @param str   [in/out] The string to tokenize
 * @param delim [in]     The delimeters used to determine where to split the string
 * @return char*
 */
char* dstrtok( char* str, const char* delim );

/**
 * @brief Reverses a string.
 *
 * @param str [in/out] The string to be reversed
 * @return void
 */
void reverse(char* str);

std::string reverseWordOrder(const std::string& strIn);

void reverseWordOrder(char* strIn);

/**
 * @brief Returns the length of a string, not including the null terminator.
 *
 * @param strIn The string to find the length of.
 * @return The size of the string.
 */
int strlen (const char* strIn);


/**
* @brief Compare two strings up to a maximum length. Returns 0 if the two strings are the
* same, 1 if string1 > string2, or -1 if string1 < string2
* 
* @param string1 first string to compare
* @param string2 second string to compare
* @param length  max number of characters to compare
* @return int 
*/
int strncmp(const char*  string1,
            const char*  string2,
            unsigned int length);

/**
 * @brief Convert an ascii string to all lowercase. Only characters A-Z are modified,
 * all others are ignored.
 *
 * @param strIn The string to convert to lowercase.
 * @return void
 */
void strToLower(char* strIn);

/**
 * @brief Convert an ascii string to all uppercase. Only characters a-z are modified,
 * all others are ignored.
 *
 * @param strIn The string to convert to uppercase.
 * @return void
 */
void strToUpper(char* strIn);

/**
 * @brief Converts a single character to its lowercase equivalent.
 *
 * @param value the character to convert
 * @return the converted character
 */
char toLower(char value);

/**
 * @brief Converts a single character to its uppercase equivalent.
 *
 * @param value the character to convert.
 * @return the converted character
 */
char toUpper(char value);

} // end namespace dw

#endif
