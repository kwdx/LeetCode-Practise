/*
 * @lc app=leetcode.cn id=367 lang=cpp
 *
 * [367] 有效的完全平方数
 */

#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
    bool isPerfectSquare(int num) {
        int left = 0, right = num;
        while (left <= right) {
            int mid = left + ((right - left) >> 1);
            long square = (long)mid * mid;
            if (square == num) {
                return true;
            } else if (square < num) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return false;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int num;
    bool res;
    
    /**
     输入：num = 16
     输出：true
     */
    num = 16;
    res = true;
    assert(res == Solution().isPerfectSquare(num));
    
    /**
     输入：num = 14
     输出：false
     */
    num = 14;
    res = false;
    assert(res == Solution().isPerfectSquare(num));
    
    /**
     输入：num = 2000105819
     输出：false
     */
    num = 2000105819;
    res = false;
    assert(res == Solution().isPerfectSquare(num));

    cout << "OK~" << endl;

    return 0;
}
