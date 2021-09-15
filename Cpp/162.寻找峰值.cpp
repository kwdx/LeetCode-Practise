/*
 * @lc app=leetcode.cn id=162 lang=cpp
 *
 * [162] 寻找峰值
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = (int)nums.size();
        int left = 0, right = n - 1;

        auto get = [&](int i) -> pair<int, int> {
            if (i == -1 || i == n) 
                return {0, 0};
            return {1, nums[i]};
        };

        while (left <= right) {
            int mid = left + ((right - left) >> 1);
            if (get(mid - 1) < get(mid) && get(mid) > get(mid + 1))
                return mid;
            if (get(mid) < get(mid + 1))
                left = mid + 1;
            else
                right = mid - 1;
        }

        return -1;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    vector<int> nums;
    int res;
    
    /**
     输入：nums = [1,2,3,1]
     输出：2
     解释：3 是峰值元素，你的函数应该返回其索引 2。
     */
    nums = {1,2,3,1};
    res = 2;
    assert(res == Solution().findPeakElement(nums));
    
    /**
     输入：nums = [1,2,1,3,5,6,4]
     输出：1 或 5
     解释：你的函数可以返回索引 1，其峰值元素为 2；
          或者返回索引 5， 其峰值元素为 6。
     */
    nums = {1,2,1,3,5,6,4};
    res = 1;
    assert(res == Solution().findPeakElement(nums) ||
           5 == Solution().findPeakElement(nums));
    
    cout << "OK~" << endl;
    
    return 0;
}
