//
//  _509_斐波那契数.cpp
//  LeetCode-C++
//
//  Created by warden on 2019/11/25.
//  Copyright © 2019 warden. All rights reserved.
//
// https://leetcode-cn.com/problems/fibonacci-number/

#include <iostream>

using namespace std;

class Solution {
public:
    int fib(int N) {
        if (N == 0) {
            return 0;
        }
        int f0 = 0;
        int f1 = 1;
        for (int i = 1; i < N; i++) {
            int tmp = f1;
            f1 = f1 + f0;
            f0 = tmp;
        }
        return f1;
    }
};

/**
 输入：2
 输出：1
 解释：F(2) = F(1) + F(0) = 1 + 0 = 1.

 输入：3
 输出：2
 解释：F(3) = F(2) + F(1) = 1 + 1 = 2.

 输入：4
 输出：3
 解释：F(4) = F(3) + F(2) = 2 + 1 = 3.
*/
/**
int main(int argc, const char * argv[]) {
    Solution solution = Solution();
    cout << solution.fib(0) << endl;
    cout << solution.fib(1) << endl;
    cout << solution.fib(2) << endl;
    cout << solution.fib(3) << endl;
    cout << solution.fib(4) << endl;
    cout << solution.fib(5) << endl;
    cout << solution.fib(6) << endl;
    cout << solution.fib(7) << endl;
    
    return 0;
}
*/
