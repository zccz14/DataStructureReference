#include "unordered_sequence.h"
#include <algorithm>

namespace DS {
unordered_sequence::unordered_sequence(int cap) {
  capital = cap;
  data = new int[cap];
  count = 0;
}

int unordered_sequence::find(int x) {
  for (int i = 0; i < count; i++) {
    if (data[i] == x) {
      return i;
    }
  }
  return -1;
}

bool unordered_sequence::search(int x) { return find(x) != -1; }
bool unordered_sequence::insert(int x) {
  if (count >= capital) {
    return false;
  }
  data[count++] = x;
  return true;
}

int unordered_sequence::remove(int index) {
  if (0 < index && index < count) {
    int ret = data[index];
    count--;
    for (int i = index; i < count; i++) {
      data[i] = data[i + 1];
    }
    return ret;
  } else {
    // undefined
  }
}
int unordered_sequence::predecessor(int x) {
  int index = find(x);
  if (0 < index) {
    return data[index - 1];
  } else {
    // undefined
  }
}
int unordered_sequence::successor(int x) {
  int index = find(x);
  if (0 <= index && index < count - 1) {
    return data[index + 1];
  } else {
    // undefined
  }
}
int unordered_sequence::minimum() {
  if (0 < count) {
    int ret = data[0];
    for (int i = 1; i < count; i++) {
      if (ret > data[i]) {
        ret = data[i];
      }
    }
    return ret;
  } else {
    // undefined
  }
}
int unordered_sequence::maximum() {
  if (0 < count) {
    int ret = data[0];
    for (int i = 1; i < count; i++) {
      if (ret < data[i]) {
        ret = data[i];
      }
    }
    return ret;
  } else {
    // undefined
  }
}
int unordered_sequence::KthElement(int k) {
  int *temp = new int[count];
  for (int i = 0; i < count; i++) {
    temp[i] = data[i];
  }
  std::sort(temp, temp + count);
  int ret = temp[count - k];
  delete temp;
  return ret;
}
int unordered_sequence::size() { return count; }
};
