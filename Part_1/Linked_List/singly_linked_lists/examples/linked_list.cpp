#include <iostream>
#include <vector>

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
    // Init the list with a 'dummy' node which makes
    // removing a node from the beginning of list easier.
    head = new ListNode(-1);
    tail = head;
  }


  int get(int index) {
    int currentIndex = 0;
    ListNode* currentNode = head->next;

    while (currentIndex != index && currentNode != nullptr) {
      currentIndex++;
      currentNode = currentNode->next;
    }

    if (currentNode == nullptr) return -1; 

    return currentNode->val;
  }

  void insertHead(int val) {
    ListNode* newNode = new ListNode(val);

    newNode->next = head->next;
    head->next = newNode;

    if (newNode->next == nullptr) {
      tail = newNode;
    }
  }

  void insertTail(int val) {
    ListNode* newNode = new ListNode(val);

    tail->next = newNode;
    tail = newNode;
  }

  bool remove(int index) {
    int currentIndex = 0;
    ListNode* currentNode = head;

    while (currentIndex < index && currentNode != nullptr) {
      currentIndex++;
      currentNode = currentNode->next;
    }

    if (currentNode != nullptr && currentNode->next != nullptr) {

      if (currentNode->next == tail) {
        tail = currentNode;
      }

      ListNode* nodeToDelete = currentNode->next;
      currentNode->next = currentNode->next->next;

      delete nodeToDelete;

      return true;
    }

    return false;
  }

  std::vector<int> getValues() {
    std::vector<int> allValues;

    ListNode* currentNode = head->next;

    while (currentNode != nullptr) {
      allValues.push_back(currentNode->val);
      currentNode = currentNode->next;
    }

    return allValues;
  }
};

int main() {

  SinglyLinkedList list;

  return 0;
}