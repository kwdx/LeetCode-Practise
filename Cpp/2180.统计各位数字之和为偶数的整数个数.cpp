/*
 * @lc app=leetcode.cn id=2180 lang=cpp
 *
 * [2180] 统计各位数字之和为偶数的整数个数
 */

#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
    int countEven(int num) {
        int y = num / 10;
        int x = num % 10;
        int ans = y * 5, ySum = 0;
        while (y) {
            ySum += y % 10;
            y /= 10;
        }
        if (ySum % 2 == 0) {
            ans += x / 2 + 1;
        } else {
            ans += (x + 1) / 2;
        }
        return ans - 1;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int num;
    int res;

    /**
     输入：num = 4
     输出：2
     解释：
     只有 2 和 4 满足小于等于 4 且各位数字之和为偶数。
     */
    num = 4;
    res = 2;
    assert(res == Solution().countEven(num));
    
    /**
     输入：num = 30
     输出：14
     解释：
     只有 14 个整数满足小于等于 30 且各位数字之和为偶数，分别是：
     2、4、6、8、11、13、15、17、19、20、22、24、26 和 28 。
     */
    num = 30;
    res = 14;
    assert(res == Solution().countEven(num));

    cout << "OK~" << endl;
    
    return 0;
}
