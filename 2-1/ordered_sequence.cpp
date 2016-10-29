#include "ordered_sequence.h"
#include <algorithm>

namespace DS {
ordered_sequence::ordered_sequence(int cap) {
  data = new int[cap];
  count = 0;
  capital = cap;
}

int ordered_sequence::find(int x, int &l, int &r) {
  l = 0, r = count;
  while (r - l > 1) {
    int mid = (l + r) >> 1;
    if (data[mid] < x) {
      l = mid;
    } else if (x < data[mid]) {
      r = mid;
    } else {
      l = mid;
      r = mid + 1;
    }
  }
  return data[l] == x ? l : -1;
}

bool ordered_sequence::search(int x) {
  int l, r;
  return find(x, l, r) != -1;
}
bool ordered_sequence::insert(int x) {
  if (count >= capital) {
    return false;
  }
  int l, r;
  find(x, l, r);
  for (int i = count; i > r; i++) {
    data[i] = data[i - 1];
  }
  data[r] = x;
  count++;
  return true;
}

int ordered_sequence::remove(int index) {
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
int ordered_sequence::predecessor(int x) {
  int l, r, index = find(x, l, r);
  if (0 < index) {
    return data[index - 1];
  } else {
    // undefined
  }
}
int ordered_sequence::successor(int x) {
  int l, r, index = find(x, l, r);
  if (0 <= index && index < count - 1) {
    return data[index + 1];
  } else {
    // undefined
  }
}
int ordered_sequence::minimum() {
  if (0 < count) {
    return data[0];
  } else {
    // undefined
  }
}
int ordered_sequence::maximum() {
  if (0 < count) {
    return data[count - 1];
  } else {
    // undefined
  }
}
int ordered_sequence::KthElement(int k) {
  if (0 < k && k <= count) {
    return data[count - k];
  } else {
    // undefined
  }
}
int ordered_sequence::size() { return count; }
};
