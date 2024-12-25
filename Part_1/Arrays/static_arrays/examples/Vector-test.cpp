#include <iostream>
#include <vector>

class Person
{
public:
  int a;
  int b;

  Person() : a(0), b(0) { }

  // Constructor
  Person(int x, int y) : a(x), b(y) {}

  // Copy Constructor
  Person(const Person &other) : a(other.a), b(other.b)
  {
    std::cout << "Copy constructor called" << std::endl;
  }
};

int main()
{
  std::vector<Person> people;
  people.reserve(3);

  people.emplace_back(3, 5);
  people.emplace_back(6, 7);
  people.emplace_back(9, 2);

  people.erase(people.begin() + 1);

  for (auto &person : people)
  {
    std::cout << person.a << " " << person.b << std::endl;
  }

  people.resize(2);
  people.resize(5); // Called two times copy constructor
}