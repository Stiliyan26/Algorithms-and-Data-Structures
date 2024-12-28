#include <iostream>
#include <stack>
#include <queue>
#include <limits>

class MinStack
{
public:
    std::stack<int> stack;
    std::stack<int> minStack;

    MinStack()
    {
    }

    void push(int val)
    {
        stack.push(val);
        val = std::min(val, minStack.empty() ? val : minStack.top());
        minStack.push(val);
    }

    void pop()
    {
        stack.pop();
        minStack.pop();
    }

    int top()
    {
        return stack.top();
    }

    int getMin()
    {
        return minStack.top();
    }
};

class MinStack_V2   
{
public:
    std::stack<int> stack;
    std::stack<int> minStack;

    MinStack_V2()
    {
    }

    void push(int val)
    {
        stack.push(val);
        if (minStack.empty() || val <= minStack.top()) minStack.push(val);
    }

    void pop()
    {
        int t = stack.top();
        stack.pop();
        if (t == minStack.top()) minStack.pop();
    }

    int top()
    {
        return stack.top();
    }

    int getMin()
    {
        return minStack.top();
    }
};

int main()
{
    MinStack *minStack = new MinStack();
    // MinStack& minStackRef = *minStack;

    minStack->push(1);
    minStack->push(2);
    minStack->push(0);
    std::cout << "Min: " << minStack->getMin() << std::endl;
    minStack->pop();
    std::cout << "Top: " << minStack->top() << std::endl;
    std::cout << "Min: " << minStack->getMin() << std::endl;
}