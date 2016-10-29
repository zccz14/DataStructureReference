#include "unordered_link_list.h"
#include <algorithm>

namespace DS {
unordered_link_list::unordered_link_list() {
  head = tail = 0;
  count = 0;
}

link_list_node *unordered_link_list::find(int x) {
  for (link_list_node *cur = head; cur; cur = cur->next) {
    if (cur->value == x) {
      return cur;
    }
  }
  return 0;
}

bool unordered_link_list::search(int x) { return find(x) != 0; }
bool unordered_link_list::insert(int x) {
  link_list_node *node = new link_list_node(x);
  if (!node) {
    return false;
  }
  if (!tail) {
    head = tail = node;
    count = 1;
  } else {
    tail->next = node;
    node->prev = tail;
    tail = node;
    count++;
  }
  return true;
}

int unordered_link_list::remove(int index) {
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
int unordered_link_list::predecessor(int x) {
  link_list_node *cur = find(x);
  if (cur && cur->prev) {
    return cur->prev->value;
  } else {
    // undefined
  }
}
int unordered_link_list::successor(int x) {
  link_list_node *cur = find(x);
  if (cur && cur->next) {
    return cur->next->value;
  } else {
    // undefined
  }
}
int unordered_link_list::minimum() {
  if (0 < count) {
    int ret = head->value;
    for (link_list_node *cur = head->next; cur; cur = cur->next) {
      if (ret > cur->value) {
        ret = cur->value;
      }
    }
    return ret;
  } else {
    // undefined
  }
}
int unordered_link_list::maximum() {
  if (0 < count) {
    int ret = head->value;
    for (link_list_node *cur = head->next; cur; cur = cur->next) {
      if (ret < cur->value) {
        ret = cur->value;
      }
    }
    return ret;
  } else {
    // undefined
  }
}
int unordered_link_list::KthElement(int k) {
  if (0 < k && k < count) {
    int *temp = new int[count];
    link_list_node *cur = head;
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
int unordered_link_list::size() { return count; }
};
