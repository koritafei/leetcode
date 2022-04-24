#include <iostream>

// 实现一个计算器

// 1.字符串转整数
int strToInt(std::string str) {
  int n = 0;
  for (int i = 0; i < str.size(); ++i) {
    n = n * 10 + (str[i] - '0');
  }

  return n;
}

// 2. 处理加减法
int calculate(std::string str) {
}