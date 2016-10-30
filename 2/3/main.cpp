#include <iostream>
#include <queue>
#include <string>

int radix(int x, int base, int t) {
  while (t--) {
    x /= base;
  }
  return x % base;
}

int radix(const std::string &x, int base, int t) { return x[x.length() - 1 - t]; }

template <class T> void RadixSort1(T *data, int n, int base) {
  auto q = new std::queue<T>[ base ];
  for (int t = 0;; t++) {
    for (int i = 0; i < n; i++) {
      q[radix(data[i], base, t)].push(data[i]);
    }
    int cnt = 0, qCnt = 0;
    for (int i = 0; i < base; i++) {
      if (!q[i].empty()) {
        qCnt++;
      }
      while (!q[i].empty()) {
        data[cnt++] = q[i].front();
        q[i].pop();
      }
    }
    if (qCnt == 1) {
      break;
    }
  }
  delete q;
}

template <class T> void RadixSort2(T *data, int n, int base) {
  auto pool = new T[base * n];
  auto qFront = new int[base];
  auto qRear = new int[base];
  for (int i = 0; i < base; i++) {
    qFront[i] = qRear[i] = i * n;
  }
  for (int t = 0;; t++) {
    for (int i = 0; i < n; i++) {
      int rad = radix(data[i], base, t);
      pool[qRear[rad]++] = data[i];
    }
    int cnt = 0, qCnt = 0;
    for (int i = 0; i < base; i++) {
      if (qRear[i] > qFront[i]) {
        qCnt++;
      }
      while (qRear[i] > qFront[i]) {
        data[cnt++] = pool[qFront[i]++];
      }
    }
    if (qCnt == 1) {
      break;
    }
  }
  delete pool;
  delete qFront;
  delete qRear;
}

#define RadixSort RadixSort1
int main() {
  bool isInt = true;
  int T;
  while (std::cin >> T) {
    while (T--) {
      int n;
      std::cin >> n;
      if (isInt) {
        auto data = new int[n];
        for (int i = 0; i < n; i++) {
          std::cin >> data[i];
        }
        RadixSort(data, n, 10);
        for (int i = 0; i < n; i++) {
          std::cout << data[i] << " ";
        }
        std::cout << std::endl;
        delete data;
      } else {
        auto data = new std::string[n];
        for (int i = 0; i < n; i++) {
          std::cin >> data[i];
        }
        RadixSort(data, n, 256);
        for (int i = 0; i < n; i++) {
          std::cout << data[i] << " ";
        }
        std::cout << std::endl;
        delete data;
      }
    }
    isInt = !isInt;
  }
  return 0;
}
