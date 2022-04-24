/*
 * @lc app=leetcode id=71 lang=cpp
 *
 * [71] Simplify Path
 *
 * https://leetcode.com/problems/simplify-path/description/
 *
 * algorithms
 * Medium (36.72%)
 * Likes:    1037
 * Dislikes: 262
 * Total Accepted:    335.9K
 * Total Submissions: 912.6K
 * Testcase Example:  '"/home/"'
 *
 * Given a string path, which is an absolute path (starting with a slash '/')
 * to a file or directory in a Unix-style file system, convert it to the
 * simplified canonical path.
 *
 * In a Unix-style file system, a period '.' refers to the current directory, a
 * double period '..' refers to the directory up a level, and any multiple
 * consecutive slashes (i.e. '//') are treated as a single slash '/'. For this
 * problem, any other format of periods such as '...' are treated as
 * file/directory names.
 *
 * The canonical path should have the following format:
 *
 *
 * The path starts with a single slash '/'.
 * Any two directories are separated by a single slash '/'.
 * The path does not end with a trailing '/'.
 * The path only contains the directories on the path from the root directory
 * to the target file or directory (i.e., no period '.' or double period
 * '..')
 *
 *
 * Return the simplified canonical path.
 *
 *
 * Example 1:
 *
 *
 * Input: path = "/home/"
 * Output: "/home"
 * Explanation: Note that there is no trailing slash after the last directory
 * name.
 *
 *
 * Example 2:
 *
 *
 * Input: path = "/../"
 * Output: "/"
 * Explanation: Going one level up from the root directory is a no-op, as the
 * root level is the highest level you can go.
 *
 *
 * Example 3:
 *
 *
 * Input: path = "/home//foo/"
 * Output: "/home/foo"
 * Explanation: In the canonical path, multiple consecutive slashes are
 * replaced by a single one.
 *
 *
 * Example 4:
 *
 *
 * Input: path = "/a/./b/../../c/"
 * Output: "/c"
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= path.length <= 3000
 * path consists of English letters, digits, period '.', slash '/' or '_'.
 * path is a valid absolute Unix path.
 *
 *
 */

#include <cstring>
#include <iostream>
#include <list>
#include <string>
#include <vector>

// @lc code=start
class Solution {
public:
  std::string simplifyPath(std::string path) {
    std::vector<std::string> str = splitString(path.c_str(), "/");
    std::list<std::string>   que;
    for (auto item : str) {
      if (item == "." || item == "") {
        continue;
      } else if (item == "..") {
        if (que.size()) {
          que.pop_back();
        }
      } else if (item != "") {
        que.push_back(item);
      }
    }
    std::string res = "/";

    while (que.size()) {
      res.append(que.front() + "/");
      que.pop_front();
    }

    if (res.length() > 1) {
      res.pop_back();
    }
    return res;
  }

private:
  std::vector<std::string> splitString(std::string s, std::string seq) {
    std::vector<std::string> res;

    char* str = strtok(const_cast<char*>(s.c_str()), seq.c_str());
    if (str != nullptr) {
      res.push_back(str);
    }

    while ((str = strtok(NULL, seq.c_str()))) {
      res.push_back(str);
    }

    for (auto it : res) {
      std::cout << it << std::endl;
    }

    return res;
  }
};
// @lc code=end

int main(int argc, char** argv) {
  std::string path = "//home/";
  Solution    solution;
  std::cout << solution.simplifyPath(path) << std::endl;
}
