/*
 * @lc app=leetcode.cn id=410 lang=cpp
 *
 * [410] 分割数组的最大值
 */

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

// @lc code=start
class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int lo = 0;
        int hi = 1;
        for (int num : nums) {
            lo = max(lo, num);
            hi += num;
        }
        while (lo < hi) {
            int mid = lo + ((hi - lo) >> 1);
            int n = split(nums, mid);
            if (n <= m)
                hi = mid;
            else
                lo = mid + 1;
        }
        return lo;
    }
    
    int split(vector<int>& nums, int max) {
        int count = 1;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (sum + nums[i] > max) {
                count++;
                sum = nums[i];
            } else {
                sum += nums[i];
            }
        }
        return count;
    }
    
};
// @lc code=end

int main(int argc, const char * argv[]) {
    vector<int> nums;
    
    /**
     输入：nums = [7,2,5,10,8], m = 2
     输出：18
     解释：
     一共有四种方法将 nums 分割为 2 个子数组。 其中最好的方式是将其分为 [7,2,5] 和 [10,8] 。
     因为此时这两个子数组各自的和的最大值为18，在所有情况中最小。
     */
    nums = {7,2,5,10,8};
    cout << (18 == Solution().splitArray(nums, 2)) << endl;
    
    /**
     输入：nums = [1,2,3,4,5], m = 2
     输出：9
     */
    nums = {1,2,3,4,5};
    cout << (9 == Solution().splitArray(nums, 2)) << endl;

    /**
     输入：nums = [1,4,4], m = 3
     输出：4
     */
    nums = {1,4,4};
    cout << (4 == Solution().splitArray(nums, 3)) << endl;

    return 0;
}
