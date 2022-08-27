/*
 * @lc app=leetcode.cn id=640 lang=cpp
 *
 * [640] 求解方程
 */

#include <iostream>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    string solveEquation(string equation) {
        int n = (int)equation.size();
        int factor = 0, val = 0;
        int index = 0, sign1 = 1;   // 等式左边默认系数为正
        while (index < n) {
            if (equation[index]  == '=') {
                sign1 = -1; // 等式右边默认系数为负
                index++;
                continue;
            }
            
            int sign2 = sign1, number = 0;
            bool valid = false; // 记录 number 是否有效
            if (equation[index] == '-' || equation[index] == '+') { // 去掉前面的符号
                sign2 = (equation[index] == '-') ? -sign1 : sign1;
                index++;
            }
            while (index < n && isdigit(equation[index])) {
                number = number * 10 + (equation[index] - '0');
                index++;
                valid = true;
            }
            
            if (index < n && equation[index] == 'x') { // 变量
                factor += valid ? sign2 * number : sign2;
                index++;
            } else { // 数值
                val += sign2 * number;
            }
        }
        if (factor == 0) {
            return val == 0 ? "Infinite solutions" : "No solution";
        }
        if (val % factor != 0) {
            return "No solution";
        }
        return string("x=") + to_string(-val / factor);
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    string equation;
    string res;
    
    /**
     输入: equation = "x+5-3+x=6+x-2"
     输出: "x=2"
     */
    equation = "x+5-3+x=6+x-2";
    res = "x=2";
    assert(res == Solution().solveEquation(equation));
    
    /**
     输入: equation = "x=x"
     输出: "Infinite solutions"
     */
    equation = "x+5-3+x=6+x-2";
    res = "x=2";
    assert(res == Solution().solveEquation(equation));

    /**
     输入: equation = "2x=x"
     输出: "x=0"
     */
    equation = "2x=x";
    res = "x=0";
    assert(res == Solution().solveEquation(equation));

    cout << "OK~" << endl;
    
    return 0;
}
