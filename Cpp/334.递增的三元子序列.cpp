/*
 * @lc app=leetcode.cn id=334 lang=cpp
 *
 * [334] 递增的三元子序列
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<int> tops;
        for (int num : nums) {
            int left = 0, right = (int)tops.size();
            while (left < right) {
                int mid = (left + right) >> 1;
                if (tops[mid] > num) {
                    right = mid;
                } else if (tops[mid] < num) {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }
            
            if (left == tops.size()) {
                tops.push_back(num);
                if (tops.size() > 2) return true;
            } else {
                tops[left] = num;
            }
        }
        return false;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<int> nums;
    bool res;
    
    /**
     输入：nums = [1,2,3,4,5]
     输出：true
     解释：任何 i < j < k 的三元组都满足题意
     */
    nums = {1,2,3,4,5};
    res = true;
    assert(res == Solution().increasingTriplet(nums));

    /**
     输入：nums = [5,4,3,2,1]
     输出：false
     解释：不存在满足题意的三元组
     */
    nums = {5,4,3,2,1};
    res = false;
    assert(res == Solution().increasingTriplet(nums));

    /**
     输入：nums = [2,1,5,0,4,6]
     输出：true
     解释：三元组 (3, 4, 5) 满足题意，因为 nums[3] == 0 < nums[4] == 4 < nums[5] == 6
     */
    nums = {2,1,5,0,4,6};
    res = true;
    assert(res == Solution().increasingTriplet(nums));
    
    /**
     输入：nums =[0,4,2,1,0,-1,-3]
     输出：false
     */
    nums = {0,4,2,1,0,-1,-3};
    res = false;
    assert(res == Solution().increasingTriplet(nums));

    cout << "OK~" << endl;

    return 0;
}
