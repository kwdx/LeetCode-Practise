/*
 * @lc app=leetcode.cn id=646 lang=cpp
 *
 * [646] 最长数对链
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end());
        vector<int> ans;
        for (auto& pair : pairs) {
            int x = pair[0], y = pair[1];
            if (ans.empty() || x > ans.back()) {
                ans.emplace_back(y);
            } else {
                int idx = (int)(lower_bound(ans.begin(), ans.end(), x) - ans.begin());
                ans[idx] = min(ans[idx], y);
            }
        }
        return (int)ans.size();
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<vector<int>> pairs;
    int res;
    
    /**
     输入：[[1,2], [2,3], [3,4]]
     输出：2
     解释：最长的数对链是 [1,2] -> [3,4]
     */
    pairs = {{1,2},{2,3},{3,4}};
    res = 2;
    assert(res == Solution().findLongestChain(pairs));

    cout << "OK~" << endl;
    
    return 0;
}
