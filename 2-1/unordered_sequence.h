#pragma once
#include "list.h"

namespace DS {
class unordered_sequence : public list {
public:
  unordered_sequence(int capital);
  int find(int x); // find index
  bool search(int x);
  bool insert(int x);
  int remove(int index); // remove by index and return removed element
  int successor(int x);
  int predecessor(int x);
  int minimum();
  int maximum();
  int KthElement(int k);
  int size();

private:
  int *data;
  int count, capital;
};
};
