/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
 */

#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1(nums1.begin(), nums1.end());
        vector<int> res;
        for (auto num:nums2) {
            if (set1.erase(num)) {
                res.push_back(num);
            }
        }
        return res;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<int> nums1, nums2, res;
    
    /**
     输入：nums1 = [1,2,2,1], nums2 = [2,2]
     输出：[2]
     */
    nums1 = {1,2,2,1};
    nums2 = {2,2};
    res = {2};
    assert(res == Solution().intersection(nums1, nums2));
    
    /**
     输入：nums1 = [4,9,5], nums2 = [9,4,9,8,4]
     输出：[9,4]
     */
    nums1 = {4,9,5};
    nums2 = {9,4,9,8,4};
    res = {9,4};
    assert(res == Solution().intersection(nums1, nums2));
    
    cout << "OK~" << endl;
    
    return 0;
}
