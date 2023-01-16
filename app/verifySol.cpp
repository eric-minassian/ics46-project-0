#include "verifySol.hpp"

#include <math.h>
#include <string>
#include <unordered_map>

using std::pow;

bool verifySolution(std::string s1, std::string s2, std::string s3,
                    const std::unordered_map<char, unsigned> &mapping) {
  unsigned int s1Num = 0, s2Num = 0, s3Num = 0;

  for (int i = 0; i < s1.length(); i++) {
    s1Num += mapping.at(s1[i]) * pow(10, s1.length() - i - 1);
  }

  for (int i = 0; i < s2.length(); i++) {
    s2Num += mapping.at(s2[i]) * pow(10, s2.length() - i - 1);
  }

  for (int i = 0; i < s3.length(); i++) {
    s3Num += mapping.at(s3[i]) * pow(10, s3.length() - i - 1);
  }

  if ((s1Num + s2Num) == s3Num) {
    return true;
  } else {
    return false;
  }
}
