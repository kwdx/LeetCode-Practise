//
//  _150_逆波兰表达式求值.cpp
//  LeetCode-C++
//
//  Created by warden on 2019/11/25.
//  Copyright © 2019 warden. All rights reserved.
//

#include "_150_逆波兰表达式求值.hpp"
#include <stack>
#include <set>

int _150_逆波兰表达式求值::evalRPN(vector<string>& tokens) {
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
