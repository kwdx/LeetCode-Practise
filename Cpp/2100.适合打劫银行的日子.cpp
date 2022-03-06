/*
 * @lc app=leetcode.cn id=2100 lang=cpp
 *
 * [2100] 适合打劫银行的日子
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        int n = (int)security.size();
        vector<int> g(n, 0);
        for (int i = 1; i < n; ++i) {
            if (security[i] == security[i - 1]) continue;
            g[i] = security[i] > security[i - 1] ? 1 : -1;
        }
        vector<int> a(n + 1, 0), b(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            a[i] = a[i - 1] + (g[i - 1] == 1 ? 1 : 0);
            b[i] = b[i - 1] + (g[i - 1] == -1 ? 1 : 0);
        }
        
        vector<int> ans;
        for (int i = time; i < n - time; ++i) {
            int c1 = a[i + 1] - a[i + 1 - time];
            int c2 = b[i + 1 + time] - b[i + 1];
            if (c1 == 0 && c2 == 0) ans.push_back(i);
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<int> security;
    int time;
    vector<int> res;
    
    /**
     输入：security = [5,3,3,3,5,6,2], time = 2
     输出：[2,3]
     解释：
     第 2 天，我们有 security[0] >= security[1] >= security[2] <= security[3] <= security[4] 。
     第 3 天，我们有 security[1] >= security[2] >= security[3] <= security[4] <= security[5] 。
     没有其他日子符合这个条件，所以日子 2 和 3 是适合打劫银行的日子。
     */
    security = {5,3,3,3,5,6,2};
    time = 2;
    res = {2,3};
    assert(res == Solution().goodDaysToRobBank(security, time));
    
    /**
     输入：security = [1,1,1,1,1], time = 0
     输出：[0,1,2,3,4]
     解释：
     因为 time 等于 0 ，所以每一天都是适合打劫银行的日子，所以返回每一天。
     */
    security = {1,1,1,1,1};
    time = 0;
    res = {0,1,2,3,4};
    assert(res == Solution().goodDaysToRobBank(security, time));
    
    /**
     输入：security = [1,2,3,4,5,6], time = 2
     输出：[]
     解释：
     没有任何一天的前 2 天警卫数目是非递增的。
     所以没有适合打劫银行的日子，返回空数组。
     */
    security = {1,2,3,4,5,6};
    time = 2;
    res = {};
    assert(res == Solution().goodDaysToRobBank(security, time));
    
    /**
     输入：security = [1], time = 5
     输出：[]
     解释：
     没有日子前面和后面有 5 天时间。
     所以没有适合打劫银行的日子，返回空数组。
     */
    security = {1};
    time = 5;
    res = {};
    assert(res == Solution().goodDaysToRobBank(security, time));

    cout << "OK~" << endl;
    
    return 0;
}
