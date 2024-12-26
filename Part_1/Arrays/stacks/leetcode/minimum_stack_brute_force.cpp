#include <iostream>
#include <stack>
#include <queue>
#include <limits>
#include <algorithm>

class MinStack
{
public:
    std::stack<int> stack;

    MinStack()
    {
    }

    void push(int val)
    {
        stack.push(val);
    }

    void pop()
    {
        if (!stack.empty())
        {
            stack.pop();
        }
    }

    int top()
    {
        return stack.top();
    }

    int getMin()
    {
        std::stack<int> tempStack;
        int minValue = std::numeric_limits<int>::max();

        while (!stack.empty())
        {
            if (minValue > stack.top())
            {
                minValue = stack.top();
            }

            tempStack.push(stack.top());
            stack.pop();
        }

        while (!tempStack.empty())
        {
            stack.push(tempStack.top());
            tempStack.pop();
        }

        return minValue;
    }
};

class MinStack_2 {
public:
    std::stack<int> stk;

    MinStack_2() {
        
    }
    
    void push(int val) {
        stk.push(val);
    }
    
    void pop() {
        stk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        std::stack<int> tmp;
        
        int mini = stk.top();

        while (stk.size()) {
            mini = std::min(mini, stk.top());
            tmp.push(stk.top());
            stk.pop();
        }

        while (tmp.size()) {
            stk.push(tmp.top());
            tmp.pop();
        }

        return mini;
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