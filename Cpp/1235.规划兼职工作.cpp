/*
 * @lc app=leetcode.cn id=1235 lang=cpp
 *
 * [1235] 规划兼职工作
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = (int)startTime.size();
        vector<vector<int>> jobs(n);
        for (int i = 0; i < n; ++i) {
            jobs[i] = {startTime[i], endTime[i], profit[i]};
        }
        sort(jobs.begin(), jobs.end(), [](const vector<int> &job1, const vector<int> &job2) -> bool {
            return job1[1] < job2[1];
        });
        vector<int> dp(n + 1);
        for (int i = 1; i <= n; ++i) {
            int k = (int)(upper_bound(jobs.begin(), jobs.begin() + i - 1, jobs[i - 1][0], [&](int startTime, const vector<int> &job) -> bool {
                return startTime < job[1];
            }) - jobs.begin());
            dp[i] = max(dp[i - 1], dp[k] + jobs[i - 1][2]);
        }
        return dp[n];
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<int> startTime;
    vector<int> endTime;
    vector<int> profit;
    int res;
    
    /**
     输入：startTime = [1,2,3,3], endTime = [3,4,5,6], profit = [50,10,40,70]
     输出：120
     解释：
     我们选出第 1 份和第 4 份工作，
     时间范围是 [1-3]+[3-6]，共获得报酬 120 = 50 + 70。
     */
    startTime = {1,2,3,3};
    endTime = {3,4,5,6};
    profit = {50,10,40,70};
    res = 120;
    assert(res == Solution().jobScheduling(startTime, endTime, profit));
    
    /**
     输入：startTime = [1,2,3,4,6], endTime = [3,5,10,6,9], profit = [20,20,100,70,60]
     输出：150
     解释：
     我们选择第 1，4，5 份工作。
     共获得报酬 150 = 20 + 70 + 60。
     */
    startTime = {1,2,3,4,6};
    endTime = {3,5,10,6,9};
    profit = {20,20,100,70,60};
    res = 150;
    assert(res == Solution().jobScheduling(startTime, endTime, profit));
    
    /**
     输入：startTime = [1,1,1], endTime = [2,3,4], profit = [5,6,4]
     输出：6
     */
    startTime = {1,1,1};
    endTime = {2,3,4};
    profit = {5,6,4};
    res = 6;
    assert(res == Solution().jobScheduling(startTime, endTime, profit));
    
    cout << "OK~" << endl;
    
    return 0;
}
