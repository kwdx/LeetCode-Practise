/*
 * @lc app=leetcode.cn id=414 lang=cpp
 *
 * [414] 第三大的数
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// @lc code=start
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long a = LONG_MIN, b = LONG_MIN, c = LONG_MIN;
        for (long num : nums) {
            if (num > a) {
                c = b;
                b = a;
                a = num;
            } else if (a > num && num > b) {
                c = b;
                b = num;
            } else if (b > num && num > c) {
                c = num;
            }
        }
        return (int)(c == LONG_MIN ? a : c);
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    vector<int> nums;
    int res;
    
    /**
     输入：[3, 2, 1]
     输出：1
     解释：第三大的数是 1 。
     */
    nums = {3,2,1};
    res = 1;
    assert(res == Solution().thirdMax(nums));

    /**
     输入：[1, 2]
     输出：2
     解释：第三大的数不存在, 所以返回最大的数 2 。
     */
    nums = {1,2};
    res = 2;
    assert(res == Solution().thirdMax(nums));

    /**
     输入：[2, 2, 3, 1]
     输出：1
     解释：注意，要求返回第三大的数，是指在所有不同数字中排第三大的数。
     此例中存在两个值为 2 的数，它们都排第二。在所有不同数字中排第三大的数为 1 。
     */
    nums = {2,2,3,1};
    res = 1;
    assert(res == Solution().thirdMax(nums));
    
    /**
     输入：[1,1,2]
     输出：2
     */
    nums = {1,1,2};
    res = 2;
    assert(res == Solution().thirdMax(nums));
    
    cout << "OK~" << endl;
    
    return 0;
}
