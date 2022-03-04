/*
 * @lc app=leetcode.cn id=258 lang=cpp
 *
 * [258] 各位相加
 */

#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
    int addDigits(int num) {
//        int ans = num;
//        int tmp;
//        while (ans > 9) {
//            tmp = 0;
//            while (ans > 0) {
//                tmp += ans % 10;
//                ans /= 10;
//            }
//            ans = tmp;
//        }
//        return ans;
        
        return (num - 1) % 9 + 1;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int num;
    int res;
    
    /**
     输入: num = 38
     输出: 2
     解释: 各位相加的过程为：
     38 --> 3 + 8 --> 11
     11 --> 1 + 1 --> 2
     由于 2 是一位数，所以返回 2。
     */
    num = 38;
    res = 2;
    assert(res == Solution().addDigits(num));
    
    /**
     输入: num = 0
     输出: 0
     */
    num = 0;
    res = 0;
    assert(res == Solution().addDigits(num));

    cout << "OK~" << endl;
    
    return 0;
}
