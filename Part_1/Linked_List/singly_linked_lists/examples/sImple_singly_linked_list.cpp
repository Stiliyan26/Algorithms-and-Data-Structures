#include <iostream>


struct ListNode
{
  int val_;
  ListNode *next = nullptr;

  ListNode(int val)
  {
    val_ = val;
  }
};

class SinglyLinkedList
{
public:
  ListNode *head;
  ListNode *tail;

  SinglyLinkedList()
  {
    // Init the list with a 'dummy' node which makes
    // removing a node from the beginning of list easier.
    head = new ListNode(-1);
    tail = head;
  }

  void insertEnd(int val)
  {
    tail->next = new ListNode(val);
    tail = tail->next;
  }

  void remove(int index)
  {
    int i = 0;
    ListNode* curr = head;

    //We start from dummy element wich is has value -1 

    // 1. Checking for the curr becouse we could exceed the indexes 
    // if we pass a big number for index varaible also we move the 
    // last element so when we check for if (curr && curr->next) the condition is false
    
    // 2. Checking for i < index is to stop when we find the element
    // wich we want to remove 
    while (i < index && curr)
    {
      i++;
      curr = curr->next;
    }
    
    if (curr && curr->next) {
      if (curr->next == tail) {
        tail = curr;
      }
      
      ListNode* nodeToRemove = curr->next;
      curr->next = curr->next->next;

      delete nodeToRemove;
    }
  }

  void print() {
    ListNode* curr = head->next;

    while (curr)
    {
      std::cout << curr->val_ << " -> ";
      curr = curr->next;
    }
    
    std::cout << std::endl;
  }
};

int main() {

  SinglyLinkedList list;

    // Adding elements to the list
    list.insertEnd(10);
    list.insertEnd(20); //remove
    list.insertEnd(30);
    list.insertEnd(40);

    std::cout << "List after adding elements:" << std::endl;
    list.print();

    // Removing an element at index 1
    std::cout << "Removing element at index 1:" << std::endl;
    list.remove(0);
    list.print();

    // Removing an element at index 0
    std::cout << "Removing element at index 0:" << std::endl;
    list.remove(0);
    list.print();

    // Attempt to remove an element at an invalid index
    std::cout << "Removing element at invalid index 10:" << std::endl;
    list.remove(10);
    list.print();

  return 0;
}

  // void remove(int index)
  // {
  //   int currentIndex = 0;

  //   ListNode *currentNode = head;

  //   while (currentNode != nullptr)
  //   {
  //     // If the removal index is not equal to the current index of the LinkedList
  //     //  set currentNode to the next node and increment the current index
  //     if (index != currentIndex + 1)
  //     {
  //       currentNode = currentNode->next;
  //       currentIndex++;

  //       continue;
  //     }

  //     currentNode->next = currentNode->next->next;
  //     break;
  //   }
  // }