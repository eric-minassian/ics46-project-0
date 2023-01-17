#include "postfixCalc.hpp"
#include "LLStack.hpp"

unsigned postfixCalculator(const std::vector<std::string> &entries) {

  // Check to see if vector has invalid number of entries and throws an
  // exception if true
  if (entries.size() == 0 || entries.size() == 2) {
    throw CannotEvaluateException("Empty vector as input");
  }

  // Create a stack from LLStack implementation to store the entries into
  LLStack<unsigned> stack;

  // Loop through all the entries in the vector
  for (auto entry : entries) {

    // If the entry is one of the 4 operators, then we store the values of the
    // top 2 elements and pop them Then we evaluate the result with the operator
    // given and push the result to the stack
    if (entry == "+") {
      unsigned int a = stack.top();
      stack.pop();
      unsigned int b = stack.top();
      stack.pop();
      stack.push(b + a);
    } else if (entry == "-") {
      unsigned int a = stack.top();
      stack.pop();
      unsigned int b = stack.top();
      stack.pop();
      stack.push(b - a);
    } else if (entry == "*") {
      unsigned int a = stack.top();
      stack.pop();
      unsigned int b = stack.top();
      stack.pop();
      stack.push(b * a);
    } else if (entry == "/") {
      unsigned int a = stack.top();
      stack.pop();
      unsigned int b = stack.top();
      stack.pop();
      stack.push(b / a);
    } else {
      // Try to convert the entry to unsigned int and push to stack
      // If the entry is not a number, then we throw an exception
      try {
        stack.push(std::stol(entry));
      } catch (...) {
        throw CannotEvaluateException("Non valid entry in vector");
      }
    }
  }

  // If the stack doesn't have the final result then we throw an exception
  // Else we will return the top of the stack which is the result
  if (stack.size() != 1) {
    throw CannotEvaluateException("Cannot evaluate postfix expression");
  } else {
    return stack.top();
  }
}
