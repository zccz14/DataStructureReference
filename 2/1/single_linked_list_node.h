#pragma once
namespace DS {
class single_linked_list_node {
public:
  int value;
  single_linked_list_node *next;

  single_linked_list_node(int val) {
    value = val;
    next = 0;
  }
};
};
