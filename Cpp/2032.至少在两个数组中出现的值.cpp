/*
 * @lc app=leetcode.cn id=2032 lang=cpp
 *
 * [2032] 至少在两个数组中出现的值
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        unordered_map<int, int> numMap;
        for (int num : nums1) {
            numMap[num] = 1;
        }
        for (int num : nums2) {
            numMap[num] |= 2;
        }
        for (int num : nums3) {
            numMap[num] |= 4;
        }
        vector<int> ans;
        for (auto& [key, value] : numMap) {
            if (value & (value - 1)) {
                ans.push_back(key);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<int> nums1;
    vector<int> nums2;
    vector<int> nums3;
    vector<int> res;
    
    /**
     输入：nums1 = [1,1,3,2], nums2 = [2,3], nums3 = [3]
     输出：[3,2]
     解释：至少在两个数组中出现的所有值为：
     - 3 ，在全部三个数组中都出现过。
     - 2 ，在数组 nums1 和 nums2 中出现过。
     */
    nums1 = {1,1,3,2};
    nums2 = {2,3};
    nums3 = {3};
    res = {3,2};
    sort(res.begin(), res.end());
    assert(res == Solution().twoOutOfThree(nums1, nums2, nums3));
    
    /**
     输入：nums1 = [3,1], nums2 = [2,3], nums3 = [1,2]
     输出：[2,3,1]
     解释：至少在两个数组中出现的所有值为：
     - 2 ，在数组 nums2 和 nums3 中出现过。
     - 3 ，在数组 nums1 和 nums2 中出现过。
     - 1 ，在数组 nums1 和 nums3 中出现过。
     */
    nums1 = {3,1};
    nums2 = {2,3};
    nums3 = {1,2};
    res = {2,3,1};
    sort(res.begin(), res.end());
    assert(res == Solution().twoOutOfThree(nums1, nums2, nums3));
    
    /**
     输入：nums1 = [1,2,2], nums2 = [4,3,3], nums3 = [5]
     输出：[]
     解释：不存在至少在两个数组中出现的值。
     */
    nums1 = {1,2,2};
    nums2 = {4,3,3};
    nums3 = {5};
    res = {};
    sort(res.begin(), res.end());
    assert(res == Solution().twoOutOfThree(nums1, nums2, nums3));

    cout << "OK~" << endl;
    
    return 0;
}
