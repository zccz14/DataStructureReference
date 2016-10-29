#pragma once
#include "list.h"

namespace DS {
class ordered_sequence : public list {
public:
  ordered_sequence(int capital);
  int find(int x, int &l, int &r); // find index (binary search)
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
