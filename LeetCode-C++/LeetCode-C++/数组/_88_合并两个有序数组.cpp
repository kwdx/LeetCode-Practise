//
//  _88_合并两个有序数组.cpp
//  LeetCode-C++
//
//  Created by warden on 2019/11/28.
//  Copyright © 2019 warden. All rights reserved.
//

#include "_88_合并两个有序数组.hpp"

using namespace std;

void _88_合并两个有序数组::merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
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
