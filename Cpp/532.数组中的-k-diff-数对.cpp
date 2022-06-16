/*
 * @lc app=leetcode.cn id=532 lang=cpp
 *
 * [532] 数组中的 k-diff 数对
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n = (int)nums.size();
        int ans = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0, j = 0; i < n - 1 && j < n; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            while (j <= i) {
                ++j;
            }
            while (j < n && (nums[j] < nums[i] + k)) {
                ++j;
            }
            if (j < n && nums[j] == nums[i] + k) {
                ++ans;
            }
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<int> nums;
    int k;
    int res;
    
    /**
     输入：nums = [3, 1, 4, 1, 5], k = 2
     输出：2
     解释：数组中有两个 2-diff 数对, (1, 3) 和 (3, 5)。
     尽管数组中有两个1，但我们只应返回不同的数对的数量。
     */
    nums = {3, 1, 4, 1, 5};
    k = 2;
    res = 2;
    assert(res == Solution().findPairs(nums, k));
    
    /**
     输入：nums = [1, 2, 3, 4, 5], k = 1
     输出：4
     解释：数组中有四个 1-diff 数对, (1, 2), (2, 3), (3, 4) 和 (4, 5)。
     */
    nums = {1, 2, 3, 4, 5};
    k = 1;
    res = 4;
    assert(res == Solution().findPairs(nums, k));
    
    /**
     输入：nums = [1, 3, 1, 5, 4], k = 0
     输出：1
     解释：数组中只有一个 0-diff 数对，(1, 1)。
     */
    nums = {1, 3, 1, 5, 4};
    k = 0;
    res = 1;
    assert(res == Solution().findPairs(nums, k));
    
    cout << "OK~" << endl;
    
    return 0;
}
