#include <iostream>

struct ListNode {
  int val;
  ListNode* next;

  ListNode(int _val) : val(_val), next(nullptr) {}

  ListNode(int _val, ListNode* _next) : val(_val), next(_next) {}
};

class SinglyLinkedList {

private:
  ListNode* head;
  ListNode* tail;

public:
  SinglyLinkedList() {
    head = new ListNode(-1);
    tail = head;
  }


  int get(int index) {
    int currentIndex = 0;
    ListNode* currentNode = head->next;

    while (!equalCurrentIndexAndIndex(currentIndex, index) && !nodeIsNullptr(currentNode)) {
      currentIndex++;
      currentNode = currentNode->next;
    }

    if (nodeIsNullptr(currentNode)) return -1;

    return currentNode->val;
  }

private:
  bool equalCurrentIndexAndIndex(int currentIndex, int index) {
    return currentIndex == index;
  }

  bool nodeIsNullptr(ListNode* node) {
    return node == nullptr;
  }
};

int main() {

  SinglyLinkedList list;

  return 0;
}
