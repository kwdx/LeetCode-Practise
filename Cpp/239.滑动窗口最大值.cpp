/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> window;
        for (int i = 0; i < nums.size(); i++) {
            while (!window.empty() && nums[window.back()] <= nums[i]) {
                window.pop_back();
            }
            window.push_back(i);
            if (i < k - 1) continue;
            
            if (i - k == window.front()) window.pop_front();
            
            res.push_back(nums[window.front()]);
        }
        
        return res;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    vector<int> nums;
    vector<int> res;

    /**
     输入：nums = [1,3,-1,-3,5,3,6,7], k = 3
     输出：[3,3,5,5,6,7]
     解释：
     滑动窗口的位置                最大值
     ---------------               -----
     [1  3  -1] -3  5  3  6  7       3
      1 [3  -1  -3] 5  3  6  7       3
      1  3 [-1  -3  5] 3  6  7       5
      1  3  -1 [-3  5  3] 6  7       5
      1  3  -1  -3 [5  3  6] 7       6
      1  3  -1  -3  5 [3  6  7]      7
     */
    nums = {1,3,-1,-3,5,3,6,7};
    res = {3,3,5,5,6,7};
    cout << (res == Solution().maxSlidingWindow(nums, 3)) << endl;

    /**
     输入：nums = [1], k = 1
     输出：[1]
     */
    nums = {1};
    res = {1};
    cout << (res == Solution().maxSlidingWindow(nums, 1)) << endl;

    /**
     输入：nums = [1,-1], k = 1
     输出：[1,-1]
     */
    nums = {1,-1};
    res = {1,-1};
    cout << (res == Solution().maxSlidingWindow(nums, 1)) << endl;

    /**
     输入：nums = [9,11], k = 2
     输出：[11]
     */
    nums = {9,11};
    res = {11};
    cout << (res == Solution().maxSlidingWindow(nums, 2)) << endl;

    /**
     输入：nums = [4,-2], k = 2
     输出：[4]
     */
    nums = {4,-2};
    res = {4};
    cout << (res == Solution().maxSlidingWindow(nums, 2)) << endl;

    return 0;
}
