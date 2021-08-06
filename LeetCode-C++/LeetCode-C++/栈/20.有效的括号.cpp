//
//  20.有效的括号.cpp
//  LeetCode-C++
//
//  Created by warden on 2019/12/2.
//  Copyright © 2019 warden. All rights reserved.
//
// https://leetcode-cn.com/problems/valid-parentheses/

#include <stdio.h>
#include <string>
#include <stack>
#include <map>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];
            switch (ch) {
                case '(':
                case '[':
                case '{':
                    st.push(ch);
                    break;
                case ')':
                    if (!st.empty() && st.top() == '(') {
                        st.pop();
                    } else {
                        return false;
                    }
                    break;
                case ']':
                    if (!st.empty() && st.top() == '[') {
                        st.pop();
                    } else {
                        return false;
                    }
                    break;
                case '}':
                    if (!st.empty() && st.top() == '{') {
                        st.pop();
                    } else {
                        return false;
                    }
                    break;
                default:
                    break;
            }
        }
        
        return st.empty();
    }
};

/**
 输入: "()"
 输出: true

 输入: "()[]{}"
 输出: true

 输入: "(]"
 输出: false

 输入: "([)]"
 输出: false

 输入: "{[]}"
 输出: true
*/
/**
int main(int argc, const char * argv[]) {
    Solution solution = Solution();
    printf("%d\n", solution.isValid("{[]}"));
    printf("%d\n", solution.isValid("()[]{}"));
    printf("%d\n", solution.isValid("(]"));
    printf("%d\n", solution.isValid("([)]"));
    printf("%d\n", solution.isValid("{[]}"));
    return 0;
}
*/
