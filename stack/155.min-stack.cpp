/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 */

/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 */

#include <iostream>
#include <stack>

// @lc code=start
class MinStack {
  public:
  /** initialize your data structure here. */
  MinStack() {
  }

  void push(int x) {
    stack.push(x);
    if (!minstack.empty()) {
      minstack.push(x < minstack.top() ? x : minstack.top());
    } else {
      minstack.push(x);
    }
  }

  void pop() {
    if (!stack.empty()) {
      stack.pop();
      minstack.pop();
    }
  }

  int top() {
    if (!stack.empty()) {
      return stack.top();
    }
    throw std::runtime_error("empty stack");
  }

  int getMin() {
    if (!minstack.empty()) {
      return minstack.top();
    }
    throw std::runtime_error("empty stack");
  }

  private:
  std::stack<int> stack;
  std::stack<int> minstack;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

int main(int argc, char** argv) {
  MinStack m;
  m.push(2);
  m.push(1);
  std::cout << m.getMin() << std::endl;
  m.pop();
  std::cout << m.getMin() << std::endl;
  m.pop();
}
