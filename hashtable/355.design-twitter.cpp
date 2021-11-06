/*
 * @lc app=leetcode id=355 lang=cpp
 *
 * [355] Design Twitter
 *
 * https://leetcode.com/problems/design-twitter/description/
 *
 * algorithms
 * Medium (33.39%)
 * Likes:    1662
 * Dislikes: 250
 * Total Accepted:    75.7K
 * Total Submissions: 226.7K
 * Testcase Example:
 '["Twitter","postTweet","getNewsFeed","follow","postTweet","getNewsFeed","unfollow","getNewsFeed"]\n'
 +
  '[[],[1,5],[1],[1,2],[2,6],[1],[1,2],[1]]'
 *
 * Design a simplified version of Twitter where users can post tweets,
 * follow/unfollow another user, and is able to see the 10 most recent tweets
 * in the user's news feed.
 *
 * Implement the Twitter class:
 *
 *
 * Twitter() Initializes your twitter object.
 * void postTweet(int userId, int tweetId) Composes a new tweet with ID tweetId
 * by the user userId. Each call to this function will be made with a unique
 * tweetId.
 * List<Integer> getNewsFeed(int userId) Retrieves the 10 most recent tweet IDs
 * in the user's news feed. Each item in the news feed must be posted by users
 * who the user followed or by the user themself. Tweets must be ordered from
 * most recent to least recent.
 * void follow(int followerId, int followeeId) The user with ID followerId
 * started following the user with ID followeeId.
 * void unfollow(int followerId, int followeeId) The user with ID followerId
 * started unfollowing the user with ID followeeId.
 *
 *
 *
 * Example 1:
 *
 *
 * Input
 * ["Twitter", "postTweet", "getNewsFeed", "follow", "postTweet",
 * "getNewsFeed", "unfollow", "getNewsFeed"]
 * [[], [1, 5], [1], [1, 2], [2, 6], [1], [1, 2], [1]]
 * Output
 * [null, null, [5], null, null, [6, 5], null, [5]]
 *
 * Explanation
 * Twitter twitter = new Twitter();
 * twitter.postTweet(1, 5); // User 1 posts a new tweet (id = 5).
 * twitter.getNewsFeed(1);  // User 1's news feed should return a list with 1
 * tweet id -> [5]. return [5]
 * twitter.follow(1, 2);    // User 1 follows user 2.
 * twitter.postTweet(2, 6); // User 2 posts a new tweet (id = 6).
 * twitter.getNewsFeed(1);  // User 1's news feed should return a list with 2
 * tweet ids -> [6, 5]. Tweet id 6 should precede tweet id 5 because it is
 * posted after tweet id 5.
 * twitter.unfollow(1, 2);  // User 1 unfollows user 2.
 * twitter.getNewsFeed(1);  // User 1's news feed should return a list with 1
 * tweet id -> [5], since user 1 is no longer following user 2.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= userId, followerId, followeeId <= 500
 * 0 <= tweetId <= 10^4
 * All the tweets have unique IDs.
 * At most 3 * 10^4 calls will be made to postTweet, getNewsFeed, follow, and
 * unfollow.
 *
 *
 */

#include <iostream>
#include <list>
#include <queue>
#include <set>
#include <unordered_map>
#include <vector>

// @lc code=start

struct Tweet {
  Tweet(int tweetId, int timeId)
      : tweetId(tweetId), timeId(timeId), next(nullptr) {
  }

  int    timeId;
  int    tweetId;
  Tweet *next;
};

class User {
public:
  User(int userId) : userId(userId), head(nullptr) {
    follow(userId);  // 关注他自己
  }

  void post(Tweet *tw) {
    // 放入一个tweet
    if (head == nullptr) {
      head = tw;
      return;
    }
    tw->next = head;
    head     = tw;
  }

  void follow(int userid) {
    // 关注一个用户
    followee.insert(userid);
  }

  void unfllow(int userid) {
    // 取关一个用户
    if (userid != this->userId) {
      followee.erase(userid);
    }
  }

  // 返回关注列表
  std::set<int> getFollow() const {
    return followee;
  }

  Tweet *getTweetList() const {
    return head;
  }

private:
  int           userId;
  std::set<int> followee;  // 该用户的关注列表
  Tweet *       head;      // 最新的一条tweet
};

class Twitter {
public:
  Twitter() {
  }

  void postTweet(int userId, int tweetId) {
    if (!map.count(userId)) {
      map.insert(std::make_pair(userId, new User(userId)));
    }
    Tweet *tw = new Tweet(tweetId, timeId++);
    map[userId]->post(tw);
  }

  std::vector<int> getNewsFeed(int userId) {
    std::vector<int> res;
    if (!map.count(userId)) {
      return res;
    }

    std::priority_queue<Tweet *, std::vector<Tweet *>, less> pq;  // 小根堆
    std::set<int> s = map[userId]->getFollow();

    for (auto item : s) {
      Tweet *tw = map[item]->getTweetList();
      if (tw != nullptr) {
        pq.push(tw);
      }
    }

    while (!pq.empty()) {
      if (res.size() == 10) {
        break;
      }
      Tweet *tw = pq.top();
      pq.pop();

      res.push_back(tw->tweetId);

      if (tw->next) {
        pq.push(tw->next);
      }
    }

    return res;
  }

  void follow(int followerId, int followeeId) {
    if (!map.count(followerId)) {
      User *user = new User(followerId);
      map.insert(std::make_pair(followerId, user));
    }

    if (!map.count(followeeId)) {
      User *user = new User(followeeId);
      map.insert(std::make_pair(followeeId, user));
    }

    map[followerId]->follow(followeeId);
  }

  void unfollow(int followerId, int followeeId) {
    if (map.count(followerId)) {
      map[followerId]->unfllow(followeeId);
    }
  }

  void print() {
    for (auto it : map) {
      std::cout << "user " << it.first << " : ";
      for (auto item : it.second->getFollow()) {
        std::cout << item << ' ';
      }
      std::cout << '\n';
    }
  }

private:
  struct less {
    bool operator()(const Tweet *t1, const Tweet *t2) const {
      return t1->timeId < t2->timeId;
    }
  };

  std::unordered_map<int, User *> map;  // userid 与 User的对应关系
  static int                      timeId;
};

int Twitter::timeId = 1;

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
// @lc code=end

void print(std::vector<int> &nums) {
  for (auto item : nums) {
    std::cout << item << ' ';
  }
  std::cout << "\n";
}

int main(int argc, char **argv) {
  Twitter *obj = new Twitter();
  obj->postTweet(1, 5);
  std::vector<int> param_2 = obj->getNewsFeed(1);
  print(param_2);
  obj->follow(1, 2);
  obj->print();
  obj->postTweet(2, 6);
  param_2 = obj->getNewsFeed(1);
  print(param_2);
  obj->unfollow(1, 2);
  obj->print();
}
