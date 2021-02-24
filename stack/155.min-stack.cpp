/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 */

#include <iostream>
#include <stack>

using namespace std;

// @lc code=start
class MinStack {
public:
  /** initialize your data structure here. */
  MinStack() {
  }

  void push(int x) {
    _value.push(x);
    if (_min.size()) {
      if (_min.top() <= x) {
        _min.push(_min.top());
      } else {
        _min.push(x);
      }
    } else {
      _min.push(x);
    }
  }

  void pop() {
    if (_value.size()) {
      _value.pop();
      _min.pop();
    } else {
      throw("No Data");
    }
  }

  int top() {
    if (_value.size()) {
      return _value.top();
    } else {
      throw("No Data");
    }
  }

  int getMin() {
    if (_min.size()) {
      return _min.top();
    } else {
      throw("No Datas");
    }
  }

private:
  stack<int> _value;  // store value
  stack<int> _min;    // store min value
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

int main(int argc, char **argv) {
  MinStack *minStack = new MinStack();
  minStack->push(-2);
  minStack->push(0);
  minStack->push(5);
  minStack->push(-3);
  std::cout << minStack->getMin() << std::endl;  // return -3
  minStack->pop();
  std::cout << minStack->top() << std::endl;     // return 0
  std::cout << minStack->getMin() << std::endl;  // return -2
  delete minStack;
}
