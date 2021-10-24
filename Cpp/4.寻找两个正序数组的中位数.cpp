/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int l1 = 0, r1 = (int)nums1.size() - 1, l2 = 0, r2 = (int)nums2.size() - 1;
        int move = (r1 + r2 + 1) >> 1;
        while (move > 0) {
            if (l1 <= r1 && l2 <= r2) {
                if (nums1[l1] < nums2[l2]) {
                    l1 += 1;
                } else {
                    l2 += 1;
                }
                if (nums1[r1] > nums2[r2]) {
                    r1 -= 1;
                } else {
                    r2 -= 1;
                }
            } else if (l1 < r1) {
                l1 += 1;
                r1 -= 1;
            } else {
                l2 += 1;
                r2 -= 1;
            }
            move -= 1;
        }
        double val = 0;
        int count = 0;
        while (l1 <= r1) {
            val += nums1[l1];
            l1 += 1;
            count += 1;
        }
        while (l2 <= r2) {
            val += nums2[l2];
            l2 += 1;
            count += 1;
        }
        if (count == 0) {
            return 0;
        }
        return val / count;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<int> nums1, nums2;
    double res;
    
    /**
     输入：nums1 = [1,3], nums2 = [2]
     输出：2.00000
     解释：合并数组 = [1,2,3] ，中位数 2
     */
    nums1 = {1,3};
    nums2 = {2};
    res = 2.00000;
    assert(res == Solution().findMedianSortedArrays(nums1, nums2));
    
    /**
     输入：nums1 = [1,2], nums2 = [3,4]
     输出：2.50000
     解释：合并数组 = [1,2,3,4] ，中位数 (2 + 3) / 2 = 2.5
     */
    nums1 = {1,2};
    nums2 = {3,4};
    res = 2.50000;
    assert(res == Solution().findMedianSortedArrays(nums1, nums2));
    
    /**
     输入：nums1 = [0,0], nums2 = [0,0]
     输出：0.00000
     */
    nums1 = {0,0};
    nums2 = {0,0};
    res = 0.00000;
    assert(res == Solution().findMedianSortedArrays(nums1, nums2));
    
    /**
     输入：nums1 = [], nums2 = [1]
     输出：1.00000
     */
    nums1 = {};
    nums2 = {1};
    res = 1.00000;
    assert(res == Solution().findMedianSortedArrays(nums1, nums2));
    
    /**
     输入：nums1 = [2], nums2 = []
     输出：2.00000
     */
    nums1 = {2};
    nums2 = {};
    res = 2.00000;
    assert(res == Solution().findMedianSortedArrays(nums1, nums2));

    cout << "OK~" << endl;
    
    return 0;
}
