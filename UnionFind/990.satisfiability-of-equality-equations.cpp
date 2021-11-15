/*
 * @lc app=leetcode id=990 lang=cpp
 *
 * [990] Satisfiability of Equality Equations
 *
 * https://leetcode.com/problems/satisfiability-of-equality-equations/description/
 *
 * algorithms
 * Medium (48.94%)
 * Likes:    1179
 * Dislikes: 13
 * Total Accepted:    37.7K
 * Total Submissions: 77.1K
 * Testcase Example:  '["a==b","b!=a"]'
 *
 * You are given an array of strings equations that represent relationships
 * between variables where each string equations[i] is of length 4 and takes
 * one of two different forms: "xi==yi" or "xi!=yi".Here, xi and yi are
 * lowercase letters (not necessarily different) that represent one-letter
 * variable names.
 *
 * Return true if it is possible to assign integers to variable names so as to
 * satisfy all the given equations, or false otherwise.
 *
 *
 * Example 1:
 *
 *
 * Input: equations = ["a==b","b!=a"]
 * Output: false
 * Explanation: If we assign say, a = 1 and b = 1, then the first equation is
 * satisfied, but not the second.
 * There is no way to assign the variables to satisfy both equations.
 *
 *
 * Example 2:
 *
 *
 * Input: equations = ["b==a","a==b"]
 * Output: true
 * Explanation: We could assign a = 1 and b = 1 to satisfy both equations.
 *
 *
 * Example 3:
 *
 *
 * Input: equations = ["a==b","b==c","a==c"]
 * Output: true
 *
 *
 * Example 4:
 *
 *
 * Input: equations = ["a==b","b!=c","c==a"]
 * Output: false
 *
 *
 * Example 5:
 *
 *
 * Input: equations = ["c==c","b==d","x!=z"]
 * Output: true
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= equations.length <= 500
 * equations[i].length == 4
 * equations[i][0] is a lowercase letter.
 * equations[i][1] is either '=' or '!'.
 * equations[i][2] is '='.
 * equations[i][3] is a lowercase letter.
 *
 *
 */

#include <iostream>
#include <vector>

// @lc code=start

class Solution {
public:
  bool equationsPossible(std::vector<std::string>& equations) {
    UF  uf(26);
    int row = equations.size();

    for (int i = 0; i < row; i++) {
      char ch = equations[i][1];
      if (ch == '=') {
        uf.connect(equations[i][0] - 'a', equations[i][3] - 'a');
      }
    }

    for (int i = 0; i < row; i++) {
      char ch = equations[i][1];
      if (ch == '!') {
        if (uf.isConnect(equations[i][0] - 'a', equations[i][3] - 'a')) {
          return false;
        }
      }
    }

    return true;
  }

private:
  class UF {
  public:
    UF(int n) {
      _weight = std::vector<int>(n, 1);
      _parent = std::vector<int>(n, 0);
      for (int i = 0; i < n; i++) {
        _parent[i] = i;
      }

      _count = n;
    }

    int find(int p) {
      while (p != _parent[p]) {
        _parent[p] = _parent[_parent[p]];
        p          = _parent[p];
      }

      return p;
    }

    void connect(int p, int q) {
      int rootP = find(p);
      int rootQ = find(q);

      if (rootQ == rootP) {
        return;
      }

      if (_weight[rootP] >= _weight[rootQ]) {
        _parent[rootQ] = rootP;
        _weight[rootP] += _weight[rootQ];
      } else {
        _parent[rootP] = rootQ;
        _weight[rootQ] += _weight[rootP];
      }
      _count--;
    }

    int count() const {
      return _count;
    }

    bool isConnect(int p, int q) {
      int rootP = find(p);
      int rootQ = find(q);

      return rootP == rootQ;
    }

  private:
    std::vector<int> _weight;
    std::vector<int> _parent;
    int              _count;
  };
};
// @lc code=end
