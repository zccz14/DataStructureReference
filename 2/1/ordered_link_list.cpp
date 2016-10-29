#include "ordered_link_list.h"
#include <algorithm>

namespace DS {
ordered_link_list::ordered_link_list() {
  head = tail = 0;
  count = 0;
}

link_list_node *ordered_link_list::find(int x) {
  link_list_node *cur;
  for (cur = head; cur; cur = cur->next) {
    if (cur->value == x) {
      return cur;
    }
    if (cur->next && cur->next->value > x) {
      return cur;
    }
  }
  return cur;
}

bool ordered_link_list::search(int x) {
  link_list_node *p = find(x);
  return p && p->value == x;
}
bool ordered_link_list::insert(int x) {
  link_list_node *node = new link_list_node(x);
  if (!node) {
    return false;
  }
  link_list_node *pos = find(x);
  if (!pos) {
    head = tail = node;
    count = 1;
  } else {
    pos->next = node;
    node->prev = pos;
    if (tail == pos) {
      tail = node;
    }
    count++;
  }
  return true;
}

int ordered_link_list::remove(int index) {
  if (0 <= index && index < count) {
    if (index == 0) {
      head = head->next;
      int ret = head->prev->value;
      delete head->prev;
      head->prev = NULL;
      return ret;
    } else {
      link_list_node *cur = head;
      for (int i = 0; i < index; i++) {
        cur = cur->next;
      }
      int ret = cur->value;
      cur->prev->next = cur->next;
      cur->next->prev = cur->prev;
      delete cur;
      count--;
      return ret;
    }
  } else {
    // undefined
  }
}
int ordered_link_list::predecessor(int x) {
  link_list_node *cur = find(x);
  if (cur && cur->prev) {
    return cur->prev->value;
  } else {
    // undefined
  }
}
int ordered_link_list::successor(int x) {
  link_list_node *cur = find(x);
  if (cur && cur->next) {
    return cur->next->value;
  } else {
    // undefined
  }
}
int ordered_link_list::minimum() {
  if (0 < count) {
    return head->value;
  } else {
    // undefined
  }
}
int ordered_link_list::maximum() {
  if (0 < count) {
    return tail->value;
  } else {
    // undefined
  }
}
int ordered_link_list::KthElement(int k) {
  if (0 < k && k <= count) {
  link_list_node *cur = head;
  for (int i = k; i < count; i++) {
    cur = cur->next;
  }
  return cur->value;
  } else {
    // undefined
  }
}
int ordered_link_list::size() { return count; }
};
