#include "ordered_single_circular_linked_list.h"
#include "ordered_sequence.h"
#include "unordered_single_circular_linked_list.h"
#include "unordered_sequence.h"
#include <iostream>

int main() {
  DS::list *ptr;
  DS::unordered_sequence list1(100);
  DS::ordered_sequence list2(100);
  DS::unordered_single_circular_linked_list list3;
  DS::ordered_single_circular_linked_list list4;
  int lists[4] = {int(&list1), int(&list2), int(&list3), int(&list4)};
  for (int i = 0; i < 4; i++) {
    std::cout << "testing: " << i << std::endl;
    DS::list *ptr = (DS::list *)lists[i];
    // operating list
    std::cout << ptr->insert(4) << std::endl;
    std::cout << ptr->search(4) << std::endl;
    std::cout << ptr->search(5) << std::endl;
    std::cout << ptr->insert(5) << std::endl;
    std::cout << ptr->size() << std::endl;
    std::cout << ptr->minimum() << std::endl;
    std::cout << ptr->remove(4) << std::endl;
    std::cout << ptr->minimum() << std::endl;
  }
  return 0;
}
