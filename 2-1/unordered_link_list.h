#pragma once
#include "list.h"
#include "link_list_node.h"

namespace DS {
class unordered_link_list : public list {
public:
  unordered_link_list();
  link_list_node *find(int x); // find address
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
  link_list_node *head, *tail;
  int count;
};
};
