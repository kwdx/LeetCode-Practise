/*
 * @lc app=leetcode.cn id=801 lang=cpp
 *
 * [801] 使序列递增的最小交换次数
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int n = (int)nums1.size();
        int a = 0, b = 1;
        for (int i = 1; i < n; ++i) {
            int at = a, bt = b;
            a = b = n;
            if (nums1[i] > nums1[i - 1] && nums2[i] > nums2[i - 1]) {
                a = min(a, at);
                b = min(b, bt + 1);
            }
            if (nums1[i] > nums2[i - 1] && nums2[i] > nums1[i - 1]) {
                a = min(a, bt);
                b = min(b, at + 1);
            }
        }
        return min(a, b);
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<int> nums1;
    vector<int> nums2;
    int res;
    
    /**
     输入: nums1 = [1,3,5,4], nums2 = [1,2,3,7]
     输出: 1
     解释:
     交换 A[3] 和 B[3] 后，两个数组如下:
     A = [1, 3, 5, 7] ， B = [1, 2, 3, 4]
     两个数组均为严格递增的。
     */
    nums1 = {1,3,5,4};
    nums2 = {1,2,3,7};
    res = 1;
    assert(res == Solution().minSwap(nums1, nums2));
    
    /**
     输入: nums1 = [0,3,5,8,9], nums2 = [2,1,4,6,9]
     输出: 1
     */
    nums1 = {0,3,5,8,9};
    nums2 = {2,1,4,6,9};
    res = 1;
    assert(res == Solution().minSwap(nums1, nums2));

    cout << "OK~" << endl;
    
    return 0;
}

