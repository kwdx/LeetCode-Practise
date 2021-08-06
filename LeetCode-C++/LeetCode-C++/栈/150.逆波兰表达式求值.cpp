//
//  150.逆波兰表达式求值.cpp
//  LeetCode-C++
//
//  Created by warden on 2019/11/25.
//  Copyright © 2019 warden. All rights reserved.
//
// https://leetcode-cn.com/problems/evaluate-reverse-polish-notation/

#include <stdio.h>
#include <vector>
#include <string>
#include <stack>
#include <set>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> nums;
        for (auto token : tokens) {
            if (token.size() == 1 && (token[0] < '0' || token[0] > '9')) {
                int right = nums.top();
                nums.pop();
                int left = nums.top();
                nums.pop();
                switch (token[0]) {
                    case '+':
                        nums.push(left + right);
                        break;
                    case '-':
                        nums.push(left - right);
                        break;
                    case '*':
                        nums.push(left * right);
                        break;
                    case '/':
                        nums.push(left / right);
                        break;
                    default:
                        break;
                }
            } else {
                nums.push(stoi(token));
            }
        }
        return nums.top();
    }
};

/**
 示例 1：

 输入: ["2", "1", "+", "3", "*"]
 输出: 9
 解释: ((2 + 1) * 3) = 9
 示例 2：

 输入: ["4", "13", "5", "/", "+"]
 输出: 6
 解释: (4 + (13 / 5)) = 6
 示例 3：

 输入: ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]
 输出: 22
 */
/**
int main(int argc, const char * argv[]) {
//    vector<string> tokens = {"2", "1", "+", "3", "*"};
//    vector<string> tokens = {"4", "13", "5", "/", "+"};
    vector<string> tokens = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    Solution solution = Solution();
    
    printf("%d\n", solution.evalRPN(tokens));
    
    return 0;
}
*/
