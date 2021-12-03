/*
 * @lc app=leetcode.cn id=1005 lang=cpp
 *
 * [1005] K 次取反后最大化的数组和
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// @lc code=start
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> pq;
        int sum = 0;
        int a = 0;
        for (int num : nums) {
            sum += num;
            if (num < 0) {
                ++a;
            }
            pq.push(num);
        }
        // 将所有负数反正
        while (k > 0 && a > 0) {
            int num = pq.top();
            pq.pop();
            pq.push(-num);
            --k;
            --a;
            sum -= 2 * num;
        }
        
        return (k % 2 == 1) ? (sum - 2 * pq.top()) : sum;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<int> nums;
    int k;
    int res;
    
    /**
     输入：nums = [4,2,3], k = 1
     输出：5
     解释：选择下标 1 ，nums 变为 [4,-2,3] 。
     */
    nums = {4,2,3};
    k = 1;
    res = 5;
    assert(res == Solution().largestSumAfterKNegations(nums, k));

    /**
     输入：nums = [3,-1,0,2], k = 3
     输出：6
     解释：选择下标 (1, 2, 2) ，nums 变为 [3,1,0,2] 。
     */
    nums = {3,-1,0,2};
    k = 3;
    res = 6;
    assert(res == Solution().largestSumAfterKNegations(nums, k));
    
    /**
     输入：nums = [2,-3,-1,5,-4], k = 2
     输出：13
     解释：选择下标 (1, 4) ，nums 变为 [2,3,-1,5,4] 。
     */
    nums = {2,-3,-1,5,-4};
    k = 2;
    res = 13;
    assert(res == Solution().largestSumAfterKNegations(nums, k));

    cout << "OK~" << endl;

    return 0;
}
