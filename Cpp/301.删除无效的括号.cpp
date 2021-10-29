/*
 * @lc app=leetcode.cn id=301 lang=cpp
 *
 * [301] 删除无效的括号
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        int lRemove = 0, rRemove = 0;
        
        for (auto c : s) {
            if (c == '(') {
                ++lRemove;
            } else if (c == ')') {
                if (lRemove == 0) {
                    ++rRemove;
                } else {
                    --lRemove;
                }
            }
        }
        
        helper(s, 0, lRemove, rRemove);
        
        return ans;
    }
private:
    vector<string> ans;
    
    void helper(string str, int start, int lRemove, int rRemove) {
        if (lRemove == 0 && rRemove == 0) {
            if (isValid(str)) {
                ans.push_back(str);
            }
            return;
        }
        for (int i = start; i < str.size(); i++) {
            if (i != start && str[i] == str[i - 1]) {
                continue;
            }
            // 剩余字符串长度不够删除
            if (lRemove + rRemove > str.size() - i) {
                return;
            }
            if (lRemove > 0 && str[i] == '(') {
                helper(str.substr(0, i) + str.substr(i + 1), i, lRemove - 1, rRemove);
            }
            if (rRemove > 0 && str[i] == ')') {
                helper(str.substr(0, i) + str.substr(i + 1), i, lRemove, rRemove - 1);
            }
        }
    }
    
    bool isValid(string str) {
        int cnt = 0;
        
        for (char & c : str) {
            if (c == '(') {
                ++cnt;
            } else if (c == ')') {
                --cnt;
                if (cnt < 0) {
                    return false;
                }
            }
        }
        return cnt == 0;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    string s;
    vector<string> res;
    
    /**
     输入：s = "()())()"
     输出：["(())()","()()()"]
     */
    s = "()())()";
    res = {"(())()","()()()"};
    assert(res == Solution().removeInvalidParentheses(s));

    /**
     输入：s = "(a)())()"
     输出：["(a())()","(a)()()"]
     */
    s = "(a)())()";
    res = {"(a())()","(a)()()"};
    assert(res == Solution().removeInvalidParentheses(s));

    /**
     输入：s = ")("
     输出：[""]
     */
    s = ")(";
    res = {""};
    assert(res == Solution().removeInvalidParentheses(s));
    
    /**
     输入：s = "(r(()()("
     输出：["r()()","r(())","(r)()","(r())"]
     */
    s = "(r(()()(";
    res = {"r()()","r(())","(r)()","(r())"};
    assert(res == Solution().removeInvalidParentheses(s));

    cout << "OK~" << endl;

    return 0;
}
