/*
 * @lc app=leetcode.cn id=373 lang=cpp
 *
 * [373] 查找和最小的K对数字
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// @lc code=start
//struct cmp {
//    bool operator() (vector<int> a, vector<int> b) {
//        return nums1
//    }
//}
class Solution {
private:
    bool flag = true;
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = (int)nums1.size(), m = (int)nums2.size();
        if (n > m && flag) {
            flag = false;
            return kSmallestPairs(nums2, nums1, k);
        }
        vector<vector<int>> ans;
        auto my_cmp = [&nums1, &nums2](const vector<int>& a, const vector<int>& b) {
            return nums1[a[0]] + nums2[a[1]] > nums1[b[0]] + nums2[b[1]];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(my_cmp)> q(my_cmp);
        for (int i = 0; i < min(n, k); ++i) {
            q.push({i, 0});
        }
        
        while (ans.size() < k && !q.empty()) {
            vector<int> poll = q.top();
            q.pop();
            int a = poll[0], b = poll[1];
            if (flag) {
                ans.push_back({nums1[a], nums2[b]});
            } else {
                ans.push_back({nums2[b], nums1[a]});
            }
            if (b + 1 < m) {
                q.push({a, b + 1});
            }
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<int> nums1;
    vector<int> nums2;
    int k;
    vector<vector<int>> res;
    
    /**
     输入: nums1 = [1,7,11], nums2 = [2,4,6], k = 3
     输出: [1,2],[1,4],[1,6]
     解释: 返回序列中的前 3 对数：
          [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
     */
    nums1 = {1,7,11};
    nums2 = {2,4,6};
    k = 3;
    res = {{1,2},{1,4},{1,6}};
    assert(res == Solution().kSmallestPairs(nums1, nums2, k));
    
    /**
     输入: nums1 = [1,1,2], nums2 = [1,2,3], k = 2
     输出: [1,1],[1,1]
     解释: 返回序列中的前 2 对数：
          [1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]
     */
    nums1 = {1,1,2};
    nums2 = {1,2,3};
    k = 2;
    res = {{1,1},{1,1}};
    assert(res == Solution().kSmallestPairs(nums1, nums2, k));
    
    /**
     输入: nums1 = [1,2], nums2 = [3], k = 3
     输出: [1,3],[2,3]
     解释: 也可能序列中所有的数对都被返回:[1,3],[2,3]
     */
    nums1 = {1,2};
    nums2 = {3};
    k = 3;
    res = {{1,3},{2,3}};
    assert(res == Solution().kSmallestPairs(nums1, nums2, k));

    cout << "OK~" << endl;

    return 0;
}

