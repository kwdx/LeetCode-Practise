/*
 * @lc app=leetcode.cn id=1106 lang=cpp
 *
 * [1106] 解析布尔表达式
 */

#include <iostream>
#include <string>
#include <stack>

using namespace std;

// @lc code=start
class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> ops, nums;
        for (char c : expression) {
            if (c == ',') continue;
            else if (c == '!' || c == '&' || c == '|') ops.push(c);
            else if (c == 't' || c == 'f') nums.push(c);
            else if (c == '(') nums.push('-');
            else if (c == ')') {
                char op = ops.top();
                ops.pop();
                char cur = ' ';
                while (!nums.empty() && nums.top() != '-') {
                    char top = nums.top();
                    nums.pop();
                    cur = cur == ' ' ? top : calc(cur, top, op);
                }
                if (op == '!') cur = cur == 't' ? 'f' : 't';
                nums.pop();
                nums.push(cur);
            }
        }
        return nums.top() == 't';
    }
    
    char calc(char a, char b, char op) {
        bool x = a == 't';
        bool y = b == 't';
        bool ans = op == '|' ? (x | y) : (x & y);
        return ans ? 't' : 'f';
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    string expression;
    bool res;
    
    /**
     输入：expression = "!(f)"
     输出：true
     */
    expression = "!(f)";
    res = true;
    assert(res == Solution().parseBoolExpr(expression));
    
    /**
     输入：expression = "|(f,t)"
     输出：true
     */
    expression = "|(f,t)";
    res = true;
    assert(res == Solution().parseBoolExpr(expression));
    
    /**
     输入：expression = "&(t,f)"
     输出：false
     */
    expression = "&(t,f)";
    res = false;
    assert(res == Solution().parseBoolExpr(expression));
    
    /**
     输入：expression = "|(&(t,f,t),!(t))"
     输出：false
     */
    expression = "|(&(t,f,t),!(t))";
    res = false;
    assert(res == Solution().parseBoolExpr(expression));
    
    cout << "OK~" << endl;
    
    return 0;
}
