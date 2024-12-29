#include <iostream>
#include <vector>

struct ListNode {
  int val;
  ListNode* next;

  ListNode(const int _val) : val(_val), next(nullptr) {}

  ListNode(const int _val, ListNode* _next) : val(_val), next(_next) {}
};

class SinglyLinkedList {

private:
  ListNode* head;
  ListNode* tail;
  int& a;

public:
  SinglyLinkedList(int& b) : head(new ListNode(-1)), tail(head), a(b) {}

  int get(int index) const {
    int currentIndex = 0;
    ListNode* currentNode = head->next;

    // head = head->next;
    // a = currentIndex;

    while (currentNode != nullptr) {

      if (currentIndex == index) {
        return currentNode->val;
      }

      currentIndex++;
      currentNode = currentNode->next;
    }

    return -1;
  }

  // int get(int index) {
  //   int currentIndex = 0;
  //   ListNode* currentNode = head->next;

  //   while (currentIndex != index) {

  //     if (currentNode == nullptr) return -1;

  //     currentIndex++;
  //     currentNode = currentNode->next;
  //   }

  //   return currentNode->val;
  // }

  void insertHead(int val) {
    ListNode* newNode = new ListNode(val);

    newNode->next = head->next;
    head->next = newNode;

    // If list was empty before insertion
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

    if (currentNode == nullptr) {
      return false;
    }

    ListNode* nodeToDelete = currentNode->next;

    if (nodeToDelete == nullptr) {
      return false;
    }

    if (nodeToDelete == tail) {
      tail = currentNode;
    }

    currentNode->next = nodeToDelete->next;
    delete nodeToDelete;

    return true;
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
  int a{2};
  int b = 2 + a;
  SinglyLinkedList list(b);

  return 0;
}

//gcc -c Part_1\Linked_List\singly_linked_lists\examples\singly_linked_list.cpp -Wall -Wextra -Werror

//All warings , extra warnings