/*
 * @lc app=leetcode.cn id=282 lang=cpp
 *
 * [282] 给表达式添加运算符
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<string> addOperators(string num, int target) {
        int n = (int)num.length();
        vector<string> ans;
        
        function<void(string&, int, long, long)> backtrack = [&](string &expr, int i, long res, long mul) {
            if (i == n) {
                if (res == target) {
                    ans.emplace_back(expr);
                }
                return;
            }
            int signIndex = (int)expr.size();
            if (i > 0) {
                expr.push_back(0);
            }
            long val = 0;
            // 枚举截取的数字长度（取多少位），注意数字可以是单个 0 但不能有前导 0
            for (int j = i; j < n && (j == i || num[i] != '0'); ++j) {
                val = val * 10 + (num[j] - '0');
                expr.push_back(num[j]);
                if (i == 0) {
                    backtrack(expr, j + 1, val, val);
                } else {
                    expr[signIndex] = '+';
                    backtrack(expr, j + 1, res + val, val);
                    expr[signIndex] = '-';
                    backtrack(expr, j + 1, res - val, -val);
                    expr[signIndex] = '*';
                    backtrack(expr, j + 1, res - mul + mul * val, mul * val);
                }
            }
            expr.resize(signIndex);
        };

        string expr;
        backtrack(expr, 0, 0, 0);
        return ans;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    string num;
    int target;
    vector<string> res;
    
    /**
     输入: num = "123", target = 6
     输出: ["1+2+3", "1*2*3"]
     */
    num = "123";
    target = 6;
    res = {"1+2+3", "1*2*3"};
    assert(res == Solution().addOperators(num, target));
    
    /**
     输入: num = "232", target = 8
     输出: ["2*3+2", "2+3*2"]
     */
    num = "232";
    target = 8;
    res = {"2+3*2", "2*3+2"};
    assert(res == Solution().addOperators(num, target));
    
    /**
     输入: num = "105", target = 5
     输出: ["1*0+5","10-5"]
     */
    num = "105";
    target = 5;
    res = {"1*0+5","10-5"};
    assert(res == Solution().addOperators(num, target));
    
    /**
     输入: num = "00", target = 0
     输出: ["0+0", "0-0", "0*0"]
     */
    num = "00";
    target = 0;
    res = {"0+0", "0-0", "0*0"};
    assert(res == Solution().addOperators(num, target));
    
    /**
     输入: num = "3456237490", target = 9191
     输出: []
     */
    num = "3456237490";
    target = 9191;
    res = {};
    assert(res == Solution().addOperators(num, target));
    
    cout << "OK~" << endl;
    
    return 0;
}
