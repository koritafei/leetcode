/*
 * @lc app=leetcode id=1024 lang=cpp
 *
 * [1024] Video Stitching
 *
 * https://leetcode.com/problems/video-stitching/description/
 *
 * algorithms
 * Medium (49.72%)
 * Likes:    1008
 * Dislikes: 44
 * Total Accepted:    40.9K
 * Total Submissions: 82.2K
 * Testcase Example:  '[[0,2],[4,6],[8,10],[1,9],[1,5],[5,9]]\n10'
 *
 * You are given a series of video clips from a sporting event that lasted time
 * seconds. These video clips can be overlapping with each other and have
 * varying lengths.
 *
 * Each video clip is described by an array clips where clips[i] = [starti,
 * endi] indicates that the ith clip started at starti and ended at endi.
 *
 * We can cut these clips into segments freely.
 *
 *
 * For example, a clip [0, 7] can be cut into segments [0, 1] + [1, 3] + [3,
 * 7].
 *
 *
 * Return the minimum number of clips needed so that we can cut the clips into
 * segments that cover the entire sporting event [0, time]. If the task is
 * impossible, return -1.
 *
 *
 * Example 1:
 *
 *
 * Input: clips = [[0,2],[4,6],[8,10],[1,9],[1,5],[5,9]], time = 10
 * Output: 3
 * Explanation:
 * We take the clips [0,2], [8,10], [1,9]; a total of 3 clips.
 * Then, we can reconstruct the sporting event as follows:
 * We cut [1,9] into segments [1,2] + [2,8] + [8,9].
 * Now we have segments [0,2] + [2,8] + [8,10] which cover the sporting event
 * [0, 10].
 *
 *
 * Example 2:
 *
 *
 * Input: clips = [[0,1],[1,2]], time = 5
 * Output: -1
 * Explanation: We can't cover [0,5] with only [0,1] and [1,2].
 *
 *
 * Example 3:
 *
 *
 * Input: clips =
 * [[0,1],[6,8],[0,2],[5,6],[0,4],[0,3],[6,7],[1,3],[4,7],[1,4],[2,5],[2,6],[3,4],[4,5],[5,7],[6,9]],
 * time = 9
 * Output: 3
 * Explanation: We can take clips [0,4], [4,7], and [6,9].
 *
 *
 * Example 4:
 *
 *
 * Input: clips = [[0,4],[2,8]], time = 5
 * Output: 2
 * Explanation: Notice you can have extra video after the event ends.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= clips.length <= 100
 * 0 <= starti <= endi <= 100
 * 1 <= time <= 100
 *
 *
 */

#include <algorithm>
#include <vector>

// @lc code=start
class Solution {
public:
  int videoStitching(std::vector<std::vector<int>>& clips, int time) {
    if (time == 0) {
      return 0;
    }

    // 起点升序，起点相同，终点降序
    std::sort(clips.begin(),
              clips.end(),
              [](std::vector<int> a, std::vector<int> b) {
                if (a[0] == b[0]) {
                  return a[1] > b[1];
                }

                return a[0] < b[0];
              });
    int res     = 0;  // 选择的视频数
    int currend = 0, nextend = 0;
    int i = 0, len = clips.size();

    while (i < len && clips[i][0] <= currend) {
      // 在第res个视频区间内贪心选择下一个视频
      // 起点一定小于等于当前的终点
      // 一直到找到一个区间的起点大于大于当前的终点结束
      while (i < len && clips[i][0] <= currend) {
        nextend = std::max(nextend, clips[i][1]);
        i++;
      }

      res++;  // 选中一个视频
      currend = nextend;
      if (currend >= time) {
        return res;
      }
    }

    return -1;
  }
};
// @lc code=end
