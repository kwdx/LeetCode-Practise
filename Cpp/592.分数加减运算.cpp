/*
 * @lc app=leetcode.cn id=592 lang=cpp
 *
 * [592] 分数加减运算
 */

#include <iostream>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    string fractionAddition(string expression) {
        long long denominator = 0;  // 分子
        long long numerator = 1;    // 分母
        int index = 0, n = (int)expression.size();
        while (index < n) {
            // 读取分子
            long long denominator1 = 0, sign = 1;
            if (expression[index] == '-' || expression[index] == '+') {
                sign = expression[index] == '-' ? -1 : 1;
                ++index;
            }
            while (index < n && isdigit(expression[index])) {
                denominator1 = denominator1 *10 + (expression[index] - '0');
                ++index;
            }
            denominator1 = sign * denominator1;
            ++index;
            
            // 读取分母
            long long numerator1 = 0;
            while (index < n && isdigit(expression[index])) {
                numerator1 = numerator1 * 10 + expression[index] - '0';
                ++index;
            }
            
            denominator = denominator * numerator1 + denominator1 * numerator;
            numerator *= numerator1;
        }
        if (denominator == 0) {
            return "0/1";
        }
        long long g = gcd(abs(denominator), numerator); // 获取最大公约数
        return to_string(denominator / g) + "/" + to_string(numerator / g);
    }
    
    int gcd(int a, int b) {
        int r = a % b;
        return r == 0 ? b : gcd(b, r);
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    string expression;
    string res;
    
    /**
     输入: expression = "-1/2+1/2"
     输出: "0/1"
     */
    expression = "-1/2+1/2";
    res = "0/1";
    assert(res == Solution().fractionAddition(expression));
    
    /**
     输入: expression = "-1/2+1/2+1/3"
     输出: "1/3"
     */
    expression = "-1/2+1/2+1/3";
    res = "1/3";
    assert(res == Solution().fractionAddition(expression));
    
    /**
     输入: expression = "1/3-1/2"
     输出: "-1/6"
     */
    expression = "1/3-1/2";
    res = "-1/6";
    assert(res == Solution().fractionAddition(expression));
    
    cout << "OK~" << endl;
    
    return 0;
}
