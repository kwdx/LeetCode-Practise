/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() < 3) return {};
        
        vector<vector<int>> res;
        
        sort(nums.begin(), nums.end());
        
        for (int first = 0; first < nums.size() - 2; first++) {
            if (nums[first] > 0) return res;
            if (first > 0 && nums[first] == nums[first - 1]) continue;
            int second = first + 1;
            int third = (int)nums.size() - 1;
            int target = -nums[first];
            while (second < third) {
                if (nums[second] + nums[third] == target) {
                    res.push_back({nums[first], nums[second++], nums[third--]});
                    while (second < third && nums[second] == nums[second - 1]) ++second;
                    while (second < third && nums[third] == nums[third + 1]) --third;
                } else if (nums[second] + nums[third] < target) {
                    ++second;
                } else {
                    --third;
                }
            }
        }
        
        return res;
    }
};
// @lc code=end


int main(int argc, const char * argv[]) {
    vector<int> nums;
    vector<vector<int>> res;

     /**
      输入：nums = [-1,0,1,2,-1,-4]
      输出：[[-1,-1,2],[-1,0,1]]
      */
     nums = {-1,0,1,2,-1,-4};
     res = {
         {-1,-1,2},
         {-1,0,1}
     };
     assert(res == Solution().threeSum(nums));

     /**
      输入：nums = []
      输出：[]
      */
     nums = {};
     res = {};
     assert(res == Solution().threeSum(nums));

     /**
      输入：nums = [0]
      输出：[]
      */
     nums = {0};
     res = {};
     assert(res == Solution().threeSum(nums));

    /**
     输入：nums = [0,0,0]
     输出：[0,0,0]
     */
    nums = {0,0,0};
    res = {{0,0,0}};
    assert(res == Solution().threeSum(nums));

    /**
     输入：nums = [-2,0,0,2,2]
     输出：[-2,0,2]
     */
    nums = {-2,0,0,2,2};
    res = {{-2,0,2}};
    assert(res == Solution().threeSum(nums));

    cout << "OK~" << endl;

    return 0;
}
