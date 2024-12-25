#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>

bool isValid(std::string &stringOfPrentasis)
{
  std::stack<char> stack;
  std::unordered_map<char, char> closeToOpen = {
      {'}', '{'},
      {']', '['},
      {')', '('}};

  for (char c : stringOfPrentasis)
  {
    if (closeToOpen.count(c))
    {
      if (!stack.empty() && stack.top() == closeToOpen[c])
      {
        stack.pop();
      }
      else
      {
        return false;
      }
    }
    else
    {
      stack.push(c);
    }
  }

  return stack.empty();
}

bool isValid_2(std::string &s)
{
  while (true) {
    std::size_t pos = std::string::npos;

    if ((pos = s.find("()")) != std::string::npos) {
      s.erase(pos, 2);
      continue;
    }

    if ((pos = s.find("[]")) != std::string::npos) {
      s.erase(pos, 2);
      continue;
    }

    if ((pos = s.find("{}")) != std::string::npos) {
      s.erase(pos, 2);
      continue;
    }

    break;
  }

  return s.empty();
}

int main()
{
  // std::string brackets = "]";
  std::string brackets = "([{}])";
  // std::string brackets = "()[]{}";
  // std::string brackets = "([)]]{}";
  // std::string brackets = "(){}}{";

  std::cout << std::boolalpha << isValid_2(brackets) << std::endl;

  return 0;
}