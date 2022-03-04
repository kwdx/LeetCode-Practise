/*
 * @lc app=leetcode.cn id=2104 lang=cpp
 *
 * [2104] 子数组范围和
 */

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// @lc code=start
class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = (int)nums.size();
        vector<int> minLeft(n), minRight(n), maxLeft(n), maxRight(n);
        stack<int> minStack, maxStack;
        for (int i = 0; i < n; ++i) {
            while (!minStack.empty() && nums[minStack.top()] > nums[i]) {
                minStack.pop();
            }
            minLeft[i] = minStack.empty() ? -1 : minStack.top();
            minStack.push(i);
            
            while (!maxStack.empty() && nums[maxStack.top()] <= nums[i]) {
                maxStack.pop();
            }
            maxLeft[i] = maxStack.empty() ? -1 : maxStack.top();
            maxStack.push(i);
        }
        minStack = stack<int>();
        maxStack = stack<int>();
        for (int i = n - 1; i >= 0; --i) {
            while (!minStack.empty() && nums[minStack.top()] >= nums[i]) {
                minStack.pop();
            }
            minRight[i] = minStack.empty() ? n : minStack.top();
            minStack.push(i);
            
            while (!maxStack.empty() && nums[maxStack.top()] < nums[i]) {
                maxStack.pop();
            }
            maxRight[i] = maxStack.empty() ? n : maxStack.top();
            maxStack.push(i);
        }
        
        long long sumMax = 0, sumMin = 0;
        for (int i = 0; i < n; ++i) {
            sumMax += static_cast<long long>(maxRight[i] - i) * (i - maxLeft[i]) * nums[i];
            sumMin += static_cast<long long>(minRight[i] - i) * (i - minLeft[i]) * nums[i];
        }
        return sumMax - sumMin;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<int> nums;
    long long res;
    
    /**
     输入：nums = [1,2,3]
     输出：4
     解释：nums 的 6 个子数组如下所示：
     [1]，范围 = 最大 - 最小 = 1 - 1 = 0
     [2]，范围 = 2 - 2 = 0
     [3]，范围 = 3 - 3 = 0
     [1,2]，范围 = 2 - 1 = 1
     [2,3]，范围 = 3 - 2 = 1
     [1,2,3]，范围 = 3 - 1 = 2
     所有范围的和是 0 + 0 + 0 + 1 + 1 + 2 = 4
     */
    nums = {1,2,3};
    res = 4;
    assert(res == Solution().subArrayRanges(nums));
    
    /**
     输入：nums = [1,3,3]
     输出：4
     解释：nums 的 6 个子数组如下所示：
     [1]，范围 = 最大 - 最小 = 1 - 1 = 0
     [3]，范围 = 3 - 3 = 0
     [3]，范围 = 3 - 3 = 0
     [1,3]，范围 = 3 - 1 = 2
     [3,3]，范围 = 3 - 3 = 0
     [1,3,3]，范围 = 3 - 1 = 2
     所有范围的和是 0 + 0 + 0 + 2 + 0 + 2 = 4
     */
    nums = {1,3,3};
    res = 4;
    assert(res == Solution().subArrayRanges(nums));
    
    /**
     输入：nums = [4,-2,-3,4,1]
     输出：59
     解释：nums 中所有子数组范围的和是 59
     */
    nums = {4,-2,-3,4,1};
    res = 59;
    assert(res == Solution().subArrayRanges(nums));

    cout << "OK~" << endl;
    
    return 0;
}
