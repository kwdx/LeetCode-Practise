/*
 * @lc app=leetcode.cn id=2028 lang=cpp
 *
 * [2028] 找出缺失的观测数据
 */

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = (int)rolls.size();
        int total = (m + n) * mean;
        int rest = total - accumulate(rolls.begin(), rolls.end(), 0);
        if (rest < n || rest > n * 6) return {};
        vector<int> ans(n, rest / n);
        if (rest / n * n < rest) {
            int d = rest - (rest / n * n), idx = 0;
            while (d-- > 0) ans[idx++]++;
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<int> rolls;
    int mean;
    int n;
    vector<int> res;
    
    /**
     输入：rolls = [3,2,4,3], mean = 4, n = 2
     输出：[6,6]
     解释：所有 n + m 次投掷的平均值是 (3 + 2 + 4 + 3 + 6 + 6) / 6 = 4 。
     */
    rolls = {3,2,4,3};
    mean = 4;
    n = 2;
    res = {6,6};
    assert(res == Solution().missingRolls(rolls, mean, n));
    
    /**
     输入：rolls = [1,5,6], mean = 3, n = 4
     输出：[2,3,2,2]
     解释：所有 n + m 次投掷的平均值是 (1 + 5 + 6 + 2 + 3 + 2 + 2) / 7 = 3 。
     */
    rolls = {1,5,6};
    mean = 3;
    n = 4;
    res = {3,2,2,2};
    assert(res == Solution().missingRolls(rolls, mean, n));
    
    /**
     输入：rolls = [1,2,3,4], mean = 6, n = 4
     输出：[]
     解释：无论丢失的 4 次数据是什么，平均值都不可能是 6 。
     */
    rolls = {1,2,3,4};
    mean = 6;
    n = 4;
    res = {};
    assert(res == Solution().missingRolls(rolls, mean, n));
    
    /**
     输入：rolls = [1], mean = 3, n = 1
     输出：[5]
     解释：所有 n + m 次投掷的平均值是 (1 + 5) / 2 = 3 。
     */
    rolls = {1};
    mean = 3;
    n = 1;
    res = {5};
    assert(res == Solution().missingRolls(rolls, mean, n));

    cout << "OK~" << endl;
    
    return 0;
}
