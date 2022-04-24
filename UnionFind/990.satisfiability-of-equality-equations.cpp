/*
 * @lc app=leetcode id=990 lang=cpp
 *
 * [990] Satisfiability of Equality Equations
 *
 * https://leetcode.com/problems/satisfiability-of-equality-equations/description/
 *
 * algorithms
 * Medium (49.15%)
 * Likes:    1222
 * Dislikes: 13
 * Total Accepted:    39K
 * Total Submissions: 79.3K
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
#include <string>
#include <vector>
// @lc code=start
class Solution {
public:
  bool equationsPossible(std::vector<std::string>& equations) {
    int len = equations.size();
    if (len == 0) {
      return true;
    }
    UF uf(26);

    for (int i = 0; i < len; i++) {
      std::string str = equations[i];
      char        ch1 = str[0];
      char        ch2 = str[3];
      if (str[1] == '=') {
        if (uf.connected(ch1 - 'a', ch2 - 'a')) {
          continue;
        }
        uf.connect(ch1 - 'a', ch2 - 'a');
      }
    }

    for (int i = 0; i < len; i++) {
      std::string str = equations[i];
      char        ch1 = str[0];
      char        ch2 = str[3];
      if (str[1] == '!') {
        if (uf.connected(ch1 - 'a', ch2 - 'a')) {
          return false;
        }
      }
    }

    return true;
  }

  class UF {
  public:
    UF(int size) : count_(0) {
      parent_ = std::vector<int>(size, 0);
      weight_ = std::vector<int>(size, 0);
      for (int i = 0; i < size; i++) {
        parent_[i] = i;
        weight_[i] = 0;
      }
    }

    void connect(int p, int q) {
      int rootp = find(p);
      int rootq = find(q);

      if (rootp == rootq) {
        return;
      }

      if (weight_[rootp] < weight_[rootq]) {
        weight_[rootp] += weight_[rootq];
        parent_[rootq] = rootp;
      } else {
        weight_[rootq] += weight_[rootp];
        parent_[rootp] = rootq;
      }
    }

    int count() const {
      return count_;
    }

    int find(int p) {
      while (p != parent_[p]) {
        parent_[p] = parent_[parent_[p]];
        p          = parent_[p];
      }
      return p;
    }

    bool connected(int p, int q) {
      int rootp = find(p);
      int rootq = find(q);

      return rootp == rootq;
    }

  private:
    int              count_;
    std::vector<int> parent_;
    std::vector<int> weight_;
  };
};
// @lc code=end
