#pragma once
namespace DS {
class list {
public:
  virtual bool search(int x) = 0;  
  virtual bool insert(int x) = 0;
  virtual int remove(int x) = 0;
  virtual int successor(int x) = 0;
  virtual int predecessor(int x) = 0;
  virtual int minimum() = 0;
  virtual int maximum() = 0;
  virtual int KthElement(int k) = 0;
  virtual int size() = 0;
};
};
