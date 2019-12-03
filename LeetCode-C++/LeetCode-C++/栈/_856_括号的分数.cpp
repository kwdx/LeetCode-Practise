//
//  _856_括号的分数.cpp
//  LeetCode-C++
//
//  Created by warden on 2019/12/3.
//  Copyright © 2019 warden. All rights reserved.
//

#include "_856_括号的分数.hpp"
#include <stack>

int _856_括号的分数::scoreOfParentheses(string S) {
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
