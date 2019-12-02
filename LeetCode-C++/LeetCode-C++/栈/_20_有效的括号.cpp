//
//  _20_有效的括号.cpp
//  LeetCode-C++
//
//  Created by warden on 2019/12/2.
//  Copyright © 2019 warden. All rights reserved.
//

#include "_20_有效的括号.hpp"
#include <stack>
#include <map>

using namespace std;

bool _20_有效的括号::isValid(string s) {
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
