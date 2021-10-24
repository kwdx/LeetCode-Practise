/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
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
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<int> nums1, nums2;
    int m, n;
    
    /**
     输入：nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
     输出：[1,2,2,3,5,6]
     解释：需要合并 [1,2,3] 和 [2,5,6] 。
     合并结果是 [1,2,2,3,5,6] ，其中斜体加粗标注的为 nums1 中的元素。
     */
    nums1 = {1,2,3,0,0,0};
    m = 3;
    nums2 = {2,5,6};
    n = 3;
    Solution().merge(nums1, m, nums2, n);
    assert(is_sorted(nums1.begin(), nums1.end()));
    
    /**
     输入：nums1 = [1], m = 1, nums2 = [], n = 0
     输出：[1]
     解释：需要合并 [1] 和 [] 。
     合并结果是 [1] 。
     */
    nums1 = {1};
    m = 1;
    nums2 = {};
    n = 0;
    Solution().merge(nums1, m, nums2, n);
    assert(is_sorted(nums1.begin(), nums1.end()));

    /**
     输入：nums1 = [0], m = 0, nums2 = [1], n = 1
     输出：[1]
     解释：需要合并的数组是 [] 和 [1] 。
     合并结果是 [1] 。
     注意，因为 m = 0 ，所以 nums1 中没有元素。nums1 中仅存的 0 仅仅是为了确保合并结果可以顺利存放到 nums1 中。
     */
    nums1 = {0};
    m = 0;
    nums2 = {1};
    n = 1;
    Solution().merge(nums1, m, nums2, n);
    assert(is_sorted(nums1.begin(), nums1.end()));

    cout << "OK~" << endl;
    
    return 0;
}
