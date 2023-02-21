/*
 * @lc app=leetcode.cn id=1326 lang=cpp
 *
 * [1326] 灌溉花园的最少水龙头数目
 */

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

// @lc code=start
class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> rightMost(n + 1);
        iota(rightMost.begin(), rightMost.end(), 0);
        for (int i = 0; i <= n; i++) {
            int start = max(0, i - ranges[i]);
            int end = min(n, i + ranges[i]);
            rightMost[start] = max(rightMost[start], end);
        }
        int last = 0, ans = 0, pre = 0;
        for (int i = 0; i < n; i++) {
            last = max(last, rightMost[i]);
            if (i == last) {
                return -1;
            }
            if (i == pre) {
                ans++;
                pre = last;
            }
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int n;
    vector<int> ranges;
    int res;
    
    /**
     输入：n = 5, ranges = [3,4,1,1,0,0]
     输出：1
     解释：
     点 0 处的水龙头可以灌溉区间 [-3,3]
     点 1 处的水龙头可以灌溉区间 [-3,5]
     点 2 处的水龙头可以灌溉区间 [1,3]
     点 3 处的水龙头可以灌溉区间 [2,4]
     点 4 处的水龙头可以灌溉区间 [4,4]
     点 5 处的水龙头可以灌溉区间 [5,5]
     只需要打开点 1 处的水龙头即可灌溉整个花园 [0,5] 。
     */
    n = 5;
    ranges = {3,4,1,1,0,0};
    res = 1;
    assert(res == Solution().minTaps(n, ranges));
    
    /**
     输入：n = 3, ranges = [0,0,0,0]
     输出：-1
     解释：即使打开所有水龙头，你也无法灌溉整个花园。
     */
    n = 3;
    ranges = {0,0,0,0};
    res = -1;
    assert(res == Solution().minTaps(n, ranges));

    cout << "OK~" << endl;
    
    return 0;
}
