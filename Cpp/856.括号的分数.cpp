/*
 * @lc app=leetcode.cn id=856 lang=cpp
 *
 * [856] 括号的分数
 */

#include <iostream>
#include <string>
#include <stack>

using namespace std;

// @lc code=start
class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> score;
        stack<int> parentheses;
        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];
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
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    string s;
    int res;
    
    /**
     输入： "()"
     输出： 1
     */
    s = "()";
    res = 1;
    assert(res == Solution().scoreOfParentheses(s));
    
    /**
     输入： "(())"
     输出： 2
     */
    s = "(())";
    res = 2;
    assert(res == Solution().scoreOfParentheses(s));
    
    /**
     输入： "()()"
     输出： 2
     */
    s = "()()";
    res = 2;
    assert(res == Solution().scoreOfParentheses(s));
    
    /**
     输入： "(()(()))"
     输出： 6
     */
    s = "(()(()))";
    res = 6;
    assert(res == Solution().scoreOfParentheses(s));
    
    cout << "OK~" << endl;
    
    return 0;
}
