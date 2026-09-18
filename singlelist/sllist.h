// sllist.h - singly linked list class
// Copyright 2026 Humberto Ortiz Zuazaga
// Based on SLList class by Pat Morin
// in https://opendatastructures.org/
// Released under
// https://creativecommons.org/licenses/by/2.5/ca/

#ifndef SLLIST_H
#define SLLIST_H

template<class T>
class SLList {
  class Node {
  public:
    T value;
    Node *next;

    Node(T x) {
      value = x;
      next = nullptr;
    }
  };
  Node* head;
  Node* tail;

 public:

  // Constructor
  SLList() {
    head = tail = nullptr;
  }

  ~SLList () {
    Node *u = head;
    while (u != nullptr) {
      Node *w = u;
      u = u->next;
      delete w;
    }
    head = nullptr;
    tail = nullptr;
  }

  void push(T x) {
    Node *u = new Node(x);
    u->next = head;
    head = u;
    if (tail == nullptr) tail = u;
  }

  T pop() {
    Node *u = head;
    T x = u->value;
    head = u->next;
    delete u;
    if (nullptr == head) tail = nullptr;
    return x;
  }

  void enqueue(T x) {
    Node *u = new Node(x);
    if (nullptr == head) {	// si la lista esta vacia
      head = u;			// enlazamos u al principio
    } else {			// si no
      tail->next = u;		// enlazamos u al final
    }
    u->next = nullptr;		// u es el ultimo
    tail = u;
  }

  T dequeue() {
    return pop();
  }   
};

#endif
