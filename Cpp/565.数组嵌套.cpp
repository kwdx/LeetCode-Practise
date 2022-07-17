/*
 * @lc app=leetcode.cn id=565 lang=cpp
 *
 * [565] 数组嵌套
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int n = (int)nums.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int cur = i, cnt = 0;
            while (nums[cur] != -1) {
                ++cnt;
                int c = cur;
                cur = nums[cur];
                nums[c] = -1;
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};
// @lc code=end


int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<int> nums;
    int res;
    
    /**
     输入: A = [5,4,0,3,1,6,2]
     输出: 4
     解释:
     A[0] = 5, A[1] = 4, A[2] = 0, A[3] = 3, A[4] = 1, A[5] = 6, A[6] = 2.

     其中一种最长的 S[K]:
     S[0] = {A[0], A[5], A[6], A[2]} = {5, 6, 2, 0}
     */
    nums = {5,4,0,3,1,6,2};
    res = 4;
    assert(res == Solution().arrayNesting(nums));
    
    cout << "OK~" << endl;
    
    return 0;
}
