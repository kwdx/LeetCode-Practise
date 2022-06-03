/*
 * @lc app=leetcode.cn id=829 lang=cpp
 *
 * [829] 连续整数求和
 */

#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
    int consecutiveNumbersSum(int n) {
        int ans = 0;
        n <<= 1;
        for (int i = 0; i * i < n; ++i) {
            if (n % i != 0) continue;
            if ((n / i - (i - 1)) % 2 == 0) ++ans;
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int n;
    int res;
    
    /**
     输入: n = 5
     输出: 2
     解释: 5 = 2 + 3，共有两组连续整数([5],[2,3])求和后为 5。
     */
    n = 5;
    res = 2;
    assert(res == Solution().consecutiveNumbersSum(n));
    
    /**
     输入: n = 9
     输出: 3
     解释: 9 = 4 + 5 = 2 + 3 + 4
     */
    n = 9;
    res = 3;
    assert(res == Solution().consecutiveNumbersSum(n));
    
    /**
     输入: n = 15
     输出: 4
     解释: 15 = 8 + 7 = 4 + 5 + 6 = 1 + 2 + 3 + 4 + 5
     */
    n = 15;
    res = 4;
    assert(res == Solution().consecutiveNumbersSum(n));

    cout << "OK~" << endl;
    
    return 0;
}
