/*
 * @lc app=leetcode.cn id=1817 lang=cpp
 *
 * [1817] 查找用户活跃分钟数
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        unordered_map<int, unordered_set<int>> activeMinutes;
        for (auto &&log : logs) {
            int id = log[0], time = log[1];
            activeMinutes[id].emplace(time);
        }
        vector<int> ans(k);
        for (auto &&[_, minutes] : activeMinutes) {
            int activeCount = (int)minutes.size();
            ++ans[activeCount - 1];
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<vector<int>> logs;
    int k;
    vector<int> res;

    /**
     输入：logs = [[0,5],[1,2],[0,2],[0,5],[1,3]], k = 5
     输出：[0,2,0,0,0]
     解释：
     ID=0 的用户执行操作的分钟分别是：5 、2 和 5 。因此，该用户的用户活跃分钟数为 2（分钟 5 只计数一次）
     ID=1 的用户执行操作的分钟分别是：2 和 3 。因此，该用户的用户活跃分钟数为 2
     2 个用户的用户活跃分钟数都是 2 ，answer[2] 为 2 ，其余 answer[j] 的值都是 0
     */
    logs = {{0,5},{1,2},{0,2},{0,5},{1,3}};
    k = 5;
    res = {0,2,0,0,0};
    assert(res == Solution().findingUsersActiveMinutes(logs, k));
    
    /**
     输入：logs = [[1,1],[2,2],[2,3]], k = 4
     输出：[1,1,0,0]
     解释：
     ID=1 的用户仅在分钟 1 执行单个操作。因此，该用户的用户活跃分钟数为 1
     ID=2 的用户执行操作的分钟分别是：2 和 3 。因此，该用户的用户活跃分钟数为 2
     1 个用户的用户活跃分钟数是 1 ，1 个用户的用户活跃分钟数是 2
     因此，answer[1] = 1 ，answer[2] = 1 ，其余的值都是 0
     */
    logs = {{0,5},{1,2},{0,2},{0,5},{1,3}};
    k = 5;
    res = {0,2,0,0,0};
    assert(res == Solution().findingUsersActiveMinutes(logs, k));
    
    cout << "OK~" << endl;
    
    return 0;
}
