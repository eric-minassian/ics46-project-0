#ifndef __ICS46_LL_STACK_HPP
#define __ICS46_LL_STACK_HPP

#include "runtimeexcept.hpp"
#include <cstddef>
#include <stdexcept>

class StackEmptyException : public RuntimeException {
public:
  StackEmptyException(const std::string &err) : RuntimeException(err) {}
};

template <typename Object> struct LLNode {
  Object value;
  LLNode<Object> *next;
};

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

  // We have two top() functions.  The first gets called if your LLStack is not
  // a const, while the latter gets called on a const LLStack
  // (the latter might occur via const reference parameter, for instance).
  // Be sure to test both!  It is important when testing to ensure that
  // EVERY funtion gets called and tested!
  Object &top();
  const Object &top() const;

  void push(const Object &elem) noexcept;
  void pop();
};

template <typename Object>
LLStack<Object>::LLStack() : head(nullptr), length(0) {}

template <typename Object> LLStack<Object>::LLStack(const LLStack &st) {
  head = nullptr;
  length = 0;

  LLNode<Object> *cur = st.head, *prev = nullptr;
  while (cur) {
    length++;
    LLNode<Object> *new_node = new LLNode<Object>;
    if (prev) {
      prev->next = new_node;
    } else {
      head = new_node;
    }

    prev = new_node;
    new_node->value = cur->value;
    new_node->next = nullptr;

    cur = cur->next;
  }
}

template <typename Object>
LLStack<Object> &LLStack<Object>::operator=(const LLStack &st) {
  while (head != nullptr) {
    pop();
  }

  LLNode<Object> *cur = st.head, *prev = nullptr;
  while (cur) {
    length++;
    LLNode<Object> *new_node = new LLNode<Object>;
    if (prev) {
      prev->next = new_node;
    } else {
      head = new_node;
    }

    prev = new_node;
    new_node->value = cur->value;
    new_node->next = nullptr;

    cur = cur->next;
  }
  return *this;
}

template <typename Object> LLStack<Object>::~LLStack() {
  while (head) {
    LLStack<Object>::pop();
  }
}

template <typename Object> size_t LLStack<Object>::size() const noexcept {
  return length;
}

template <typename Object> bool LLStack<Object>::isEmpty() const noexcept {
  return 0 == length;
}

template <typename Object> Object &LLStack<Object>::top() {
  if (!head) {
    throw StackEmptyException("Stack is empty");
  } else {
    return head->value;
  }
}

template <typename Object> const Object &LLStack<Object>::top() const {
  if (!head) {
    throw StackEmptyException("Stack is empty");
  } else {
    return head->value;
  }
}

// Done
template <typename Object>
void LLStack<Object>::push(const Object &elem) noexcept {
  // Increment the length of the stack
  length++;

  // Create a new node and set its next and value fields
  LLNode<Object> *new_node = new LLNode<Object>;
  new_node->value = elem;
  new_node->next = head;
  head = new_node;
}

// Done
template <typename Object> void LLStack<Object>::pop() {
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
