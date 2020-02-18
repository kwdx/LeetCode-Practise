//
//  _856_括号的分数.cpp
//  LeetCode-C++
//
//  Created by warden on 2019/12/3.
//  Copyright © 2019 warden. All rights reserved.
//
// https://leetcode-cn.com/problems/score-of-parentheses/

#include <stdio.h>
#include <string>
#include <stack>

using namespace std;
class Solution {
public:
    int scoreOfParentheses(string S) {
        stack<int> score;
        stack<int> parentheses;
        for (int i = 0; i < S.length(); i++) {
            char ch = S[i];
            if (ch == '(') {
                score.push(0);
                parentheses.push((int)score.size());
            } else if (ch == ')') {
                int leftPos = parentheses.top();
                parentheses.pop();
                if (score.size() == leftPos) {
                    score.pop();
                    score.push(1);
                    continue;
                }
                int val = 0;
                while (score.size() > leftPos) {
                    val += score.top();
                    score.pop();
                }
                score.push(val * 2);
            }
        }
        int val = 0;
        while (!score.empty()) {
            val += score.top();
            score.pop();
        }
        return val;
    }
};

/**
 () 得 1 分。
 AB 得 A + B 分，其中 A 和 B 是平衡括号字符串。
 (A) 得 2 * A 分，其中 A 是平衡括号字符串。

 输入： "()"
 输出： 1

 输入： "(())"
 输出： 2

 输入： "()()"
 输出： 2

 输入： "(()(()))"
 输出： 6
*/
/**
int main(int argc, const char * argv[]) {
    Solution solution = Solution();

    printf("%d\n", solution.scoreOfParentheses("()"));
    printf("%d\n", solution.scoreOfParentheses("(())"));
    printf("%d\n", solution.scoreOfParentheses("()()"));
    printf("%d\n", solution.scoreOfParentheses("(()(()))"));
    return 0;
}
*/
