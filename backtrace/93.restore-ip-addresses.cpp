/*
 * @lc app=leetcode id=93 lang=cpp
 *
 * [93] Restore IP Addresses
 *
 * https://leetcode.com/problems/restore-ip-addresses/description/
 *
 * algorithms
 * Medium (37.66%)
 * Likes:    1685
 * Dislikes: 553
 * Total Accepted:    228.3K
 * Total Submissions: 605.8K
 * Testcase Example:  '"25525511135"'
 *
 * Given a string s containing only digits, return all possible valid IP
 * addresses that can be obtained from s. You can return them in any order.
 *
 * A valid IP address consists of exactly four integers, each integer is
 * between 0 and 255, separated by single dots and cannot have leading zeros.
 * For example, "0.1.2.201" and "192.168.1.1" are valid IP addresses and
 * "0.011.255.245", "192.168.1.312" and "192.168@1.1" are invalid IP
 * addresses. 
 *
 *
 * Example 1:
 * Input: s = "25525511135"
 * Output: ["255.255.11.135","255.255.111.35"]
 * Example 2:
 * Input: s = "0000"
 * Output: ["0.0.0.0"]
 * Example 3:
 * Input: s = "1111"
 * Output: ["1.1.1.1"]
 * Example 4:
 * Input: s = "010010"
 * Output: ["0.10.0.10","0.100.1.0"]
 * Example 5:
 * Input: s = "101023"
 * Output: ["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]
 *
 *
 * Constraints:
 *
 *
 * 0 <= s.length <= 3000
 * s consists of digits only.
 *
 *
 */

// @lc code=start
class Solution {
public:
  vector<string> restoreIpAddresses(string s) {
    backtrace(s, 0, 0);
    return res;
  }

private:
  void backtrace(string s, int start, int part) {
    if (part == 4 && start == s.size()) {
      res.push_back(solution);
      return;
    }

    for (int i = start; i < s.size(); i++) {
      if (part < 4 && i - start < 3 && isValidIP(s, start, i)) {
        solution.append(s.substr(start, i - start + 1));
        part++;
        if (part < 4) {
          solution.push_back('.');
        }
        backtrace(s, i + 1, part);
        if (part < 4) {
          solution.pop_back();
        }
        part--;
        for (int j = 0; j < i - start + 1; j++) {
          solution.pop_back();
        }
      }
    }
  }

  bool isValidIP(string s, int start, int end) {
    // 判断string中从start到end是否满足ip要求
    string tmp = s.substr(start, end - start + 1);
    int    ip  = stoll(tmp);
    if (s[start] == '0' && start != end) {
      return false;
    } else if (ip >= 0 && ip <= 255) {
      return true;
    }

    return false;
  }

  string         solution;
  vector<string> res;
};
// @lc code=end
