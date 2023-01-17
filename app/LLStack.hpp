#ifndef __ICS46_LL_STACK_HPP
#define __ICS46_LL_STACK_HPP

#include "runtimeexcept.hpp"
#include <cstddef>
#include <stdexcept>

class StackEmptyException : public RuntimeException {
public:
  StackEmptyException(const std::string &err) : RuntimeException(err) {}
};

// Node struct for the linked list implementation of stack
template <typename Object> struct LLNode {
  Object value;
  LLNode<Object> *next;
};

// Linked list implementation of stack
template <typename Object> class LLStack {
private:
  LLNode<Object> *head;
  unsigned int length;

public:
  LLStack();

  LLStack(const LLStack &st);

  LLStack &operator=(const LLStack &st);

  ~LLStack();

  size_t size() const noexcept;
  bool isEmpty() const noexcept;

  Object &top();
  const Object &top() const;

  void push(const Object &elem) noexcept;
  void pop();
};

// Constructor
// Sets the head pointer to null and the length to 0
template <typename Object>
LLStack<Object>::LLStack() : head(nullptr), length(0) {}

// Copy Constructor
// Loops through the stack given as a parameter and deep copies the elements to
// the stack
template <typename Object> LLStack<Object>::LLStack(const LLStack &st) {
  // Sets the head pointer to null and the length to 0
  head = nullptr;
  length = 0;

  // Loops through the stack given as a parameter and deep copies the elements
  LLNode<Object> *cur = st.head, *prev = nullptr;
  while (cur) {
    // Increment the length of the stack
    length++;

    // Creates a new node for the respective node in the stack given as a
    // parameter
    LLNode<Object> *new_node = new LLNode<Object>;

    // If previous is not null then we set the previous node's next pointer to
    // the newly created node This will allow us to reverse the order were
    // reading the given stack in and create a new stack with the same order as
    // the given stack
    if (prev) {
      prev->next = new_node;
      // Else we set the head pointer to the newly created node
    } else {
      head = new_node;
    }

    // Update previous node and set the newly created node's value and next
    prev = new_node;
    new_node->value = cur->value;
    new_node->next = nullptr;

    // Update current node to next node in given stack
    cur = cur->next;
  }
}

// Removes all elements from the stack and dynamic memory
// Makes a deep copy of the stack given as a parameter to the stack
template <typename Object>
LLStack<Object> &LLStack<Object>::operator=(const LLStack &st) {

  // Continuously loops through the stack while the head is not null and uses
  // the pop method to remove elements from dynamic memory and stack
  while (head != nullptr) {
    pop();
  }

  // Loops through the stack given as a parameter and deep copies the elements
  LLNode<Object> *cur = st.head, *prev = nullptr;
  while (cur) {
    // Increment the length of the stack
    length++;

    // Creates a new node for the respective node in the stack given as a
    // parameter
    LLNode<Object> *new_node = new LLNode<Object>;

    // If previous is not null then we set the previous node's next pointer to
    // the newly created node This will allow us to reverse the order were
    // reading the given stack in and create a new stack with the same order as
    // the given stack
    if (prev) {
      prev->next = new_node;
      // Else we set the head pointer to the newly created node
    } else {
      head = new_node;
    }

    // Update previous node and set the newly created node's value and next
    prev = new_node;
    new_node->value = cur->value;
    new_node->next = nullptr;

    // Update current node to next node in given stack
    cur = cur->next;
  }
  return *this;
}

// Destructor
// Continuously loops through the stack while the head is not null and uses the
// pop method to remove elements from dynamic memory
template <typename Object> LLStack<Object>::~LLStack() {
  while (head) {
    LLStack<Object>::pop();
  }
}

// Returns the length of the stack
template <typename Object> size_t LLStack<Object>::size() const noexcept {
  return length;
}

// Returns true if the stack size is 0 and false if it is not 0
template <typename Object> bool LLStack<Object>::isEmpty() const noexcept {
  return 0 == length;
}

// Returns the head of the stack
template <typename Object> Object &LLStack<Object>::top() {

  // If the stack is empty we throw a StackEmptyException
  // Else we return the value of the head of the stack
  if (!head) {
    throw StackEmptyException("Stack is empty");
  } else {
    return head->value;
  }
}

// Returns the head of the stack
template <typename Object> const Object &LLStack<Object>::top() const {

  // If the stack is empty we throw a StackEmptyException
  // Else we return the value of the head of the stack
  if (!head) {
    throw StackEmptyException("Stack is empty");
  } else {
    return head->value;
  }
}

// Adds an element to the top of the stack
template <typename Object>
void LLStack<Object>::push(const Object &elem) noexcept {
  // Increment the length of the stack
  length++;

  // Create a new node and set its next and value fields
  LLNode<Object> *new_node = new LLNode<Object>;
  new_node->value = elem;
  new_node->next = head;
  // Update the head pointer to the newly created node
  head = new_node;
}

// Removes top element from stack
template <typename Object> void LLStack<Object>::pop() {

  // If the stack is empty we throw a StackEmptyException
  // Else we decrease the length by 1, set the head pointer to the next member
  // in the current head and delete the old head from dynamic memory
  if (!head) {
    throw StackEmptyException("Stack is empty");
  } else {
    length--;

    LLNode<Object> *temp = head;
    head = head->next;
    delete temp;
  }
}

#endif
