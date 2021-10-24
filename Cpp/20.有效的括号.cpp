/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

#include <iostream>
#include <string>
#include <stack>
#include <map>

using namespace std;

// @lc code=start
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
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    string s;
    bool res;
    
    /**
     输入：s = "()"
     输出：true
     */
    s = "()";
    res = true;
    assert(res == Solution().isValid(s));
    
    /**
     输入：s = "()[]{}"
     输出：true
     */
    s = "()[]{}";
    res = true;
    assert(res == Solution().isValid(s));
    
    /**
     输入：s = "(]"
     输出：false
     */
    s = "(]";
    res = false;
    assert(res == Solution().isValid(s));
    
    /**
     输入：s = "([)]"
     输出：false
     */
    s = "([)]";
    res = false;
    assert(res == Solution().isValid(s));
    
    /**
     输入：s = "{[]}"
     输出：true
     */
    s = "{[]}";
    res = true;
    assert(res == Solution().isValid(s));
    
    cout << "OK~" << endl;
    
    return 0;
}
