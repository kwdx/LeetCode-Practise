/*
 * @lc app=leetcode.cn id=2006 lang=cpp
 *
 * [2006] 差的绝对值为 K 的数对数目
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// @lc code=start
class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        unordered_map<int, int> cnts;
        int ans = 0;
        for (int num : nums) {
            ans += cnts[num - k] + cnts[num + k];
            cnts[num] += 1;
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
     输入：nums = [1,2,2,1], k = 1
     输出：4
     解释：差的绝对值为 1 的数对为：
     - [1,2,2,1]
     - [1,2,2,1]
     - [1,2,2,1]
     - [1,2,2,1]
     */
    nums = {1,2,2,1};
    k = 1;
    res = 4;
    assert(res == Solution().countKDifference(nums, k));
    
    /**
     输入：nums = [1,3], k = 3
     输出：0
     解释：没有任何数对差的绝对值为 3 。
     */
    nums = {1,3};
    k = 3;
    res = 0;
    assert(res == Solution().countKDifference(nums, k));
    
    /**
     输入：nums = [3,2,1,5,4], k = 2
     输出：3
     解释：差的绝对值为 2 的数对为：
     - [3,2,1,5,4]
     - [3,2,1,5,4]
     - [3,2,1,5,4]
     */
    nums = {3,2,1,5,4};
    k = 2;
    res = 3;
    assert(res == Solution().countKDifference(nums, k));

    cout << "OK~" << endl;

    return 0;
}
