/*
 * @lc app=leetcode.cn id=537 lang=cpp
 *
 * [537] 复数乘法
 */

#include <iostream>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        auto idx1 = num1.find("+");
        int a = atoi(num1.substr(0, idx1).c_str());
        int b = atoi(num1.substr(idx1 + 1, num1.size() - idx1 - 2).c_str());
        auto idx2 = num2.find("+");
        int c = atoi(num2.substr(0, idx2).c_str());
        int d = atoi(num2.substr(idx2 + 1, num2.size() - idx2 - 2).c_str());
        return to_string(a * c - b * d) + "+" + to_string(a * d + b * c) + "i";
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    string num1;
    string num2;
    string res;
    
    /**
     输入：num1 = "1+1i", num2 = "1+1i"
     输出："0+2i"
     解释：(1 + i) * (1 + i) = 1 + i2 + 2 * i = 2i ，你需要将它转换为 0+2i 的形式。
     */
    num1 = "1+1i";
    num2 = "1+1i";
    res = "0+2i";
    assert(res == Solution().complexNumberMultiply(num1, num2));

    /**
     输入：num1 = "1+-1i", num2 = "1+-1i"
     输出："0+-2i"
     解释：(1 - i) * (1 - i) = 1 + i2 - 2 * i = -2i ，你需要将它转换为 0+-2i 的形式。
     */
    num1 = "1+-1i";
    num2 = "1+-1i";
    res = "0+-2i";
    assert(res == Solution().complexNumberMultiply(num1, num2));
    
    /**
     输入：num1 = "1+-1i", num2 = "1+-1i"
     输出："0+-2i"
     解释：(1 - i) * (1 - i) = 1 + i2 - 2 * i = -2i ，你需要将它转换为 0+-2i 的形式。
     */
    num1 = "78+-76i";
    num2 = "-86+72i";
    res = "-1236+12152i";
    assert(res == Solution().complexNumberMultiply(num1, num2));

    cout << "OK~" << endl;
    
    return 0;
}
