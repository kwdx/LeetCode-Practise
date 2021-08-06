/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

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

