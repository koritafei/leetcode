/*
 * @lc app=leetcode id=232 lang=cpp
 *
 * [232] Implement Queue using Stacks
 */

#include <iostream>
#include <stack>

// @lc code=start
class MyQueue {
  public:
  /** Initialize your data structure here. */
  MyQueue() {
  }

  /** Push element x to the back of queue. */
  void push(int x) {
    _stack1.push(x);
  }

  /** Removes the element from in front of queue and returns that element. */
  int pop() {
    if (_stack2.empty()) {
      while (!_stack1.empty()) {
        _stack2.push(_stack1.top());
        _stack1.pop();
      }
    }

    if (!_stack2.empty()) {
      int res = _stack2.top();
      _stack2.pop();
      return res;
    } else {
      throw std::runtime_error("empty queue");
    }
  }

  /** Get the front element. */
  int peek() {
    if (_stack2.empty()) {
      while (!_stack1.empty()) {
        _stack2.push(_stack1.top());
        _stack1.pop();
      }
    }

    if (!_stack2.empty()) {
      return _stack2.top();
    } else {
      throw std::runtime_error("empty queue");
    }
  }

  /** Returns whether the queue is empty. */
  bool empty() {
    return _stack1.empty() && _stack2.empty();
  }

  private:
  std::stack<int> _stack1;
  std::stack<int> _stack2;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end

int main(int argc, char** argv) {
  MyQueue mq;
  mq.push(1);
  mq.push(2);
}
