#include "ordered_single_circular_linked_list.h"
#include <algorithm>

namespace DS {
ordered_single_circular_linked_list::ordered_single_circular_linked_list() {
  head = 0;
  count = 0;
}

single_linked_list_node *ordered_single_circular_linked_list::find(int x) {
  if (count > 0) {
    auto *cur = head;
    if (head->value > x) {
      for (int i = 1; i < count; i++) {
        cur = cur->next;
      }
      return cur;
    }

    for (int i = 1; i < count; i++) {
      if (cur->value == x || cur->next->value > x) {
        return cur;
      }
      cur = cur->next;
    }
    return cur;
  } else {
    return 0;
  }
}

bool ordered_single_circular_linked_list::search(int x) {
  auto *p = find(x);
  return p && p->value == x;
}
bool ordered_single_circular_linked_list::insert(int x) {
  auto *node = new single_linked_list_node(x);
  if (!node) {
    return false;
  }
  auto *pos = find(x);
  if (count == 0) {
    head = node;
    head->next = node;
  } else {
    node->next = pos->next;
    pos->next = node;
  }
  count++;
  return true;
}

int ordered_single_circular_linked_list::remove(int index) {
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
int ordered_single_circular_linked_list::predecessor(int x) {
  auto *cur = head;
  for (int i = 0; i < count; i++) {
    if (cur->next->value == x) {
      return cur->value;
    }
    cur = cur->next;
  }
  // undefined
}
int ordered_single_circular_linked_list::successor(int x) {
  auto *cur = head;
  for (int i = 0; i < count; i++) {
    if (cur->value == x) {
      return cur->next->value;
    }
    cur = cur->next;
  }
  // undefined
}
int ordered_single_circular_linked_list::minimum() {
  if (0 < count) {
    return head->value;
  } else {
    // undefined
  }
}
int ordered_single_circular_linked_list::maximum() {
  if (0 < count) {
    auto *cur = head;
    for (int i = 1; i < count; i++) {
      cur = cur->next;
    }
    return cur->value;
  } else {
    // undefined
  }
}
int ordered_single_circular_linked_list::KthElement(int k) {
  if (0 < k && k <= count) {
    auto *cur = head;
    for (int i = k; i < count; i++) {
      cur = cur->next;
    }
    return cur->value;
  } else {
    // undefined
  }
}
int ordered_single_circular_linked_list::size() { return count; }
};
