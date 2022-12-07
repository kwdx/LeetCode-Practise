/*
 * @lc app=leetcode.cn id=1775 lang=cpp
 *
 * [1775] 通过最少操作次数使数组的和相等
 */

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

// @lc code=start
class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int sum1 = accumulate(nums1.begin(), nums1.end(), 0);
        int sum2 = accumulate(nums2.begin(), nums2.end(), 0);
        
        if (sum1 == sum2) return 0;
        
        if (sum1 < sum2) {
            swap(sum1, sum2);
            swap(nums1, nums2);
        }
        
        int n1 = (int)nums1.size();
        int n2 = (int)nums2.size();
        
        int diff = sum1 - sum2;
        
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        int i = n1 - 1;
        int j = 0;
        
        int ans = 0;
        while (i >= 0 || j < n2) {
            int d1 = 0, d2 = 0;
            if (i >= 0) d1 = nums1[i] - 1;
            if (j < n2) d2= 6 - nums2[j];
            
            int maxDiff = max(d1, d2);
            if (maxDiff == 0) return -1;
            if (maxDiff >= diff) return ans + 1;
            if (d1 == maxDiff) {
                --i;
            } else {
                ++j;
            }
            diff -= maxDiff;
            ++ans;
        }
        return -1;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<int> nums1;
    vector<int> nums2;
    int res;
    
    /**
     输入：nums1 = [1,2,3,4,5,6], nums2 = [1,1,2,2,2,2]
     输出：3
     解释：你可以通过 3 次操作使 nums1 中所有数的和与 nums2 中所有数的和相等。以下数组下标都从 0 开始。
     - 将 nums2[0] 变为 6 。 nums1 = [1,2,3,4,5,6], nums2 = [6,1,2,2,2,2] 。
     - 将 nums1[5] 变为 1 。 nums1 = [1,2,3,4,5,1], nums2 = [6,1,2,2,2,2] 。
     - 将 nums1[2] 变为 2 。 nums1 = [1,2,2,4,5,1], nums2 = [6,1,2,2,2,2] 。
     */
    nums1 = {1,2,3,4,5,6};
    nums2 = {1,1,2,2,2,2};
    res = 3;
    assert(res == Solution().minOperations(nums1, nums2));
    
    /**
     输入：nums1 = [1,1,1,1,1,1,1], nums2 = [6]
     输出：-1
     解释：没有办法减少 nums1 的和或者增加 nums2 的和使二者相等。
     */
    nums1 = {1,1,1,1,1,1,1};
    nums2 = {6};
    res = -1;
    assert(res == Solution().minOperations(nums1, nums2));
    
    /**
     输入：nums1 = [6,6], nums2 = [1]
     输出：3
     解释：你可以通过 3 次操作使 nums1 中所有数的和与 nums2 中所有数的和相等。以下数组下标都从 0 开始。
     - 将 nums1[0] 变为 2 。 nums1 = [2,6], nums2 = [1] 。
     - 将 nums1[1] 变为 2 。 nums1 = [2,2], nums2 = [1] 。
     - 将 nums2[0] 变为 4 。 nums1 = [2,2], nums2 = [4] 。
     */
    nums1 = {6,6};
    nums2 = {1};
    res = 3;
    assert(res == Solution().minOperations(nums1, nums2));
    
    cout << "OK~" << endl;
    
    return 0;
}
