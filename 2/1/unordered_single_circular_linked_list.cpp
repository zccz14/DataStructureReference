#include "unordered_single_circular_linked_list.h"
#include <algorithm>

namespace DS {
unordered_single_circular_linked_list::unordered_single_circular_linked_list() {
  head = 0;
  count = 0;
}

single_linked_list_node *unordered_single_circular_linked_list::find(int x) {
  auto *cur = head;
  for (int i = 0; i < count; i++) {
    if (cur->value == x) {
      return cur;
    }
    cur = cur->next;
  }
  return 0;
}

bool unordered_single_circular_linked_list::search(int x) {
  return find(x) != 0;
}
bool unordered_single_circular_linked_list::insert(int x) {
  auto *node = new single_linked_list_node(x);
  if (!node) {
    return false;
  }
  if (count == 0) {
    head = node;
    head->next = head;
  } else {
    node->next = head->next;
    head->next = node;
  }
  count++;
  return true;
}

int unordered_single_circular_linked_list::remove(int index) {
  if (0 <= index && index < count) {
    auto *cur = head;
    int times = index == 0 ? count - 1 : index - 1;
    for (int i = 0; i < times; i++) {
      cur = cur->next;
    }
    auto *rm = cur->next;
    int ret = rm->value;
    cur->next = rm->next;
    delete rm;
    count--;
    return ret;
  } else {
    // undefined
  }
}
int unordered_single_circular_linked_list::predecessor(int x) {
  auto *cur = head;
  for (int i = 0; i < count; i++) {
    if (cur->next->value == x) {
      return cur->value;
    }
    cur = cur->next;
  }
  // undefined
}
int unordered_single_circular_linked_list::successor(int x) {
  auto *cur = head;
  for (int i = 0; i < count; i++) {
    if (cur->value == x) {
      return cur->next->value;
    }
    cur = cur->next;
  }
  // undefined
}
int unordered_single_circular_linked_list::minimum() {
  if (0 < count) {
    int ret = head->value;
    auto *cur = head->next;
    for (int i = 1; i < count; i++) {
      if (ret > cur->value) {
        ret = cur->value;
      }
      cur = cur->next;
    }
    return ret;
  } else {
    // undefined
  }
}
int unordered_single_circular_linked_list::maximum() {
  if (0 < count) {
    int ret = head->value;
    auto *cur = head->next;
    for (int i = 1; i < count; i++) {
      if (ret < cur->value) {
        ret = cur->value;
      }
      cur = cur->next;
    }
    return ret;
  } else {
    // undefined
  }
}
int unordered_single_circular_linked_list::KthElement(int k) {
  if (0 < k && k < count) {
    int *temp = new int[count];
    auto *cur = head;
    for (int i = 0; i < count; i++) {
      temp[i] = cur->value;
      cur = cur->next;
    }
    std::sort(temp, temp + count);
    int ret = temp[count - k];
    delete temp;
    return ret;
  } else {
    // undefined
  }
}
int unordered_single_circular_linked_list::size() { return count; }
};
