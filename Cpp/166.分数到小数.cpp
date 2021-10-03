/*
 * @lc app=leetcode.cn id=166 lang=cpp
 *
 * [166] 分数到小数
 */

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

// @lc code=start
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if ((int64_t)numerator % denominator == 0) {
            return to_string((int64_t)numerator / denominator);
        }
        
        int64_t up = abs((int64_t)numerator);
        int64_t down = abs((int64_t)denominator);
        
        string ans(((numerator < 0) ^ (denominator < 0) ? "-" : "") + to_string(up / down) + '.');
        
        unordered_map<int64_t, int> index;
        
        for (int i = (int)ans.size(); up = up % down * 10; ++i) {
            if (index.count(up)) {
                ans.insert(begin(ans) + index[up], '(');
                ans.push_back(')');
                break;
            }
            index[up] = i;
            ans.push_back('0' + up / down);
        }
        
        return ans;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    int numerator, denominator;
    string res;
    
    /**
     输入：numerator = 1, denominator = 2
     输出："0.5"
     */
    numerator = 1;
    denominator = 2;
    res = "0.5";
    assert(res == Solution().fractionToDecimal(numerator, denominator));
    
    /**
     输入：numerator = 2, denominator = 1
     输出："2"
     */
    numerator = 2;
    denominator = 1;
    res = "2";
    assert(res == Solution().fractionToDecimal(numerator, denominator));
    
    /**
     输入：numerator = 2, denominator = 3
     输出："0.(6)"
     */
    numerator = 2;
    denominator = 3;
    res = "0.(6)";
    assert(res == Solution().fractionToDecimal(numerator, denominator));
    
    /**
     输入：numerator = 4, denominator = 333
     输出："0.(012)"
     */
    numerator = 4;
    denominator = 333;
    res = "0.(012)";
    assert(res == Solution().fractionToDecimal(numerator, denominator));
    
    /**
     输入：numerator = 1, denominator = 5
     输出："0.2"
     */
    numerator = 1;
    denominator = 5;
    res = "0.2";
    assert(res == Solution().fractionToDecimal(numerator, denominator));
    
    cout << "OK~" << endl;
    
    return 0;
}
