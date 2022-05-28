/*
 * @lc app=leetcode.cn id=1021 lang=cpp
 *
 * [1021] 删除最外层的括号
 */

#include <iostream>
#include <string>
#include <stack>

using namespace std;

// @lc code=start
class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans;
        stack<char> st;
        for (auto c : s) {
            if (c == ')') {
                st.pop();
            }
            if (!st.empty()) {
                ans.push_back(c);
            }
            if (c == '(') {
                st.emplace(c);
            }
        }
        return ans;
    }
};
// @lc code=end


int main(int argc, const char * argv[]) {
    // insert code here...
    
    string s;
    string res;
    
    /**
     输入：s = "(()())(())"
     输出："()()()"
     解释：
     输入字符串为 "(()())(())"，原语化分解得到 "(()())" + "(())"，
     删除每个部分中的最外层括号后得到 "()()" + "()" = "()()()"。
     */
    s = "(()())(())";
    res = "()()()";
    assert(res == Solution().removeOuterParentheses(s));
    
    /**
     输入：s = "(()())(())(()(()))"
     输出："()()()()(())"
     解释：
     输入字符串为 "(()())(())(()(()))"，原语化分解得到 "(()())" + "(())" + "(()(()))"，
     删除每个部分中的最外层括号后得到 "()()" + "()" + "()(())" = "()()()()(())"。
     */
    s = "(()())(())(()(()))";
    res = "()()()()(())";
    assert(res == Solution().removeOuterParentheses(s));
    
    /**
     输入：s = "()()"
     输出：""
     解释：
     输入字符串为 "()()"，原语化分解得到 "()" + "()"，
     删除每个部分中的最外层括号后得到 "" + "" = ""。
     */
    s = "()()";
    res = "";
    assert(res == Solution().removeOuterParentheses(s));

    cout << "OK~" << endl;

    return 0;
}
