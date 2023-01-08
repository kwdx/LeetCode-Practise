/*
 * @lc app=leetcode.cn id=1658 lang=cpp
 *
 * [1658] 将 x 减到 0 的最小操作数
 */

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

// @lc code=start
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = (int)nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        
        if (sum < x) {
            return -1;
        }
        
        int right = 0;
        int lSum = 0, rSum = sum;
        int ans = n + 1;
        
        for (int left = -1; left < n; ++left) {
            if (left != -1) {
                lSum += nums[left];
            }
            while (right < n && lSum + rSum > x) {
                rSum -= nums[right];
                ++right;
            }
            if (lSum + rSum == x) {
                ans = min(ans, (left + 1) + (n - right));
            }
        }

        return ans > n ? -1 : ans;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<int> nums;
    int x;
    int res;
    
    /**
     输入：nums = [1,1,4,2,3], x = 5
     输出：2
     解释：最佳解决方案是移除后两个元素，将 x 减到 0 。
     */
    nums = {1,1,4,2,3};
    x = 5;
    res = 2;
    assert(res == Solution().minOperations(nums, x));
    
    /**
     输入：nums = [5,6,7,8,9], x = 4
     输出：-1
     */
    nums = {5,6,7,8,9};
    x = 4;
    res = -1;
    assert(res == Solution().minOperations(nums, x));
    
    /**
     输入：nums = [3,2,20,1,1,3], x = 10
     输出：5
     解释：最佳解决方案是移除后三个元素和前两个元素（总共 5 次操作），将 x 减到 0 。
     */
    nums = {3,2,20,1,1,3};
    x = 10;
    res = 5;
    assert(res == Solution().minOperations(nums, x));
    
    cout << "OK~" << endl;
    
    return 0;
}
