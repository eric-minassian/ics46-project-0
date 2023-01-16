#include "LLStack.hpp"
#include "postfixCalc.hpp"
#include "gtest/gtest.h"
#include <string>
#include <unordered_map>

// NOTE:  these are not intended as exhaustive tests.
// This should get you started testing.
// However, be aware that if ANY test marked "Required" fails,
// your score for the portion will be zero, regardless of other considerations.

namespace {

// And some tests for the linked list based stack and the associated calculator.
// VERY IMPORTANT:  if your LLStack is not templated, or if
//      it is not linked-list based, your score for this project
//      will be zero.  Be sure your LLStack compiles and runs
//      with non-numeric data types.  A char is a numeric type.
//

TEST(Required, RequiredStackTest1) {
  LLStack<int> a;
  a.push(5);
  EXPECT_EQ(a.top(), 5);
}

TEST(Required, RequiredStackTest2) {
  LLStack<int> a;
  a.push(5);
  a.push(3);
  EXPECT_EQ(a.top(), 3);
}

TEST(Required, RequiredStackTest3) {
  LLStack<int> a;
  a.push(5);
  a.push(3);
  a.pop();
  EXPECT_EQ(a.top(), 5);
}

TEST(Required, RequiredStackTest4) {
  LLStack<int> a;
  EXPECT_THROW(a.top(), StackEmptyException);
}

// Custom Test for Stack Implementation
TEST(StackTest, AdditionalTest1) {
  LLStack<int> myStack;
  myStack.push(5);
  myStack.push(3);
  myStack.push(2);
  myStack.push(1);
  myStack.pop();
  LLStack<int> newStack = myStack;
  EXPECT_EQ(newStack.top(), 2);
  newStack.pop();
  EXPECT_EQ(newStack.top(), 3);
  EXPECT_EQ(myStack.top(), 2);
}

TEST(StackTest, AdditionalTest2) {
  LLStack<int> myStack;
  myStack.push(5);
  myStack.push(3);
  myStack.push(2);
  myStack.push(1);
  myStack.pop();
  LLStack<int> newStack;
  newStack.push(1);
  newStack.push(2);
  newStack.pop();
  EXPECT_EQ(newStack.top(), 1);
  newStack = myStack;
  EXPECT_EQ(newStack.top(), 2);
  newStack.pop();
  EXPECT_EQ(newStack.top(), 3);
  EXPECT_EQ(myStack.top(), 2);
}

TEST(StackTest, AdditionalTest3) {
  LLStack<std::string> myStack;
  myStack.push("Hello");
  myStack.push("World");
  myStack.push("!");
  myStack.pop();
  EXPECT_EQ(myStack.top(), "World");
}

TEST(StackTest, AdditionalTest4) {
  LLStack<std::string> myStack;
  myStack.push("Hello");
  myStack.push("World");
  myStack.push("!");
  EXPECT_EQ(myStack.size(), 3);
  myStack.pop();
  EXPECT_EQ(myStack.size(), 2);
  myStack.pop();
  EXPECT_FALSE(myStack.isEmpty());
  EXPECT_EQ(myStack.size(), 1);
  myStack.pop();
  EXPECT_EQ(myStack.size(), 0);
  EXPECT_TRUE(myStack.isEmpty());
  EXPECT_THROW(myStack.pop(), StackEmptyException);
}

TEST(StackTest, AdditionalTest5) {
  LLStack<int> myStack;
  myStack.push(5);
  myStack.push(3);
  myStack.push(2);
  myStack.pop();
  // myStack = (3, 5)
  LLStack<int> newStack;
  newStack.push(1);
  newStack.push(2);
  newStack.pop();
  // newStack = (1)
  EXPECT_EQ(newStack.top(), 1);
  EXPECT_EQ(newStack.size(), 1);
  newStack = myStack;
  // newStack = (3, 5)
  EXPECT_EQ(newStack.size(), 2);
  EXPECT_EQ(newStack.top(), 3);
  newStack.pop();
  // newStack = (5)
  EXPECT_EQ(newStack.size(), 1);
  EXPECT_EQ(myStack.size(), 2);
  EXPECT_EQ(newStack.top(), 5);
  EXPECT_EQ(myStack.top(), 3);
}

TEST(StackTest, AdditionalTest6) {
  LLStack<int> myStack;
  myStack.push(5);
  myStack.push(3);
  myStack.push(2);
  myStack.pop();
  // myStack = (3, 5)
  LLStack<int> newStack = myStack;
  // newStack = (3, 5)
  EXPECT_EQ(newStack.size(), 2);
  EXPECT_EQ(newStack.top(), 3);
  newStack.pop();
  // newStack = (5)
  EXPECT_EQ(newStack.size(), 1);
  EXPECT_EQ(myStack.size(), 2);
  EXPECT_EQ(newStack.top(), 5);
  EXPECT_EQ(myStack.top(), 3);
}

// Required Test for Calculator Implementation

TEST(Required, RequiredCalcTest1) {
  const std::vector<std::string> EXPRESSION = {"5", "3", "*"};
  EXPECT_EQ(postfixCalculator(EXPRESSION), 15);
}

TEST(Required, RequiredCalcTest2) {
  const std::vector<std::string> EXPRESSION = {"5", "3", "2", "-", "*"};
  EXPECT_EQ(postfixCalculator(EXPRESSION), 5);
}

TEST(Required, RequiredCalcTest3) {
  const std::vector<std::string> EXPRESSION = {"5", "3", "2", "-"};
  EXPECT_ANY_THROW(postfixCalculator(EXPRESSION));
}

// You can fail this test and still get partial credit from others that pass.
// Of course, I would recommend you get this one to pass, too...
// Note that the group name is "CalcTest" and not "Required."
TEST(CalcTest, AdditionalTest4) {
  const std::vector<std::string> EXPRESSION = {"5", "3", "*", "20", "*"};
  EXPECT_EQ(postfixCalculator(EXPRESSION), 300);
}

} // end namespace
