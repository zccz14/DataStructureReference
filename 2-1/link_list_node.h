#pragma once
namespace DS {
class link_list_node {
public:
  int value;
  link_list_node *prev, *next;

  link_list_node(int val) {
    value = val;
    prev = next = 0;
  }
};
};
