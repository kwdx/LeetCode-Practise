//
//  5856.完成任务的最少工作时间段.cpp
//  Cpp
//
//  Created by warden on 2021/8/29.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// @lc code=start
class Solution {
public:
    int minSessions(vector<int>& tasks, int sessionTime) {
        int n = (int)tasks.size();
        int N = 1 << n;
        vector<int> dp(N, n);
        dp[0] = 0;
        vector<int> sums(N, 0);
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i & (1 << j)) {
                    sums[i] += tasks[j];
                }
            }
            if (sums[i] <= sessionTime) {
                dp[i] = 1;
            }
        }
        
        for (int i = 1; i < N; i++) {
            for (int sub = (i - 1) & i; sub; sub = (sub - 1) & i) {
                if (sums[sub] <= sessionTime) {
                    dp[i] = min(dp[i], dp[i ^ sub] + 1);
                }
            }
        }
        return dp[N-1];
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    vector<int> tasks;
    int sessionTime, res;
    
    /**
     输入：tasks = [1,2,3], sessionTime = 3
     输出：2
     解释：你可以在两个工作时间段内完成所有任务。
     - 第一个工作时间段：完成第一和第二个任务，花费 1 + 2 = 3 小时。
     - 第二个工作时间段：完成第三个任务，花费 3 小时。
     */
    tasks = {1,2,3};
    sessionTime = 3;
    res = 2;
    assert(res == Solution().minSessions(tasks, sessionTime));

    /**
     输入：tasks = [3,1,3,1,1], sessionTime = 8
     输出：2
     解释：你可以在两个工作时间段内完成所有任务。
     - 第一个工作时间段：完成除了最后一个任务以外的所有任务，花费 3 + 1 + 3 + 1 = 8 小时。
     - 第二个工作时间段，完成最后一个任务，花费 1 小时。
     */
    tasks = {3,1,3,1,1};
    sessionTime = 8;
    res = 2;
    assert(res == Solution().minSessions(tasks, sessionTime));

    /**
     输入：tasks = [1,2,3,4,5], sessionTime = 15
     输出：1
     解释：你可以在一个工作时间段以内完成所有任务。
     */
    tasks = {1,2,3,4,5};
    sessionTime = 15;
    res = 1;
    assert(res == Solution().minSessions(tasks, sessionTime));

    /**
     输入：tasks = [1,2,2,2,3,3,2,3,2], sessionTime = 10
     输出：2
     解释：你可以在一个工作时间段以内完成所有任务。
     */
    tasks = {1,2,2,2,3,3,2,3,2};
    sessionTime = 10;
    res = 2;
    assert(res == Solution().minSessions(tasks, sessionTime));

    /**
     输入：tasks = [1,5,7,10,3,8,4,2,6,2], sessionTime = 10
     输出：5
     解释：你可以在一个工作时间段以内完成所有任务。
     */
    tasks = {1,5,7,10,3,8,4,2,6,2};
    sessionTime = 10;
    res = 5;
    assert(res == Solution().minSessions(tasks, sessionTime));

    /**
     输入：tasks = [2,3,3,4,4,4,5,6,7,10], sessionTime = 12
     输出：5
     解释：你可以在一个工作时间段以内完成所有任务。
     */
    tasks = {2,3,3,4,4,4,5,6,7,10};
    sessionTime = 12;
    res = 4;
    assert(res == Solution().minSessions(tasks, sessionTime));

    /**
     输入：tasks = [10,6,6,8,3,7], sessionTime = 13
     输出：4
     解释：你可以在一个工作时间段以内完成所有任务。
     */
    tasks = {10,6,6,8,3,7};
    sessionTime = 13;
    res = 4;
    assert(res == Solution().minSessions(tasks, sessionTime));
    
    /**
     输入：tasks = [3,3,3,3,4,5,5,5,7,9], sessionTime = 12
     输出：4
     解释：你可以在一个工作时间段以内完成所有任务。
     */
    tasks = {3,3,3,3,4,5,5,5,7,9};
    sessionTime = 12;
    res = 4;
    assert(res == Solution().minSessions(tasks, sessionTime));

    cout << "OK~" << endl;
    
    return 0;
}
