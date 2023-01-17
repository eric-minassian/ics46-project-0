#include "verifySol.hpp"

#include <math.h>
#include <string>
#include <unordered_map>

using std::pow;

bool verifySolution(std::string s1, std::string s2, std::string s3,
                    const std::unordered_map<char, unsigned> &mapping) {

  // Create an unsigned int for each string
  unsigned int s1Num = 0, s2Num = 0, s3Num = 0;

  // Loop through each string and add the value to its respective unsigned int
  // The value is multiplied by 10 to the power of the length of the string
  // minus the current index minus 1 to get the correct place value of each
  // value
  for (int i = 0; i < s1.length(); i++) {
    s1Num += mapping.at(s1[i]) * pow(10, s1.length() - i - 1);
  }

  for (int i = 0; i < s2.length(); i++) {
    s2Num += mapping.at(s2[i]) * pow(10, s2.length() - i - 1);
  }

  for (int i = 0; i < s3.length(); i++) {
    s3Num += mapping.at(s3[i]) * pow(10, s3.length() - i - 1);
  }

  // If the sum of s1Num and s2Num is equal to s3Num, return true
  // Else return false
  if ((s1Num + s2Num) == s3Num) {
    return true;
  } else {
    return false;
  }
}
