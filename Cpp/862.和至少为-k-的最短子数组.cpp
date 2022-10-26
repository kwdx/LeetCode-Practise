/*
 * @lc app=leetcode.cn id=862 lang=cpp
 *
 * [862] 和至少为 K 的最短子数组
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// @lc code=start
class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = (int)nums.size();
        vector<long> preSums(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            preSums[i + 1] = preSums[i] + nums[i];
        }
        int ans = n + 1;
        deque<int> q;
        for (int i = 0; i <= n; ++i) {
            long curSum = preSums[i];
            while (!q.empty() && curSum - preSums[q.front()] >= k) {
                ans = min(ans, i - q.front());
                q.pop_front();
            }
            while (!q.empty() && preSums[q.back()] >= curSum) {
                q.pop_back();
            }
            q.push_back(i);
        }
        return ans < n + 1 ? ans : -1;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<int> nums;
    int k;
    int res;
    
    /**
     输入：nums = [1], k = 1
     输出：1
     */
    nums = {1};
    k = 1;
    res = 1;
    assert(res == Solution().shortestSubarray(nums, k));
    
    /**
     输入：nums = [1,2], k = 4
     输出：-1
     */
    nums = {1,2};
    k = 4;
    res = -1;
    assert(res == Solution().shortestSubarray(nums, k));
    
    /**
     输入：nums = [2,-1,2], k = 3
     输出：3
     */
    nums = {2,-1,2};
    k = 3;
    res = 3;
    assert(res == Solution().shortestSubarray(nums, k));
    
    cout << "OK~" << endl;
    
    return 0;
}
