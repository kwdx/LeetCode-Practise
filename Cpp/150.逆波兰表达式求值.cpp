/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */

#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

// @lc code=start
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
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
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<string> tokens;
    int res;
    
    /**
     输入：tokens = ["2","1","+","3","*"]
     输出：9
     解释：该算式转化为常见的中缀算术表达式为：((2 + 1) * 3) = 9
     */
    tokens = {"2","1","+","3","*"};
    res = 9;
    assert(res == Solution().evalRPN(tokens));
    
    /**
     输入：tokens = ["4","13","5","/","+"]
     输出：6
     解释：该算式转化为常见的中缀算术表达式为：(4 + (13 / 5)) = 6
     */
    tokens = {"4","13","5","/","+"};
    res = 6;
    assert(res == Solution().evalRPN(tokens));
    
    /**
     输入：tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
     输出：22
     解释：
     该算式转化为常见的中缀算术表达式为：
       ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
     = ((10 * (6 / (12 * -11))) + 17) + 5
     = ((10 * (6 / -132)) + 17) + 5
     = ((10 * 0) + 17) + 5
     = (0 + 17) + 5
     = 17 + 5
     = 22
     */
    tokens = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    res = 22;
    assert(res == Solution().evalRPN(tokens));

    cout << "OK~" << endl;
    
    return 0;
}
