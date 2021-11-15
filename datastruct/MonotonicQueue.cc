#include <list>

// 单调队列的实现
class MonotonicQueue {
public:
  void push(int n) {
    // 删除当前队列中所有小于n的元素
    while (!que_.empty() && que_.back() <= n) {
      que_.pop_back();
    }

    que_.push_back(n);
  }

  int max() const {
    return que_.front();
  }

  void popFirst(int n) {
    if (n == que_.front()) {
      return que_.pop_front();
    }
  }

private:
  std::list<int> que_;
};
