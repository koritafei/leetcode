/*
 * @lc app=leetcode id=341 lang=cpp
 *
 * [341] Flatten Nested List Iterator
 *
 * https://leetcode.com/problems/flatten-nested-list-iterator/description/
 *
 * algorithms
 * Medium (54.62%)
 * Likes:    2057
 * Dislikes: 785
 * Total Accepted:    204.1K
 * Total Submissions: 373.5K
 * Testcase Example:  '[[1,1],2,[1,1]]'
 *
 * Given a nested list of integers, implement an iterator to flatten it.
 *
 * Each element is either an integer, or a list -- whose elements may also be
 * integers or other lists.
 *
 * Example 1:
 *
 *
 *
 * Input: [[1,1],2,[1,1]]
 * Output: [1,1,2,1,1]
 * Explanation: By calling next repeatedly until hasNext returns
 * false,
 * the order of elements returned by next should be: [1,1,2,1,1].
 *
 *
 * Example 2:
 *
 *
 * Input: [1,[4,[6]]]
 * Output: [1,4,6]
 * Explanation: By calling next repeatedly until hasNext returns
 * false,
 * the order of elements returned by next should be: [1,4,6].
 *
 *
 *
 *
 */

// @lc code=start
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than
 * a nested list. bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a
 * single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a
 * nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
  NestedIterator(vector<NestedInteger> &nestedList) {
    int size = nestedList.size();
    for (int i = size-1; i >= 0; i--) {
      _stack.push(nestedList[i]);
    }
  }

  int next() {
    int result = _stack.top().getInteger();
    _stack.pop();
    return result;
  }

  bool hasNext() {
    while (_stack.size()) {
      NestedInteger curr = _stack.top();
      if (curr.isInteger()) {
        return true;
      }
      _stack.pop();

      vector<NestedInteger> &adj = curr.getList();
      for (int i = adj.size()-1; i >= 0; i--) {
        _stack.push(adj[i]);
      }
    }

      return false;
    }

  private:
    stack<NestedInteger> _stack;
  };

  /**
   * Your NestedIterator object will be instantiated and called as such:
   * NestedIterator i(nestedList);
   * while (i.hasNext()) cout << i.next();
   */
  // @lc code=end
