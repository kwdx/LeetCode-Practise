//
//  224.基本计算器.cpp
//  LeetCode-C++
//
//  Created by warden on 2019/12/3.
//  Copyright © 2019 warden. All rights reserved.
//
// https://leetcode-cn.com/problems/basic-calculator/

#include <stdio.h>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        int score = 0;
        int num = 0;
        bool opFlag = true;
        stack<bool> opStack;
        opStack.push(opFlag);
        for (char ch:s) {
            switch (ch) {
                case '+':
                case '-':
                {
                    score += opFlag ? num : -num;
                    opFlag = opStack.top() == (ch == '+');
                    num = 0;
                }
                    break;
                case '(':
                    opStack.push(opFlag);
                    break;
                case ')':
                    opStack.pop();
                    break;
                case ' ':
                    break;
                default:
                    num = num * 10 + (int)(ch - '0');
                    break;
            }
        }
        return score + ((opStack.top() == opFlag) ? num : -num);
    }
    
    int calculate1(string s) {
        stack<int> score;
        stack<int> parentheses;
        int num = 0;
        bool opFlag = true;
        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];
            if (ch >= '0' && ch <= '9') {
                num = num * 10 + (int)(ch - '0');
            } else {
                if (num != 0) {
                    if (opFlag) {
                        score.push(num);
                    } else {
                        score.push(-num);
                    }
                    num = 0;
                    opFlag = true;
                }
                switch (ch) {
                    case '+':
                        opFlag = true;
                        break;
                    case '-':
                        opFlag = false;
                        break;
                    case '(':
                    {
                        score.push(opFlag ? 0 : -1);
                        parentheses.push((int)score.size());
                        opFlag = true;
                    }
                        break;
                    case ')':
                    {
                        int leftPos = parentheses.top();
                        parentheses.pop();
                        int val = 0;
                        while (score.size() > leftPos) {
                            val += score.top();
                            score.pop();
                        }
                        int numflag = score.top();
                        score.pop();
                        if (numflag == 0) {
                            score.push(val);
                        } else {
                            score.push(-val);
                        }
                    }
                        break;
                    default:
                        break;
                }
            }
        }
        int val = opFlag ? num : -num;
        while (!score.empty()) {
            val += score.top();
            score.pop();
        }
        return val;
    }
};

/**
 输入: "1 + 1"
 输出: 2

 输入: " 2-1 + 2 "
 输出: 3

 输入: "(1+(4+5+2)-3)+(6+8)"
 输出: 23

 输入: "2-(5-6)"
 输出: 3
*/
/**
int main(int argc, const char * argv[]) {
    Solution solution = Solution();

    printf("%d\n", solution.calculate("1 + 1"));
    printf("%d\n", solution.calculate(" 2-1 + 2 "));
    printf("%d\n", solution.calculate("(1+(4+5+2)-3+(6+8)"));
    printf("%d\n", solution.calculate("2-(5-6)"));
    
    return 0;
}
*/
