/*
 * @lc app=leetcode.cn id=1764 lang=cpp
 *
 * [1764] 通过连接另一个数组的子数组得到一个数组
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int find(vector<int> &nums, int k, vector<int> &g) {
        int m = (int)g.size(), n = (int)nums.size();
        if (k + g.size() > nums.size()) {
            return -1;
        }
        vector<int> pi(m);
        for (int i = 1, j = 0; i < m; i++) {
            while (j > 0 && g[i] != g[j]) {
                j = pi[j - 1];
            }
            if (g[i] == g[j]) {
                j++;
            }
            pi[i] = j;
        }
        for (int i = k, j = 0; i < n; i++) {
            while (j > 0 && nums[i] != g[j]) {
                j = pi[j - 1];
            }
            if (nums[i] == g[j]) {
                j++;
            }
            if (j == m) {
                return i - m + 1;
            }
        }
        return -1;
    }

    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        int k = 0;
        for (int i = 0; i < groups.size(); i++) {
            k = find(nums, k, groups[i]);
            if (k == -1) {
                return false;
            }
            k += groups[i].size();
        }
        return true;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<vector<int>> groups;
    vector<int> nums;
    bool res;
    
    /**
     输入：groups = [[1,-1,-1],[3,-2,0]], nums = [1,-1,0,1,-1,-1,3,-2,0]
     输出：true
     解释：你可以分别在 nums 中选出第 0 个子数组 [1,-1,0,1,-1,-1,3,-2,0] 和第 1 个子数组 [1,-1,0,1,-1,-1,3,-2,0] 。
     这两个子数组是不相交的，因为它们没有任何共同的元素。
     */
    groups = {{1,-1,-1},{3,-2,0}};
    nums = {1,-1,0,1,-1,-1,3,-2,0};
    res = true;
    assert(res == Solution().canChoose(groups, nums));
    
    /**
     输入：groups = [[10,-2],[1,2,3,4]], nums = [1,2,3,4,10,-2]
     输出：false
     解释：选择子数组 [1,2,3,4,10,-2] 和 [1,2,3,4,10,-2] 是不正确的，因为它们出现的顺序与 groups 中顺序不同。
     [10,-2] 必须出现在 [1,2,3,4] 之前。
     */
    groups = {{10,-2},{1,2,3,4}};
    nums = {1,2,3,4,10,-2};
    res = false;
    assert(res == Solution().canChoose(groups, nums));
    
    /**
     输入：groups = [[1,2,3],[3,4]], nums = [7,7,1,2,3,4,7,7]
     输出：false
     解释：选择子数组 [7,7,1,2,3,4,7,7] 和 [7,7,1,2,3,4,7,7] 是不正确的，因为它们不是不相交子数组。
     它们有一个共同的元素 nums[4] （下标从 0 开始）。
     */
    groups = {{1,2,3},{3,4}};
    nums = {7,7,1,2,3,4,7,7};
    res = false;
    assert(res == Solution().canChoose(groups, nums));

    cout << "OK~" << endl;
    
    return 0;
}
