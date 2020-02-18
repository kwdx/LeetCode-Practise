//
//  _88_合并两个有序数组.cpp
//  LeetCode-C++
//
//  Created by warden on 2019/11/28.
//  Copyright © 2019 warden. All rights reserved.
//
// https://leetcode-cn.com/problems/merge-sorted-array/

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (int i = m + n - 1; i >= n; i--) {
            nums1[i] = nums1[i - n];
        }
        int idx1 = 0;
        int idx2 = 0;
        while (idx1 < m && idx2 < n) {
            if (nums1[idx1 + n] <= nums2[idx2]) {
                nums1[idx1 + idx2] = nums1[idx1 + n];
                idx1++;
            } else {
                nums1[idx1 + idx2] = nums2[idx2];
                idx2++;
            }
        }
        while (idx2 < n) {
            nums1[idx1 + idx2] = nums2[idx2];
            idx2++;
        }
    }
};

/**
 输入:
 nums1 = [1,2,3,0,0,0], m = 3
 nums2 = [2,5,6],       n = 3

 输出: [1,2,2,3,5,6]
*/
/**
int main(int argc, const char * argv[]) {
    Solution solution = Solution();
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};
    solution.merge(nums1, 3, nums2, 3);
    for (int num: nums1) {
        printf("%d ", num);
    }
    printf("\n");

    nums1 = {1, 2, 4, 5, 6, 0};
    nums2 = {3};
    solution.merge(nums1, 5, nums2, 1);
    for (int num: nums1) {
        printf("%d ", num);
    }
    printf("\n");

    nums1 = {2, 0};
    nums2 = {1};
    solution.merge(nums1, 1, nums2, 1);
    for (int num: nums1) {
        printf("%d ", num);
    }
    printf("\n");
    
    return 0;
}
*/
