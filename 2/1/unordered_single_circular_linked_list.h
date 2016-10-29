#pragma once
#include "list.h"
#include "single_linked_list_node.h"

namespace DS {
class unordered_single_circular_linked_list : public list {
public:
  unordered_single_circular_linked_list();
  single_linked_list_node *find(int x); // find address
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
  single_linked_list_node *head;
  int count;
};
};
