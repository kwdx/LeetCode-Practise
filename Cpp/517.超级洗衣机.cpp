/*
 * @lc app=leetcode.cn id=517 lang=cpp
 *
 * [517] 超级洗衣机
 */

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

// @lc code=start
class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int tot = accumulate(machines.begin(), machines.end(), 0);
        int n = (int)machines.size();
        if (tot % n) {
            return -1;
        }
        int avg = tot / n;
        int ans = 0, sum = 0;
        for (int & num : machines) {
            num -= avg;
            sum += num;
            ans = max(ans, max(abs(sum), num));
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    vector<int> machines;
    int res;
    
    /**
     输入：machines = [1,0,5]
     输出：3
     解释：
     第一步:    1     0 <-- 5    =>    1     1     4
     第二步:    1 <-- 1 <-- 4    =>    2     1     3
     第三步:    2     1 <-- 3    =>    2     2     2
     */
    machines = {1,0,5};
    res = 3;
    assert(res == Solution().findMinMoves(machines));
    
    /**
     输入：machines = [0,3,0]
     输出：2
     解释：
     第一步:    0 <-- 3     0    =>    1     2     0
     第二步:    1     2 --> 0    =>    1     1     1
     */
    machines = {0,3,0};
    res = 2;
    assert(res == Solution().findMinMoves(machines));
    
    /**
     输入：machines = [0,2,0]
     输出：-1
     解释：
     不可能让所有三个洗衣机同时剩下相同数量的衣物。
     */
    machines = {0,2,0};
    res = -1;
    assert(res == Solution().findMinMoves(machines));
    
    cout << "OK~" << endl;
    
    return 0;
}
