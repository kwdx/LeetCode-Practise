/*
 * @lc app=leetcode.cn id=324 lang=cpp
 *
 * [324] 摆动排序 II
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = (int)nums.size();
        vector<int> arr = nums;
        sort(arr.begin(), arr.end());
        int left = (n - 1) / 2, right = n - 1;
        for (int i = 0; i < n; ++i) {
            if ((i & 1) == 0) {
                nums[i] = arr[left--];
            } else {
                nums[i] = arr[right--];
            }
        }
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<int> nums;
    vector<int> res;
    
    nums = {1,4,3,4,1,2,1,3,1,3,2,3,3};
    res = {3,4,2,4,2,3,1,3,1,3,1,3,1};
    Solution().wiggleSort(nums);
    assert(res == nums);
        
    /**
     输入：nums = [1,5,1,1,6,4]
     输出：[1,6,1,5,1,4]
     解释：[1,4,1,5,1,6] 同样是符合题目要求的结果，可以被判题程序接受。
     */
    nums = {1,5,1,1,6,4};
    res = {1,6,1,5,1,4};
    Solution().wiggleSort(nums);
    assert(res == nums);
    
    /**
     输入：nums = [1,3,2,2,3,1]
     输出：[2,3,1,3,1,2]
     */
    nums = {1,3,2,2,3,1};
    res = {2,3,1,3,1,2};
    Solution().wiggleSort(nums);
    assert(res == nums);
    
    cout << "OK~" << endl;
    
    return 0;
}
