/*
 * @lc app=leetcode.cn id=219 lang=cpp
 *
 * [219] 存在重复元素 II
 */

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// @lc code=start
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> sets;
        for (int i = 0; i < nums.size(); ++i) {
            if (i > k) sets.erase(nums[i - k - 1]);
            if (sets.count(nums[i])) return true;
            sets.insert(nums[i]);
        }
        return false;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<int> nums;
    int k;
    bool res;
    
    /**
     输入：nums = [1,2,3,1], k = 3
     输出：true
     */
    nums = {1,2,3,1};
    k = 3;
    res = true;
    assert(res == Solution().containsNearbyDuplicate(nums, k));
    
    /**
     输入：nums = [1,0,1,1], k = 1
     输出：true
     */
    nums = {1,0,1,1};
    k = 1;
    res = true;
    assert(res == Solution().containsNearbyDuplicate(nums, k));
    
    /**
     输入：nums = [1,2,3,1,2,3], k = 2
     输出：false
     */
    nums = {1,2,3,1,2,3};
    k = 2;
    res = false;
    assert(res == Solution().containsNearbyDuplicate(nums, k));

    cout << "OK~" << endl;

    return 0;
}
