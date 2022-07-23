//
//  115.重建序列.cpp
//  Cpp
//
//  Created by warden on 2022/7/23.
//

#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

// @lc code=start
class Solution {
public:
    bool sequenceReconstruction(vector<int>& nums, vector<vector<int>>& sequences) {
        int n = (int)nums.size();
        vector<int> indegress(n + 1);
        vector<unordered_set<int>> graph(n + 1);
        for (auto& sequence : sequences) {
            for (int i = 1; i < sequence.size(); ++i) {
                int prev = sequence[i - 1], next = sequence[i];
                if (!graph[prev].count(next)) {
                    graph[prev].emplace(next);
                    ++indegress[next];
                }
            }
        }
        queue<int> q;
        for (int i = 1; i <= n; ++i) {
            if (indegress[i] == 0) {
                q.emplace(i);
            }
        }
        while (!q.empty()) {
            if (q.size() > 1) {
                return false;
            }
            int num = q.front();
            q.pop();
            for (int next : graph[num]) {
                indegress[next]--;
                if (indegress[next] == 0) {
                    q.emplace(next);
                }
            }
        }
        return true;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<int> nums;
    vector<vector<int>> sequences;
    bool res;
    
    /**
     输入：nums = [1,2,3], sequences = [[1,2],[1,3]]
     输出：false
     解释：有两种可能的超序列：[1,2,3]和[1,3,2]。
     序列 [1,2] 是[1,2,3]和[1,3,2]的子序列。
     序列 [1,3] 是[1,2,3]和[1,3,2]的子序列。
     因为 nums 不是唯一最短的超序列，所以返回false。
     */
    nums = {1,2,3};
    sequences = {{1,2},{1,3}};
    res = false;
    assert(res == Solution().sequenceReconstruction(nums, sequences));

    /**
     输入：nums = [1,2,3], sequences = [[1,2]]
     输出：false
     解释：最短可能的超序列为 [1,2]。
     序列 [1,2] 是它的子序列：[1,2]。
     因为 nums 不是最短的超序列，所以返回false。
     */
    nums = {1,2,3};
    sequences = {{1,2}};
    res = false;
    assert(res == Solution().sequenceReconstruction(nums, sequences));
    
    /**
     输入：nums = [1,2,3], sequences = [[1,2],[1,3],[2,3]]
     输出：true
     解释：最短可能的超序列为[1,2,3]。
     序列 [1,2] 是它的一个子序列：[1,2,3]。
     序列 [1,3] 是它的一个子序列：[1,2,3]。
     序列 [2,3] 是它的一个子序列：[1,2,3]。
     因为 nums 是唯一最短的超序列，所以返回true。
     */
    nums = {1,2,3};
    sequences = {{1,2},{1,3},{2,3}};
    res = true;
    assert(res == Solution().sequenceReconstruction(nums, sequences));
    
    cout << "OK~" << endl;
    
    return 0;
}
