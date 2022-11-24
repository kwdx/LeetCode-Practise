/*
 * @lc app=leetcode.cn id=795 lang=cpp
 *
 * [795] 区间子数组个数
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        return count(nums, right) - count(nums, left - 1);
    }
    
    int count(vector<int>& nums, int lower) {
        int res = 0, cur = 0;
        for (auto x : nums) {
            cur = x <= lower ? cur + 1 : 0;
            res += cur;
        }
        return res;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<int> nums;
    int left;
    int right;
    int res;
    
    nums = {445,730,557,930,797,398,9,441,194,706,419,840,164,718,559,783,760,934,771,89,494,253,503,563,6,915,861,361,296,647,730,792,523,24,805,296,600,542,367,974,875,569,56,921,330,348,355,890,940,577,490,289,860,195,350,11,752,796,390,604,116,382,497,924,750,180,466,449,177,45,663,592,328,857,195,166,558,164,895,922,311,714,110,934,373,25,323,239,808,541,419,694,961,397,355,162,728,974,872,709};
    left = 493;
    right = 915;
    res = 543;
    assert(res == Solution().numSubarrayBoundedMax(nums, left, right));
    
    /**
     输入：nums = [2,1,4,3], left = 2, right = 3
     输出：3
     解释：满足条件的三个子数组：[2], [2, 1], [3]
     */
    nums = {2,1,4,3};
    left = 2;
    right = 3;
    res = 3;
    assert(res == Solution().numSubarrayBoundedMax(nums, left, right));
    
    /**
     输入：nums = [2,9,2,5,6], left = 2, right = 8
     输出：7
     */
    nums = {2,9,2,5,6};
    left = 2;
    right = 8;
    res = 7;
    assert(res == Solution().numSubarrayBoundedMax(nums, left, right));

    cout << "OK~" << endl;
    
    return 0;
}
