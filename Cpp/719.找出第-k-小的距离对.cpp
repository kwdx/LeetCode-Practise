/*
 * @lc app=leetcode.cn id=719 lang=cpp
 *
 * [719] 找出第 k 小的距离对
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = (int)nums.size();
        int left = 0, right = nums.back() - nums.front();
        
        while (left <= right) {
            int mid = (left + right) >> 1;
            int cnt = 0;
            for (int i = 0, j = 0; j < n; ++j) {
                while (nums[j] - nums[i] > mid) {
                    ++i;
                }
                cnt += j - i;
            }
            if (cnt >= k) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<int> nums;
    int k;
    int res;
    
    /**
     输入：nums = [1,3,1], k = 1
     输出：0
     解释：数对和对应的距离如下：
     (1,3) -> 2
     (1,1) -> 0
     (3,1) -> 2
     距离第 1 小的数对是 (1,1) ，距离为 0 。
     */
    nums = {1,3,1};
    k = 1;
    res = 0;
    assert(res == Solution().smallestDistancePair(nums, k));
    
    /**
     输入：nums = [1,1,1], k = 2
     输出：0
     */
    nums = {1,1,1};
    k = 2;
    res = 0;
    assert(res == Solution().smallestDistancePair(nums, k));
    
    /**
     输入：nums = [1,6,1], k = 3
     输出：5
     */
    nums = {1,6,1};
    k = 3;
    res = 5;
    assert(res == Solution().smallestDistancePair(nums, k));
    
    cout << "OK~" << endl;
    
    return 0;
}
