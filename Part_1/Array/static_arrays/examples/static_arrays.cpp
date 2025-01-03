#include <iostream>

// Insert n into arr at the next open position.
// Length is the number of 'real' values in arr, and capacity
// is the size (aka memory allocated for the fixed size array).
void insertEnd(int arr[], int n, int length, int capacity)
{
  if (length < capacity)
  {
    arr[length - 1] = n;
  }
}

// Remove from the last position in the array if the array
// is not empty (i.e. length is non-zero).
void removeEnd(int arr[], int length)
{
  // Overwrite last element with some default value.
  // We would also consider the length to be decreased by 1.
  if (length > 0)
  {
    arr[length - 1] = 0;
  }
}

// Insert n into index i after shifting elements to the right.
// Assuming i is a valid index and arr is not full.
void insertMiddle(int arr[], int i, int n, int length)
{
  // Shift starting from the end to i.
  for (int index = length - 1; index >= i; index--)
  {
    arr[index + 1] = arr[index];
  }

  arr[i] = n;
}

// Remove value at index i before shifting elements to the left.
// Assuming i is a valid index.
void removeMiddle(int arr[], int i, int length) {
  for (int index = i + 1; index < length; index++)
  {
    arr[index - 1] = arr[index];
  }
}

void printArr(int arr[], int capacity) {
  for (int i = 0; i < capacity; i++)
  {
    std::cout << arr[i] << ' ';
  }
  std::cout << std::endl;
}


int main()
{
    int arr[10] = {1, 2, 3, 4, 5}; // Initial array with 5 elements.
    int length = 5;                // Current number of elements.

    // Insert 99 at index 2.
    insertMiddle(arr, 2, 99, length);

    // Update length after insertion.
    length++;

    // Print the updated array.
    printArr(arr, 10);

    return 0;
}
