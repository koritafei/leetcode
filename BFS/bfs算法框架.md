## `BFS`算法框架
`BFS`找到的路径一定是最短的,代价是空间复杂度比`DFS`大很多。
本质上`BFS`问题：
**在一幅图中找到从起点`start`到终点`target`的最近距离。**
`BFS框架`：
```cpp
// 计算起点start到终点target的最短距离
int BFS(Node start, Node end) {
  std::queue<Node> queue; // 核心数据结构
  std::set<Node> visited; // 避免走回头路

  queue.push(start); // 将起点加入队列
  visited[start] = true; // 标记已访问
  int step = 0; // 记录扩散的步数
  while(!queue.empty()) {
    int sz = queue.size();
    // 将队列的所有节点向四周扩散
    for(int i = 0; i < sz;i++) {
      Node cur = queue.poll();
      // 判断是否到达终点
      if(cur is target) {
        return step;
      }
      // 将cur 相邻的节点加入队列
      for(Node x: cur.adj()) {
        if(x is not visited) {
          queue.push(x);
          visited[x] = true;
        }
      }
    }
    step++; // 更新步数
  }
}
```
### 双向`BFS`优化
传统`BFS`是从`start`向四周扩散到`target`终止;
双向`BFS`是`start`和`target`同时开始扩散，当两边有交集时终止。
双向优化框架：
```cpp
int twoBFS(std::vector<T> &depends,T start ,T target) {
  std::unordered_set<T> set;

  for(auto s:depends) {
    set.insert(s);
  }

  // 使用集合加快元素判断
  std::unordered_set<T> q1;
  std::unordered_set<T> q2;
  std::unordered_set<T> visited;

  int step = 0;

  q1.insert(start);
  q2.insert(target);

  while(!q1.empty() && !q2.empty()) {
    // 哈希集合在遍历时不能修改，用temp扩散结果
    std::unordered_set<T> temp;

    // 优化，判断q1和q2的大小，每次从最小的集合开始
    if(q1.size() > q2.size()) {
      temp = q1;
      q1 = q2;
      q2 = temp;
    }

    // 将q1的所有节点向四周扩散
    for(auto s : q1) {
      // 判断是否到达终点
      if(set.find(s) != set.end()) {
        continue;
      }

      if(q2.find(s) != q2.end()) {
        return step;
      }

      visited.insert(s);

      // 将每个节点未遍历节点加入集合
      temp.insert(next);

    }

    // 增加步数
    step++;
    // 此时temp 相当于q1
    // 交换q1,q2，下一次循环扩散q2
    q1 = q2;
    q2 = temp;
  }

  return -1;
}
```

