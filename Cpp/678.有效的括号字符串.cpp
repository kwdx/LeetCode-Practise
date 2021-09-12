/*
 * @lc app=leetcode.cn id=678 lang=cpp
 *
 * [678] 有效的括号字符串
 */

#include <iostream>
#include <string>
#include <stack>

using namespace std;

// @lc code=start
class Solution {
public:
    bool checkValidString(string s) {
        stack<int> leftSt;
        stack<int> asteriskSt;
        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];
            switch (c) {
                case '(':
                    leftSt.push(i);
                    break;
                case ')':
                    if (!leftSt.empty()) {
                        leftSt.pop();
                        break;
                    } else if (!asteriskSt.empty()) {
                        asteriskSt.pop();
                        break;
                    } else {
                        return false;
                    }
                case '*':
                    asteriskSt.push(i);
                    break;
                default:
                    break;
            }
        }
        if (leftSt.size() > asteriskSt.size()) {
            return false;
        }
        while (!leftSt.empty()) {
            if (leftSt.top() > asteriskSt.top()) {
                return false;
            }
            leftSt.pop();
            asteriskSt.pop();
        }
        return true;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    string s;
    bool res;
    
    /**
     输入: "()"
     输出: True
     */
    s = "()";
    res = true;
    assert(res == Solution().checkValidString(s));
    
    /**
     输入: "(*)"
     输出: True
     */
    s = "(*)";
    res = true;
    assert(res == Solution().checkValidString(s));
    
    /**
     输入: "(*))"
     输出: True
     */
    s = "(*))";
    res = true;
    assert(res == Solution().checkValidString(s));
        
    /**
     输入: "(((((*(()((((*((**(((()()*)()()()*((((**)())*)*)))))))(())(()))())((*()()(((()((()*(())*(()**)()(())"
     输出: false
     */
    s = "(((((*(()((((*((**(((()()*)()()()*((((**)())*)*)))))))(())(()))())((*()()(((()((()*(())*(()**)()(())";
    res = false;
    assert(res == Solution().checkValidString(s));
    
    cout << "OK~" << endl;
    
    return 0;
}
